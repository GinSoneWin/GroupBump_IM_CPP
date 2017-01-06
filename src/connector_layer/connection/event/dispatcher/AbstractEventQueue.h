//
// Created by WenJinXiong on 16-12-25.
//

#pragma once
#include <memory>
class AbstractEvent;

class AbstractEventQueue {
public:
    AbstractEventQueue();
    virtual ~AbstractEventQueue();
    virtual void prodEvent(std::shared_ptr<AbstractEvent>) = 0;
    virtual std::shared_ptr<AbstractEvent> consEvent() = 0;
};




