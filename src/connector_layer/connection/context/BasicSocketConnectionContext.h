//
// Created by WenJinXiong on 16-12-25.
//

#pragma once

#include "AbstractSocketConnectionContext.h"
#include <string>
#include <memory>
class ByteBuffer;
class SocketConnectionHandlerChain;
class SocketConnection;


class BasicSocketConnectionContext : public AbstractSocketConnectionContext{
public:
    BasicSocketConnectionContext(int connfd,const std::string &ipstr);
    ~BasicSocketConnectionContext();
    int getConnFd() override;
    std::shared_ptr<SocketConnection> getConnection()override ;
    void setConnection(std::shared_ptr<SocketConnection> conn)override;
    std::shared_ptr<SocketConnectionHandlerChain> getHandlerChain()override ;
    void read()override;
    virtual std::shared_ptr<ByteBuffer> getByteBuffer() override;



private:
    int connfd;
    std::weak_ptr<SocketConnection> connection;
    std::shared_ptr<SocketConnectionHandlerChain> handlerChain;
    std::shared_ptr<ByteBuffer> bytebuf;

};




