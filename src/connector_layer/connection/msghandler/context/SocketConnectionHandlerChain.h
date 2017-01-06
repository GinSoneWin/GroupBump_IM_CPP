//
// Created by WenJinXiong on 16-12-25.
//

#pragma once

#include <memory>
class AbstractSocketConnectionContext;
class SocketConnectionInboundHandler;
class SocketConnectionOutboundHandler;
class SocketConnection;


class SocketConnectionHandlerChain {
public:
    SocketConnectionHandlerChain();
    virtual ~SocketConnectionHandlerChain();
    virtual std::shared_ptr<AbstractSocketConnectionContext> getConnectionContext() = 0;
    virtual void setConnectionContext(std::shared_ptr<AbstractSocketConnectionContext> connectionContext) = 0;
    virtual void addInbound(std::shared_ptr<SocketConnectionInboundHandler> handler,std::shared_ptr<SocketConnection>) = 0;
    virtual void addOutbound(std::shared_ptr<SocketConnectionOutboundHandler> handler,std::shared_ptr<SocketConnection>) = 0;
    virtual void triggerChainRead() = 0;
};




