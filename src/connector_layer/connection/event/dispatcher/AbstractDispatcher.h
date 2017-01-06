//
// Created by WenJinXiong on 16-12-25.
//

#pragma once
#include <memory>
class AbstractEvent;
class AbstractDemultiplexer;


class AbstractDispatcher {
public:
    AbstractDispatcher();
    virtual  ~AbstractDispatcher();
    virtual void init() = 0;

    virtual void handle_events() = 0;

    virtual void register_event(std::shared_ptr<AbstractEvent> event) = 0;

    virtual void remove_event(std::shared_ptr<AbstractEvent> event) = 0;

    virtual void modify_event(std::shared_ptr<AbstractEvent> event) = 0;

    virtual int getListenDescriptor() const = 0;
    virtual std::shared_ptr<AbstractDemultiplexer> getDemultiplexer()const = 0;
};




