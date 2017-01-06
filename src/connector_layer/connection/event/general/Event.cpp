//
// Created by WenJinXiong on 16-12-25.
//

#include "Event.h"



Event::Event(EventType eventType, int handle,std::shared_ptr<AbstractEventHandler> handler,std::shared_ptr<AbstractSocketConnectionContext> context)
        :type(eventType),handle(handle),handler(handler),conncontext_ptr(context)
{

}
Event::~Event() {

}

const EventType &Event::getType() const {
    return type;
}

int Event::getHandle() const {
    return handle;
}
std::shared_ptr<AbstractEventHandler> Event::getHandler() const {
    return handler;
}
const std::shared_ptr<AbstractSocketConnectionContext> &Event::getConncontext_ptr() const {
    return conncontext_ptr;
}