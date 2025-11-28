/*JVIDA2-EJPV-Controller.cpp - Projeto Jogo da Vida - Etapa FINAL
13/11/2024 - Grupo: EJPV
-Enzo Marasca Soranz Saragiotto
-Joao Pedro Pedott Rocha
-Pedro Paulo Martins de Oliveira Tonon
-Vinicius Queiroz e Silva Soares
*/

#include "JVIDA2-EJPV-Controller.h"
#include "JVIDA2-EJPV-View.h"
#include "JVIDA2-EJPV-Model.h"

//Permite o jogo a ser jogado
void jogoGeral()
{	
	int opcao = 0;
	char simulac;

	escolheVerificaTamanho();
	
	do
	{
		mostraAreaJogo();
		opcao = menu2();
		switch(opcao)
		{
			case 1:				//Limpa Mapa
			{
				limpaMatriz();
				deletaTudo();
				vizinhasMortas();
				criaListaVivo();
				criaListaMorto();
				break;
			}
			case 2:				//Da vida ou mata celulas
			{
				vidaOuMorte();
				break;
			}
			case 3:				//Escolhe se mostra ou nao as celulas vizinhas mortas
			{
				do
				{
					escolheVerMorte();
				}while(verificaSimOuNao(verVizinhos) == 0);
				break;
			}
			case 4:				//Mostra o tutorial para o usuario
			{
				tutoras();
				break;
			}
			case 5:				//Inicia a simulacao de geracoes
			{
				do
				{
					simulac = velocidadeSimulacao();
				}while(simulac != '0' && simulac != '3');
				if(simulac == '3')
				{
					simulacao();
				}
				break;
			}
			case 6:				//Salvar uma geracao inicial  
			{
				salvaCelulas();
				break;
			}
			case 7:			//Carregar uma geracao inicial salva
			{
				carregaConfiguracao();
				recuperaCelulas();
				break;
			}
			case 8:			//Limpar o cadastro de geracoes iniciais salvas (n geracoes)
			{
				limpaGeracao();
				break;
			}
		}
	}while(opcao != 0);
}

//Reinicia a matriz principal
void limpaMatriz()
{
	for(int i = 0; i <= tamanho; i++)
	{
		for(int j = 0; j <= tamanho; j++)
		{
			areaJogo[i][j] = '.';
		}
	}
}

//Conta quantas celulas estao vivas
int contaCelulasVivas()
{
	int cont = 0;
	
	for(int i = 0; i <= tamanho; i++)
	{
		for(int j = 0; j <= tamanho; j++)
		{
			if(areaJogo[i][j] == 'O')
			{
				cont++;
			}
		}
	}
	
	return cont;
}

//Chama as funcoes para escolher e verificar o tamanho
void escolheVerificaTamanho()
{
	int ok = 1;

	do
	{
		ok = 1;
		
		tamanhoDoJogo();
		if(verificaTamanho(tamanho + 1) != 1)
		{
			mensagens(1);
			ok = 0;
		}
			
	}while(ok != 1);		
	
}

//Verifica se o tamanho escolhido pelo usuario e' valido
int verificaTamanho(int ta)
{
	int ok = 1;
	
	if(ta < 10 || ta > 50)
	{
		ok = 0;
	}
		
	return ok;
}

//Verifica se as coordenadas escolhidas sao validas
int verificaCoordenadas(int a, int b)
{
	int ok = 1;
	
	if(a < 0 || a > tamanho)
	{
		ok = 0;
	}
	if(b < 0 || b > tamanho)
	{
		ok = 0;
	}
	
	if(ok == 0)
	{
		mensagens(5);
	}
		
	return ok;
}

//Limpa o buffer do teclado
void fClear()
{
	char c;
	while((c = fgetc(stdin)) != EOF && c!='\n'){}
}

//Altera a velocidade da simulacao ou mostra o passo a passo conforme a escolha do usuario
char velocidadeSimulacao()
{
	int validadeEscolha = 0;
	int validadePassoaPasso = 0;
	char escolha;
	
	do
	{
		escolha = velocidadePasso();
	}while(verificaEscolhaVelocidade(escolha) == 0);
	
	if(escolha != '0' && escolha != '3')
	{
		if(escolha == '1')
		{
			do
			{
				escolheVelocidade();
			}while(verificaVelocidade() == 0);
		}
		else
		{
			do
			{
					escolhePasso();
			}while(verificaSimOuNao(verPasso) == 0);
		}
	}
	
	return escolha;
}	

//Verifica se o usuario escolheu 1 ou 2
int verificaEscolhaVelocidade(char es)
{
	int validade = 1;
	
	if(es != '1' && es != '2' && es != '0' && es != '3')
	{
		mensagens(4);
		validade = 0;
	}
	
	return validade;
}

//Verifica se a velocidade escolhida e' valida
int verificaVelocidade()
{
	int ok = 1;
	
	if(velocidade < 0)
	{
		mensagens(7);
		velocidade = 1;
		ok = 0;
	}
	
	return ok;
}
			
//Insere ou exclui uma celula
void vidaOuMorte()
{
	int cord[2];
	int i, j;
	int verCord;
	int sair = 0;
	char excluir;
	
	do
	{
		verCord = 0;
		
		while(verCord == 0)
		{
			mostraAreaJogo();
			escolheVida(cord);
			i = cord[0];
			j = cord[1];
			
			if(i != -1 && j != -1)
			{
				verCord = verificaCoordenadas(i, j);
			}
			else
			{
				verCord = 1;
				sair = 1;
			}
		}
		if(sair != 1)
		{
			if(areaJogo[i][j] == 'O')
			{
				excluir = mataCelula();
				if(excluir == 's')
				{
					areaJogo[i][j] = '.';
					deletaTudo();
					vizinhasMortas();
					criaListaVivo();
					criaListaMorto();
				}
			}
			else
			{
				areaJogo[i][j] = 'O';
				deletaTudo();
				vizinhasMortas();
				criaListaVivo();
				criaListaMorto();
			}
		}
	}while(i != -1 && j != -1);
	
	system("cls");
}

//Verifica se o usuario escolheu sim ou nao
int verificaSimOuNao(char teste)
{
	int ok = 1;
	
	if(teste != 's' && teste != 'n')
	{
		mensagens(4);
		ok = 0;
	}
	
	return ok;
}

//Coloca o simbolo + onde for necessario 
void vizinhasMortas()
{
	int iCima, jEsq, iBaix, jDir; 
	
	for(int i=0; i<=tamanho; i++)
	{
		for(int j=0; j<=tamanho; j++)
		{
			if(areaJogo[i][j] == 'O')
			{
				iCima = i-1;
				jEsq = j-1;
				iBaix = i+1;
				jDir = j+1;
				if(iCima >= 0 && jEsq >= 0 && areaJogo[iCima][jEsq] != 'O')
				{
					areaJogo[iCima][jEsq] = '+';	
				}
				if(iCima >= 0 && jDir <= tamanho && areaJogo[iCima][jDir] != 'O')
				{
					areaJogo[iCima][jDir] = '+';	
				}
				if(iBaix <= tamanho && jEsq >= 0 && areaJogo[iBaix][jEsq] !='O')
				{
					areaJogo[iBaix][jEsq] = '+';	
				}
				if(iBaix <= tamanho && jDir <= tamanho && areaJogo[iBaix][jDir] != 'O')
				{
					areaJogo[iBaix][jDir] = '+';
				}
				if(iCima >= 0 && areaJogo[iCima][j] != 'O')
				{
					areaJogo[iCima][j] = '+';
				}
				if(jEsq >= 0 && areaJogo[i][jEsq] != 'O')
				{
					areaJogo[i][jEsq] = '+';
				}
				if(iBaix <= tamanho && areaJogo[iBaix][j] != 'O')
				{
					areaJogo[iBaix][j] = '+';	
				}
				if(jDir <= tamanho && areaJogo[i][jDir] != 'O')
				{
					areaJogo[i][jDir] = '+';	
				}
			}
		}
	}	
}

//Transforma o simbolo + em . 
void escondeVizinhasMortas()
{
	for(int i = 0; i <= tamanho; i++)
	{
		for(int j = 0; j <= tamanho; j++)
		{
			if(areaJogo[i][j] == '+')
			{
				areaJogo[i][j] = '.';
			}
		}
	}
}

//Aplica um atraso na mudanca das geracoes
void delay(float atraso)
{
	time_t it1, it2;
	it1 = time(NULL);
	it2 = it1;
	
	while(difftime(it2, it1) < atraso)
	{
		it2 = time(NULL);
	}		
}

//Gera novas celulas nas coordenas possiveis
void evolucao()
{
	int cont;
	int iCima, jEsq, iBaix, jDir; 
	
	deletaTudo();
	vizinhasMortas();
	
	for(int i=0; i<=tamanho; i++)
	{
		for(int j=0; j<=tamanho; j++)
		{
			cont = 0;
			if(areaJogo[i][j] == 'O' || areaJogo[i][j] == '+')
			{
				iCima = i-1;
				jEsq = j-1;
				iBaix = i+1;
				jDir = j+1;
				if(iCima >= 0 && jEsq >= 0 && areaJogo[iCima][jEsq] == 'O')
				{
					cont++;	
				}
				if(iCima >= 0 && jDir <= tamanho && areaJogo[iCima][jDir] == 'O')
				{
					cont++;	
				}
				if(iBaix <= tamanho && jEsq >= 0 && areaJogo[iBaix][jEsq] =='O')
				{
					cont++;	
				}
				if(iBaix <= tamanho && jDir <= tamanho && areaJogo[iBaix][jDir] == 'O')
				{
					cont++;
				}
				if(iCima >= 0 && areaJogo[iCima][j] == 'O')
				{
					cont++;
				}
				if(jEsq >= 0 && areaJogo[i][jEsq] == 'O')
				{
					cont++;
				}
				if(iBaix <= tamanho && areaJogo[iBaix][j] == 'O')
				{
					cont++;	
				}
				if(jDir <= tamanho && areaJogo[i][jDir] == 'O')
				{
					cont++;	                                   
				}
				if (cont == 3)
				{
					carregaVivoProx(i, j);
				}
				else if(cont == 2 && areaJogo[i][j] == 'O')
				{
					carregaVivoProx(i, j);
				}
			}
		}
	}
	transfereListaProx();
	criaListaVivo();
	vizinhasMortas();
	criaListaMorto();
}

//Insere na lista principal as celulas da proxima geracao
void transfereListaProx()
{
	limpaMatriz();
	
	int i, j;
	tipoCel *aux;
	
	aux = pVivoProx;
	
	if(totVivoProx > 0)
	{
		while (aux->next != NULL)
		{
			i = aux->lin;
			j = aux->col;
			areaJogo[i][j] = 'O';
			aux = aux->next;
		}
		i = aux->lin;
		j = aux->col;
		areaJogo[i][j] = 'O';
	}
}

//Insere na lista principal as celulas da proxima geracao
void transfereListaVivo()
{
	limpaMatriz();
	
	int i, j;
	tipoCel *aux;
	
	aux = pVivo;
	
	if(totVivo > 0)
	{
		while (aux->next != NULL)
		{
			i = aux->lin;
			j = aux->col;
			areaJogo[i][j] = 'O';
			aux = aux->next;
		}
		i = aux->lin;
		j = aux->col;
		areaJogo[i][j] = 'O';
	}
}

//Cria a lista das celulas vivas
void criaListaVivo()
{
	for(int i = 0; i <= tamanho; i++)
	{
		for(int j = 0; j<=tamanho; j++)
		{
			if(areaJogo[i][j] == 'O')
			{
				carregaVivo(i, j);
			}
		}
	}
}

//Cria a lista das celulas mortas
void criaListaMorto()
{
	for(int i = 0; i <= tamanho; i++)
	{
		for(int j = 0; j<=tamanho; j++)
		{
			if(areaJogo[i][j] == '+')
			{
				carregaMorto(i, j);
			}
		}
	}
}

//Reinicia as listas dinamicas e os contadores de celuas vivas, mortas, e as da proxima geracao
void deletaTudo()
{
	if(totVivo > 0)
	{
		free(pVivo);
		totVivo = 0;
	}
	if(totMorto > 0)
	{
		free(pMorto);
		totMorto = 0;
	}
	if(totVivoProx > 0)
	{
		free(pVivoProx);
		totVivoProx = 0;
	}
}

//Verifica se a quantidade de simulacoes e' valida
int verificaNumSimulacoes(int num)
{
	int var = 0;
	
	if(num > 0 && num <= 400000000)
	{
		var = 1;
	}
	
	return var;
}

//Realiza a mudanca de geracoes do jogo
void simulacao()
{
	int verificaSimu = 0; 
	int simulacoes = 0;
	int i = 1;
	int vivas = 0;
	
	vivas = contaCelulasVivas();
	if(vivas > 0)
	{
		mostraAreaJogo();
		simulacoes = numEvolucao();
		verificaSimu = verificaNumSimulacoes(simulacoes);
		
		if(verificaSimu == 1)
		{
			for(int i = 1; i <= simulacoes; i++)
			{
				if(verPasso == 'n')
				{
					system("cls");
				}
				evolucao();
				mostraAreaJogo();
				delay(velocidade);
			}
			
			system("pause");
		}
		else
		{
			mensagens(4);
		}
		system("cls");
	}
	else 
	{
		mensagens(8);
	}
}

//Adiciona as coordenas das celulas que estao vivas em uma lista ligada
void carregaVivo(int i, int j)
{
	tipoCel *aux = (tipoCel *)malloc(sizeof(tipoCel));
	
	if(aux == NULL)
	{
		mensagens(6); 
		return;
	}
	else
	{

		aux->lin = i;
		aux->col = j;
		
		if(totVivo == 0)
		{
			pVivo = aux;
			pVivo->next = NULL;
		}
		else
		{
			aux->next = pVivo;
			pVivo = aux;
		}
		totVivo++;
	}
}

//Adiciona as coordenas das celulas que estao mortas em uma lista ligada
void carregaMorto(int i, int j)
{
	tipoCel *aux = (tipoCel *)malloc(sizeof(tipoCel));
	
	if(aux == NULL)
	{
		mensagens(6); 
		return;
	}
	else
	{
		aux->lin = i;
		aux->col = j;
		
		if(totMorto == 0)
		{
			pMorto = aux;
			pMorto->next = NULL;
		}
		else
		{
			aux->next = pMorto;
			pMorto = aux;
		}
		totMorto++;
	}
}

///Adiciona as coordenas das celulas que serao geradas na proxima simulacao na lista ligada
void carregaVivoProx(int i, int j)
{
	tipoCel *aux = (tipoCel *)malloc(sizeof(tipoCel));
	
	if(aux == NULL)
	{
		mensagens(6);
		return;
	}
	else
	{
		aux->lin = i;
		aux->col = j;
		
		if(totVivoProx == 0)
		{
			pVivoProx = aux;
			pVivoProx->next = NULL;
		}
		else
		{
			aux->next = pVivoProx;
			pVivoProx = aux;
		}
		totVivoProx++;
	}
}

//Pergunta ao usuario se ele deseja salvar a geracao e salva a geracao
void salvaCelulas()
{
	char escolha;
	
	do
	{
		escolha = salvaGeracao();
	}while(verificaSimOuNao(escolha) == 0);
	
	if(escolha == 's')
	{
		gravaCelulas();
	}
}

//Grava a lista de celulas vivas
void gravaCelulas()
{
	int k, i, ni;
	k = qtdConfig;
	
	if(totVivo != 0)
	{
		tipoCel *aux;
		aux = pVivo;
		ni = 0;
		
		do
		{
			Lvivo.L[ni].lin = aux->lin;
			Lvivo.L[ni].col = aux->col;
			ni++;
			aux = aux->next;
		}while(aux != NULL);
		Lvivo.cont = totVivo;
		
		LConfig[k].TL = Lvivo;
		
		FILE *fp;
		if((fp = fopen("CONFIG_INIC","w")) == NULL)
		{
			mensagens(8);
			return;
		}
		
		for(i = 0; i <= qtdConfig; i++)
		{
			if(fwrite(&LConfig[i], sizeof(tipoLista), 1 , fp) != 1)
			{
				mensagens(10);
				fclose(fp);
				return;
			}
		}
		fclose(fp);
		qtdConfig++;
		mensagens(11);
	}
	deletaTudo();
	vizinhasMortas();
	criaListaVivo();
	criaListaMorto();
}

//Carrega a configuracao de uma geracao salva
void carregaConfiguracao()
{
	int k;
	FILE *fp;
	
	if((fp = fopen("CONFIG_INIC", "r"))!=NULL)
	{
		qtdConfig = 0;
		k = 0;
		while(!feof(fp))
		{
			if(fread(&LConfig[k], sizeof(tipoLista), 1, fp)!=1)
			{
				fclose(fp);
				return;
			}
			qtdConfig++;
			k++;
		}
		fclose(fp);
	}
}

//Recupera as geracoes salvas no arquivo
void recuperaCelulas()
{
	int i, j, k, ni;
	deletaTudo();
	limpaMatriz();
	
	
	if(qtdConfig == 0)
	{
		mensagens(12);
	}
	else
	{
		k = ultRecup +1;
		if(k >= qtdConfig)
		{
			k = 0;
		}
		Lvivo = LConfig[k].TL;
		ultRecup = k;
		
		for(ni = 0; ni < Lvivo.cont; ni++)
		{
			carregaVivo(Lvivo.L[ni].lin, Lvivo.L[ni].col);
		}
	}
	
	transfereListaVivo();
	deletaTudo();
	vizinhasMortas();
	criaListaVivo();
	criaListaMorto();
	mensagens(16);
}

//Exclui todas as geracoes salvas
void limpaGeracao()
{
	if(qtdConfig > 0)
	{
		if(excluirGeracoes() == 0)
		{
			return;
		}
	}
	
	qtdConfig = 0;
	ultRecup = -1;
	deletaConfiguracao();
	mensagens(13);
}

//Ativamente deleta as geracoes salvas
void deletaConfiguracao()
{
	if(remove("CONFIG_INIC") != 0)
	{
		mensagens(14);
	}
	else
	{
		qtdConfig = 0;
		mensagens(15);
	}
}
