/*Fac¸a um programa para gerar automaticamente numeros entre 0 e 99 de uma cartela de ´
bingo. Sabendo que cada cartela devera conter 5 linhas de 5 n ´ umeros, gere estes dados ´
de modo a nao ter n ˜ umeros repetidos dentro das cartelas. O programa deve exibir na ´
tela a cartela gerada.*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int tabelaBingo[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            tabelaBingo[i][j]= rand() % 99;
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%d ", tabelaBingo[i][j]);
        }
        printf("\n");
    }

}