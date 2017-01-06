//
// Created by WenJinXiong on 16-12-26.
//

#pragma once


#include <thread>

class ThreadGuard {
public:
    explicit ThreadGuard(std::thread &&t);
    ~ThreadGuard();
    ThreadGuard(const ThreadGuard &t)=delete;
    ThreadGuard&  operator=(const ThreadGuard &)=delete;
private:
    std::thread t;
};




