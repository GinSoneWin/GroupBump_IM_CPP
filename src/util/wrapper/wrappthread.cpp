//
// Created by WenJinXiong on 16-12-25.
//

#include "unix_develop.h"

void
Pthread_create(pthread_t *tid, const pthread_attr_t *attr, void *(*func)(void*),void *arg)
{
    int n;
    if( (n = pthread_create(tid,attr,func,arg)) == 0)
        return ;
    errno = n;
    perror("pthread_create error : ");
    exit(1);
}
void
Pthread_join(pthread_t tid, void **status)
{
    int n;
    if( (n = pthread_join(tid,status)) == 0)
        return;
    errno = n;
    perror("pthread_join error : ");
    exit(1);
}
void Pthread_mutex_lock(pthread_mutex_t *mptr)
{
    int n;
    if( (n = pthread_mutex_lock(mptr)) == 0)
        return;
    errno = n;
    perror("pthread_mutex_lock error : ");
    exit(1);
}
void Pthread_mutex_unlock(pthread_mutex_t *mptr)
{
    int n;
    if( (n = pthread_mutex_unlock(mptr)) == 0)
        return;
    errno = n;
    perror("pthread_mutex_unlock error : ");
    exit(1);
}
void Pthread_cond_signal(pthread_cond_t *cptr)
{
    int n;
    if( (n = pthread_cond_signal(cptr)) == 0)
        return;
    errno = n;
    perror("pthread_cond_signal error : ");
    exit(1);
}
void Pthread_cond_wait(pthread_cond_t *cptr, pthread_mutex_t *mptr)
{
    int n;
    if( (n = pthread_cond_wait(cptr,mptr)) == 0)
        return;
    errno = n;
    perror("pthread_cond_wait error : ");
    exit(1);
}
