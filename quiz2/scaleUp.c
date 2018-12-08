#include <stdio.h>


int main(){
    int nRow = 0;
    int nCol = 0;
    int ratio = 0;

    scanf("%d %d %d", &nRow, &nCol, &ratio);
    
    int newM[nRow*ratio][nCol*ratio];
    
    int num = 0;

    for(int r =0; r<nRow; r++){
        for(int c =0; c<nCol; c++){
            
            scanf("%d", &num);

            for(int i = 0; i<ratio ; i++){
                for(int j =0; j<ratio; j++){
                    
                    newM[r*ratio+i][c*ratio+j] = num;
                }
            }
        }
    }

    for(int r=0; r<nRow*ratio; r++){
        for(int c = 0; c<nCol*ratio; c++){
           printf("%d ", newM[r][c]);
        }
        printf("\n");
    }
    return 0;
}
