#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
    char senha[6], cripto[80];
    int vetor[6], i, temp, vetor2[6], temp2;
    int tamanhoPalavra = strlen(senha);
    
    printf("Digite sua senha (Máximo de 8 caracteres): ");
    scanf("%s", &senha);
    fflush(stdin);
    for (i=0; i < tamanhoPalavra;i++) {
        vetor[i]=senha[i];
        vetor[i] += vetor[i] + 25;
        if (vetor[i]>255){
            temp=vetor[i]-255;
            vetor[i]=temp;
        }
        cripto[i]=vetor[i];
        printf("%c", cripto[i]);
    }
    
    printf("\n");
    
    for(i=0; i < tamanhoPalavra; i++) {
    	vetor2[i]=vetor[i];
        vetor2[i] = (vetor2[i] - 25) / 2;
        if (vetor2[i] < 0){
        	printf("Entrei");
         	temp2 = 255 - vetor2[i];
         	vetor2[i]=temp2;
        }
        cripto[i] = vetor2[i];
        printf("%c",cripto[i]);
	}
}
