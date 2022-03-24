#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int A=5;

void *thread_add(void *arg)
{	sleep(2);
	A= A+10;

	printf("after incr=%d\n",A);
}

void *thread_div(void *arg)
{	
	sleep(2);
	A= A/5;
	printf("after decr=%d\n",A);
}

int main()
{
	pthread_t thread1, thread2;
	pthread_create(&thread1,NULL,thread_add,NULL);
//pthread_join(thread1,NULL);
	pthread_create(&thread2,NULL,thread_div,NULL);
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);

printf("sharedvar=%d\n",A);
return 0;
}
