//
// Created by WenJinXiong on 16-12-25.
//

#include "LengthBasedFrameDecoder.h"
#include "../../../../global/global.h"
#include "../../buffer/ByteBuffer.h"
#include "../../event/general/AbstractEvent.h"
#include "../../event/general/Event.h"
#include "../context/SocketConnectionHandlerContext.h"
#include "../../../server/context/AbstractSocketServerContext.h"
#include "../../event/dispatcher/AbstractEventQueue.h"
#include "../../event/evhandler/ConnDisconnectEventHandler.h"
#include "../../context/AbstractSocketConnectionContext.h"

extern template class  SocketConnectionHandlerContext<SocketConnectionInboundHandler>;
LengthBasedFrameDecoder::LengthBasedFrameDecoder(int maxFrameLen, int lenFieldOffset, int lenFieldSize):SocketConnectionInboundHandler(),maxFrameLength(maxFrameLen),
                                                                                                        lengthFieldOffset(lenFieldOffset),lengthFieldLength(lenFieldSize)
{

}
LengthBasedFrameDecoder::~LengthBasedFrameDecoder() {

}



void LengthBasedFrameDecoder::pipelineRead(std::shared_ptr<SocketConnectionHandlerContext<SocketConnectionInboundHandler>> context, std::shared_ptr<Message> msg) {
    GLOBAL_CONSOLE_LOGGER->debug("lengthbasedframedecoder processing");
    std::shared_ptr<Message> message = decode(context,context->getConnectionContext()->getByteBuffer());
    if(message == nullptr){
        GLOBAL_CONSOLE_LOGGER->debug("not enougth bytes to create a frame message");
        return;
    }

}

std::shared_ptr<Message> LengthBasedFrameDecoder::decode(std::shared_ptr<SocketConnectionHandlerContext<SocketConnectionInboundHandler>> context, std::shared_ptr<ByteBuffer> in) {
    int n;
    if(in->isWritable()){
        if( (n = in->readBytes(context->getConnectionContext()->getConnFd())) == 0 ){
            std::shared_ptr<AbstractEvent> ev(new Event(EventType::CONN_DISCONNECT(),context->getConnectionContext()->getConnFd(),std::make_shared<ConnDisconnectEventHandler>(),context->getConnectionContext()));
            AbstractSocketServerContext::getInstance()->getEventQueue()->prodEvent(ev);
            return nullptr;
        }
    }
    return nullptr;
}