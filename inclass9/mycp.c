#include <stdio.h>

int main(int argc, char **argv){
	
	FILE *fin = fopen(argv[1],"rb");
	FILE *fout = fopen(argv[2],"w");
	int c;
	char buffer[1000];

	while((c =fread(buffer,1,1000,fin)) > 0){
		fwrite(buffer,1,c,fout);

	}
	fclose(fin);
	fclose(fout);
	return 0;
}
