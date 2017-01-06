//
// Created by WenJinXiong on 16-12-25.
//

#include "unix_develop.h"

int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
    int		n;
    again:
    if ( (n = accept(fd, sa, salenptr)) < 0) {
        if (errno == EPROTO || errno == ECONNABORTED) {
            goto again;
        }else {
            perror("accept error");
            exit(1);
        }
    }
    return(n);
}
void Bind(int fd, const struct sockaddr *sa, socklen_t salenptr){
    if (bind(fd, sa, salenptr) < 0){
        perror("Bind error");
        exit(1);
    }
}
void Connect(int fd, const struct sockaddr *sa, socklen_t salen){
    if (connect(fd, sa, salen) < 0){
        perror("Connect error");
        exit(1);
    }
}
void Getsockopt(int fd, int level, int optname, void *optval, socklen_t *optlenptr){
    if (getsockopt(fd, level, optname, optval, optlenptr) < 0){
        perror("Getsockopt error");
        exit(1);
    }
}
void Listen(int fd, int backlog){
    char	*ptr;

    /*4can override 2nd argument with environment variable */
    if ( (ptr = getenv("LISTENQ")) != NULL)
        backlog = atoi(ptr);

    if (listen(fd, backlog) < 0){
        perror("Listen error");
        exit(1);
    }
}
void Shutdown(int fd, int how){
    if (shutdown(fd, how) < 0){
        perror("Shutdown error");
        exit(1);
    }
}
int Socket(int family, int type, int protocol){
    int		n;

    if ( (n = socket(family, type, protocol)) < 0){
        perror("Socket error");
        exit(1);
    }
    return(n);
}