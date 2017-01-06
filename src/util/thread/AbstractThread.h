//
// Created by WenJinXiong on 16-12-25.
//

#pragma once


class AbstractThread {
public:
    AbstractThread();
    virtual ~AbstractThread();
    virtual void run() = 0;
    virtual void join(void **status) = 0;
};




