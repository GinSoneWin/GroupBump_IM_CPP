//
// Created by WenJinXiong on 16-12-25.
//


#pragma once
#include<cstring>
#include<sys/mman.h>
#include<algorithm>
#include<signal.h>
#include<pthread.h>
#include<cstdlib>
#include<strings.h>
#include<cstdarg>
#include<unistd.h>
#include<fcntl.h>
#include<mqueue.h>
#include<sys/wait.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<cstdio>
#include<semaphore.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <arpa/inet.h>
//wrapunix.cpp
ssize_t Read(int fd, void *ptr, size_t nbytes);
void Write(int fd,const void *ptr, size_t nbytes);
void Close(int fd);
int Open(const char *pathname, int oflag, ...);
off_t Lseek(int fd, off_t offset, int whence);
void Ftruncate(int fd, off_t length);
void Fstat(int fd, struct stat *ptr);
pid_t Fork(void);
int Select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds,
           struct timeval *timeout);
int Getopt(int argc, char *const *argv, const char *str);
pid_t Waitpid(pid_t pid, int *iptr, int options);
void Pipe(int *fds);
mqd_t Mq_open(const char *pathname, int oflag, ...);
void Mq_close(mqd_t mqd);
void Mq_unlink(const char *pathname);
void Mq_getattr(mqd_t mqd, struct mq_attr *mqstat);
void Mq_setattr(mqd_t mqd,const struct mq_attr *mqstat,struct mq_attr *omqstat);
void Mq_send(mqd_t mqd, const char *ptr, size_t len, unsigned int prio);
ssize_t Mq_receive(mqd_t mqd,char *ptr,size_t len,unsigned int *prio);
void Mq_notify(mqd_t mqd,const struct sigevent *notification);
void* Calloc(size_t n, size_t size);
void* Malloc(size_t size);
long Sysconf(int name);
void Sigaddset(sigset_t *set, int signo);
void Sigemptyset(sigset_t *set);
void Sigprocmask(int how, const sigset_t *set, sigset_t *oset);
void Sigwait(const sigset_t *set, int *signo);
void Sigqueue(pid_t pid, int signo, const union sigval val);
sem_t* Sem_open(const char *pathname, int oflag, ...);
void Sem_close(sem_t *sem);
void Sem_unlink(const char *pathname);
void Sem_getvalue(sem_t *sem, int *valp);
void Sem_post(sem_t *sem);
void Sem_wait(sem_t *sem);
int Sem_trywait(sem_t *sem);
void Sem_init(sem_t *sem, int pshared, unsigned int value);
void Sem_destroy(sem_t *sem);
void Sem_deleter(sem_t *ptr);
void* Mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);
int Shm_open(const char *pathname,int oflag,mode_t mode);
void Shm_unlink(const char *pathname);
void SetNonblocking(int fd);
const char* Inet_ntop(int af,const void *src, char *dst, socklen_t size);
//Signal.cpp
typedef void Sigfunc(int);
typedef void Sigfunc_rt(int,siginfo_t *, void*);
Sigfunc* Signal(int signo, Sigfunc *func);
Sigfunc* Signal_intr(int signo, Sigfunc *func);
Sigfunc_rt* Signal_rt(int, Sigfunc_rt *);
Sigfunc_rt* Signal_rt_intr(int, Sigfunc_rt *);

//wrappthread.cpp
void Pthread_create(pthread_t *, const pthread_attr_t *, void *(*func)(void*),void*);
void Pthread_join(pthread_t tid, void **status);
void Pthread_mutex_lock(pthread_mutex_t *mptr);
void Pthread_mutex_unlock(pthread_mutex_t *mptr);
void Pthread_cond_wait(pthread_cond_t *cptr, pthread_mutex_t *mptr);
void Pthread_cond_signal(pthread_cond_t *cptr);

//px_ipc_name.cpp
char* Px_ipc_name(const char *name);

//sleep_us.cpp
void Sleep_us(unsigned int nusecs);



//wrapsock.cpp
int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr);
void Bind(int fd, const struct sockaddr *sa, socklen_t salenptr);
void Connect(int fd, const struct sockaddr *sa, socklen_t salen);
void Getsockopt(int fd, int level, int optname, void *optval, socklen_t *optlenptr);
void Listen(int fd, int backlog);
void Shutdown(int fd, int how);
int Socket(int family, int type, int protocol);

//wraplinux.cpp
int Epoll_create(int size);
void Epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
int Epoll_wait(int epfd, struct epoll_event *events,int maxevents, int timeout);