//
// Created by WenJinXiong on 16-12-25.
//

#pragma once

#include <memory>
class SocketConnection;


class SocketConnectionInitializer {
public:
    SocketConnectionInitializer();
    virtual ~SocketConnectionInitializer();
    virtual void initConnection(std::shared_ptr<SocketConnection> conn) = 0;
};




