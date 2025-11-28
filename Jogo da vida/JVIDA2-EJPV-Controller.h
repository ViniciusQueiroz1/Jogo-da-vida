/* JVIDA2-EJPV-Controller.h - Projeto Jogo da Vida - Etapa FINAL
13/11/2024 - Grupo: EJPV
- Enzo Marasca Soranz Saragiotto
- Joao Pedro Pedott Rocha
- Pedro Paulo Martins de Oliveira Tonon
- Vinicius Queiroz e Silva Soares
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#ifndef JVIDA2_EJPV_CONTROLLER_H
#define JVIDA2_EJPV_CONTROLLER_H

void jogoGeral();                       // Permite o jogo a ser jogado
void escolheVerificaTamanho();          // Chama as funções para escolher e verificar o tamanho
int verificaTamanho(int ta);            // Verifica se o tamanho escolhido é válido
int verificaCoordenadas(int a, int b);  // Verifica se as coordenadas são válidas
int verificaSimOuNao(char teste);       // Verifica se o usuário escolheu sim ou não
int verificaNumSimulacoes(int num);     // Verifica se a quantidade de simulações é válida
int verificaEscolhaVelocidade(char es); // Verifica se a velocidade escolhida é válida (1 ou 2)
int verificaVelocidade();               // Verifica se a velocidade é válida
void fClear();                          // Limpa o buffer do teclado
void vidaOuMorte();                     // Insere ou exclui uma célula
void vizinhasMortas();                   // Coloca "+" onde for necessário
void escondeVizinhasMortas();            // Transforma "+" em "."
void evolucao();                        // Gera novas células
void copiaAreaJogo();                   // Copia a matriz principal na auxiliar
void transfereAuxJogo();                // Copia a auxiliar na matriz principal
void simulacao();                       // Realiza a evolução do jogo
void limpaMatriz();                     // Reinicia a matriz principal
int contaCelulasVivas();                // Conta quantas células estão vivas
char velocidadeSimulacao();             // Ajusta velocidade da simulação ou passo a passo
void delay(float atraso);               // Aplica atraso entre gerações
void carregaVivo(int i, int j);         // Carrega células vivas
void carregaMorto(int i, int j);        // Carrega células mortas
void carregaVivoProx(int i, int j);     // Carrega células da próxima geração
void transfereListaProx();              // Passa lista da próxima geração para a atual
void transfereListaVivo();              // Passa lista de arquivo para a principal
void criaListaMorto();                  // Cria lista de células mortas
void criaListaVivo();                   // Cria lista de células vivas
void deletaTudo();                      // Reinicia listas e contadores
void carregaConfiguracao();             // Carrega configuração salva
void recuperaCelulas();                 // Recupera células salvas
void limpaGeracao();                    // Exclui todas as gerações salvas
void deletaConfiguracao();              // Deleta configurações
void gravaCelulas();                    // Grava células vivas atuais
void salvaCelulas();                    // Pergunta e salva geração atual

#endif // JVIDA2_EJPV_CONTROLLER_H
