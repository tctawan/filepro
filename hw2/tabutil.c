#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){

	int num = atoi(argv[2]);
	if (strcmp("-d", argv[1]) == 0 ){
		char s;	
		int spaces = 0;
		while( EOF != (s = getc(stdin)) ){
			if (s == '\t'){
				spaces += num;
			}
		}
		//printf("%d",spaces);
		printf("The number of spaces is %d: start|", spaces);
		for(int i=0; i < spaces;i++){
			printf(" ");
		}
		printf("|end\n");
	}else if( strcmp("-e", argv[1]) == 0){
		char s;
		int count = 0;
		int tabs = 0;
		while((s = getc(stdin)) != EOF){	
			if(s == ' '){
				count++ ;
			}
			if( count == num){
				count = 0 ;
				tabs++;
                        }

		}
		printf("The number of tabs is %d: start|" , tabs);
		for (int i =0; i < tabs;i++){

			printf("\t");
		}
		printf("|ends\n");
	}
	return 0;
}
