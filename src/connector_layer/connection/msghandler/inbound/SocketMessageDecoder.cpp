//
// Created by WenJinXiong on 16-12-25.
//

#include "SocketMessageDecoder.h"
SocketMessageDecoder::SocketMessageDecoder() : SocketConnectionInboundHandler(){

}
SocketMessageDecoder::~SocketMessageDecoder() {

}
void SocketMessageDecoder::pipelineRead(std::shared_ptr<SocketConnectionHandlerContext<SocketConnectionInboundHandler>> context, std::shared_ptr<Message> msg) {

}
