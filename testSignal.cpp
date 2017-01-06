//
// Created by WenJinXiong on 16-12-28.
//

#include "src/util/wrapper/unix_develop.h"
bool stop = false;
void cleanup(int signo,siginfo_t *info,void *context)
{

    printf("terminate  signal caught \n");
    stop = true;

}
int main()
{
//    int listenfd = Socket(AF_INET,SOCK_STREAM,0);
//    struct sockaddr_in servaddr;
//    bzero(&servaddr,sizeof(servaddr));
//    servaddr.sin_family AF_INET;
//    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
//    servaddr.sin_port = htons(3333);
//    Listen(listenfd,100);
//    Bind(listenfd,(struct sockeaddr_in *)&servaddr,sizeof(servaddr));
        int fd = 10;
        Signal_rt(SIGINT,cleanup);
        while(!stop);
//    int epollfd = Epoll_create(256);
//    struct epoll_event evlist[20];
//    int nfd;
//    for(;;)
//    {
//        nfd = Epoll_wait(epollfd,evlist,20,-1);
//        for(int i = 0)
//    }


}