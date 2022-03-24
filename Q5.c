#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
int shaerdVar = 5;

pthread_mutex_t my_mutex; 

void * thread1_inc(void *arg){
    pthread_mutex_lock(&my_mutex);
    shaerdVar++; 
    pthread_mutex_unlock(&my_mutex); 
    printf("after increment=%d\n", shaerdVar);
}

void * thread2_dec(void *arg){
    pthread_mutex_lock(&my_mutex); 
    shaerdVar--;
    pthread_mutex_unlock(&my_mutex); 
    printf("after decrement=%d\n", shaerdVar);
}

int main(){
    pthread_t ttid, ttid1;

    pthread_mutex_init(&my_mutex, NULL); 

    pthread_create(&ttid, NULL, thread1_inc, NULL);
    pthread_create(&ttid1, NULL, thread2_dec, NULL);

    pthread_join(ttid, NULL);
    pthread_join(ttid1, NULL); 
    
    printf("shared variable: %d\n", shaerdVar);
    return 0;
}
