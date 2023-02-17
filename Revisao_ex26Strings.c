/*O codigo de C ´ esar ´ e uma das mais simples e conhecidas t ´ ecnicas de criptografia. ´ E um ´
tipo de substituic¸ao na qual cada letra do texto ˜ e substitu ´ ´ıda por outra, que se apresenta
no alfabeto abaixo dela um numero fixo de vezes. Por exemplo, com uma troca de tr ´ esˆ
posic¸oes, ‘A’ seria substitu ˜ ´ıdo por ‘D’, ‘B’ se tornaria ‘E’, e assim por diante. Implemente
um programa que fac¸a uso desse Codigo de C ´ esar (3 posic¸ ´ oes), entre com uma string e ˜
retorne a string codificada. Exemplo:
String: a ligeira raposa marrom saltou sobre o cachorro cansado
Nova string: D OLJHLUD UDSRVD PDUURP VDOWRX VREUH R FDFKRUUR FDQVDGR
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    char frase[100];

    scanf("%[^\n]s",&frase);
    for(int i=0;frase[i]!='\0';i++){
            if(frase[i]==' '){
                frase[i]=' ';
            }
            else{
                frase[i]+=3;
                if(frase[i]==125){
                    frase[i]=99;
                }
                else if (frase[i]==124)
                {
                    frase[i]=98;
                }
                else if (frase[i]==123)
                {
                    frase[i]=97;
                }
                
                
            }
        }
            
    printf("%s",frase);
}
