/* JVIDA2-EJPV-Model.h - Projeto Jogo da Vida - Etapa FINAL
13/11/2024 - Grupo: EJPV
- Enzo Marasca Soranz Saragiotto
- Joao Pedro Pedott Rocha
- Pedro Paulo Martins de Oliveira Tonon
- Vinicius Queiroz e Silva Soares
*/

#ifndef JVIDA2_EJPV_MODEL_H
#define JVIDA2_EJPV_MODEL_H

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

// Variáveis globais
extern float velocidade;             
extern int tamanho;                  
extern int totVivo;                  
extern int totMorto;                 
extern int totVivoProx;              
extern char areaJogo[51][51];        
extern char verVizinhos;             
extern char verPasso;                
extern int qtdConfig;                
extern int ultRecup;                 

// Tipos de dados
typedef struct cel {
    int lin, col;
    struct cel *next;
} tipoCel;

typedef struct c {
    int lin, col;
} Cel;

typedef struct list {
    int cont;
    Cel L[400];
} tipoLista;

struct arquivo {
    tipoLista TL;
};

// Variáveis globais do tipo definido
extern tipoCel *pVivo;
extern tipoCel *pMorto;
extern tipoCel *pVivoProx;
extern tipoLista Lvivo;
extern struct arquivo LConfig[50];

// Funções
void criaPosicoes();                 // Inicializa a matriz com pontinhos ('.')

#endif // JVIDA2_EJPV_MODEL_H
