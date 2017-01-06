//
// Created by WenJinXiong on 16-12-25.
//

#include "BasicSocketServerContext.h"
#include "../../../util/wrapper/unix_develop.h"
#include "../../connection/context/BasicSocketConnectionMap.h"
#include "../../../global/global.h"
#include "../../connection/event/general/Event.h"
#include "../../connection/event/dispatcher/BasicEventQueue.h"
#include "../../connection/event/dispatcher/BasicDispatcher.h"
#include "../../../util/thread/BossThread.h"
#include "../../connection/initializer/SocketConnectionInitializer.h"
#include "../../../util/thread/WorkerThread.h"


std::shared_ptr<sockaddr_in> BasicSocketServerContext::servaddr(new sockaddr_in());
int BasicSocketServerContext::port = 0;
bool BasicSocketServerContext::hasbind = false;

BasicSocketServerContext::BasicSocketServerContext():conninitializer_ptr(nullptr),event_queue_ptr(new BasicEventQueue()),
                                                     bossThread(nullptr),workerThreads(),workerThreadCnt(5),dispatcher(new BasicDispatcher()),
                                                     connmap(new BasicSocketConnectionMap())
{
    GLOBAL_CONSOLE_LOGGER->debug("basic socketserver context created successfully");
}
BasicSocketServerContext::~BasicSocketServerContext()
{
    GLOBAL_CONSOLE_LOGGER->debug("~BasicSocketServerContext()");
}
void BasicSocketServerContext::init() {
    assert(conninitializer_ptr != nullptr);
    assert(hasbind);
    std::shared_ptr<AbstractDispatcher> dispatcher = AbstractSocketServerContext::getInstance()->getDispatcher();
    dispatcher->init();
    std::shared_ptr<AbstractEvent> event(new Event(EventType::LISTEN_EVENT(),dispatcher->getListenDescriptor(), nullptr));
    dispatcher->register_event(event);
    event.reset();

    GLOBAL_CONSOLE_LOGGER->debug("now create bossthread and workerthreads.");

    bossThread = std::make_shared<BossThread>();
    for(int i = 0; i < workerThreadCnt; ++i){
        workerThreads.push_back(std::make_shared<WorkerThread>());
    }
    bossThread->run();
    for(int i = 0; i < workerThreadCnt; ++i){
        workerThreads[i]->run();
    }
    GLOBAL_CONSOLE_LOGGER->debug("BasicSocketServerContext init successfully");
}

AbstractSocketServerContext &
BasicSocketServerContext::setConnectionInitializer(std::shared_ptr<SocketConnectionInitializer> conninit) {

    conninitializer_ptr = conninit;
    return *this;
}

AbstractSocketServerContext &BasicSocketServerContext::setWorkerThreadCnt(int cnt) {
    if(cnt >= 20 || cnt <= 0)
        this->workerThreadCnt = 5;
    else
        this->workerThreadCnt = cnt;
    return *this;
}
std::shared_ptr<AbstractEventQueue> BasicSocketServerContext::getEventQueue() {
    return event_queue_ptr;
}

std::shared_ptr<SocketConnection> BasicSocketServerContext::getConnection(int sockfd) {
    return connmap->getConnection(sockfd);
}
void BasicSocketServerContext::sync() {
    for(int i = 0; i < workerThreadCnt; ++i){
        workerThreads[i]->join(nullptr);
    }
}
std::shared_ptr<AbstractDispatcher> BasicSocketServerContext::getDispatcher()
{
    return this->dispatcher;
}
AbstractSocketServerContext& BasicSocketServerContext::bind(int port) {
    BasicSocketServerContext::port = port;
    BasicSocketServerContext::hasbind = true;
    return *this;
}

int BasicSocketServerContext::getPort() const {
    return this->port;
}
bool BasicSocketServerContext::isBind() const {
    return hasbind;
}
std::shared_ptr<sockaddr_in> BasicSocketServerContext::getServaddr()
{
    return this->servaddr;
}

void BasicSocketServerContext::addConnection(int connfd,std::shared_ptr<SocketConnection> conn) {
    conninitializer_ptr->initConnection(conn);
    connmap->addConnection(connfd,conn);
    GLOBAL_CONSOLE_LOGGER->debug("new connection added");
}

void BasicSocketServerContext::shutdown() {

}









