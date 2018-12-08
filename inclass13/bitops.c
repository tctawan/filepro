#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printByte(unsigned char *arr, int idx){
    
    unsigned char c = arr[idx];
    int myByte[8];
    for (int j =0; j<8; j++ ){
        int bit = (c >> (7-j) ) & 1;
        myByte[j] = bit;
    }
    

    for (int i = 0; i<8; i++){
        printf("%d", myByte[i]);
    }
    printf("  ");

}


int get(unsigned char *arr,int idx){

    int charIndex = idx/8;  
    unsigned char c = arr[charIndex];
    int bIndex = idx % 8;
    int bit = (c & (1 << bIndex)) != 0 ; 
    return bit;
}

void set(unsigned char *arr, int idx, int val){
    
    int charIndex = idx/8;
    unsigned char c = arr[charIndex];
    int bIndex = idx % 8;
    //set
    if(val != get(arr,idx)){
        c = (c ^ (1 << bIndex));
    }
    arr[charIndex] = c;
}

int main(){
    
    unsigned char *tawan = "IMAGE";
    int n = strlen(tawan);
    unsigned char *arr = (unsigned char *) malloc(sizeof(char)*n+1);
    strcpy(arr, tawan);
    printf("arr : %s\n", arr );
    for (int i =0; i<n; i++){
        printByte(arr,i);
    }
    printf("\n");


    printf("---------------------------------------------------\n");
    int idx = 20;
    printf("get(arr,%d):\n",idx );
    printf("char: %c , bitIdx: %d  , bit: %d\n", arr[idx/8], idx%8 , get(arr,idx));

    printf("---------------------------------------------------\n");
    idx = 17;
    int val = 1;
    set(arr,idx,val);
    printf("set(arr,%d,%d) :\n",idx,val);
    printf("char: %c, bitIdx: %d , final: %s\n", arr[idx/8], idx%8, arr);
}
