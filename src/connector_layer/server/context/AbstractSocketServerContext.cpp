//
// Created by WenJinXiong on 16-12-25.
//

#include "AbstractSocketServerContext.h"
#include "../../../util/wrapper/unix_develop.h"
#include "BasicSocketServerContext.h"

std::shared_ptr<AbstractSocketServerContext> AbstractSocketServerContext::uniqueContext = nullptr;
std::shared_ptr<sem_t> AbstractSocketServerContext::mutex(new sem_t(),Sem_deleter);
AbstractSocketServerContext::AbstractSocketServerContext() {

}
AbstractSocketServerContext::~AbstractSocketServerContext() {

}
void AbstractSocketServerContext::globalinit() {
    Sem_init(mutex.get(),0,1);
}
std::shared_ptr<AbstractSocketServerContext> AbstractSocketServerContext::getInstance() {
    if(uniqueContext == nullptr){
        Sem_wait(mutex.get());
        if(uniqueContext == nullptr)
            uniqueContext = std::make_shared<BasicSocketServerContext>();
        Sem_post(mutex.get());
    }
    return uniqueContext;
}