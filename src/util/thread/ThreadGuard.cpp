//
// Created by WenJinXiong on 16-12-26.
//

#include "ThreadGuard.h"

ThreadGuard::ThreadGuard(std::thread &&t_):t(std::move(t_))
{
    if(!t.joinable())
        throw std::logic_error("ThreadGuard::ThreadGuard(thread&&) : thread not joinnable");
}

ThreadGuard::~ThreadGuard() {
    t.join();
}
