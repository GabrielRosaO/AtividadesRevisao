/*Leia um vetor com 20 numeros inteiros. Escreva os elementos do vetor eliminando ele- ´
mentos repetidos*/

#include <stdio.h>
int main(){
    int numeros[20]={0,1,2,3,2,4,5,6,7,8,8,9,10,11,12,13,14,15,15,16},numerosArrumados[20],tamVetorNovo=0;
    for(int i=0;i<20;i++){
        for(int j=i+1;j<20;j++){
            if(numeros[j]!=numeros[i]){
                numerosArrumados[tamVetorNovo]=numeros[i];
                tamVetorNovo++;
            }
        }
    }   
    for(int i = 0;i<tamVetorNovo;i++){
        printf("%d",numerosArrumados[i]);
    } 

}