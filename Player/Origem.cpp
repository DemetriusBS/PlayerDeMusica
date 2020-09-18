#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

int menu();
void inserirMusicaInicio(char nomeMusica[], char nomeArtista[], float minuto);
void Listar();

struct PlayerMusica { //Estrutura heterogênea de dados para armazenar as informações
	char nomeMusica[30];
	char nomeArtista[40];
	float duracaoMusica;
	PlayerMusica* prox; //Ponteiro 'próximo' da lista simplesmente encadeada 
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
		case 1: //Aqui é realizada a coleta de dados informados pelo usuário
			printf("Informe o nome da música que deseja adicionar: ");
			fgets(nomeMus, 30, stdin);
			printf("\nInforme o nome do artista ou banda: ");
			fgets(nomeArt, 30, stdin);
			printf("\nPor último, informe qual a duração da música: ");
			scanf_s("%f", &minuto);
			while ((c = getchar()) != '\n' && c != EOF) {};
			inserirMusicaInicio(nomeMus, nomeArt, minuto); //Função de inserção
			break;
		case 2:
			Listar(); //Função para listar as musicas 
			break;
		case 3:
			return 0;
			break;
		default:
			printf("Opção inválida! \n\n");
			break;
		}
	}

	system("pause");
	return 0;
}

int menu() {
	int op, c;
	system("Cls");

	printf("Digite [1] para inserir uma nova música. \n");
	printf("\nDigite [2] para listar as músicas. \n");
	printf("\nDigite [3] para sair. \n");
	scanf_s("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF) {}; //Limpeza de buffer
	system("Cls");
	return op;
}

void inserirMusicaInicio(char nomeMusica[], char nomeArtista[], float minuto) {
	PlayerMusica* NovoElemento;
	NovoElemento = (struct PlayerMusica*)malloc(sizeof(PlayerMusica));

	strcpy_s(NovoElemento->nomeMusica, nomeMusica), //Pegando o dado informado pelo usuário e armazenando na struct
	strcpy_s(NovoElemento->nomeArtista, nomeArtista),
	NovoElemento->duracaoMusica = minuto;
	
	if (Head == NULL) //Teste condicional
	{
		Head = NovoElemento; //Caso a Head esteja vazia, meu novo elemento será a Head
		Head->prox = NULL; 
	}
	else
	{
		NovoElemento->prox = Head;//Como optei pela inserção no início, meu novo elemento entra na frente da Head e consequentemente se torna a nova Head
		Head = NovoElemento;
	}
}

void Listar() {
	PlayerMusica* ElementoVarredura; //Elemento que irá varrer a lista
	ElementoVarredura = (struct PlayerMusica*)malloc(sizeof(PlayerMusica));

	if (Head == NULL) { //Teste condicional
		printf("Lista vazia! ");
	}
	else {
		ElementoVarredura = Head;

		while (ElementoVarredura != NULL) { //Listagem das músicas

     		printf("\nNome da música: %s \n", ElementoVarredura->nomeMusica);
			printf("Nome da banda/artista: %s \n", ElementoVarredura->nomeArtista);
			printf("Duração: %.2f minutos \n", ElementoVarredura->duracaoMusica);
			printf("------------------------------------\n");
			ElementoVarredura = ElementoVarredura->prox;
		}

		printf("\n");
		system("pause");
	}
}