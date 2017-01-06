//
// Created by WenJinXiong on 16-12-25.
//

#include "SocketConnectionOutboundHandler.h"
#include "../context/SocketConnectionHandlerContext.h"


extern template class SocketConnectionHandlerContext<SocketConnectionOutboundHandler>;

SocketConnectionOutboundHandler::SocketConnectionOutboundHandler() {

}
SocketConnectionOutboundHandler::~SocketConnectionOutboundHandler() {

}
std::shared_ptr<SocketConnectionHandlerContext<SocketConnectionOutboundHandler>> SocketConnectionOutboundHandler::getHandlerContext() {
    return handlerContext;
}