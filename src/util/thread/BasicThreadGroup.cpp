//
// Created by WenJinXiong on 16-12-26.
//

#include "BasicThreadGroup.h"

BasicThreadGroup::BasicThreadGroup():threads()
{

}

BasicThreadGroup::~BasicThreadGroup() {
    for(int i = 0; i != threads.size(); ++i)
    {
        threads[i].join();
    }
}

void BasicThreadGroup::addThread(std::thread &&t) {
    if(!t.joinable())
        throw std::logic_error("BasicThreadGroup::addThread : thread not joinnable");
    threads.push_back(std::move(t));
}
