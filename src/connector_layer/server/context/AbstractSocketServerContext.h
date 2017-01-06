//
// Created by WenJinXiong on 16-12-25.
//

#pragma once
#include <memory>
#include <netinet/in.h>
#include <semaphore.h>
class SocketConnectionInitializer;
class AbstractEventQueue;
class AbstractDispatcher;
class SocketConnection;


class AbstractSocketServerContext {
public:
    AbstractSocketServerContext();
    virtual ~AbstractSocketServerContext();
    static void globalinit();
    virtual void init() = 0;
    virtual AbstractSocketServerContext& setConnectionInitializer(std::shared_ptr<SocketConnectionInitializer> conninit) = 0;
    virtual std::shared_ptr<AbstractEventQueue> getEventQueue() = 0;
    virtual std::shared_ptr<SocketConnection> getConnection(int sockfd) = 0;
    virtual AbstractSocketServerContext& setWorkerThreadCnt(int cnt) = 0;
    virtual void sync() = 0;
    virtual std::shared_ptr<AbstractDispatcher> getDispatcher() = 0;
    virtual AbstractSocketServerContext& bind(int port) = 0;
    virtual int getPort()const = 0;
    virtual bool isBind()const = 0;
    virtual std::shared_ptr<sockaddr_in> getServaddr() = 0;
    virtual void addConnection(int connfd,std::shared_ptr<SocketConnection> conn) = 0;
    virtual void shutdown() = 0;
    static std::shared_ptr<AbstractSocketServerContext> getInstance();
private:
    static std::shared_ptr<AbstractSocketServerContext> uniqueContext;
    static std::shared_ptr<sem_t> mutex;

};


