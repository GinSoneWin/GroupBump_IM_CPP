//
// Created by WenJinXiong on 16-12-25.
//

#include "BasicEventQueue.h"
#include "../../../../util/wrapper/unix_develop.h"
#include "../../../../global/global.h"


BasicEventQueue::BasicEventQueue():event_queue(),nstored(new sem_t(),Sem_deleter),
                                   mutex(new sem_t(),Sem_deleter),nempty(new sem_t(),Sem_deleter)
{
    Sem_init(nstored.get(),0,0);
    Sem_init(mutex.get(),0,1);
    Sem_init(nempty.get(),0,MAXEVENTCOUNT);
    GLOBAL_CONSOLE_LOGGER->debug("event queue created successfully.");
}
BasicEventQueue::~BasicEventQueue() {

}
void BasicEventQueue::prodEvent(std::shared_ptr<AbstractEvent> ptr) {
    GLOBAL_CONSOLE_LOGGER->debug("ready to produce an new event");
    Sem_wait(nempty.get());
    Sem_wait(mutex.get());
    event_queue.push(ptr);  //add a event into queue
    Sem_post(mutex.get());
    Sem_post(nstored.get());
    GLOBAL_CONSOLE_LOGGER->debug("produce an new event successfully.");
}

std::shared_ptr<AbstractEvent> BasicEventQueue::consEvent() {
    GLOBAL_CONSOLE_LOGGER->debug("ready to consume an new event.");
    Sem_wait(nstored.get());
    Sem_wait(mutex.get());
    std::shared_ptr<AbstractEvent> ptr = nullptr;
    ptr =  event_queue.front();
    event_queue.pop();      //consume a event from queue
    Sem_post(mutex.get());
    Sem_post(nempty.get());
    GLOBAL_CONSOLE_LOGGER->debug("consume an new event successfully.");
    return ptr;
}
