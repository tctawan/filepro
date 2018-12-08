#include <stdio.h>

int parity_check(int x){

    int a = x ^ (x >> 16);
    int b = a ^ (a >> 8);
    int c = b ^ (b >> 4);
    int d = c ^ (c >> 2);
    int e = d ^ (d >> 1);
    return e & 1;
}

int main(){
    
    int number = 0;
    scanf("%d", &number);
    int parity = parity_check(number);
    printf("%d\n",parity);
    return 0;

}
