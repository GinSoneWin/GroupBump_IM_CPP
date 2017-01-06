//
// Created by WenJinXiong on 16-12-25.
//

#pragma once
#include "SocketConnection.h"
#include <memory>
class AbstractSocketConnectionContext;
class ConnectionHandlerChain;

class BasicSocketConnection : public SocketConnection{
public:
    BasicSocketConnection(int connfd,const std::string &ip_str);
    ~BasicSocketConnection();
    std::shared_ptr<AbstractSocketConnectionContext> getConnectionContext()override;
private:
    std::shared_ptr<AbstractSocketConnectionContext> connectionContext;

};




