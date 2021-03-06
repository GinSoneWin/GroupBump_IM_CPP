//
// Created by WenJinXiong on 16-12-28.
//

#include"unix_develop.h"
Sigfunc_rt*
signal_rt(int signo, Sigfunc_rt *func)
{
    struct sigaction act,oact;
    act.sa_sigaction = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO;
    if(signo == SIGALRM){
        act.sa_flags |= SA_INTERRUPT;
    }else{
        act.sa_flags |= SA_RESTART;
    }
    if(sigaction(signo,&act,&oact) < 0)
        return (Sigfunc_rt*)SIG_ERR;
    return oact.sa_sigaction;
}
Sigfunc_rt*
Signal_rt(int signo, Sigfunc_rt *func)
{
    Sigfunc_rt *sigfunc;
    if( (sigfunc = signal_rt(signo, func)) == (Sigfunc_rt*)SIG_ERR){
        perror("sigaction_rt error : ");
        exit(1);
    }
    return sigfunc;
}
