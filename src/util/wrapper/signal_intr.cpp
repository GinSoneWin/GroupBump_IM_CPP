//
// Created by WenJinXiong on 16-12-28.
//
#include"unix_develop.h"
Sigfunc*
signal_intr(int signo, Sigfunc *func)
{
    struct sigaction act,oact;
    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    act.sa_flags |= SA_INTERRUPT;
    if(sigaction(signo,&act,&oact) < 0)
        return SIG_ERR;
    return oact.sa_handler;
}
Sigfunc*
Signal_intr(int signo,Sigfunc *func)
{
    Sigfunc *sigfunc;
    if( (sigfunc = signal_intr(signo,func)) == SIG_ERR){
        perror("sigaction_intr error : ");
        exit(1);
    }
    return sigfunc;
}
