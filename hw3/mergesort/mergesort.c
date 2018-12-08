/* Name: Tawan Chaeyklinthes
 * ID: 5980963
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergesort.h"

void merge(Entry *output, Entry *L, int nL, Entry *R, int nR) {
    int i,j,k;
    i=j=k=0;
    while(k< nL+nR){
        if((i<nL&& j <nR && L[i].data < R[j].data) || j>=nR){
            output[k].data = L[i].data;
            output[k].name = L[i].name;
            i++;

        }else{
            output[k].data = R[j].data;
            output[k].name = R[j].name;
            j++;

        }
        k++;
    }
}

void merge_sort(Entry *entries, int n) {
    if(n>1){
        int nL = n/2;
        int nR = n-n/2;
        merge_sort(entries,nL);
        merge_sort(entries+nL,nR);
        
        Entry *output = (Entry *)malloc(n*sizeof(Entry));
        
        merge(output,entries,nL,entries+nL,nR);
        
        memcpy(entries, output, n*sizeof(Entry)); 
        free(output);
    }
}

/*
TEST: ./mergesort < test.in
OUTPUT:
1 lsdfjl
2 ghijk
3 ksdljf
5 abc
6 def
*/
int main(void) {
    int n = 0;
    scanf("%d",&n);
    
    Entry *entries = (Entry *)malloc(n*sizeof(Entry));

    for(int i=0; i<n; i++){
        int key = 0;
        char s[MAX_NAME_LENGTH];

        scanf("%d %s",&key,s);

        entries[i].data = key;
        entries[i].name = (char *) malloc(sizeof(char)*strlen(s)+1);
        strcpy(entries[i].name, s);

    }

    merge_sort(entries , n);

    for(int i =0 ; i<n ;i++){
        printf("%d %s\n",entries[i].data,entries[i].name);
        free(entries[i].name);
    }
    free(entries);
}
