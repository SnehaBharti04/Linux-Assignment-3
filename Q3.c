#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

void* Proc(void* param){
    sleep(2);
    return 0;
}

int main(){
    pthread_attr_t Attr;
    pthread_t Id;
    void *Stk;
    size_t Siz;
    int err;

    size_t my_stksize = 0x3000000;
    void * my_stack;

    pthread_attr_init(&Attr); 

    pthread_attr_getstacksize(&Attr, &Siz);
    pthread_attr_getstackaddr(&Attr, &Stk); 

    printf("default: addr=%08x    default size=%ld\n", Stk, Siz); 
                                                                 
  my_stack = (void*)malloc(my_stksize); 
    pthread_attr_setstack(&Attr, my_stack, my_stksize);

    pthread_create(&Id, &Attr, Proc, NULL);

    pthread_attr_getstacksize(&Attr, &Siz); 
    pthread_attr_getstackaddr(&Attr, &Stk); 
    printf("modified: addr=%08x    modified size=%ld\n", Stk, Siz); 


    pthread_join(Id, NULL);
    return 0;
}
