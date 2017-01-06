//
// Created by WenJinXiong on 16-12-25.
//

#pragma once
#include <memory>


class Message;
class SocketConnectionOutboundHandler;
template <typename > class SocketConnectionHandlerContext;

class SocketConnectionOutboundHandler {
public:
    SocketConnectionOutboundHandler();
    virtual ~SocketConnectionOutboundHandler();

    std::shared_ptr<SocketConnectionHandlerContext<SocketConnectionOutboundHandler>> getHandlerContext();
    virtual void pipelineWrite(std::shared_ptr<SocketConnectionHandlerContext<SocketConnectionOutboundHandler>>context, std::shared_ptr<Message> message) = 0;

private:
    std::shared_ptr<SocketConnectionHandlerContext<SocketConnectionOutboundHandler>> handlerContext;
};




