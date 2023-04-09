#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.c>
#include <stdbool.h>

bool autenticaUsuario(char usuario[20], char senha[20]);
bool formLogin();
void menu();
void formataFrase(int corFundo, int corTexto, char frase[30], int tamanhoEspaco, int espacoInicial, int posicao);
void formataFraseSimples(int corFundo, int corTexto, char frase[30]);
void formataCor(int corFundo, int corTexto);
void quebraLinha(int quantidadeQuebras);

char usuario[20] = "admin";
char senha[20] = "admin";


int main() {
	setlocale(LC_ALL, "Portuguese");
	bool usuarioAutenticado;
	do {
		usuarioAutenticado = formLogin();		
		Sleep(2000);
		system("cls");
	} while(!usuarioAutenticado);
	menu();
}

void formataFraseSimples(int corFundo, int corTexto, char frase[30]) {
	int tamanhoFrase = strlen(frase);
	char fraseFormatada[tamanhoFrase];
	int i, x = 0;
		
	for(i = 0; i < tamanhoFrase; i++) {
		fraseFormatada[i] = ' ';
	}
	
	for(i = 0; i < tamanhoFrase; i++)
		fraseFormatada[i] = frase[x++];
		
	formataCor(corFundo, corTexto);
	for(i = 0; i < tamanhoFrase; i++) {
		printf("%c", fraseFormatada[i]);
	}
}

void formataFrase(int corFundo, int corTexto, char frase[30], int tamanhoEspaco, int espacoInicial, int alinhar) {
	char fraseFormatada[tamanhoEspaco];
	int tamanhoFrase = strlen(frase);
	int posicaoFrase, i, x = 0;
	
	if (tamanhoEspaco < espacoInicial + tamanhoFrase) {
		printf("Erro");
		return;
	}
		
	for(i = 0; i < tamanhoEspaco; i++) {
		fraseFormatada[i] = ' ';
	}
		
	switch(alinhar) {
		case 1:
			posicaoFrase = espacoInicial;
			for(i = posicaoFrase; i < posicaoFrase + tamanhoFrase; i++)
				fraseFormatada[i] = frase[x++];
		break;
		case 2:
			posicaoFrase = ((tamanhoEspaco - tamanhoFrase) / 2) + espacoInicial;
			for(i = posicaoFrase; i < posicaoFrase + tamanhoFrase; i++)
				fraseFormatada[i] = frase[x++];	
		break;
		case 3:
			posicaoFrase = tamanhoEspaco - espacoInicial;
			x = tamanhoFrase;
			for(i = posicaoFrase; i >= posicaoFrase - tamanhoFrase; i--)
				fraseFormatada[i] = frase[x--];
		break;
		default:
			printf("Erro");
			return;
	}
		
	formataCor(corFundo, corTexto);
	for(i = 0; i < tamanhoEspaco; i++) {
		printf("%c", fraseFormatada[i]);
	}
}

void formataCor(int corFundo, int corTexto) {
	textbackground(corFundo);
	textcolor(corTexto);
}

void quebraLinha(int quantidadeQuebras) {
	int i;
	for(i = 0; i < quantidadeQuebras; i++) {
		printf("\n");
	}
}

void menu() {
	int opcao;
	
	formataFrase(15, 0, "Menu", 30, 0, 2);
	quebraLinha(2);
	formataFrase(15, 0, "Opções", 30, 0, 2);
	quebraLinha(1);
	formataFrase(0, 15, "1 - Cadastrar motorista", 30, 2, 1);
	quebraLinha(1);
	formataFrase(0, 15, "2 - Listar motoristas", 30, 2, 1);
	quebraLinha(1);
	formataFrase(0, 15, "3 - Editar motorista", 30, 2, 1);
	quebraLinha(1);
	formataFrase(0, 15, "4 - Excluir motorista", 30, 2, 1);
	quebraLinha(1);
	formataFrase(0, 15, "5 - Sair", 30, 2, 1);
	quebraLinha(2);

	formataCor(0, 15);
	printf ("Escolha uma opção: ");
	scanf("%d", &opcao);
	fflush(stdin);
	
	do {
		switch(opcao) {
			case 1:
				printf("Opção 1");
				return;
			break;
			case 2:
				printf("Opção 2");
				return;
			break;
			case 3:
				printf("Opção 3");
				return;
			break;
			case 4:
				printf("Opção 4");
				return;
			break;
			case 5:
				system("cls");
				formataFrase(0, 12, "Saindo", 30, 2, 1);
				formataCor(0, 15);
				return;
			break;
			default:
				printf("Opção inválida");	
		}	
	} while (opcao != 5);
}

bool formLogin() {
	char usuarioLogin[20];
	char senhaLogin[20];
	
	formataFrase(15, 0, "Login", 30, 0, 2);
	quebraLinha(2);
	formataFraseSimples(0, 15, "Digite o usuário: ");
	scanf("%s", &usuarioLogin);
	fflush(stdin);
	formataFraseSimples(0, 15, "Digite a senha: ");
	scanf("%s", &senhaLogin);
	fflush(stdin);
	quebraLinha(1);
	
	if(autenticaUsuario(usuarioLogin, senhaLogin)) {
		formataFrase(0, 10, "Usuário liberado!", 20, 2, 1);
		formataCor(0, 15);
		return true;
	} else {
		formataFrase(0, 12, "Usuário inválido!", 20, 2, 1);
		formataCor(0, 15);
		return false;
	}
}

bool autenticaUsuario(char usuarioLogin[20], char senhaLogin[20]) {
	if(strcmp(usuario, usuarioLogin) == 0 && strcmp(senha, senhaLogin) == 0)
		return true;
		
	return false;
}

