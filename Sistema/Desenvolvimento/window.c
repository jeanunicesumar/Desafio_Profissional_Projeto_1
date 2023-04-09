#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char frase[30];
    printf("Informe a frase: ");
    pedeDado(&frase);
    printf("%s", frase);
}

int pedeDado(char *frase) {
	char temp[30];
	scanf("%s", &frase);
	fflush(stdin);
	*frase = temp;
}
