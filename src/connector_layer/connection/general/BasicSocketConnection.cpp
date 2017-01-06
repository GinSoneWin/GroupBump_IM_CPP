//
// Created by WenJinXiong on 16-12-25.
//

#include "BasicSocketConnection.h"
#include "../context/BasicSocketConnectionContext.h"
#include "../../../global/global.h"

BasicSocketConnection::BasicSocketConnection(int connfd,const std::string &ip_str):SocketConnection(),connectionContext(std::make_shared<BasicSocketConnectionContext>(connfd,ip_str))
{
    GLOBAL_CONSOLE_LOGGER->debug("BasicSocketConnection()");
}
BasicSocketConnection::~BasicSocketConnection() {
    GLOBAL_CONSOLE_LOGGER->debug("~BasicSocketConnection()");
}
std::shared_ptr<AbstractSocketConnectionContext> BasicSocketConnection::getConnectionContext()
{
    return connectionContext;
}