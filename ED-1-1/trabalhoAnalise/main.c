#include <stdio.h>
#include <stdlib.h>
#include <time.h>      
#include "estatica.h"
#include "dinamica.h"

#define NUM_ITERACOES 10      
#define TAMANHO 10000    

// serve para calcular o tempo em segundos
double calcularTempo(clock_t inicio, clock_t fim) {
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

// -- Oque acontece em um teste tambem acontece no outro, o tempo calculado, a logica de inserção --
// -- Todo o código que faz a inserção fica separado, depois são unidos na hora da compilação     --
// -- Esse foi o jeito q eu o Beto fizemos para dividir as tarefas, ficou mais complexo mas valeu --

void realizarTesteDesempenho() {
    clock_t t_inicio, t_fim;
    double tempo_acumulado_estatica = 0;
    double tempo_acumulado_simples = 0;
    double tempo_acumulado_dupla = 0;
    int i, k, valor, pos;

    srand(time(NULL));
    // ---------------------------------------------------------
    // |      TESTE LISTA ESTATICA                             |
    // ---------------------------------------------------------
    for (k = 0; k < NUM_ITERACOES; k++) {
        ListaEstatica lista;
        inicializaLista(&lista);

        t_inicio = clock(); //salva o tempo de inicio

        for (i = 0; i < TAMANHO; i++) {
            valor = rand() % 10000; 

            // primeiro ele coloca no inicio, depois no meio e depois no fim da lista

            if (i < 3333) { 
                insereInicioEstatica(&lista, valor); //chama a funcao que esta lá em lista_estatica.c
            } else if (i < 6666) { 
                insereFimEstatica(&lista, valor); //chama a funcao que esta lá em lista_estatica.c
            } else { 
                pos = rand() % (i + 1);
                inserePosicaoEstatica(&lista, valor, pos); //chama a funcao que esta lá em lista_estatica.c -> a MESMA coisa pros outros teste, oq muda é que vai chamar a funcao que esta em listadinamica.c
            }
        }
        t_fim = clock(); //salva o tempo de fim
        tempo_acumulado_estatica += calcularTempo(t_inicio, t_fim); //calcula o tempo gasto
    }

    // ---------------------------------------------------------
    // |      TESTE DINAMICA SIMPLES                           |
    // ---------------------------------------------------------
    for (k = 0; k < NUM_ITERACOES; k++) {
        no *listaSimples = NULL; 
        
        t_inicio = clock();

        for (i = 0; i < TAMANHO; i++) {
            valor = rand() % 10000;

            if (i < 3333) {
                inserirSimples(&listaSimples, valor, 0, 0); 
            } else if (i < 6666) {
                inserirSimples(&listaSimples, valor, i, 0); 
            } else {
                pos = rand() % (i + 1);
                inserirSimples(&listaSimples, valor, pos, 0);
            }
        }
        t_fim = clock();
        tempo_acumulado_simples += calcularTempo(t_inicio, t_fim);
        
        removerSimples(listaSimples); 
    }

    // ---------------------------------------------------------
    // |   TESTE DINAMICA DUPLA                                |
    // ---------------------------------------------------------
    for (k = 0; k < NUM_ITERACOES; k++) {
        noDuplo *listaDupla = NULL; 

        t_inicio = clock();

        for (i = 0; i < TAMANHO; i++) {
            valor = rand() % 10000;

            if (i < 3333) {
                inserirDupla(&listaDupla, valor, 0);
            } else if (i < 6666) {
                inserirDupla(&listaDupla, valor, i);
            } else {
                pos = rand() % (i + 1);
                inserirDupla(&listaDupla, valor, pos);
            }
        }
        t_fim = clock();
        tempo_acumulado_dupla += calcularTempo(t_inicio, t_fim);

        removerDupla(listaDupla);
    }

    printf("media do tempo estatica: %f segundos\n", tempo_acumulado_estatica / NUM_ITERACOES);
    printf("media do tempo dinamica simples: %f segundos\n", tempo_acumulado_simples / NUM_ITERACOES);
    printf("media do tempo dinamica dupla %f segundos\n", tempo_acumulado_dupla / NUM_ITERACOES);
}

int main() {
    realizarTesteDesempenho();
    return 0;
}