//
// Created by WenJinXiong on 16-12-25.
//

#pragma once
#include "ByteBuffer.h"
#include <memory>

class BasicByteBuffer : public ByteBuffer{
public:
    BasicByteBuffer(int capacity = DEFAULT_MAX_FRAME_LENGTH);
    ~BasicByteBuffer();
    int readableBytes() override;
    int writableBytes() override;
    bool isReadable()override;
    bool isWritable()override ;
    void writeBytes(int fd) override;
    int readBytes(int fd) override;

private:
    static constexpr int DEFAULT_MAX_FRAME_LENGTH = 1024000;
    int capacity = 0;
    std::shared_ptr<char> bytebufptr = nullptr;
    int toreadidx = 0;
    int towriteidx = 0;
};




