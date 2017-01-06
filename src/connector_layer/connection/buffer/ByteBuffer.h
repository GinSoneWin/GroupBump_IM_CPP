//
// Created by WenJinXiong on 16-12-25.
//

#pragma once


class ByteBuffer {
public:
    ByteBuffer();
    virtual  ~ByteBuffer();
    virtual int readableBytes() = 0;
    virtual int writableBytes() = 0;
    virtual bool isReadable() = 0;
    virtual bool isWritable() = 0;
    virtual void writeBytes(int fd) = 0;
    virtual int readBytes(int fd) = 0;


};




