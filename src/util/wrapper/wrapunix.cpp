//
// Created by WenJinXiong on 16-12-25.
//



#include "unix_develop.h"


ssize_t Read(int fd, void *ptr, size_t nbytes){
    ssize_t n;
    if( (n = read(fd,ptr,nbytes)) == -1){
        perror("read error :");
        exit(1);
    }
    return n;
}
void Write(int fd, const void *ptr, size_t nbytes){
    ssize_t n;
    if( (n = write(fd,ptr,nbytes)) < 0 || (size_t)n != nbytes){
        perror("write error : ");
        exit(1);
    }
}
int Open(const char *pathname,int oflag, ...)
{
    int fd;
    va_list ap;
    mode_t mode;
    if(oflag & O_CREAT){
        va_start(ap,oflag);
        mode = va_arg(ap,mode_t);
        if( (fd = open(pathname,oflag,mode)) ==-1){
            perror("open error : ");
            exit(1);
        }
        va_end(ap);
    }else{
        if( (fd = open(pathname,oflag)) == -1){
            perror("open error : ");
            exit(1);
        }
    }
    return fd;
}
off_t Lseek(int fd, off_t offset, int whence)
{
    off_t pos;
    if( (pos = lseek(fd,offset,whence)) == (off_t)-1){
        perror("lseek error : ");
        exit(1);
    }
    return pos;
}
void Ftruncate(int fd, off_t length)
{
    if(ftruncate(fd,length) == -1){
        perror("ftruncate error : ");
        exit(1);
    }
}
void Fstat(int fd, struct stat *ptr)
{
    if( fstat(fd,ptr) == -1){
        perror("fstat error : ");
        exit(1);
    }
}
void Close(int fd)
{
    if(close(fd) == -1){
        perror("close error : ");
        exit(1);
    }
}
pid_t Fork(void){
    pid_t pid;
    if( (pid = fork()) == -1){
        perror("fork error : ");
        exit(1);
    }
    return pid;
}
int Select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds,struct timeval *timeout){
    int n;
    again:
    if( (n = select(nfds,readfds,writefds,exceptfds,timeout)) < 0)		    {
        if(errno == EINTR)
            goto again;
        perror("select error : ");
        exit(1);
    }else if(n == 0 && timeout == nullptr){
        printf("select returned 0 with no timeout\n");
        exit(1);
    }
    return n;
}
int Getopt(int argc,char *const*argv,const char *str)
{
    int opt;
    if( (opt = getopt(argc,argv,str)) == '?')
        exit(1);
    return opt;
}
mqd_t
Mq_open(const char *pathname, int oflag, ...)
{
    mqd_t	mqd;
    va_list	ap;
    mode_t	mode;
    struct mq_attr	*attr;

    if (oflag & O_CREAT) {
        va_start(ap, oflag);		/* init ap to final named argument */
        mode = va_arg(ap, mode_t);
        attr = va_arg(ap, struct mq_attr *);
        if ( (mqd = mq_open(pathname, oflag, mode, attr)) == (mqd_t) -1)		{
            perror("mq_open error : ");
            exit(1);
        }
        va_end(ap);
    } else {
        if ( (mqd = mq_open(pathname, oflag)) == (mqd_t) -1)
        {
            perror("mq_open error : ");
            exit(1);
        }
    }
    return(mqd);
}

void
Mq_close(mqd_t mqd)
{
    if (mq_close(mqd) == -1){
        perror("mq_close error");
        exit(1);
    }
}
void
Mq_unlink(const char *pathname)
{
    if (mq_unlink(pathname) == -1){
        perror("mq_unlink error : ");
        exit(1);
    }
}
void
Mq_getattr(mqd_t mqd, struct mq_attr *mqstat)
{
    if(mq_getattr(mqd,mqstat) == -1){
        perror("mq_getattr error : ");
        exit(1);
    }
}
void
Mq_setattr(mqd_t mqd, const struct mq_attr *mqstat, struct mq_attr *omqstat)
{
    if(mq_setattr(mqd,mqstat,omqstat) == -1){
        perror("mq_setattr erro : ");
        exit(1);
    }
}
void
Mq_send(mqd_t mqd, const char *ptr, size_t len, unsigned int prio)
{
    if(mq_send(mqd,ptr,len,prio) == -1){
        perror("mq_send : ");
        exit(1);
    }
}
ssize_t
Mq_receive(mqd_t mqd, char *ptr, size_t len, unsigned int *prio)
{
    ssize_t n;
    if( (n = mq_receive(mqd, ptr, len , prio)) == -1){
        perror("mq_receive error : ");
        exit(1);
    }
    return n;
}
void
Mq_notify(mqd_t mqd, const struct sigevent *notification)
{
    if(mq_notify(mqd,notification) == -1){
        perror("mq_notify : ");
        exit(1);
    }
}
void *
Malloc(size_t size)
{
    void *ptr;
    if( (ptr = malloc(size)) == nullptr){
        perror("malloc error : ");
        exit(1);
    }
    return ptr;
}
void*
Calloc(size_t n, size_t size)
{
    void *ptr;
    if( (ptr = calloc(n,size)) == nullptr){
        perror("calloc error : ");
        exit(1);
    }
    return ptr;
}
long
Sysconf(int name)
{
    long val;
    errno = 0;
    if( (val = sysconf(name)) == -1){
        if(errno != 0){
            perror("sysconf : ");
            exit(1);
        }else{
            printf("sysconf : %d not defined\n",name);
        }
    }
    return val;
}
void Sigaddset(sigset_t *set, int signo)
{
    if(sigaddset(set,signo) == -1){
        perror("sigaddset : ");
        exit(1);
    }
}
void Sigemptyset(sigset_t *set)
{
    if(sigemptyset(set) == -1){
        perror("sigemptyset : ");
        exit(1);
    }
}
void Sigprocmask(int how, const sigset_t *set, sigset_t *oset){
    if(sigprocmask(how,set,oset) == -1){
        perror("sigprocmask error : ");
        exit(1);
    }
}
void
Sigwait(const sigset_t *set, int *signo)
{
    int n;
    if( (n = sigwait(set,signo)) == 0)
        return;
    errno = n;
    perror("sigwait error : ");
    exit(1);
}
void Sigqueue(pid_t pid, int signo, const union sigval val){
    if(sigqueue(pid,signo,val) == -1){
        perror("sigqueue error : ");
        exit(1);
    }
}
void Pipe(int *fds)
{
    if(pipe(fds) < 0){
        perror("pipe error : ");
        exit(1);
    }
}
sem_t*
Sem_open(const char *pathname, int oflag, ...)
{
    sem_t *sem;
    va_list ap;
    mode_t mode;
    unsigned int value;
    if(oflag & O_CREAT){
        va_start(ap,oflag);
        mode = va_arg(ap,mode_t);
        value = va_arg(ap, unsigned int);
        if( (sem = sem_open(pathname,oflag,mode,value)) == SEM_FAILED){
            perror("sem_open error : ");
            exit(1);
        }
        va_end(ap);
    }else {
        if( (sem = sem_open(pathname,oflag))  == SEM_FAILED){
            perror("sem_open error :");
            exit(1);
        }
    }
    return sem;
}
void Sem_close(sem_t *sem)
{
    if(sem_close(sem) == -1){
        perror("sem_close error : ");
        exit(1);
    }
}
void Sem_unlink(const char *pathname){
    if(sem_unlink(pathname) == -1){
        perror("sem_unlink error");
        exit(1);
    }
}

void
Sem_wait(sem_t *sem)
{
    if(sem_wait(sem) == -1){
        perror("sem_wait error : ");
        exit(1);
    }
}
int
Sem_trywait(sem_t *sem)
{
    int rc;
    if( (rc = sem_trywait(sem)) ==-1 && errno != EAGAIN){
        perror("sem_trywait error : ");
        exit(1);
    }
    return rc;
}
void
Sem_post(sem_t *sem)
{
    if(sem_post(sem) == -1){
        perror("sem_post : ");
        exit(1);
    }
}
void
Sem_getvalue(sem_t *sem, int *valp)
{
    if(sem_getvalue(sem, valp) == -1){
        perror("sem_getvalue error : ");
        exit(1);
    }
}
void
Sem_init(sem_t *sem, int pshared, unsigned int value)
{
    if(sem_init(sem,pshared,value) == -1){
        perror("sem_init error : ");
        exit(1);
    }
}
void
Sem_destroy(sem_t *sem)
{
    if(sem_destroy(sem) == -1){
        perror("sem_destroy error :");
        exit(1);
    }
}
void Sem_deleter(sem_t *ptr)
{
    Sem_destroy(ptr);
    delete ptr;
}
void*
Mmap(void *addr,size_t len, int prot, int flags, int fd, off_t offset)
{
    void *ptr;
    if( (ptr = mmap(addr,len,prot,flags,fd,offset)) == MAP_FAILED){
        perror("mmap error : ");
        exit(1);
    }
    return ptr;
}
int
Shm_open(const char *pathname, int oflag, mode_t mode)
{
    int fd;
    if( (fd = shm_open(pathname,oflag,mode)) ==-1){
        perror("shm_open error :");
        exit(1);
    }
    return fd;
}
void Shm_unlink(const char *pathname)
{
    if(shm_unlink(pathname) == -1){
        perror("shm_unlink error : ");
        exit(1);
    }
}
pid_t
Waitpid(pid_t pid, int *iptr, int options)
{
    pid_t retpid;
    if( (retpid = waitpid(pid, iptr, options)) == -1){
        perror("waitpid error : ");
        exit(1);
    }
    return retpid;
}
void SetNonblocking(int fd)
{
    int opts= fcntl(fd,F_GETFL);
    if(opts < 0){
        perror("set nonblocking error : ");
        exit(1);
    }
    opts |= O_NONBLOCK;
    if(fcntl(fd,F_SETFL,opts) < 0){
        perror("set nonblocking error : ");
        exit(1);
    }
    return;
}
const char* Inet_ntop(int af, const void *src, char *dst, socklen_t size)
{
    const char *rptr;
    if( (rptr = inet_ntop(af,src,dst,size)) == NULL){
        perror("inet_ntop error : ");
        exit(1);
    }
    return rptr;
}