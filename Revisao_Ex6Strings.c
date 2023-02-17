/*Ler nome, sexo e idade. Se sexo for feminino e idade menor que 25, imprime o nome da
pessoa e a palavra “ACEITA”, caso contrario imprimir “N ´ AO ACEITA”*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa{
    int idade;
    char nome[30];
    char genero[20];
};

int main(){

    struct Pessoa pessoaNova; 

    printf("Insira nome: ");
    scanf("%[^\n]s",&pessoaNova.nome);
    printf("Insira a idade: ");
    scanf("%d",&pessoaNova.idade);
    getchar();
    printf("Insira o genero: ");
    scanf("%[^\n]s",&pessoaNova.genero);
    
    if(strcmp("Feminino",pessoaNova.genero)==0 && pessoaNova.idade<25){
        printf("Aceita");
    }
    else{
        printf("Nao aceita");
    }
}
