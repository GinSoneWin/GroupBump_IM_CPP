//
// Created by WenJinXiong on 16-12-29.
//
#include <mutex>
#include "src/util/thread/BasicThreadGroup.h"
int global_int = 0;
std::mutex global_mutex;
void increment()
{
    std::lock_guard<std::mutex> guard(global_mutex);
    while(global_int < 10000){
        ++global_int;
        printf("curr threead :%d, global_int : %d\n",std::this_thread::get_id(),global_int);
    }
}
int main()
{
    std::shared_ptr<AbstractThreadGroup> group = std::make_shared<BasicThreadGroup>();
    unsigned long maxThreads = std::thread::hardware_concurrency();
    maxThreads = (maxThreads == 0) ? 2 : maxThreads;
    for(int i = 0; i != maxThreads; ++i)
    {
        group->addThread(std::thread(increment));
    }
}
