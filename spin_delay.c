#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>

void delay(int spin){

  struct timeval start, end;
  time_t start_time, cur_time;

  gettimeofday(&start, NULL);
  
  time(&start_time);
  do
  {
	time(&cur_time);
  }
  while((cur_time - start_time) < spin);

  gettimeofday(&end, NULL);

  printf("%ld\n", ((end.tv_sec * 1000000 + end.tv_usec)
		  - (start.tv_sec * 1000000 + start.tv_usec)));
}
