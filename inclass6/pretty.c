#include <stdio.h>
#include <string.h> 

int main(int arg0, char** arg[]){
	char wa[10][15];
	char w[15];
	int na[15];
	int n;
	int i = 0 ;
	while(scanf("%s %d",w,&n) == 2){
		strcpy(wa[i],w);
		na[i] = n;
		i++; 
	}
	printf("==================================\n");
	int j = 0;
	while (j<i){
		strcpy(w,wa[j]);
		n = na[j];
		printf("%*s%03d\n",-16,w,n);
		j++;
	}
	printf("=================================\n");
	return 0;
}
