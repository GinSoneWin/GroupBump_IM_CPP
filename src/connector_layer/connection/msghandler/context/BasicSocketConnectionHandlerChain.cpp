//
// Created by WenJinXiong on 16-12-25.
//

#include "BasicSocketConnectionHandlerChain.h"
#include "../../../../global/global.h"
#include "../inbound/SocketConnectionInboundHandler.h"
#include "../outbound/SocketConnectionOutboundHandler.h"
#include "../context/SocketConnectionHandlerContext.h"
#include "../../general/SocketConnection.h"
#include "../../context/AbstractSocketConnectionContext.h"

BasicSocketConnectionHandlerChain::BasicSocketConnectionHandlerChain():inboundlist(std::make_shared<std::list<std::shared_ptr<SocketConnectionInboundHandler>>>()),
                                                                       outboundlist(std::make_shared<std::list<std::shared_ptr<SocketConnectionOutboundHandler>>>()),
                                                                       connectionContext()
{
    GLOBAL_CONSOLE_LOGGER->debug("BasicSocketConnectionHandlerChain()");
}
BasicSocketConnectionHandlerChain::~BasicSocketConnectionHandlerChain() {
    GLOBAL_CONSOLE_LOGGER->debug("~BasicSocketConnectionHandlerChain()");
}

std::shared_ptr<AbstractSocketConnectionContext> BasicSocketConnectionHandlerChain::getConnectionContext() {
    if(connectionContext.expired())
        throw std::runtime_error("BasicSocketConnectionHandlerChain::getConnectionContext() : nullpointer exception");
    return connectionContext.lock();
}

void BasicSocketConnectionHandlerChain::setConnectionContext(std::shared_ptr<AbstractSocketConnectionContext> connContext) {
    connectionContext = connContext;
}

void BasicSocketConnectionHandlerChain::addInbound(std::shared_ptr<SocketConnectionInboundHandler> handler,std::shared_ptr<SocketConnection> conn) {
    if(!inboundlist->empty()){
        std::shared_ptr<SocketConnectionInboundHandler> &curptr = inboundlist->back();
        curptr->getHandlerContext()->setNextHandler(handler);
    }
    inboundlist->push_back(handler);
    handler->getHandlerContext()->setCurrHandler(handler);
    handler->getHandlerContext()->setHandlerChain(conn->getConnectionContext()->getHandlerChain());
    handler->getHandlerContext()->setConnectionContext(conn->getConnectionContext());
}

void BasicSocketConnectionHandlerChain::addOutbound(std::shared_ptr<SocketConnectionOutboundHandler> handler,std::shared_ptr<SocketConnection> conn) {
    if(!outboundlist->empty()){
        std::shared_ptr<SocketConnectionOutboundHandler> &curptr = outboundlist->back();
        curptr->getHandlerContext()->setNextHandler(handler);
    }
    outboundlist->push_back(handler);
    handler->getHandlerContext()->setCurrHandler(handler);
    handler->getHandlerContext()->setHandlerChain(conn->getConnectionContext()->getHandlerChain());
    handler->getHandlerContext()->setConnectionContext(conn->getConnectionContext());
}

void BasicSocketConnectionHandlerChain::triggerChainRead() {
    if(this->inboundlist->empty())return;
    inboundlist->front()->pipelineRead(inboundlist->front()->getHandlerContext(), nullptr);
}