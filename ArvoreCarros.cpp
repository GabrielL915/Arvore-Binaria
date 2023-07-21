#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoCarro
{
	char placa[10];
	char modelo[15];
	float valor;
	int ano;
}TCarro;

typedef struct tipoNo
{
	TCarro carro;
	struct tipoNo *esquerdo;
	struct tipoNo *direito;
}TNo;

void lerDadosCarro(TCarro *novoCarro)
{
	printf("\n Placa: ");
	fflush(stdin);
	gets(novoCarro->placa);
	
	printf("\n Modelo: ");
	fflush(stdin);
	gets(novoCarro->modelo);
	
	printf("\n Ano: ");
	scanf("%d", &novoCarro->ano);
	
	printf("\n Valor: ");
	scanf("%f", &novoCarro->valor);
}

void preOrdem (TNo *raiz)
{
	if (raiz != NULL)
	{
		printf("\n Placa: %s", raiz->carro.placa);
		printf("\n Modelo: %s", raiz->carro.modelo);
		printf("\n Ano: %d", raiz->carro.ano);
		printf("\n Valor: %.2f", raiz->carro.valor);
		printf("\n ---------------------------");
		preOrdem(raiz->esquerdo);
		preOrdem(raiz->direito);
	}
}

TNo* inserirCarro (TNo *raiz, TCarro novoCarro)
{
	if (raiz == NULL)
	{
		raiz = new TNo;
		raiz->carro = novoCarro;
		raiz->esquerdo = NULL;
		raiz->direito = NULL;
	}
	else
	{
		//se novo carro for "menor" que o carro da raiz, tenta inserção do lado esquerdo
		if (strcmp(novoCarro.placa, raiz->carro.placa) < 0) 
		{
			raiz->esquerdo = inserirCarro(raiz->esquerdo, novoCarro);
		}
		else
		{
			raiz->direito = inserirCarro(raiz->direito, novoCarro);
		}
	}
	return raiz;	
}

int verificarVeiculo(TNo *raiz_aux, char consultaPlaca[])
{
	while ((raiz_aux != NULL) && (strcmp(consultaPlaca, raiz_aux->carro.placa) != 0))
	{
		if (strcmp(consultaPlaca, raiz_aux->carro.placa) < 0)
		{
			raiz_aux = raiz_aux->esquerdo;
		}
		else {
			raiz_aux = raiz_aux->direito;
		}
	}
	if (raiz_aux != NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void consultarVeiculo(TNo *raiz)
{
	if (raiz == NULL)
	{
		printf("\n Nao possui elementos cadastrados");
	}
	else
	{
		char consultaPlaca[15];
		
		printf("\n Informe modelo do veiculo: ");
		fflush(stdin);
		gets(consultaPlaca);
		
		if (verificarVeiculo(raiz, consultaPlaca) == 1)
		{
			printf("\n *** Veiculo Encontrado ***");
		}
		else
		{
			printf("\n *** Veiculo NAO Encontrado ***");
		}
	}
}

int main()
{
	TNo *raiz;
	raiz = NULL;
	
	int opcao;
	
	TCarro novoCarro;
	
	do
	{
		printf("\n 1 - Inserir novo veiculo");
		printf("\n 2 - Apresentar veiculos");
		printf("\n 3 - Consultar veiculo");
		printf("\n 0 - Sair");
		printf("\n Escolha uma opcao: ");
		scanf("%d", &opcao);
		switch(opcao)
		{
			case 1:
			{
				lerDadosCarro(&novoCarro);
				raiz = inserirCarro(raiz, novoCarro);
				break;
			}
			case 2:
			{
				preOrdem(raiz);
				break;			
			}
			case 3:
			{
				consultarVeiculo(raiz); 
				break;
			}
		}
	}while (opcao != 0);
}
	


