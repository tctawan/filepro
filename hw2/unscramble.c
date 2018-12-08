#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char table[500000][2][50];
int tablelen = 0;



int cmpfunc(const void * a,const void *b){
	return *(char *)a - *(char *)b;
}

void createDic(FILE *dic ){
	int i =0;
	while(!feof(dic)){
		char word[50];
		fscanf(dic, "%s",word );
		strcpy(table[i][0],word);
		qsort(word,strlen(word),sizeof(char), cmpfunc);
		strcpy(table[i][1], word);
		i++;
		tablelen++;
	}
}

void findWord(FILE *jum){
	char found[100000][50];
	int j = 0;
	char word[50];
	while(!feof(jum)){
		fscanf(jum,"%s",word);
		printf("%s:",word);
		qsort(word,strlen(word),sizeof(char),cmpfunc);
		for (int i = 0; i<tablelen ;i++){
			if(strcmp(table[i][1],word) == 0){
				strcpy(found[j],table[i][0]);
				j++;	
			}
		}
		if(j == 0){
			printf(" NO MATCHES\n");
			continue;
		}
		while(j>0){
			printf(" %s",found[j-1]);
			j--;
		}
		printf("\n");
	}

}

int main(int argc ,char **argv){
	FILE *dic = fopen(argv[1],"r"); 
	FILE *jum = fopen(argv[2], "r");
	
	createDic(dic);
	findWord(jum);
	return 0;

}
