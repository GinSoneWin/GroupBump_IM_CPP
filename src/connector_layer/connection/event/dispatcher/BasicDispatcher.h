//
// Created by WenJinXiong on 16-12-25.
//

#pragma once



#include "AbstractDispatcher.h"
class AbstractDemultiplexer;


class BasicDispatcher : public AbstractDispatcher{
public:
    BasicDispatcher();
    ~BasicDispatcher();
    void init()override ;

    void handle_events() override;

    void register_event(std::shared_ptr<AbstractEvent> event) override;

    void remove_event(std::shared_ptr<AbstractEvent> event) override;

    void modify_event(std::shared_ptr<AbstractEvent> event) override;

    int getListenDescriptor()const override ;

    std::shared_ptr<AbstractDemultiplexer> getDemultiplexer() const override ;


private:
    std::shared_ptr<AbstractDemultiplexer> demultiplexer;
    int listenfd;
};




