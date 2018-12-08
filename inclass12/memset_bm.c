#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define LARGE 10000000UL
#define MEDIUM 100000UL

void simple_reset() {
	int *arr = (int *)malloc(LARGE*sizeof(int));
	for(long i = 0; i<LARGE; i++){
		arr[i] = 0;
	}
	free(arr);
	arr = NULL;
}

void mem_set() {
	int *arr = (int *)malloc(LARGE*sizeof(int));
	memset(arr,0,LARGE*sizeof(int));
	free(arr);
	arr = NULL;
}


unsigned long benchmark(void (*f)(), int iter) {
  struct timeval begin, end;

  gettimeofday(&begin, NULL);

  for (int i=0;i<iter;i++) (*f)();

  gettimeofday(&end, NULL);

  return (1000000UL*(end.tv_sec - begin.tv_sec) +
	  (end.tv_usec - begin.tv_usec))/iter;
}

int main() {
  printf("simple_reset() time: %lu usec\n",
	 benchmark(simple_reset,10));
  printf("mem_set() time: %lu usec\n",
	 benchmark(mem_set,10));
  
}
