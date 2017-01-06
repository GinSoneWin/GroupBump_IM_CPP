//
// Created by WenJinXiong on 16-12-25.
//

#pragma once
#include <memory>
class AbstractEvent;

class AbstractEventHandler {
public:
    AbstractEventHandler();
    virtual ~AbstractEventHandler();
    virtual void handle_event(std::shared_ptr<AbstractEvent> event) = 0;
};




