//
// Created by WenJinXiong on 16-12-25.
//

#include "EpollDemultiplexer.h"
#include "../../../../global/global.h"
#include "../../../../util/wrapper/unix_develop.h"
#include "AbstractEventQueue.h"
#include "../../../server/context/AbstractSocketServerContext.h"
#include "../general/EventType.h"
#include "AbstractDispatcher.h"
#include "../evhandler/NewConnEventHandler.h"
#include "../evhandler/ConnReadableEventHandler.h"
#include "../evhandler/ConnWritableEventHandler.h"
#include "../../general/SocketConnection.h"
#include "../general/AbstractEvent.h"
#include "../general/Event.h"

EpollDemultiplexer::EpollDemultiplexer():epollfd(0),maxevents(30),evlist_ptr(new epoll_event[maxevents],[](epoll_event *list){delete[]list;})
{
    this->epollfd = epoll_create(256);
    GLOBAL_CONSOLE_LOGGER->debug("epoll demultiplexer init successfully");
}
EpollDemultiplexer::~EpollDemultiplexer() {

}
void EpollDemultiplexer::demultiplex() {
    int nfd = 0;
    int i;
    int listenfd = AbstractSocketServerContext::getInstance()->getDispatcher()->getListenDescriptor();
    epoll_event *evlist = evlist_ptr.get();
//    struct sockaddr_in cliaddr;
//    socklen_t clilen;
    std::shared_ptr<AbstractEventQueue> event_queue = AbstractSocketServerContext::getInstance()->getEventQueue();
    while(true){
        nfd = Epoll_wait(epollfd,evlist,maxevents,-1);
        GLOBAL_CONSOLE_LOGGER->debug("event loop start.");
        for(i = 0; i < nfd; ++i){
            if(evlist[i].data.fd == listenfd){
                GLOBAL_CONSOLE_LOGGER->debug("listen descriptor event trigger.");
                std::shared_ptr<AbstractEvent> event(new Event(EventType::NEWCONN_EVENT(),listenfd,std::make_shared<NewConnEventHandler>(), nullptr));
                event_queue->prodEvent(event);
            }else if(evlist[i].events & EPOLLIN){
                GLOBAL_CONSOLE_LOGGER->debug("socket descriptor read event trigger.");
                if(evlist[i].data.fd < 0)continue;
                std::shared_ptr<AbstractEvent> event(new Event(EventType::CONNREADABLE_EVENT(),evlist[i].data.fd,std::make_shared<ConnReadableEventHandler>(),
                                                       AbstractSocketServerContext::getInstance()->getConnection(evlist[i].data.fd)->getConnectionContext()));
                event_queue->prodEvent(event);
            }else if(evlist[i].events & EPOLLOUT){
                GLOBAL_CONSOLE_LOGGER->debug("socket descriptor write event trigger.");
                std::shared_ptr<AbstractEvent> event(new Event(EventType::CONNWRITABLE_EVENT(),evlist[i].data.fd,std::make_shared<ConnWritableEventHandler>(),
                                                       AbstractSocketServerContext::getInstance()->getConnection(evlist[i].data.fd)->getConnectionContext()));
                event_queue->prodEvent(event);
            }
        }
    }
}

void EpollDemultiplexer::register_event(std::shared_ptr<AbstractEvent> event) {
    GLOBAL_CONSOLE_LOGGER->debug("begin register event");
    struct epoll_event ev;
    ev.data.fd = event->getHandle();
    int op = EPOLL_CTL_ADD;
    if(event->getType() == EventType::LISTEN_EVENT()){
        ev.events = EPOLLIN | EPOLLONESHOT;
    }else if(event->getType() == EventType::NEWCONN_EVENT()){
        ev.events = EPOLLIN | EPOLLONESHOT;
    }else{
        throw std::runtime_error("EpollDemultiplexer : register unknown event.");
    }
    Epoll_ctl(this->epollfd,op,event->getHandle(),&ev);
    GLOBAL_CONSOLE_LOGGER->debug("register event successfully");
}

void EpollDemultiplexer::modify_event(std::shared_ptr<AbstractEvent> event) {
    GLOBAL_CONSOLE_LOGGER->debug("begin modify event");
    struct epoll_event ev;
    ev.data.fd = event->getHandle();
    int op = EPOLL_CTL_MOD;
    if(event->getType() == EventType::LISTEN_EVENT()){
        ev.events = EPOLLIN | EPOLLONESHOT;
    }else if(event->getType() == EventType::REGISTER_READ_EVENT()){
        ev.events = EPOLLIN | EPOLLONESHOT;
    }else if(event->getType() == EventType::REGISTER_WRITE_EVENT()){
        ev.events = EPOLLOUT | EPOLLET | EPOLLONESHOT;
    }else{
        throw std::runtime_error("EpollDemultiplexer : modify unknown event");
    }
    Epoll_ctl(this->epollfd,op,event->getHandle(),&ev);
    GLOBAL_CONSOLE_LOGGER->debug("modify event successfully");

}

void EpollDemultiplexer::remove_event(std::shared_ptr<AbstractEvent> event) {
    GLOBAL_CONSOLE_LOGGER->debug("begin remove event");
    struct epoll_event ev;
    ev.data.fd = event->getHandle();
    int op = EPOLL_CTL_DEL;
    Epoll_ctl(this->epollfd,op,event->getHandle(),&ev);
    GLOBAL_CONSOLE_LOGGER->debug("deregister event successsully");
}