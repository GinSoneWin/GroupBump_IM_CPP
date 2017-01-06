//
// Created by WenJinXiong on 16-12-25.
//

#include "SocketConnectionInboundHandler.h"
#include "../../../../global/global.h"
#include "../context/SocketConnectionHandlerContext.h"

extern template class SocketConnectionHandlerContext<SocketConnectionInboundHandler>;

SocketConnectionInboundHandler::SocketConnectionInboundHandler() : handlerContext(std::make_shared<SocketConnectionHandlerContext<SocketConnectionInboundHandler>>()){

}
SocketConnectionInboundHandler::~SocketConnectionInboundHandler() {

}
std::shared_ptr<SocketConnectionHandlerContext<SocketConnectionInboundHandler>> SocketConnectionInboundHandler::getHandlerContext() {
    return handlerContext;
}