//
// Created by WenJinXiong on 16-12-25.
//

#pragma once

#include <queue>
#include "AbstractEventQueue.h"
#include <semaphore.h>
class AbstractEvent;


class BasicEventQueue : public AbstractEventQueue{
public:
    BasicEventQueue();
    ~BasicEventQueue();


    void prodEvent(std::shared_ptr<AbstractEvent> ptr) override;

    std::shared_ptr<AbstractEvent> consEvent() override;

private:
    static constexpr int MAXEVENTCOUNT = 1000000;
    std::queue<std::shared_ptr<AbstractEvent>> event_queue;
    std::shared_ptr<sem_t> nstored;
    std::shared_ptr<sem_t> mutex;
    std::shared_ptr<sem_t> nempty;
};




