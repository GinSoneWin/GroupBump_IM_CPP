//
// Created by WenJinXiong on 16-12-25.
//

#pragma once

#include "AbstractSocketConnectionMap.h"
#include <semaphore.h>
#include <map>

class BasicSocketConnectionMap : public AbstractSocketConnectionMap{
public:
    BasicSocketConnectionMap();
    ~BasicSocketConnectionMap();

    void addConnection(int fd, std::shared_ptr<SocketConnection> ptr) override;

    void removeConnection(int fd) override;

    std::shared_ptr<SocketConnection> getConnection(int fd) override;

private:
    std::shared_ptr<sem_t> mutex;
    std::map<int,std::shared_ptr<SocketConnection>> connectionsMap;
};




