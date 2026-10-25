/*UFMT - Ciencia da Computacao
Estrutura de Dados 1
prof. Ivairton
Trabalho Monitoria - ED1
Data: 22/12/2025

Aluno: Humberto Henrique Castro Rocha - 202512722003

Sistema de Análise Acadêmica
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura renomeada e campos de notas agrupados
typedef struct {
    char id_nome[51];
    int cod_matricula;
    float notas[3];
    float media_final;
    int qtd_faltas;
} Discente;

// Comparador para o ranking principal
int ordenaPorDesempenho(const void *x, const void *y) {
    Discente *d1 = (Discente *)x;
    Discente *d2 = (Discente *)y;
    
    // Se as médias forem diferentes, a maior vem primeiro
    if (d1->media_final != d2->media_final) {
        return (d1->media_final > d2->media_final) ? -1 : 1;
    }
    // Critério de desempate: quem tem menos faltas vem primeiro (ordem crescente)
    return d1->qtd_faltas - d2->qtd_faltas;
}

// Comparador para a lista de risco
int ordenaPorFaltasDecrescente(const void *x, const void *y) {
    int f1 = ((Discente *)x)->qtd_faltas;
    int f2 = ((Discente *)y)->qtd_faltas;
    // Mais faltas primeiro
    return f2 - f1;
}

int main() {
    int qtd;
    // Verificação de leitura mantida
    if (scanf("%d", &qtd) != 1) return 0;

    Discente *turma = (Discente *) malloc(qtd * sizeof(Discente));
    Discente *recuperacao = (Discente *) malloc(qtd * sizeof(Discente));
    int total_recuperacao = 0;

    for (int i = 0; i < qtd; i++) {
        // Leitura adaptada para o vetor de notas
        scanf("%s %d %f %f %f %d", 
              turma[i].id_nome, 
              &turma[i].cod_matricula, 
              &turma[i].notas[0], 
              &turma[i].notas[1], 
              &turma[i].notas[2], 
              &turma[i].qtd_faltas);
        
        // Cálculo da média
        float soma = turma[i].notas[0] + turma[i].notas[1] + turma[i].notas[2];
        turma[i].media_final = soma / 3.0f;

        // Verifica critério de risco (< 6.0)
        if (turma[i].media_final < 6.0f) {
            recuperacao[total_recuperacao] = turma[i];
            total_recuperacao++;
        }
    }

    // Ordenação e exibição do Ranking Geral
    qsort(turma, qtd, sizeof(Discente), ordenaPorDesempenho);
    
    printf("RANKING GERAL\n\n"); 
    for (int i = 0; i < qtd; i++) {
        printf("%s %d %.2f %d\n", 
               turma[i].id_nome, 
               turma[i].cod_matricula, 
               turma[i].media_final, 
               turma[i].qtd_faltas);
    }

    // Ordenação e exibição da Lista de Risco (se houver)
    if (total_recuperacao > 0) {
        qsort(recuperacao, total_recuperacao, sizeof(Discente), ordenaPorFaltasDecrescente);
        printf("LISTA DE RISCO\n");
        for (int k = 0; k < total_recuperacao; k++) {
            printf("%s %d %.2f %d\n", 
                   recuperacao[k].id_nome, 
                   recuperacao[k].cod_matricula, 
                   recuperacao[k].media_final, 
                   recuperacao[k].qtd_faltas);
        }
    }

    // Liberação de memória
    free(turma);
    free(recuperacao);
    
    return 0;
}