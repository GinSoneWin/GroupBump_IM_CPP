//
// Created by WenJinXiong on 16-12-26.
//

#include <netinet/in.h>
#include "NewConnEventHandler.h"
#include "../../../../global/global.h"
#include "../../../../util/wrapper/unix_develop.h"
#include "../../../server/context/AbstractSocketServerContext.h"
#include "../../general/BasicSocketConnection.h"
#include "../general/EventType.h"
#include "../dispatcher/AbstractDispatcher.h"
#include "../../context/AbstractSocketConnectionContext.h"
#include "../general/AbstractEvent.h"
#include "../general/Event.h"

NewConnEventHandler::NewConnEventHandler() {

}
NewConnEventHandler::~NewConnEventHandler() {

}

void NewConnEventHandler::handle_event(std::shared_ptr<AbstractEvent> event){
    GLOBAL_CONSOLE_LOGGER->debug("new connection eventhandler starts.");
    struct sockaddr_in cliaddr;
    socklen_t clilen;
    char strbuf[INET_ADDRSTRLEN];
    int connfd = Accept(event->getHandle(),(struct sockaddr *)&cliaddr,&clilen);    //if exception occur,you should close this descrptor
    std::shared_ptr<AbstractSocketServerContext> servercontext = AbstractSocketServerContext::getInstance();
    try {
        std::shared_ptr<SocketConnection> conn(new BasicSocketConnection(connfd,Inet_ntop(AF_INET,&cliaddr,strbuf,INET_ADDRSTRLEN)));
        conn->getConnectionContext()->setConnection(conn);
        servercontext->addConnection(connfd,conn);
        servercontext->getDispatcher()->modify_event(std::make_shared<Event>(EventType::LISTEN_EVENT(),servercontext->getDispatcher()->getListenDescriptor(), nullptr, nullptr));
        servercontext->getDispatcher()->register_event(std::make_shared<Event>(EventType::NEWCONN_EVENT(),connfd, nullptr, nullptr));
    }catch (...){
        GLOBAL_CONSOLE_LOGGER->error("create new connection exception.");
        Close(connfd);
    }
    GLOBAL_CONSOLE_LOGGER->info("new connection context add successfully.");
}

