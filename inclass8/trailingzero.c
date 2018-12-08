#include <stdio.h>

int main(){
	int n;
	printf("Input : ");
	scanf("%d",&n);
	int num = 1;
	for(int i=1;i<=n;i++){
		num *= i;
	}
	int count = 0;
	while (num%10 == 0){
		num /= 10;
		count++;
	}
	printf("Output : %d\n",count);
	return 0;
}
