//
// Created by WenJinXiong on 16-12-25.
//

#pragma once
#include "SocketConnectionHandlerChain.h"
#include <memory>
#include <list>


class SocketConnectionInboundHandler;
class SocketConnectionOutboundHandler;
class AbstractSocketConnectionContext;
class SocketConnection;



class BasicSocketConnectionHandlerChain : public SocketConnectionHandlerChain{
public:
    BasicSocketConnectionHandlerChain();
    ~BasicSocketConnectionHandlerChain();
    std::shared_ptr<AbstractSocketConnectionContext> getConnectionContext() override;
    void setConnectionContext(std::shared_ptr<AbstractSocketConnectionContext> connectionContext)override;

    void addInbound(std::shared_ptr<SocketConnectionInboundHandler> handler,std::shared_ptr<SocketConnection>) override;

    void addOutbound(std::shared_ptr<SocketConnectionOutboundHandler> handler,std::shared_ptr<SocketConnection>) override;

    void triggerChainRead() override;

private:
    std::shared_ptr<std::list<std::shared_ptr<SocketConnectionInboundHandler>>> inboundlist;
    std::shared_ptr<std::list<std::shared_ptr<SocketConnectionOutboundHandler>>> outboundlist;
    std::weak_ptr<AbstractSocketConnectionContext> connectionContext;
};




