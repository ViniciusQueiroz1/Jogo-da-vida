/* JVIDA2-EJPV-View.h - Projeto Jogo da Vida - Etapa FINAL
13/11/2024 - Grupo: EJPV
- Enzo Marasca Soranz Saragiotto
- Joao Pedro Pedott Rocha
- Pedro Paulo Martins de Oliveira Tonon
- Vinicius Queiroz e Silva Soares
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#ifndef JVIDA2_EJPV_VIEW_H
#define JVIDA2_EJPV_VIEW_H

// Declaração de funções da camada de View (interface com o usuário)

void tamanhoDoJogo();                 // Permite que o usuário escolha o tamanho da matriz
int menu2();                          // Mostra o menu para o usuário
void tutoras();                       // Mostra o tutorial para o usuário
void escolheVelocidade();             // Pergunta ao usuário o delay entre gerações
void mostraAreaJogo();                // Mostra a área do jogo
void escolheVida(int cord[2]);        // Pergunta ao usuário qual célula ele deseja inserir/excluir
char mataCelula();                     // Pergunta ao usuário se ele deseja excluir a célula selecionada
void escolheVerMorte();               // Pergunta ao usuário se ele deseja ver as células vizinhas mortas
char velocidadePasso();               // Pergunta ao usuário se ele deseja mudar a velocidade ou ver o passo a passo
void escolhePasso();                  // Pergunta ao usuário se ele deseja ver o passo a passo das simulações
int numEvolucao();                    // Pergunta ao usuário quantas simulações ele deseja
void mostraListaVivo();               // Mostra a lista de células vivas na geração atual
void mostraListaMorto();              // Mostra a lista de células mortas na geração atual
void mostraListaVivoProx();           // Mostra a lista de células vivas na próxima geração
char salvaGeracao();                  // Pergunta ao usuário se ele deseja salvar a geração atual
int excluirGeracoes();                // Pergunta ao usuário se ele deseja excluir as gerações salvas
void mensagens(int op);               // Mostra mensagens para o usuário

#endif // JVIDA2_EJPV_VIEW_H
