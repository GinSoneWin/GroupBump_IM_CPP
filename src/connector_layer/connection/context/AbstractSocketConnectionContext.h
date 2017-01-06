//
// Created by WenJinXiong on 16-12-25.
//

#pragma once
#include <memory>

class ByteBuffer;
class SocketConnection;
class SocketConnectionHandlerChain;


class AbstractSocketConnectionContext {
public:
    AbstractSocketConnectionContext();
    virtual ~AbstractSocketConnectionContext();
    virtual int getConnFd() = 0;
    virtual std::shared_ptr<SocketConnection> getConnection()= 0;
    virtual void setConnection(std::shared_ptr<SocketConnection> conn) = 0;
    virtual std::shared_ptr<SocketConnectionHandlerChain> getHandlerChain() = 0;
    virtual void read() = 0;
    virtual std::shared_ptr<ByteBuffer> getByteBuffer() = 0;

};




