#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define LARGE 10000000UL
#define MEDIUM 100000UL

void mall() {
	int *arr = (int *)malloc(MEDIUM*sizeof(int));
	int *new = (int *)malloc(LARGE*sizeof(int));

	/*
	for(long i =0; i<MEDIUM ; i++){
		new[i] = arr[i];
	}
	*/
	memcpy(new,arr,MEDIUM*sizeof(int));
	free(arr);
	free(new);
}


void reall() {
	int *ar = (int *)malloc(MEDIUM*sizeof(int));
	int *ne = (int *)realloc(ar,LARGE*sizeof(int));
	free(ne);
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
  printf("mall() : %lu usec\n",
	 benchmark(mall,10));
  printf("reall() : %lu usec\n",
	 benchmark(reall,10));
  
}
