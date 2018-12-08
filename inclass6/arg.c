#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	int i = argc-1;
	int sum = 0;
	int n = 0;
	while(i >0){
		n = atoi(argv[i]);
		sum += n;
		i--;
	}
	printf("%d\n",sum);
}
