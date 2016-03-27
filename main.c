#include <stdio.h>
#include <stdlib.h> 
#include "threadpool.h"
#define QUEUE_SIZE 50
#define THREAD_NUM 4

void helloTaiwan(void *arg)
{
	char *name = (char *)arg;
	printf("Hello %s, hello Taiwan\n",name); 
}

int main(int argc, char **argv)
{
	if(argc < 2 || argc>2){
		printf("Wrong argument number for main\n");
		return 0;	
	}
	//create a thread pool
	threadpool_t *pool = (threadpool_t *)malloc(sizeof(threadpool_t));
	if(-1 == (threadpool_init(pool, THREAD_NUM, QUEUE_SIZE)))
		printf("thread init error\n");
	char name[10] = "Jack";
	for(int i=0;i<atoi(argv[1]);i++){
		int err = threadpool_addQueue(pool, helloTaiwan, (void *)name);
		switch(err){
			case -1:
				printf("queue fulled\n");
				break;
			case -2:
				printf("queue is unabled\n");
				break;
		}
	}
	threadpool_destroy(pool);
	threadpool_freeMem(pool);
	return 0;
}
