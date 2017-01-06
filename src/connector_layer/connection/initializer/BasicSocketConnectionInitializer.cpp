//
// Created by WenJinXiong on 16-12-25.
//

#include "BasicSocketConnectionInitializer.h"
#include "../general/SocketConnection.h"
#include "../context/AbstractSocketConnectionContext.h"
#include "../../../global/global.h"
#include "../msghandler/context/SocketConnectionHandlerChain.h"
#include "../msghandler/inbound/LengthBasedFrameDecoder.h"
#include "../msghandler/inbound/SocketMessageDecoder.h"

BasicSocketConnectionInitializer::BasicSocketConnectionInitializer() {

}
BasicSocketConnectionInitializer::~BasicSocketConnectionInitializer() {

}
void BasicSocketConnectionInitializer::initConnection(std::shared_ptr<SocketConnection> conn) {

    std::shared_ptr<SocketConnectionHandlerChain> chain = conn->getConnectionContext()->getHandlerChain();


    //setup inbound msghandler
    chain->addInbound(std::make_shared<LengthBasedFrameDecoder>(1024*1024,sizeof(int32_t),sizeof(int32_t)),conn);
    chain->addInbound(std::make_shared<SocketMessageDecoder>(),conn);

    //setup outbound msghandler

    GLOBAL_CONSOLE_LOGGER->debug("new connection initialize complete");
}
