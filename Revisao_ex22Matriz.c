/*Fac¸a um programa que leia duas matrizes A e B de tamanho 3 x 3 e calcule C = A ∗ B*/
#include <stdio.h>


int main(){
    int a[3][3],b[3][3],c[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&a[i][j]);
            printf("agora a b\n");
            scanf("%d",&b[i][j]);
            c[i][j]=a[i][j]*b[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}