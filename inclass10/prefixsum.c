#include <stdio.h>
#include <stdlib.h>


void prefix_sum(int *a, int *b , int *c){

	*b = *a + *b;
	*c = *b + *c;
}

int main(int argc , int **argv){
	int a  =0;
	int b = 0;
	int c = 0;
	scanf("%d %d %d",&a,&b,&c );
	prefix_sum(&a,&b,&c);
	printf("a :%d b :%d c :%d\n", a,b,c);
	return 0;
}
