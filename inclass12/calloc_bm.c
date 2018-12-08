#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define LARGE 10000000UL
#define MEDIUM 100000UL

void mal() {
	int *arr = (int *)malloc(LARGE*sizeof(int));
	for(long i=0; i < LARGE; i++){
		arr[i] = 0;
	}
	free(arr);
}

void cal() {
	int *arr = (int *)calloc(LARGE,sizeof(int));
	free(arr);
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
  printf("mal() time: %lu usec\n",
	 benchmark(mal,10));
  printf("cal() time: %lu usec\n",
	 benchmark(cal,10));
  
}
