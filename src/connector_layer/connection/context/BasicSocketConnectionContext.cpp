//
// Created by WenJinXiong on 16-12-25.
//

#include "BasicSocketConnectionContext.h"
#include "../msghandler/context/SocketConnectionHandlerChain.h"
#include "../../../global/global.h"
#include "../buffer/BasicByteBuffer.h"
#include "../msghandler/context/BasicSocketConnectionHandlerChain.h"


BasicSocketConnectionContext::BasicSocketConnectionContext(int connfd,const std::string &ip_str) : connfd(connfd),connection(),
                                                                                                   handlerChain(std::make_shared<BasicSocketConnectionHandlerChain>()),
                                                                                                   bytebuf(std::make_shared<BasicByteBuffer>())
{
    GLOBAL_CONSOLE_LOGGER->debug("BasicSocketConnectionContext()");
}
BasicSocketConnectionContext::~BasicSocketConnectionContext() {
    GLOBAL_CONSOLE_LOGGER->debug("~BasicSocketConnectionContext()");
}

int BasicSocketConnectionContext::getConnFd() {
    return connfd;
}

std::shared_ptr<SocketConnection> BasicSocketConnectionContext::getConnection() {
    if(connection.expired())
        throw std::runtime_error("BasicSocketConnectionContext::getConnection : nullpointer exception.");
    else
        return connection.lock();
}

void BasicSocketConnectionContext::setConnection(std::shared_ptr<SocketConnection> conn) {
    connection = conn;
}

std::shared_ptr<SocketConnectionHandlerChain> BasicSocketConnectionContext::getHandlerChain() {
    return handlerChain;
}
void BasicSocketConnectionContext::read()
{
    this->handlerChain->triggerChainRead();
}

std::shared_ptr<ByteBuffer> BasicSocketConnectionContext::getByteBuffer() {
    return bytebuf;
}