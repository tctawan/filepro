#include <stdio.h>
#include <ctype.h>

int * count(char line[]){
	static int c =0;
	static int w =0;
	static int l = 0;
	for(int i=0 ; line[i] != '\0'; i++){
		if(isspace(line[i])){
			if(line[i] == '\n'){
				l++;
			}
			w++;
		}
		c++;
	}
	static int a[3];
	a[0] = c;
       	a[1] = w;
	a[2] = l;
	return a;
}

int main(int argc, char **argv){
	FILE *fin;
	int c=0;
	int w=0;
	int l=0;
	int *a;
	char line[1000];

	if(argc == 1){
		fin= stdin;
	}else{
		fin=fopen(argv[1], "r");

	}
	while(fgets(line, sizeof(line), fin) != NULL){
		a =count(line);
	}
	c = a[0]; 	
	w = a[1];
	l = a[2];
	fprintf(stderr,"%d %d %d\n",l,w,c);
}
