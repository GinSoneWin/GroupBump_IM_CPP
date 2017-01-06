//
// Created by WenJinXiong on 16-12-25.
//

#include "BasicSocketConnectionMap.h"
#include "../../../util/wrapper/unix_develop.h"
#include "../../../util/lock/Lock.h"
#include "../../../util/lock/SemaphoreLock.h"


BasicSocketConnectionMap::BasicSocketConnectionMap() : mutex(new sem_t(),Sem_deleter)
{
    Sem_init(mutex.get(),0,1);
}

BasicSocketConnectionMap::~BasicSocketConnectionMap() {

}

void BasicSocketConnectionMap::addConnection(int fd, std::shared_ptr<SocketConnection> ptr) {
    std::shared_ptr<Lock> mutexlock(new SemaphoreLock(mutex));
    connectionsMap.insert({fd,ptr});
}

void BasicSocketConnectionMap::removeConnection(int fd) {
    std::shared_ptr<Lock> mutexlock(new SemaphoreLock(mutex));
    if(connectionsMap.find(fd) != connectionsMap.end())
        connectionsMap.erase(fd);
}

std::shared_ptr<SocketConnection> BasicSocketConnectionMap::getConnection(int fd) {
    if(connectionsMap.find(fd) != connectionsMap.end())
        return connectionsMap[fd];
    throw std::runtime_error("BasicSocketConnectionMap::getConnection(int fd)  no coresponding connection");
}


