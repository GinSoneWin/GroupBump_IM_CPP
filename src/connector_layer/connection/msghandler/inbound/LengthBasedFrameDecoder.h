//
// Created by WenJinXiong on 16-12-25.
//

#pragma once

#include "SocketConnectionInboundHandler.h"
#include <memory>
class ByteBuffer;



class LengthBasedFrameDecoder : public SocketConnectionInboundHandler{
public:

    LengthBasedFrameDecoder(int maxFrameLength, int lengthFiledOffset, int lengthFieldLength);
    ~LengthBasedFrameDecoder();



    void pipelineRead(std::shared_ptr<SocketConnectionHandlerContext<SocketConnectionInboundHandler>> context, std::shared_ptr<Message> msg) override;
    virtual std::shared_ptr<Message> decode(std::shared_ptr<SocketConnectionHandlerContext<SocketConnectionInboundHandler>> context, std::shared_ptr<ByteBuffer> in);

private:
    int maxFrameLength = 1024000;
    int lengthFieldOffset = sizeof(int32_t);
    int lengthFieldLength = sizeof(int32_t);

};




