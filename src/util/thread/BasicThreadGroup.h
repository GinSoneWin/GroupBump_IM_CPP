//
// Created by WenJinXiong on 16-12-26.
//

#pragma once

#include <vector>
#include "AbstractThreadGroup.h"
class ThreadGuard;
class BasicThreadGroup : public AbstractThreadGroup{

public:
    BasicThreadGroup();
    ~BasicThreadGroup();

    void addThread(std::thread &&t) override;

private:
    std::vector<std::thread> threads;
};




