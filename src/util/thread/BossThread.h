//
// Created by WenJinXiong on 16-12-25.
//

#pragma once

#include "AbstractThread.h"

#include "../../global/global.h"


class BossThread : public AbstractThread{
public:
    BossThread();
    virtual ~BossThread();
    void run()override;
    void join(void **status)override;

private:
    void *thread_func_ptr = nullptr;
    fonny_thread_id_t tid;
};




void* bossthread_handler_func(void*);