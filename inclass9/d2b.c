#include <stdio.h>

int main(){
	int num=0;
	int ans[100];
	scanf("%d",&num);
	int i = 0;
	while(num>0){
		ans[i] = num%2;
		num /= 2;
		i++;
	}
	for(int j=i-1;j>= 0;j--){
		printf("%d",ans[j]);
	}
	printf("\n");
	return 0;
}
