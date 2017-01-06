//
// Created by WenJinXiong on 16-12-25.
//

#pragma once


#include "Lock.h"
#include <memory>
#include <semaphore.h>


class SemaphoreLock : public Lock{
public:
    SemaphoreLock(std::shared_ptr<sem_t>);
    ~SemaphoreLock();

private:
    std::shared_ptr<sem_t> sem;
};






