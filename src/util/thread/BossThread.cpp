//
// Created by WenJinXiong on 16-12-25.
//

#include "BossThread.h"
#include "../../connector_layer/server/context/AbstractSocketServerContext.h"
#include "../wrapper/unix_develop.h"
#include "../../connector_layer/connection/event/dispatcher/AbstractDispatcher.h"

void* bossthread_handler_func(void*)
{
    GLOBAL_CONSOLE_LOGGER->debug("boss thread start running.");

    AbstractSocketServerContext::getInstance()->getDispatcher()->handle_events();//start loop
    return nullptr;
}
BossThread::BossThread()
{


}
BossThread::~BossThread() {

}
void BossThread::run() {
    Pthread_create(&this->tid,nullptr,bossthread_handler_func, nullptr);
}
void BossThread::join(void **status) {
    Pthread_join(this->tid, status);
}
