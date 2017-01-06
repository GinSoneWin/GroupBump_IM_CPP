//
// Created by WenJinXiong on 16-12-25.
//

#include "SemaphoreLock.h"
#include "../wrapper/unix_develop.h"
#include "../../global/global.h"


SemaphoreLock::SemaphoreLock(std::shared_ptr<sem_t> ptr):Lock(),sem(ptr)
{
    Sem_wait(ptr.get());
    GLOBAL_CONSOLE_LOGGER->debug("semaphore lock hold");
}
SemaphoreLock::~SemaphoreLock() {
    Sem_post(sem.get());
    GLOBAL_CONSOLE_LOGGER->debug("semaphore lock release");
}