//
// Created by WenJinXiong on 16-12-25.
//

#pragma once

#include "SocketConnectionInitializer.h"
#include<memory>
class SocketConnection;


class BasicSocketConnectionInitializer : public SocketConnectionInitializer{
public:
    BasicSocketConnectionInitializer();
    ~BasicSocketConnectionInitializer();

    void initConnection(std::shared_ptr<SocketConnection> conn) override;
};




