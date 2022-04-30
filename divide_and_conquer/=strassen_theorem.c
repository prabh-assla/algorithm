#include <stdio.h>

void mtx_multiply(int i1,int j1,int arr1[i1][j1],int i2,int j2,int arr2[i2][j2],int i,int j,int MTX[i][j]){
    
    MTX[0][0] = arr1[0][0]*arr2[0][0] + arr1[0][1]*arr2[1][0];
    MTX[0][1] = arr1[0][0]*arr2[0][0] + arr1[0][1]*arr2[1][1];
    MTX[1][0] = arr1[1][0]*arr2[0][0] + arr1[1][1]*arr2[1][0];
    MTX[1][1] = arr1[1][0]*arr2[0][0] + arr1[1][1]*arr2[1][1];
}

void MTX_breaker(int i1,int j1,int arr1[i1][j1],int i2,int j2,int arr2[i2][j2],int i,int j,int MTX[i][j]){
    if(j1-i1!=1 && j2-i2!=1 && j-i!=1){
        MTX_breaker(i1/2, j1/2, arr1, i2/2, j2/2, arr2, i/2, j/2, MTX);
        MTX_breaker(i1/2+1, j1/2+1, arr1, i2/2+1, j2/2+1, arr2, i/2+1, j/2+1, MTX);
        mtx_multiply(i1, )

}

int main(){
int mtx1[4][4] = {{1, -1, 5, 2}, {3, 2, 6, -1}, {2, 0, 8, -1}, {-6, -8, 5, -2}}, 
mtx2[4][4] = {{4, -2, 5, 6}, {6, 3, 1, -5}, {-4, -2, 5, 1}, {-4, -5, -7, 0}}, 
MTX[4][4];

    MTX_breaker(3, 3, mtx1, 3, 3, mtx2, 3, 3, MTX);

return 0;
}