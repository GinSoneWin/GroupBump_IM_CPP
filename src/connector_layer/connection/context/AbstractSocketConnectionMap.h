//
// Created by WenJinXiong on 16-12-25.
//

#pragma once

#include <memory>
class SocketConnection;


class AbstractSocketConnectionMap {
public:
    AbstractSocketConnectionMap();
    virtual ~AbstractSocketConnectionMap();
    virtual void addConnection(int fd,std::shared_ptr<SocketConnection>) = 0;
    virtual void removeConnection(int fd) = 0;
    virtual std::shared_ptr<SocketConnection> getConnection(int fd) = 0;
};




