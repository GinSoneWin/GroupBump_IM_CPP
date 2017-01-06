//
// Created by WenJinXiong on 16-12-25.
//

#include "BasicDispatcher.h"
#include "EpollDemultiplexer.h"
#include "../../../../util/wrapper/unix_develop.h"
#include "../../../server/context/AbstractSocketServerContext.h"
#include "../../../../global/global.h"


BasicDispatcher::BasicDispatcher() : demultiplexer(new EpollDemultiplexer()),listenfd(0){

}
BasicDispatcher::~BasicDispatcher() {

}
void BasicDispatcher::init() {
    this->listenfd = Socket(AF_INET,SOCK_STREAM,0);
    std::shared_ptr<sockaddr_in> servaddr = AbstractSocketServerContext::getInstance()->getServaddr();
    bzero(servaddr.get(),sizeof(*servaddr.get()));
    servaddr->sin_family = AF_INET;
    servaddr->sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr->sin_port = htons(AbstractSocketServerContext::getInstance()->getPort());
    Bind(this->listenfd,(struct sockaddr *)servaddr.get(),sizeof(*servaddr.get()));
    Listen(this->listenfd,10000);
    GLOBAL_CONSOLE_LOGGER->debug("basic dispatcher init successfully.");
}

void BasicDispatcher::handle_events() {
    this->demultiplexer->demultiplex(); //epoll_wait loop
}

void BasicDispatcher::register_event(std::shared_ptr<AbstractEvent> event) {
    this->demultiplexer->register_event(event);
}

void BasicDispatcher::remove_event(std::shared_ptr<AbstractEvent> event) {
    this->demultiplexer->remove_event(event);
}

void BasicDispatcher::modify_event(std::shared_ptr<AbstractEvent> event) {
    this->demultiplexer->modify_event(event);
}

int BasicDispatcher::getListenDescriptor() const {
    return this->listenfd;
}



std::shared_ptr<AbstractDemultiplexer> BasicDispatcher::getDemultiplexer() const {
    return this->demultiplexer;
}