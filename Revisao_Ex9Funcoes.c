/*Fac¸a umam func¸ao que receba a altura e o raio de um cilindro circular e retorne o volume ˜
do cilindro. O volume de um cilindro circular e calculado por meio da seguinte f ´ ormula: ´
V = π ∗ raio2 ∗ altura, onde π = 3.141592.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.141592

float volumeCilindro(float altura, float raio);

int main(){
    float altura, raio,volume;
    printf("Insira a altura: ");
    scanf("%f",&altura);
    printf("Insira o raio agora: ");
    scanf("%f",&raio);

    volume= volumeCilindro(altura,raio);
    printf("O volume do cilindro eh %.2f", volume);
}

float volumeCilindro(float altura, float raio){
    float volume;
    volume = pi*pow(raio,2)*altura;
    return volume;
}