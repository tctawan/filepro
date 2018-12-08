#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double compute_det(int **a, int n){

    if(n == 1){
        return a[0][0];
    }else{

        double ans = 0.0;
        double sign = -1.0;
        for (int i =0; i<n ; i++){
            int **newMatrix = (int **)malloc((n-1)*sizeof(int*));
            
            for (int r =1; r<n; r++){
                int *row = (int *)malloc((n-1)*sizeof(int));
                int k = 0;
                
                for (int c =0; c<n ; c++){
                    if(c != i){
                        row[k] = a[r][c];
                        k++;
                    }

                }
                newMatrix[r-1] = row;

            }
            sign = sign*(-1);
             ans += sign*a[0][i]*compute_det(newMatrix,n-1);

             for (int x = 0; x<n-1;x++){
                 free(newMatrix[x]);
             }
             free(newMatrix);

        }

        return ans;
    }
}

/*
TEST: ./det < det.in
OUTPUT:
-105.00000
*/
int main(void) {
  
    int n = 0;
    scanf("%d", &n);
    int **a = (int**)malloc(n*sizeof(int*));
    
    for (int i=0; i<n; i++){
        int *row = (int*)malloc(n*sizeof(int));
        for (int j=0; j<n ;j++){
            scanf("%d",&row[j]);
        }
        a[i] = row;
    }

    double ans = compute_det(a,n);
    printf("%f\n",ans);

    for (int x=0; x<n; x++){
        free(a[x]);
    }
    free(a);
}
