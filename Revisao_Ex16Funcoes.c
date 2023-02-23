/*Fac¸a uma func¸ao chamada DesenhaLinha. Ele deve desenhar uma linha na tela usando ˜
varios s ´ ´ımbolos de igual (Ex: ========). A func¸ao recebe por par ˜ ametro quantos sinais ˆ
de igual serao mostrados.*/

#include <stdio.h>
#include <stdlib.h>

void DesenhaLinha(int qtdSimbolos);

int main(){
    int qtdIguais;
    printf("Insira a quantidade de iguais na linha: ");
    scanf("%d",&qtdIguais);
    DesenhaLinha(qtdIguais);
}

void DesenhaLinha(int qtdSimbolos){
    for(int i=0; i<qtdSimbolos; i++){
        printf("=");
    }
}
