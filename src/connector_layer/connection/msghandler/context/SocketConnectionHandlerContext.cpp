//
// Created by WenJinXiong on 16-12-25.
//

#include "SocketConnectionHandlerContext.h"
#include "../../context/AbstractSocketConnectionContext.h"
#include "../inbound/SocketConnectionInboundHandler.h"
#include "../outbound/SocketConnectionOutboundHandler.h"
#include "../../event/general/AbstractEvent.h"
#include "../../../server/context/AbstractSocketServerContext.h"
#include "../../event/general/EventType.h"
#include "../../event/dispatcher/AbstractDispatcher.h"
#include "../../event/general/Event.h"

template class SocketConnectionHandlerContext<SocketConnectionInboundHandler>;
template class SocketConnectionHandlerContext<SocketConnectionOutboundHandler>;


template<>
void SocketConnectionHandlerContext<SocketConnectionInboundHandler>::passNextHandler(std::shared_ptr<Message> message)
{
    if(getNextHandler() == nullptr){
        GLOBAL_CONSOLE_LOGGER->debug("there is no more msghandler behind");
        AbstractSocketServerContext::getInstance()->getDispatcher()->modify_event(std::make_shared<Event>(EventType::REGISTER_READ_EVENT(),getConnectionContext()->getConnFd(),nullptr,nullptr));
        return;
    }
    getNextHandler()->pipelineRead(getNextHandler()->getHandlerContext(),message);
}

template<>
void SocketConnectionHandlerContext<SocketConnectionOutboundHandler>::passNextHandler(std::shared_ptr<Message> message)
{
    if(getNextHandler() == nullptr){
        GLOBAL_CONSOLE_LOGGER->debug("there is no more msghandler behind");
        return;
    }
    getNextHandler()->pipelineWrite(getNextHandler()->getHandlerContext(),message);
}