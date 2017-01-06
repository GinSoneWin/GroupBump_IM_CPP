//
// Created by WenJinXiong on 16-12-26.
//

#pragma once


#include <thread>

class AbstractThreadGroup {
public:
    AbstractThreadGroup();
    virtual ~AbstractThreadGroup();
    virtual void addThread(std::thread &&t) = 0;

};




