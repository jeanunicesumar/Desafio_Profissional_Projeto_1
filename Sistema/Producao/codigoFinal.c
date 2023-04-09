#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.c>
#include <stdbool.h>

typedef struct {
	char cep[12];
	char logradouro[60];
	char numero[6];
	char bairro[15];
	char municipio[20];
	char uf[2];	
} StructEndereco;
typedef struct {
	int matricula;
	char nome[80];
	char cpf[15];
	char fone[15];
	char email[50];
	char senha[80];
	StructEndereco Endereco;
} StructPessoa;
typedef struct {
	StructPessoa Pessoa;
	int idMotorista;
	char cnhMotorista[15];
	char orgaoEmissorCNH[15];
	char validade[11];
	char tipoCNH[3];
	int nivelPermissao;
	int status;
} StructMotorista;

bool autenticaUsuario(char usuario[20], char senha[20]);
bool formLogin();
void menu();
void formataFrase(int corFundo, int corTexto, char frase[30], int tamanhoEspaco, int espacoInicial, int posicao);
void formataFraseSimples(int corFundo, int corTexto, char frase[30]);
void formataCor(int corFundo, int corTexto);
void quebraLinha(int quantidadeQuebras);
void cadastrarMotorista(
	int matricula, char nome[80], char cpf[15], char fone[15], char email[50], char senha[50], char cep[50],
	char logradouro[60], char numero[6], char bairro[15],char municipio[20], char uf[2], int idMotorista,
	char cnhMotorista[15], char orgaoEmissorCNH[15], char validade[11], char tipoCNH[3], int nivelPermissao, int status
);
void alteraDadosMotorista (
	int motoristaId, int matricula, char nome[80], char cpf[15], char fone[15], char email[50], char senha[50], char cep[50],
	char logradouro[60], char numero[6], char bairro[15],char municipio[20], char uf[2], int idMotorista,
	char cnhMotorista[15], char orgaoEmissorCNH[15], char validade[11], char tipoCNH[3], int nivelPermissao, int status
);
bool login(int usuario, char senha[50]);
void formMotorista();
void listarMotorista();
void cabecalhoMotorista();
void listarMotoristaUnico(int idMotorista, int corFundo, int corTexto);
int buscaMotoristaMatricula(int matricula);
void exibeMotoristaBuscaMatricula();
void filtrarMotorista(char atributo[10], char valor[10]);
void desativarMotorista();
void criptoSenha(char senha[20]);

StructMotorista Motorista[100];
int contMotorista = 1;
char usuario[20] = "admin";
char senhaUsuario[20] = "Ûáóëõ{}";
int matricula;
char nome[30];
char cpf[15];
char fone[13];
char email[30];
char senha[20];
char cep[9];
char logradouro[9];
char numero[6];
char bairro[30];
char municipio[20];
char uf[4];
char cnh[15];
char orgaoEmissorCnh[8];
char validadeCnh[11];
char tipoCnh[2];
char senhaCriptografada[20];

int main() {
	setlocale(LC_ALL, "Portuguese");
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd,SW_SHOWMAXIMIZED);
	cadastrarMotorista (3012, "Carlos Luiz", "111.111.111-11", "(44)99999-9999", "carlosluiz@email.com", "ó?õá÷", "11111-111",
	"Rua maringá", "12A", "Bairro universo", "Maringá", "PR", contMotorista, "1112333232", "SESP", "23/03/2023", "A-B", 1, 1);
	cadastrarMotorista (3013, "Igor Silva", "222.222.222-11", "(44)98888-8888", "igorsilva@email.com", "ó÷?÷ýëÿ?Û", "22222-222",
		"Rua maringá", "12A", "Bairro universo", "Maringá", "PR", contMotorista, "1112333232", "SESP", "23/03/2022", "A-B", 1, 1);
	cadastrarMotorista (3014, "Marcio Silva", "111.111.111-11", "(44)99999-9999", "carlosluiz@email.com", "ó?õá÷", "11111-111",
		"Rua maringá", "12A", "Bairro universo", "Maringá", "PR", contMotorista, "1112333232", "SESP", "23/03/2021", "A-B", 1, 1);
	cadastrarMotorista (3015, "Jhonatan Santos", "888.888.888-11", "(44)99999-9999", "jhonatan21@email.com", "íé÷", "11111-111",
		"Rua maringá", "12A", "Bairro universo", "Maringá", "PR", contMotorista, "1112333232", "SESP", "23/03/2021", "A-B", 1, 1);
	bool usuarioAutenticado;
	do {
		usuarioAutenticado = formLogin();		
		Sleep(2000);
		system("cls");
	} while(!usuarioAutenticado);
	menu();
	return;
}

bool autenticaUsuario(char usuarioLogin[20], char senhaLogin[20]) {
	criptoSenha(senhaLogin);
	if(strcmp(usuario, usuarioLogin) == 0 && strcmp(senhaUsuario, senhaCriptografada) == 0)
		return true;
		
	return false;
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
	formataFrase(0, 15, "3 - Buscar motorista", 30, 2, 1);
	quebraLinha(1);
	formataFrase(0, 15, "4 - Editar motorista", 30, 2, 1);
	quebraLinha(1);
	formataFrase(0, 15, "5 - Desativar motorista", 30, 2, 1);
	quebraLinha(1);
	formataFrase(0, 15, "6 - Sair", 30, 2, 1);
	quebraLinha(2);

	formataCor(0, 15);
	printf ("Escolha uma opção: ");
	scanf("%d", &opcao);
	fflush(stdin);
	
	do {
		switch(opcao) {
			case 1:
				system("cls");
				formMotorista();
				cadastrarMotorista(matricula, nome, cpf, fone, email, senha, cep, logradouro, numero, bairro, municipio, uf, contMotorista, cnh, orgaoEmissorCnh, validadeCnh, tipoCnh, 1, 1);
				quebraLinha(2);
				system("pause");
				system("cls");
				menu();
				break;
			case 2:
				system("cls");
				listarMotorista();
				system("pause");
				system("cls");
				menu();
				break;
			case 3:
				formataCor(0, 15);
				system("cls");
				exibeMotoristaBuscaMatricula();
				formataCor(0, 15);
				system("pause");
				system("cls");
				menu();
				break;
			case 4:
				formataCor(0, 15);
				system("cls");
				editarMotorista();
				formataCor(0, 15);
				system("pause");
				system("cls");
				menu();
				break;
			case 5:
				formataCor(0, 15);
				system("cls");
				desativarMotorista();
				formataCor(0, 15);
				system("pause");
				system("cls");
				menu();
				break;
			case 6:
				system("cls");
				quebraLinha(1);
				formataFrase(0, 12, "Saindo", 30, 2, 1);
				quebraLinha(1);
				formataCor(0, 15);
				exit(0);
				break;
			default:
				printf("Opção inválida");
				Sleep(1000);
				system("cls");
				menu();
		}
		printf("%d", opcao);	
	} while (opcao != 6);
}

void formataFraseSimples(int corFundo, int corTexto, char frase[30]) {
	formataCor(corFundo, corTexto);
	printf("%s", frase);
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

void cadastrarMotorista (
	int matricula, char nome[80], char cpf[15], char fone[15], char email[50], char senha[50], char cep[50],
	char logradouro[60], char numero[6], char bairro[15],char municipio[20], char uf[2], int idMotorista,
	char cnhMotorista[15], char orgaoEmissorCNH[15], char validade[11], char tipoCNH[3], int nivelPermissao, int status
) {
	Motorista[contMotorista].Pessoa.matricula = matricula;
	strcpy(Motorista[contMotorista].Pessoa.nome, nome);
	strcpy(Motorista[contMotorista].Pessoa.cpf, cpf);	
	strcpy(Motorista[contMotorista].Pessoa.fone, fone);	
	strcpy(Motorista[contMotorista].Pessoa.email, email);	
	strcpy(Motorista[contMotorista].Pessoa.senha, senha);
	strcpy(Motorista[contMotorista].Pessoa.Endereco.cep, cep);
	strcpy(Motorista[contMotorista].Pessoa.Endereco.logradouro, logradouro);
	strcpy(Motorista[contMotorista].Pessoa.Endereco.numero, numero);
	strcpy(Motorista[contMotorista].Pessoa.Endereco.bairro, bairro);
	strcpy(Motorista[contMotorista].Pessoa.Endereco.municipio, municipio);
	strcpy(Motorista[contMotorista].Pessoa.Endereco.uf, uf);
	Motorista[contMotorista].idMotorista = idMotorista;
	strcpy(Motorista[contMotorista].cnhMotorista, cnhMotorista);
	strcpy(Motorista[contMotorista].orgaoEmissorCNH, orgaoEmissorCNH);
	strcpy(Motorista[contMotorista].validade, validade);
	strcpy(Motorista[contMotorista].tipoCNH, tipoCNH);
	Motorista[contMotorista].nivelPermissao = nivelPermissao;
	Motorista[contMotorista].status = status;
	
	contMotorista++;
}
int pedeInt(char frase[30]) {
	int temp;
	formataFraseSimples(0, 15, frase);
	scanf("%d", &temp);
	fflush(stdin);
	return temp;
}
void formMotorista() {
	matricula = pedeInt("Informe a matrícula do motorista: ");
	printf("Digite o nome do motorista: ");
	scanf("%s", nome);
	fflush(stdin);
	printf("Digite o cpf do motorista: ");
	scanf("%s", cpf);
	fflush(stdin);
	printf("Digite o telefone do motorista: ");
	scanf("%s", fone);
	fflush(stdin);
	printf("Digite o email do motorista: ");
	scanf("%s", email);
	fflush(stdin);
	printf("Digite a senha do motorista: ");
	scanf("%s", senha);
	criptoSenha(senha);
	strcpy(senha, senhaCriptografada);
	fflush(stdin);
	printf("Digite o cep do motorista: ");
	scanf("%s", cep);
	fflush(stdin);
	printf("Digite o logradouro do motorista: ");
	scanf("%s", logradouro);
	fflush(stdin);
	printf("Digite o número do motorista: ");
	scanf("%s", numero);
	fflush(stdin);
	printf("Digite o bairro do motorista: ");
	scanf("%s", bairro);
	fflush(stdin);
	printf("Digite o município do motorista: ");
	scanf("%s", municipio);
	fflush(stdin);
	printf("Digite o UF do motorista: ");
	scanf("%s", uf);
	fflush(stdin);
	printf("Digite a CNH do motorista: ");
	scanf("%s", cnh);
	fflush(stdin);
	printf("Digite o orgão emissor da CNH: ");
	scanf("%s", orgaoEmissorCnh);
	fflush(stdin);
	printf("Digite a validade da CNH: ");
	scanf("%s", validadeCnh);
	fflush(stdin);
	printf("Digite o tipo da CNH: ");
	scanf("%s", tipoCnh);
	fflush(stdin);
}
void listarMotorista() {
	int i, contAtivo = 1;
	cabecalhoMotorista();
	quebraLinha(1);
	for(i = 1; i < contMotorista; i++) {
		if (Motorista[i].status == 1) {
			if (contAtivo % 2 == 0) {
				listarMotoristaUnico(i, 0, 15);	
			} else {
				listarMotoristaUnico(i, 8, 15);
			}
			quebraLinha(1);	
			contAtivo++;
		}			
	}
	quebraLinha(2);
	formataCor(0, 15);
}
void cabecalhoMotorista() {
	formataFrase(15, 0, "Matricula", 20, 0, 2);
	formataFrase(15, 0, "Nome", 20, 0, 2);
	formataFrase(15, 0, "Senha", 20, 0, 2);
	formataFrase(15, 0, "Fone", 20, 0, 2);
	formataFrase(15, 0, "Cpf", 20, 0, 2);
	formataFrase(15, 0, "Cidade", 20, 0, 2);
	formataFrase(15, 0, "CNH", 20, 0, 2);
	formataFrase(15, 0, "Validade", 20, 0, 2);
}
void listarMotoristaUnico(int idMotorista, int corFundo, int corTexto) {
	char matriculaChar[10];
	itoa(Motorista[idMotorista].Pessoa.matricula, &matriculaChar, 10);
	formataFrase(corFundo, corTexto, matriculaChar, 20, 0, 2);
	formataFrase(corFundo, corTexto, Motorista[idMotorista].Pessoa.nome, 20, 0, 2);
	formataFrase(corFundo, corTexto, Motorista[idMotorista].Pessoa.senha, 20, 0, 2);
	formataFrase(corFundo, corTexto, Motorista[idMotorista].Pessoa.fone, 20, 0, 2);
	formataFrase(corFundo, corTexto, Motorista[idMotorista].Pessoa.cpf, 20, 0, 2);
	formataFrase(corFundo, corTexto, Motorista[idMotorista].Pessoa.Endereco.municipio, 20, 0, 2);
	formataFrase(corFundo, corTexto, Motorista[idMotorista].cnhMotorista, 20, 0, 2);
	formataFrase(corFundo, corTexto, Motorista[idMotorista].validade, 20, 0, 2);
}

int buscaMotoristaMatricula(int matricula) {
	int i;
	for (i = 1; i < contMotorista; i++) {
		if (Motorista[i].Pessoa.matricula == matricula && Motorista[i].status == 1) {
			return i;
		}
	}
	return 0;
}

void exibeMotoristaBuscaMatricula() {
	int matricula = pedeInt("Informe a matrícula do motorista: ");
	quebraLinha(2);
	int motorista = buscaMotoristaMatricula(matricula);
	if (motorista != 0) {
		cabecalhoMotorista();
		quebraLinha(1);
		listarMotoristaUnico(motorista, 8, 15);
		quebraLinha(2);
		return;
	}
	formataFraseSimples(0, 12, "Motorista não existe");
	quebraLinha(2);
}

void editarMotorista() {
	int matricula = pedeInt("Informe a matrícula do motorista: ");
	quebraLinha(1);
	int motorista = buscaMotoristaMatricula(matricula);
	if (motorista != 0) {
		formataFraseSimples(15, 4, "Motorista encontrado");
		quebraLinha(2);
		formMotorista();
		alteraDadosMotorista(motorista, matricula, nome, cpf, fone, email, senha, cep, logradouro, numero, bairro, municipio, uf, contMotorista, cnh, orgaoEmissorCnh, validadeCnh, tipoCnh, 1, 1);
		quebraLinha(1);
		formataFraseSimples(0, 10, "Motorista atualizado");
		quebraLinha(1);
		return;
	}
	formataFraseSimples(0, 12, "Motorista não existe");
	quebraLinha(2);
}

void alteraDadosMotorista (
	int motoristaId, int matricula, char nome[80], char cpf[15], char fone[15], char email[50], char senha[50], char cep[50],
	char logradouro[60], char numero[6], char bairro[15],char municipio[20], char uf[2], int idMotorista,
	char cnhMotorista[15], char orgaoEmissorCNH[15], char validade[11], char tipoCNH[3], int nivelPermissao, int status
) {
	Motorista[motoristaId].Pessoa.matricula = matricula;
	strcpy(Motorista[motoristaId].Pessoa.nome, nome);
	strcpy(Motorista[motoristaId].Pessoa.cpf, cpf);	
	strcpy(Motorista[motoristaId].Pessoa.fone, fone);	
	strcpy(Motorista[motoristaId].Pessoa.email, email);	
	strcpy(Motorista[motoristaId].Pessoa.senha, senha);
	strcpy(Motorista[motoristaId].Pessoa.Endereco.cep, cep);
	strcpy(Motorista[motoristaId].Pessoa.Endereco.logradouro, logradouro);
	strcpy(Motorista[motoristaId].Pessoa.Endereco.numero, numero);
	strcpy(Motorista[motoristaId].Pessoa.Endereco.bairro, bairro);
	strcpy(Motorista[motoristaId].Pessoa.Endereco.municipio, municipio);
	strcpy(Motorista[motoristaId].Pessoa.Endereco.uf, uf);
	strcpy(Motorista[motoristaId].cnhMotorista, cnhMotorista);
	strcpy(Motorista[motoristaId].orgaoEmissorCNH, orgaoEmissorCNH);
	strcpy(Motorista[motoristaId].validade, validade);
	strcpy(Motorista[motoristaId].tipoCNH, tipoCNH);
	Motorista[motoristaId].nivelPermissao = nivelPermissao;
	Motorista[motoristaId].status = status;
}


void desativarMotorista() {
	int matricula = pedeInt("Informe a matrícula do motorista: ");
	quebraLinha(1);
	int motorista = buscaMotoristaMatricula(matricula);
	if (motorista != 0) {
		formataFraseSimples(0, 12, "Motorista encontrado");
		quebraLinha(2);
		Sleep(1000);
		Motorista[motorista].status = 0;
		formataFraseSimples(0, 10, "Motorista desativado");
		quebraLinha(2);
		return;
	}
	formataFraseSimples(0, 12, "Motorista não existe");
	quebraLinha(2);
}

void criptoSenha(char senha[20]) {
    int vetor[20], i, temp;
    int tamanhoPalavra = strlen(senha);
    
    for (i=0; i < tamanhoPalavra;i++) {
        vetor[i]=senha[i];
        vetor[i] += vetor[i] + 25;
        if (vetor[i]>255){
            temp=vetor[i]-255;
            vetor[i]=temp;
        }
        senhaCriptografada[i]=vetor[i];
    }
}
