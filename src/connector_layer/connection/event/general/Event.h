//
// Created by WenJinXiong on 16-12-25.
//

#pragma once
#include <memory>
#include "AbstractEvent.h"
#include "EventType.h"


class AbstractEventHandler;
class AbstractSocketConnectionContext;


class Event : public AbstractEvent{
public:
    Event(EventType type,int handle,std::shared_ptr<AbstractEventHandler> handler,std::shared_ptr<AbstractSocketConnectionContext> = nullptr);
    virtual ~Event();


    const EventType &getType() const override ;

    int getHandle() const override;

    std::shared_ptr<AbstractEventHandler> getHandler()const override;

    const std::shared_ptr<AbstractSocketConnectionContext> &getConncontext_ptr() const override;

private:
    EventType type;
    int handle;
    std::shared_ptr<AbstractEventHandler> handler;
    std::shared_ptr<AbstractSocketConnectionContext> conncontext_ptr;

};




