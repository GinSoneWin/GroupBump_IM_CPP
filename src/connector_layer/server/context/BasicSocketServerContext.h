

//
// Created by WenJinXiong on 16-12-25.
//

#pragma once


#include "AbstractSocketServerContext.h"
#include <memory>
#include <vector>
#include <map>
#include <semaphore.h>
class AbstractThread;
class SocketConnectionInitializer;
class SocketConnection;
class AbstractSocketConnectionMap;

class BasicSocketServerContext :public AbstractSocketServerContext{
public:
    BasicSocketServerContext();
    virtual ~BasicSocketServerContext();
    void init()override;
    AbstractSocketServerContext& setConnectionInitializer(std::shared_ptr<SocketConnectionInitializer> conninit)override;
    AbstractSocketServerContext &setWorkerThreadCnt(int cnt) override;
    std::shared_ptr<AbstractEventQueue> getEventQueue()override ;
    std::shared_ptr<SocketConnection> getConnection(int sockfd)override ;
    void sync()override ;
    std::shared_ptr<AbstractDispatcher> getDispatcher()override;
    AbstractSocketServerContext& bind(int port)override ;
    int getPort()const override ;
    bool isBind() const override ;
    std::shared_ptr<sockaddr_in> getServaddr()override ;
    void addConnection(int connfd,std::shared_ptr<SocketConnection> conn) override;

    void shutdown() override;


private:
    static int port;
    static bool hasbind;
    static std::shared_ptr<sockaddr_in> servaddr;

    std::shared_ptr<SocketConnectionInitializer> conninitializer_ptr = nullptr;
    std::shared_ptr<AbstractEventQueue> event_queue_ptr = nullptr;
    std::shared_ptr<AbstractThread> bossThread = nullptr;
    std::vector<std::shared_ptr<AbstractThread>> workerThreads;
    int workerThreadCnt = 5;
    std::shared_ptr<AbstractDispatcher> dispatcher;
    std::shared_ptr<AbstractSocketConnectionMap> connmap;

};





