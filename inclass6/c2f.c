#include <stdio.h>
#include <string.h>
#include <math.h>
int main(int arg0, char** arg[]){
	float lower = 0.f;
	float upper = 0.f;
	printf("lower limit: ");
	scanf("%f", &lower);
	printf("upper limit: ");
	scanf("%f", &upper);
	printf("Celecius	Fahrenheit\n");
	printf("==========================\n");
	float f = 0.f;
	for(float c = lower ; c<=upper ; c+=5.0){
		f =c*(9.0/5.0)+32.0;
		int len1 = strlen("Celecius");
		int len2 = strlen("Fahrenheit");
		printf("%*.0f	%*.1f\n",len1,c,len2,f);
	}
	printf("--------------------------\n");

	return 0;
}
