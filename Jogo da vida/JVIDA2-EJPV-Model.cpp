/* JVIDA2-EJPV-Model.cpp - Projeto Jogo da Vida - Etapa FINAL
13/11/2024 - Grupo: EJPV
- Enzo Marasca Soranz Saragiotto
- Joao Pedro Pedott Rocha
- Pedro Paulo Martins de Oliveira Tonon
- Vinicius Queiroz e Silva Soares
*/

#include "JVIDA2-EJPV-Model.h"

// Definição das variáveis globais declaradas no Model.h
float velocidade = 1;
int tamanho = 0;
int totVivo = 0;
int totMorto = 0;
int totVivoProx = 0;
char areaJogo[51][51];
char verVizinhos = 'n';
char verPasso = 'n';
int qtdConfig = 0;
int ultRecup = -1;

tipoCel *pVivo = nullptr;
tipoCel *pMorto = nullptr;
tipoCel *pVivoProx = nullptr;
tipoLista Lvivo;
struct arquivo LConfig[50];

void criaPosicoes()
{
    for (int i = 0; i <= 50; i++) {
        for (int j = 0; j <= 50; j++) {
            areaJogo[i][j] = '.';
        }
    }
}
