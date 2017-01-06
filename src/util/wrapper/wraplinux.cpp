//
// Created by WenJinXiong on 16-12-25.
//


#include "unix_develop.h"
int Epoll_create(int size)
{
    int n;
    if( (n = epoll_create(size)) < 0)
    {
        perror("epoll_create :");
        exit(1);
    }
    return n;
}

void Epoll_ctl(int epfd, int op, int fd, struct epoll_event *event)
{
    if(epoll_ctl(epfd,op,fd,event) < 0){
        perror("epoll_ctl error : ");
        exit(1);
    }
    return;
}

int Epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout)
{
    int nfd = 0;
    if( (nfd = epoll_wait(epfd,events,maxevents,timeout)) < 0 ){
        perror("epoll_wait error : ");
        exit(1);
    }
    return nfd;
}