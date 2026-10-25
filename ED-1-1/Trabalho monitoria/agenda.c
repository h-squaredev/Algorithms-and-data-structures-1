/*UFMT - Ciencia da Computacao
Estrutura de Dados 1
prof. Ivairton
Trabalho Monitoria - ED1
Data: 22/12/2025

Aluno: Humberto Henrique Castro Rocha - 202512722003

Organizador de Agenda de Compromissos

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // Biblioteca adicionada para usar true/false

typedef struct {
    char desc[55];
    int h_start;
    int h_end;
} ItemAgenda;

// Função de comparação renomeada
int organizaCronograma(const void *val1, const void *val2) {
    ItemAgenda *ev1 = (ItemAgenda *)val1;
    ItemAgenda *ev2 = (ItemAgenda *)val2;
    // Retorna negativo se ev1 começar antes de ev2
    return (ev1->h_start - ev2->h_start);
}

int main() {
    int num_eventos;
    
    if (scanf("%d", &num_eventos) != 1) {
        return 0;
    }

    ItemAgenda *meus_eventos = (ItemAgenda *) malloc(num_eventos * sizeof(ItemAgenda));

    for (int i = 0; i < num_eventos; i++) {
        scanf("%s %d %d", meus_eventos[i].desc, &meus_eventos[i].h_start, &meus_eventos[i].h_end);
    }

    // Ordena os eventos pelo horário de início
    qsort(meus_eventos, num_eventos, sizeof(ItemAgenda), organizaCronograma);

    bool existe_choque = false;
    
    // Lógica alterada: compara o atual (i) com o próximo (i+1)
    // Isso evita acessar índice -1 e muda a estrutura do loop
    for (int i = 0; i < num_eventos - 1; i++) {
        // Se o fim do evento atual for maior que o início do próximo, há choque
        if (meus_eventos[i].h_end > meus_eventos[i+1].h_start) {
            existe_choque = true;
            break;
        }
    }

    if (existe_choque) {
        printf("Conflito encontrado\n");
    } else {
        printf("Sem conflito\n"); 
        for (int j = 0; j < num_eventos; j++) {
            // %04d garante a formatação com zeros à esquerda se necessário
            printf("%s %04d %04d\n", meus_eventos[j].desc, meus_eventos[j].h_start, meus_eventos[j].h_end);
        }
    }

    free(meus_eventos);
    return 0;
}