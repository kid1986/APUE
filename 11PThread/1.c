#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_t ntid;

void err_exit(int err,char * errmsg)
{
    fprintf(stderr,"%s\n",errmsg);
    exit(err);
}

void
printids(const char * s)
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();
    printf("%s pid %lu tid %lu (0x%lx) \n",s,(unsigned long) pid, (unsigned long) tid, (unsigned long) tid);
}

void *
thr_fn(void *arg)
{
    printids("new thread: ");
    return((void *) 0);
}

int main()
{
    int err;

    err = pthread_create(&ntid,NULL,thr_fn,NULL);
    if(err != 0)
        err_exit(err, "can't create thread");
    //{
    //    fprintf(stderr,"can't create thread");
    //    return(-1);
    //}
    printids("main thread:");
    printf("parent PID: %lu \n",(unsigned long)getppid());
    printf("parent TID: %lu \n",(unsigned long)ntid);
    sleep(1);

    return 0;
}
