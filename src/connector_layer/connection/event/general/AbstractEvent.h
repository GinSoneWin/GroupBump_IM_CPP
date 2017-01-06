//
// Created by WenJinXiong on 16-12-25.
//

#pragma once

#include <memory>

class EventType;
class AbstractEventHandler;
class AbstractSocketConnectionContext;

class AbstractEvent {
public:
    AbstractEvent();
    virtual ~AbstractEvent();

    virtual const EventType &getType() const = 0;

    virtual int getHandle() const = 0;

    virtual std::shared_ptr<AbstractEventHandler> getHandler()const = 0;

    virtual const std::shared_ptr<AbstractSocketConnectionContext> &getConncontext_ptr() const = 0;
};




