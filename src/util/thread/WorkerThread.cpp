//
// Created by WenJinXiong on 16-12-25.
//

#include "WorkerThread.h"
#include "../../connector_layer/server/context/AbstractSocketServerContext.h"
#include "../../connector_layer/connection/event/general/AbstractEvent.h"
#include "../wrapper/unix_develop.h"
#include "../../connector_layer/connection/event/dispatcher/AbstractEventQueue.h"
#include "../../connector_layer/connection/event/evhandler/AbstractEventHandler.h"


void* workerthread_handler_func(void *arg){
    GLOBAL_CONSOLE_LOGGER->debug("worker thread start running.");
    std::shared_ptr<AbstractEventQueue> event_queue = AbstractSocketServerContext::getInstance()->getEventQueue();
    std::shared_ptr<AbstractEvent> event(nullptr);
    while(true){        //inifinite processing event
        event = event_queue->consEvent();
        event->getHandler()->handle_event(event);
    }
    return nullptr;
}
WorkerThread::WorkerThread() : thread_func_ptr(workerthread_handler_func)
{

}

WorkerThread::~WorkerThread()
{

}

void WorkerThread::run()
{
    Pthread_create(&this->tid,nullptr,workerthread_handler_func, nullptr);
}
void WorkerThread::join(void **status)
{
    Pthread_join(this->tid,status);
}