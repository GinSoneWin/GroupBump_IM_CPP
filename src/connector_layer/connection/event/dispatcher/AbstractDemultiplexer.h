//
// Created by WenJinXiong on 16-12-25.
//

#pragma once

#include <memory>
class AbstractEvent;

class AbstractDemultiplexer {
public:
    AbstractDemultiplexer();
    virtual ~AbstractDemultiplexer();
    virtual void demultiplex() = 0;

    virtual void register_event(std::shared_ptr<AbstractEvent> event) = 0;

    virtual void remove_event(std::shared_ptr<AbstractEvent> event) = 0;

    virtual void modify_event(std::shared_ptr<AbstractEvent> event) = 0;
};




