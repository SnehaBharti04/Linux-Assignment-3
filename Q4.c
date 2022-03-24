#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>

pthread_t ttid;

void * thread1(void *arg){
    printf("newly created thread is executing\n");
    printf("thread is created, thread ID = %u\n", ttid);
    return NULL;
}

int main(){
    int ret = pthread_create(&ttid, NULL, thread1, NULL);
    int rc, t;

    pthread_t tid = pthread_self();
    printf("calling process process ID = %u\n", tid);

    if(ret){
        printf("thread is not created\n");
    } else{
        pthread_join(ttid, NULL);
    }
    return 0;
}
