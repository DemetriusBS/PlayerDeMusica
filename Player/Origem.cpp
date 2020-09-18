#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

int menu();
void inserirMusicaInicio(char nomeMusica[], char nomeArtista[], float minuto);
void Listar();

struct PlayerMusica { //Estrutura heterog�nea de dados para armazenar as informa��es
	char nomeMusica[30];
	char nomeArtista[40];
	float duracaoMusica;
	PlayerMusica* prox; //Ponteiro 'pr�ximo' da lista simplesmente encadeada 
}*Head;

int main() {

	setlocale(LC_ALL, "Portuguese");

	int op, c;
	float minuto;
	char nomeArt[40];
	char nomeMus[30];
	Head = NULL;

	while (1) {
		op = menu();

		switch (op)
		{
		case 1: //Aqui � realizada a coleta de dados informados pelo usu�rio
			printf("Informe o nome da m�sica que deseja adicionar: ");
			fgets(nomeMus, 30, stdin);
			printf("\nInforme o nome do artista ou banda: ");
			fgets(nomeArt, 30, stdin);
			printf("\nPor �ltimo, informe qual a dura��o da m�sica: ");
			scanf_s("%f", &minuto);
			while ((c = getchar()) != '\n' && c != EOF) {};
			inserirMusicaInicio(nomeMus, nomeArt, minuto); //Fun��o de inser��o
			break;
		case 2:
			Listar(); //Fun��o para listar as musicas 
			break;
		case 3:
			return 0;
			break;
		default:
			printf("Op��o inv�lida! \n\n");
			break;
		}
	}

	system("pause");
	return 0;
}

int menu() {
	int op, c;
	system("Cls");

	printf("Digite [1] para inserir uma nova m�sica. \n");
	printf("\nDigite [2] para listar as m�sicas. \n");
	printf("\nDigite [3] para sair. \n");
	scanf_s("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF) {}; //Limpeza de buffer
	system("Cls");
	return op;
}

void inserirMusicaInicio(char nomeMusica[], char nomeArtista[], float minuto) {
	PlayerMusica* NovoElemento;
	NovoElemento = (struct PlayerMusica*)malloc(sizeof(PlayerMusica));

	strcpy_s(NovoElemento->nomeMusica, nomeMusica), //Pegando o dado informado pelo usu�rio e armazenando na struct
	strcpy_s(NovoElemento->nomeArtista, nomeArtista),
	NovoElemento->duracaoMusica = minuto;
	
	if (Head == NULL) //Teste condicional
	{
		Head = NovoElemento; //Caso a Head esteja vazia, meu novo elemento ser� a Head
		Head->prox = NULL; 
	}
	else
	{
		NovoElemento->prox = Head;//Como optei pela inser��o no in�cio, meu novo elemento entra na frente da Head e consequentemente se torna a nova Head
		Head = NovoElemento;
	}
}

void Listar() {
	PlayerMusica* ElementoVarredura; //Elemento que ir� varrer a lista
	ElementoVarredura = (struct PlayerMusica*)malloc(sizeof(PlayerMusica));

	if (Head == NULL) { //Teste condicional
		printf("Lista vazia! ");
	}
	else {
		ElementoVarredura = Head;

		while (ElementoVarredura != NULL) { //Listagem das m�sicas

     		printf("\nNome da m�sica: %s \n", ElementoVarredura->nomeMusica);
			printf("Nome da banda/artista: %s \n", ElementoVarredura->nomeArtista);
			printf("Dura��o: %.2f minutos \n", ElementoVarredura->duracaoMusica);
			printf("------------------------------------\n");
			ElementoVarredura = ElementoVarredura->prox;
		}

		printf("\n");
		system("pause");
	}
}