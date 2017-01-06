//
// Created by WenJinXiong on 16-12-25.
//

#pragma once
#include <memory>
#include "../../../../global/global.h"


class SocketConnectionHandlerChain;
class AbstractSocketConnectionContext;
class Message;




template<typename SocketConnectionHandlerType>
class SocketConnectionHandlerContext {
public:
    SocketConnectionHandlerContext();
    virtual ~SocketConnectionHandlerContext();
    virtual void passNextHandler(std::shared_ptr<Message>);
    std::shared_ptr<SocketConnectionHandlerType> getCurHandler();
    std::shared_ptr<SocketConnectionHandlerType> getNextHandler();
    std::shared_ptr<SocketConnectionHandlerChain> getHandlerChain();
    std::shared_ptr<AbstractSocketConnectionContext> getConnectionContext();
    void setCurrHandler(std::shared_ptr<SocketConnectionHandlerType> handler);
    void setNextHandler(std::shared_ptr<SocketConnectionHandlerType> handler);
    void setHandlerChain(std::shared_ptr<SocketConnectionHandlerChain> handlerChain);
    void setConnectionContext(std::shared_ptr<AbstractSocketConnectionContext> connContext);
private:
    std::weak_ptr<SocketConnectionHandlerType> currHandler;
    std::weak_ptr<SocketConnectionHandlerType> nextHandler;
    std::weak_ptr<SocketConnectionHandlerChain> handlerChain;
    std::weak_ptr<AbstractSocketConnectionContext> connectionContext;
};





//member definition
template<typename SocketConnectionHandlerType>
SocketConnectionHandlerContext<SocketConnectionHandlerType>::SocketConnectionHandlerContext(): currHandler(),nextHandler(),
                                                                                               handlerChain(),connectionContext()
{
    GLOBAL_CONSOLE_LOGGER->debug("SocketConnectionHandlerContext()");
}
template<typename SocketConnectionHandlerType>
SocketConnectionHandlerContext<SocketConnectionHandlerType>::~SocketConnectionHandlerContext() {
    GLOBAL_CONSOLE_LOGGER->debug("~SocketConnectionHandlerContext()");
}
template<typename SocketConnectionHandlerType>
std::shared_ptr<SocketConnectionHandlerType> SocketConnectionHandlerContext<SocketConnectionHandlerType>::getCurHandler()
{
    if(currHandler.expired())
        throw std::runtime_error("SocketConnectionHandlerContext::getCurHandler() : nullpointer exception");
    else
        return currHandler.lock();
}
template<typename SocketConnectionHandlerType>
std::shared_ptr<SocketConnectionHandlerType> SocketConnectionHandlerContext<SocketConnectionHandlerType>::getNextHandler()
{
    return nextHandler.lock();
}
template<typename SocketConnectionHandlerType>
std::shared_ptr<SocketConnectionHandlerChain> SocketConnectionHandlerContext<SocketConnectionHandlerType>::getHandlerChain()
{
    if(handlerChain.expired())
        throw std::runtime_error("SocketConnectionHandlerContext::getCurHandler() : nullpointer exception");
    else
        return handlerChain.lock();
}
template<typename SocketConnectionHandlerType>
std::shared_ptr<AbstractSocketConnectionContext> SocketConnectionHandlerContext<SocketConnectionHandlerType>::getConnectionContext()
{
    if(connectionContext.expired())
        throw std::runtime_error("SocketConnectionHandlerContext::getCurHandler() : nullpointer exception");
    else
        return connectionContext.lock();

}

template<typename SocketConnectionHandlerType>
void SocketConnectionHandlerContext<SocketConnectionHandlerType>::setCurrHandler(std::shared_ptr<SocketConnectionHandlerType> handler) {
    currHandler = handler;
}
template<typename SocketConnectionHandlerType>
void SocketConnectionHandlerContext<SocketConnectionHandlerType>::setNextHandler(std::shared_ptr<SocketConnectionHandlerType> handler) {
    nextHandler = handler;
}
template<typename SocketConnectionHandlerType>
void SocketConnectionHandlerContext<SocketConnectionHandlerType>::setHandlerChain(std::shared_ptr<SocketConnectionHandlerChain> chain) {
    handlerChain = chain;
}
template<typename SocketConnectionHandlerType>
void SocketConnectionHandlerContext<SocketConnectionHandlerType>::setConnectionContext(std::shared_ptr<AbstractSocketConnectionContext> connContext) {
    connectionContext = connContext;
}




