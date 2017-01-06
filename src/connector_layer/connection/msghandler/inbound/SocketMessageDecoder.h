//
// Created by WenJinXiong on 16-12-25.
//

#pragma once

#include "SocketConnectionInboundHandler.h"

class SocketMessageDecoder :public SocketConnectionInboundHandler{
public:
    SocketMessageDecoder();
    ~SocketMessageDecoder();

    void pipelineRead(std::shared_ptr<SocketConnectionHandlerContext<SocketConnectionInboundHandler>> context, std::shared_ptr<Message> msg) override;
};




