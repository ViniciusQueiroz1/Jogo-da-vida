/*JVIDA2-EJPV-View.cpp - Projeto Jogo da Vida - Etapa FINAL
13/11/2024 - Grupo: EJPV
-Enzo Marasca Soranz Saragiotto
-Joao Pedro Pedott Rocha
-Pedro Paulo Martins de Oliveira Tonon
-Vinicius Queiroz e Silva Soares
*/

#include "JVIDA2-EJPV-View.h"
#include "JVIDA2-EJPV-Model.h"
#include "JVIDA2-EJPV-Controller.h"

//Possibilita com que o usuario escolha o tamnho da matriz
void tamanhoDoJogo()
{
	int tam = 0;
	
	printf("Escolha o tamanho da Area em que a vida se desenvolvera(Entre 10 e 50): ");
	scanf("%d", &tam);
	fClear();
	system("cls");
	
	tamanho = tam - 1;

}

//Mostra o menu para o usuario
int menu2()
{
	int escolha = 0;
	
	printf("-------------------------------------------------------------------------\n");
	printf("-                               Jogo da Vida                            -\n");
	printf("-Bem vindo ao jogo da vida, por favor, selecione uma das opcoes abaixo  -\n");
	printf("-------------------------------------------------------------------------\n");
	printf("- 1) Limpar o Mapa                                                       \n");
	printf("- 2) Incluir/excluir celulas vivas                                       \n");
	printf("- 3) Mostrar/esconder celulas vizinhas mortas                            \n");
	printf("- 4) Regras de evolucao das celulas (e tutorial de como funciona o jogo) \n");
	printf("- 5) Iniciar Simulacao/Escolher Velocidade                               \n");
	printf("- 6) Salvar uma geracao inicial                                          \n");
	printf("- 7) Carregar uma geracao inicial cadastrada                             \n");
	printf("- 8) Limpar o cadastro de geracoes iniciais salvas (%d geracoes)         \n", qtdConfig);
	printf("- 0) Sair do jogo                                                        \n");
	printf("-------------------------------------------------------------------------\n");
	scanf("%d", &escolha);
	system("cls");
	fClear();
	
	return escolha;	
}

//Mostra o tutorial para o usuario 
void tutoras()
{
	char c;
	
	do
	{
		system("cls");
		printf("Escolha uma das opcoes a seguir sobre o que quer aprender (0 para sair): \n");
		printf("1) Qual e o objetivo do jogo?\n");
		printf("2) Como funciona o sistema de geracoes?\n");
		printf("3) O que faz as celulas continuarem vivas ou morrerem?\n");
		printf("4) O que as minhas configuracoes influenciam no jogo?\n");
		scanf("%c", &c);
		fClear();
		
		if (c != '0')
		{
			switch (c)
			{
				case '1':
				{
						printf("O Jogo da Vida de Conway e um automato celular criado em 1970, cujo objetivo e simular, por meio de regras\n");
						printf("basicas, a evolucao da vida e alteracoes nos grupos de seres vivos. O programa adquiriu tamanha importancia\n");
						printf("que ate os dias atuais e utilizado em experimentos cientificos.\n");
						system ("pause");
						break;
				}
				case '2':
				{
					  	printf("O jogo se passa em uma area bidimensional infinita que apresenta celulas em dois estados: vivas ou mortas.\n");
					  	printf("Cada celula possui 8 vizinhas, adjacentes horizontalmente, verticalmente e diagonalmente.\n");
					  	printf("O programa funciona em unidades de tempo discretas conhecidas como geracoes. A cada nova geracao, o\n");
					  	printf("estado do jogo e atualizado pela aplicacao de regras especificas.\n");
						system ("pause");
						break;	
				}
				case '3':
				{
						printf("As regras basicas de vida ou morte do Jogo da Vida, sao as seguintes: toda celula morta com exatos 3 vizinhas\n");
						printf("vivas torna-se viva, processo conhecido como nascimento. Toda celula com menos de 2 vizinhas vivas morre por\n");
						printf("isolamento. Toda celula viva com mais de 4 ou mais vizinhas vivas morre por superpopulacao. Por fim, para se\n");
						printf("manter viva, uma celula necessita de 2 ou 3 vizinhas vivas. Essas 4 regras principais sao aplicadas\n");
						printf("simultaneamente em todas as celulas para avancar para a proxima geracao.\n");
						system ("pause");
						break;
				}
				case '4':
				{
						printf("Voce possui a habilidade de selecionar celulas mortas para torna-las vivas e vice-versa, mudando o formato do jogo durante as geracoes, as outras opcoes.\n");
						printf("como quantas geracoes voce quer ir para o futuro, ou se quer que as geracoes pasasm automaticamente, e a velocidade de como as geracoes passam, mudam o ritmo do jogo\n");
						printf("na tela do jogador, porem nao influenciam no jogo em si.\n");
						system ("pause");
						break;
				}
			}
		}
	}while (c != '0');
	system("cls");	
}

//Pergunta ao usuario qual o delay entre as geracoes de simulacao que ele deseja
void escolheVelocidade()
{
	printf("Quanto de delay entre as geracoes voce deseja(O padrao e' 1): ");
	scanf("%f", &velocidade);
	fClear();
	system("cls");
}

//Mostra a area do jogo
void mostraAreaJogo()
{
	if(verVizinhos == 's')
	{
		vizinhasMortas();
	}
	if(verVizinhos == 'n')
	{
		escondeVizinhasMortas();
	}
	
	int a, b;
	b = tamanho;
	a = tamanho;
	
	printf("  ");
	for(int i = 0; i <= a; i++)				
		printf(" %.2d ", i);	
	printf("\n");
	
	for(int l = 0; l <= a; l++)				
	{
		printf("%.2d ", l);					
		for(int j = 0; j <= b; j++)
			printf(" %c  ",  areaJogo[l][j]);	
		printf("\n");
	}
	
	printf("\n");
	
	mostraListaVivo();
	mostraListaMorto();	
}

//Pergunta ao usuario qual celula ele deseja inserir/excluir
void escolheVida(int cord[2])
{
	int i;
	int j;
	
	printf("Escolha uma celula para inserir/Excluir (-1 -1 para voltar):");
	scanf("%d %d", &i, &j);
	fClear();
	
	cord[0] = i;
	cord[1] = j;
}

//Pergunta ao usuario se ele deseja excluir a celula selecionada 
char mataCelula()
{
	char escolha;
	
	printf("Esta celula ja esta viva. Deseja exclui-la?[sim(s) nao(n)]: ");
	scanf("%c", &escolha);
	fClear();
	
	if(escolha != 's' && escolha != 'n')
	{
		mensagens(4);
	}
	
	return escolha;
}

//Pergunta ao usuario se ele deseja ver as celulas vizinhas mortas 
void escolheVerMorte()
{
	printf("Deseja ver as celulas vizinhas mortas? [sim(s) nao(n)] : ");
	scanf("%c", &verVizinhos);
	fClear();
	
	system("cls");
}

//Pergunta ao usuario se ele deseja mudar a velocidade ou ver o passo a passo
char velocidadePasso()
{
	char escolha;
	
	printf("Escolha uma das opcoes abaixo(0 para voltar)");
	printf("\n1 - Escolher Velocidade");
	printf("\n2 - Passo a Passo");
	printf("\n3 - Iniciar Simulacao");
	printf("\n");
	scanf("%c", &escolha);
	fClear();
	
	system("cls");
	
	return escolha;
}

//Pergunta ao usuario se ele deseja ver o passo a passo das simulacoes
void escolhePasso()
{
	printf("Deseja ver o passo a passo das simulacoes? [sim(s) nao(n)] : ");
	scanf("%c", &verPasso);
	fClear();
	
	system("cls");
}

//Pergunta ao usuario quantas simulacoes ele deseja que aconteca
int numEvolucao()
{
	unsigned int num;
	
	printf("Quantas simulacoes deseja executar? (0 para sair)\n");
	scanf("%d", &num);
	fClear();
	
	return num;
}

//Informa as celulas que foram geradas na geracao atual
void mostraListaVivo()
{
	tipoCel *aux;
	aux = pVivo;
	

	printf("Lista de vivos: ");
	
	if(totVivo > 0)
	{
		while (aux->next != NULL)
		{
			printf("%d,%d  ", aux->lin, aux->col);
			aux = aux->next;
		}
		printf("%d,%d\n\n", aux->lin, aux->col);
	}
	printf("\n");
}

//Informa as celulas que foram mortas na geracao atual 
void mostraListaMorto()
{
	tipoCel *aux;
	aux = pMorto;
	
	printf("Lista de vizinhas mortas: ");
	
	if(totMorto > 0)
	{
		while (aux->next != NULL)
		{
			printf("%d,%d  ", aux->lin, aux->col);
			aux = aux->next;
		}
		printf("%d,%d\n\n", aux->lin, aux->col);
	}
	printf("\n");
}

//Informa as celulas que serao geradas na proxima geracao
void mostraListaVivoProx()
{
	tipoCel *aux;
	aux = pVivoProx;
	
	printf("Lista de vivo da proxima geracao: ");
	
	if(totVivoProx > 0)
	{
		while (aux->next != NULL)
		{
			printf("%d,%d	", aux->lin, aux->col);
			aux = aux->next;
		}
		printf("%d,%d\n\n", aux->lin, aux->col);
	}
	printf("\n");
}

//Pergunta ao usuario se ele deseja excluir as geracoes salvas
char salvaGeracao()
{
	char escolha;
	
	printf("Deseja salvar a geracao atual? [sim(s) nao(n)] : ");
	scanf("%c", &escolha);
	fClear();
	system("cls");
	
	return escolha;
}

//Pergunta ao usuario se ele deseja excluir as geracoes salvas
int excluirGeracoes()
{
	char excluir;
	int escolha = 1;
	
	do
	{
		printf("Deseja excluir as geracoes salvas? [sim(s) nao(n)] : ");
		scanf("%c", &excluir);
		fClear();
		system("cls");	
	}while(verificaSimOuNao(excluir) == 0);
	
	if(excluir == 'n')
	{
		escolha = 0;
	}
	
	return escolha;
}

//Mensagens que serao mostradas para o usuario
void mensagens(int op)
{
	switch(op)
	{
		case 1:
		{
			printf("O tamanho escolhido e' invalido\n");
			break;
		}
		case 2:
		{
			printf("\nA celula escolhida ja esta viva\n\n");
			break;
		}
		case 3:
		{
			printf("\nA celula escolhida ja esta morta\n\n");
			break;
		}
		case 4:
		{
			printf("\nOpcao invalida\n\n");
			break;
		}
		case 5:
		{
			printf("\nCoordenada invalida\n\n");
			break;
		}
		case 6:
		{
			printf("\nA simulacao parou, pois nao ha' mais celulas vivas\n\n");
			break;
		}
		case 7:
		{
			printf("Velocidade invalida\n\n");
			break;
		}
		case 8:
		{
			printf("\nA simulacao nao pode ocorrer, pois nenhuma celula esta viva\n\n");
			break;
		}
		case 9:
		{
			printf("\nERRO: O arquivo CONFIG_INIC nao pode ser aberto para gravacao\n");
			break;
		}
		case 10:
		{
			printf("\nErro na gravacao do arquivo CONFIG_INIC\n");
			break;
		}
		case 11:
		{
			printf("\nConfiguracao Gravada\n");
			break;
		}
		case 12:
		{
			printf("\nNao existe configuracao a recuperar\n");
			break;
		}
		case 13:
		{
			printf("\nO deposito de geracoes iniciais esta vazio\n");
			break;
		}
		case 14:
		{
			printf("\nERRO: O arquivo CONFIG_INIC nao pode ser removido\n");
			break;
		}
		case 15:
		{
			printf("\nO arquivo CONFIG_INIC foi removido OK\n");
			break;
		}
		case 16:
		{
			printf("\nGeracao %d Carregada\n\n", ultRecup + 1);
			break;
		}
	}
}
