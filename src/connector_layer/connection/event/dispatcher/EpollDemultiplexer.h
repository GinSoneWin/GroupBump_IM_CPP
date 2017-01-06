//
// Created by WenJinXiong on 16-12-25.
//

#pragma once
#include "AbstractDemultiplexer.h"
#include <memory>
#include <sys/epoll.h>
class AbstractEvent;

class EpollDemultiplexer : public AbstractDemultiplexer{
public:
    EpollDemultiplexer();
    ~EpollDemultiplexer();
    void demultiplex() override;

    void register_event(std::shared_ptr<AbstractEvent> event) override;

    void remove_event(std::shared_ptr<AbstractEvent> event) override;

    void modify_event(std::shared_ptr<AbstractEvent> event) override ;



private:
    int epollfd;
    int maxevents;
    std::shared_ptr<epoll_event> evlist_ptr;
};




