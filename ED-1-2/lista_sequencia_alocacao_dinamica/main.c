#include <stdio.h>
#include "lista.h"

static int total = 0;
static int falhas = 0;

static void verificar(const char *descricao, int condicao){
    total++;
    if(condicao){
        printf("  [OK]   %s\n", descricao);
    } else {
        falhas++;
        printf("  [FALHA] %s\n", descricao);
    }
}

/* Compara o conteudo da lista com um vetor esperado */
static int igual(const Lista *l, const int *esperado, int n){
    if(lista_tamanho(l) != n) return 0;
    for(int i = 0; i < n; i++){
        if(l->dados[i] != esperado[i]) return 0;
    }
    return 1;
}

int main(void){
    Lista l;
    int removido = 0;

    printf("=== Teste 1: Inicializacao ===\n");
    lista_inicializar(&l);
    verificar("lista vazia", lista_vazia(&l) == 1);
    verificar("tamanho == 0", lista_tamanho(&l) == 0);
    verificar("capacidade == CAPACIDADE_INICIAL", lista_capacidade(&l) == CAPACIDADE_INICIAL);
    verificar("dados != NULL", l.dados != NULL);

    printf("\n=== Teste 2: Insercao no final (10 20 30) ===\n");
    lista_inserir(&l, 0, 10);
    lista_inserir(&l, 1, 20);
    lista_inserir(&l, 2, 30);
    lista_imprimir(&l);
    {
        int esp[] = {10, 20, 30};
        verificar("elementos corretos", igual(&l, esp, 3));
    }
    verificar("tamanho == 3", lista_tamanho(&l) == 3);
    verificar("capacidade continua 4", lista_capacidade(&l) == 4);

    printf("\n=== Teste 3: Insercao no inicio (5) ===\n");
    lista_inserir(&l, 0, 5);
    lista_imprimir(&l);
    {
        int esp[] = {5, 10, 20, 30};
        verificar("elementos deslocados corretamente", igual(&l, esp, 4));
    }

    printf("\n=== Teste 4: Insercao no meio (15 entre 10 e 20) ===\n");
    lista_inserir(&l, 2, 15); // lista cheia (4) -> cresce para 8
    lista_imprimir(&l);
    {
        int esp[] = {5, 10, 15, 20, 30};
        verificar("elementos deslocados corretamente", igual(&l, esp, 5));
    }
    lista_destruir(&l);

    printf("\n=== Teste 5: Crescimento automatico ===\n");
    lista_inicializar(&l);
    {
        int esp[] = {10, 20, 30, 40, 50, 60};
        for(int i = 0; i < 6; i++) lista_inserir(&l, i, esp[i]);
        lista_imprimir(&l);
        verificar("capacidade aumentou para 8", lista_capacidade(&l) == 8);
        verificar("tamanho == 6", lista_tamanho(&l) == 6);
        verificar("nenhum elemento perdido, ordem correta", igual(&l, esp, 6));
    }
    lista_destruir(&l);

    printf("\n=== Teste 6: Multiplos crescimentos (4 -> 8 -> 16 -> 32) ===\n");
    lista_inicializar(&l);
    {
        int ok = 1;
        int caps_esperadas[] = {4, 8, 16, 32};
        int idx = 0;
        for(int i = 0; i < 30; i++){
            if(!lista_inserir(&l, i, i * 10)) ok = 0;
            if(i + 1 == 5 || i + 1 == 9 || i + 1 == 17){
                idx++;
                verificar("capacidade apos crescimento", lista_capacidade(&l) == caps_esperadas[idx]);
            }
        }
        for(int i = 0; i < 30; i++){
            if(l.dados[i] != i * 10) ok = 0;
        }
        verificar("todas as insercoes tiveram sucesso e elementos corretos", ok);
        verificar("tamanho == 30", lista_tamanho(&l) == 30);
        verificar("capacidade final == 32", lista_capacidade(&l) == 32);
    }
    lista_destruir(&l);

    printf("\n=== Teste 7: Busca ===\n");
    lista_inicializar(&l);
    for(int i = 0; i < 6; i++) lista_inserir(&l, i, (i + 1) * 10); // 10..60
    verificar("busca de 40 (existente) -> posicao 3", lista_buscar(&l, 40) == 3);
    verificar("busca de 10 (primeiro) -> posicao 0", lista_buscar(&l, 10) == 0);
    verificar("busca de 60 (ultimo) -> posicao 5", lista_buscar(&l, 60) == 5);
    verificar("busca de 99 (inexistente) -> -1", lista_buscar(&l, 99) == -1);

    printf("\n=== Teste 8: Remocao no inicio ===\n");
    verificar("remocao com sucesso", lista_remover(&l, 0, &removido) == 1);
    verificar("valor removido == 10", removido == 10);
    {
        int esp[] = {20, 30, 40, 50, 60};
        verificar("demais elementos deslocados", igual(&l, esp, 5));
    }

    printf("\n=== Teste 9: Remocao no meio ===\n");
    verificar("remocao com sucesso", lista_remover(&l, 2, &removido) == 1);
    verificar("valor removido == 40", removido == 40);
    {
        int esp[] = {20, 30, 50, 60};
        verificar("resultado correto", igual(&l, esp, 4));
    }

    printf("\n=== Teste 10: Remocao no final ===\n");
    verificar("remocao com sucesso", lista_remover(&l, lista_tamanho(&l) - 1, &removido) == 1);
    verificar("valor removido == 60", removido == 60);
    {
        int esp[] = {20, 30, 50};
        verificar("resultado correto", igual(&l, esp, 3));
    }

    printf("\n=== Teste 11: Lista vazia ===\n");
    {
        Lista v;
        lista_inicializar(&v);
        verificar("remover em lista vazia falha", lista_remover(&v, 0, &removido) == 0);
        verificar("buscar em lista vazia retorna -1", lista_buscar(&v, 10) == -1);
        lista_destruir(&v);
    }

    printf("\n=== Teste 12: Posicao invalida ===\n");
    {
        int tam = lista_tamanho(&l);
        int esp[] = {20, 30, 50};
        verificar("inserir na posicao -1 falha", lista_inserir(&l, -1, 99) == 0);
        verificar("inserir na posicao tamanho + 1 falha", lista_inserir(&l, tam + 1, 99) == 0);
        verificar("remover na posicao -1 falha", lista_remover(&l, -1, &removido) == 0);
        verificar("remover na posicao tamanho falha", lista_remover(&l, tam, &removido) == 0);
        verificar("remover na posicao tamanho + 1 falha", lista_remover(&l, tam + 1, &removido) == 0);
        verificar("lista nao foi corrompida", igual(&l, esp, 3));
    }

    printf("\n=== Teste 13: Destruicao da lista ===\n");
    lista_destruir(&l);
    verificar("dados == NULL", l.dados == NULL);
    verificar("tamanho == 0", lista_tamanho(&l) == 0);
    verificar("capacidade == 0", lista_capacidade(&l) == 0);
    verificar("lista vazia", lista_vazia(&l) == 1);
    lista_destruir(&l); // segunda chamada nao deve causar erro (double free)

    printf("\n=== Resultado: %d/%d verificacoes passaram ===\n", total - falhas, total);
    return falhas == 0 ? 0 : 1;
}

/*
Respostas a Analise das Operacoes

1. Complexidade da busca?
   O(N) no pior caso: busca linear, percorre todos os elementos se o valor
   estiver na ultima posicao ou nao existir.

2. Insercao no inicio?
   O(N): todos os N elementos precisam ser deslocados uma posicao a direita.

3. Insercao no meio?
   O(N): em media N/2 elementos deslocados, o que continua sendo linear.

4. Insercao no final com espaco disponivel?
   O(1): nao ha deslocamento, apenas grava-se na posicao tamanho e incrementa-se.

5. O que acontece quando a insercao exige realloc()?
   A capacidade e dobrada. O realloc pode precisar alocar um novo bloco e
   copiar os N elementos existentes, custando O(N) nessa insercao. Se
   falhar (retorna NULL), a insercao e rejeitada e a lista original permanece
   valida, pois o resultado e guardado em um ponteiro temporario.

6. Complexidade da remocao?
   O(N) no pior caso (remover o primeiro elemento desloca todos os demais);
   O(1) se for o ultimo elemento.

7. Por que insercao e remocao podem exigir deslocamento?
   Os elementos ficam contiguos na memoria e sem "buracos". Para abrir espaco
   numa posicao e preciso empurrar os elementos seguintes para a direita; para
   fechar o espaco deixado por uma remocao, puxa-los para a esquerda.

8. Diferenca entre tamanho e capacidade?
   Tamanho e a quantidade de elementos validos armazenados no momento.
   Capacidade e o numero de posicoes alocadas no vetor (quantos elementos
   cabem antes de precisar crescer). Sempre tamanho <= capacidade.

9. Vantagem da lista dinamica sobre o vetor estatico?
   Nao tem limite fixo definido em tempo de compilacao: cresce conforme a
   necessidade, evitando tanto o desperdicio de memoria (vetor grande demais)
   quanto a rejeicao de insercoes por falta de espaco.

10. Funcao do realloc()?
    Redimensionar um bloco de memoria previamente alocado, preservando o
    conteudo existente (ate o menor dos dois tamanhos). Pode estender o bloco
    no lugar ou mover para outro local, copiando os dados.

11. Por que usar free()?
    Para devolver ao sistema a memoria alocada no heap, que nao e liberada
    automaticamente ao sair do escopo como as variaveis locais.

12. O que pode acontecer se a memoria nao for liberada?
    Vazamento de memoria (memory leak): o programa consome cada vez mais
    memoria, podendo degradar o sistema ou ser encerrado por falta de memoria,
    principalmente em programas de longa duracao.

13. Por que dobrar a capacidade e mais eficiente que crescer 1 posicao?
    Crescendo 1 a 1, quase toda insercao faria realloc (e possivel copia de
    N elementos), resultando em custo total O(N^2) para N insercoes. Dobrando,
    os reallocs ocorrem raramente (a cada potencia de 2), e o custo total
    de N insercoes fica O(N), ou seja, custo amortizado O(1) por insercao
    no final.
*/
