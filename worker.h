#include<pthread.h>
#define MAX 6
typedef struct {
pthread_t thread_id;	//Thread ID 
unsigned int  thread_count; // connections handled
}workers_t;
workers_t *thread_ptr;

unsigned int buffer[MAX];
unsigned int buf_fill = 0;
unsigned int use = 0;
unsigned int count =0;
pthread_mutex_t mutex;
pthread_cond_t fill,empty;

void put(int value);
int get();
