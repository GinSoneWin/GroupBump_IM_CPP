//
// Created by WenJinXiong on 16-12-25.
//

#pragma once

#include "AbstractThread.h"
#include "../../global/global.h"

class WorkerThread : public AbstractThread{
public:
    WorkerThread();
    ~WorkerThread();
    void run()override ;
    void join(void **status)override;
private:
    void* (*thread_func_ptr)(void*) = nullptr;
    fonny_thread_id_t tid;
};


void* workerthread_handler_func(void *);

