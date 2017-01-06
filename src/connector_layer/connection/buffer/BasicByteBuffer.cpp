//
// Created by WenJinXiong on 16-12-25.
//

#include "BasicByteBuffer.h"
#include "../../../global/global.h"
#include "../../../util/wrapper/unix_develop.h"


BasicByteBuffer::BasicByteBuffer(int capacity):ByteBuffer(),capacity(capacity),bytebufptr(new char[capacity](),[](char *ptr){delete[] ptr;}),
                                               toreadidx(0),towriteidx(0)
{
    GLOBAL_CONSOLE_LOGGER->debug("BasicByteBuffer()");
}
BasicByteBuffer::~BasicByteBuffer() {
    GLOBAL_CONSOLE_LOGGER->debug("~BasicByteBuffer()");
}
int BasicByteBuffer::readableBytes() {
    return towriteidx-toreadidx;
}
int BasicByteBuffer::writableBytes() {
    return capacity-towriteidx;
}
bool BasicByteBuffer::isReadable() {
    return (towriteidx-toreadidx)>0;
}
bool BasicByteBuffer::isWritable() {
    return (capacity-towriteidx)>0;
}
void BasicByteBuffer::writeBytes(int fd)
{

}

int BasicByteBuffer::readBytes(int fd) {
    return Read(fd,&(bytebufptr.get()[towriteidx]), writableBytes());
}
