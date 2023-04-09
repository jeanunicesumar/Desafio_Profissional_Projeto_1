#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

// FALTA VALIDAR OS DADOS, GERAR HASH DE SENHA, LOGIN

void cadastrarMotorista(
	int matricula, char nome[80], char cpf[15], char fone[15], char email[50], char senha[50], char cep[50],
	char logradouro[60], char numero[6], char bairro[15],char municipio[20], char uf[2], int idMotorista,
	char cnhMotorista[15], char orgaoEmissorCNH[15], char validade[11], char tipoCNH[3], int nivelPermissao, int status
);

bool login(int usuario, char senha[50]);
char gerarHashDeSenha(char senha[80]); // Kenji
char verificarHashDeSenha(); // Kenji
void formMotorista();
void listarMotorista();
void listarMotoristaId();
void filtrarMotorista(char atributo[10], char valor[10]);
void editarMotorista(int matricula);

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

StructMotorista Motorista[10];
int contMotorista = 0;

int main() {
	setlocale(LC_ALL, "Portuguese");
	formMotorista();
	listarMotorista();
	for (i = 0;i < 10; i++) {
		listarMotorista(i);
	}
	return 0;
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
	printf("%s", frase);
	scanf("%d", &temp);
	fflush(stdin);
	return temp;
}

char *pedeChar(char frase[30]) {
	char temp[30];
	printf("%s", frase);
	fgets(temp, 30, stdin);
	return temp;
}

void formMotorista() {
	int matricula = pedeInt("Informe a matrícula do motorista: ");
	char nome[30];
	printf("Digite o nome do motorista: ");
	fgets(nome, 30, stdin);
	char cpf[15];
	printf("Digite o cpf do motorista: ");
	fgets(cpf, 15, stdin);
	char fone[13];
	printf("Digite o telefone do motorista: ");
	fgets(fone, 13, stdin);
	char email[30];
	printf("Digite o email do motorista: ");
	fgets(email, 40, stdin);
	char senha[20];
	printf("Digite a senha do motorista: ");
	fgets(senha, 20, stdin);
	char cep[9];
	printf("Digite o cep do motorista: ");
	fgets(cep, 9, stdin);
	char logradouro[9];
	printf("Digite o logradouro do motorista: ");
	fgets(logradouro, 9, stdin);
	char numero[6];
	printf("Digite o número do motorista: ");
	fgets(numero, 6, stdin);
	char bairro[30];
	printf("Digite o bairro do motorista: ");
	fgets(bairro, 30, stdin);
	char municipio[20];
	printf("Digite o município do motorista: ");
	fgets(municipio, 20, stdin);
	char uf[4];
	printf("Digite o UF do motorista: ");
	fgets(uf, 4, stdin);
	char cnh[15];
	printf("Digite a CNH do motorista: ");
	fgets(cnh, 15, stdin);
	char orgaoEmissorCnh[8];
	printf("Digite o orgão emissor da CNH: ");
	fgets(orgaoEmissorCnh, 8, stdin);
	char validadeCnh[10];
	printf("Digite a validade da CNH: ");
	fgets(validadeCnh, 10, stdin);
	char tipoCnh[2];
	printf("Digite o tipo da CNH: ");
	fgets(tipoCnh, 2, stdin);
	
	cadastrarMotorista(matricula, nome, cpf, fone, email, senha, cep, logradouro, numero, bairro, municipio, uf, contMotorista, cnh, orgaoEmissorCnh, validadeCnh, tipoCnh, 1, 1);
}

void listarMotorista(int idMotorista) {
	printf("%d ", Motorista[idMotorista].Pessoa.matricula);
	printf("%s ", Motorista[idMotorista].Pessoa.nome);
	printf("%s ", Motorista[idMotorista].Pessoa.cpf);
	printf("%s ", Motorista[idMotorista].Pessoa.fone);
	printf("%s ", Motorista[idMotorista].Pessoa.email);
	printf("%s ", Motorista[idMotorista].Pessoa.senha);
	printf("%s ", Motorista[idMotorista].Pessoa.Endereco.cep);
	printf("%s ", Motorista[idMotorista].Pessoa.Endereco.logradouro);
	printf("%s ", Motorista[idMotorista].Pessoa.Endereco.numero);
	printf("%s ", Motorista[idMotorista].Pessoa.Endereco.municipio);
	printf("%s ", Motorista[idMotorista].Pessoa.Endereco.uf);
	printf("%d ", Motorista[idMotorista].idMotorista);
	printf("%s ", Motorista[idMotorista].cnhMotorista);
	printf("%s ", Motorista[idMotorista].orgaoEmissorCNH);
	printf("%s ", Motorista[idMotorista].validade);
	printf("%d ", Motorista[idMotorista].tipoCNH);
	printf("%d ", Motorista[idMotorista].nivelPermissao);
	printf("%d ", Motorista[idMotorista].status);
}

