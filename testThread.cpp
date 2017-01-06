//
// Created by WenJinXiong on 16-12-26.
//

#include "src/util/thread/AbstractThread.h"
#include "src/util/thread/BasicThreadGroup.h"
#include "src/util/thread/ThreadGuard.h"
#include <memory>

void do_work()
{
    printf("current thread id : %ld\n",std::this_thread::get_id());
}
int main()
{
    std::thread::id master_id = std::this_thread::get_id();
    printf("main thread id : %ld\n",master_id);
    std::shared_ptr<AbstractThreadGroup> group = std::make_shared<BasicThreadGroup>();
    group->addThread(std::thread(do_work));
    group->addThread(std::thread(do_work));
    ThreadGuard g{std::thread(do_work)};
}