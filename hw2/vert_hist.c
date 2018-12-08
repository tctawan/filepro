#include <stdio.h>

int main(){
	char word[100000];
	int c[26] = {0};
	int max = 0;
	while(scanf("%s",word) == 1){
		int i = 0;
		while(word[i] != '\0'){
			int ascii = (int) word[i];
			int pos = 0;
			if(ascii> 64 && ascii < 91 ){
				pos = ascii-65;
			}
			else if(ascii >96 && ascii< 123){
				pos =  ascii-97;
			}else{
				i++;
				continue;
			}
			c[pos] += 1;
			if(c[pos] > max){
				max = c[pos];
			}
			i++;
		}
	}

	for(int check = max ; check >0; check--){
		for(int i =0 ; i<26;i++){
			int count = c[i];
			if(count == check){
				printf("*");
				c[i] -= 1;
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("abcdefghijklmnopqrstuvwxyz\n");

	return 0;

}
