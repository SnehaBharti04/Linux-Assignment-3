#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
pthread_t tid;

void * t1(void *arg){
    printf("newly created thread is executing\n");
    int s;
    s = pthread_cancel(tid);
    pthread_t ttid = pthread_self();
    if(s==0){ 
        printf("cancel thread %u\n", ttid);
    }
    return NULL;
}

int main(){
    int ret = pthread_create(&tid, NULL, t1, NULL);
    int rc, t;


    if(ret){
        printf("thread is not created\n");
    } else{
        printf("thread is created, thread ID = %u\n", tid);
        pthread_join(tid, NULL); 
    }
    return 0;
}
