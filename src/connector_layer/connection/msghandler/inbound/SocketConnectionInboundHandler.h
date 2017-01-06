//
// Created by WenJinXiong on 16-12-25.
//

#pragma once
#include <memory>

class SocketConnectionInboundHandler;
class Message;
template <typename> class SocketConnectionHandlerContext;



class SocketConnectionInboundHandler {
public:
    SocketConnectionInboundHandler();
    virtual ~SocketConnectionInboundHandler();

    std::shared_ptr<SocketConnectionHandlerContext<SocketConnectionInboundHandler>> getHandlerContext();
    virtual void pipelineRead(std::shared_ptr<SocketConnectionHandlerContext<SocketConnectionInboundHandler>> context,std::shared_ptr<Message> msg) = 0;

private:
    std::shared_ptr<SocketConnectionHandlerContext<SocketConnectionInboundHandler>> handlerContext;
};



