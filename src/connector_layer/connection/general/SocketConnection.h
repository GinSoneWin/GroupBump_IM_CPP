//
// Created by WenJinXiong on 16-12-25.
//

#pragma once


#include <memory>
class Message;
class AbstractSocketConnectionContext;

class SocketConnection {
public:
    SocketConnection();
    virtual ~SocketConnection();
    virtual std::shared_ptr<AbstractSocketConnectionContext> getConnectionContext() = 0;

};




