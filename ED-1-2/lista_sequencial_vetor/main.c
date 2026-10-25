#include <stdio.h>
#include "lista.h"

int main() {
    Lista l;
    int valor_removido;
    
    printf("=== Teste 1: Inicializacao ===\n");
    lista_inicializar(&l);
    printf("Lista vazia? %s\n", lista_vazia(&l) ? "Sim" : "Nao");
    printf("Tamanho: %d\n\n", lista_tamanho(&l));
    
    printf("=== Teste 2: Insercao no final (10, 20, 30) ===\n");
    lista_inserir(&l, 0, 10);
    lista_inserir(&l, 1, 20);
    lista_inserir(&l, 2, 30);
    lista_imprimir(&l);
    printf("Tamanho atualizado: %d\n\n", lista_tamanho(&l));
    
    printf("=== Teste 3: Insercao no inicio (5) ===\n");
    lista_inserir(&l, 0, 5);
    lista_imprimir(&l);
    printf("\n");
    
    printf("=== Teste 4: Insercao no meio (15 entre 10 e 20) ===\n");
    lista_inserir(&l, 2, 15);
    lista_imprimir(&l);
    printf("\n");
    
    printf("=== Teste 5: Busca ===\n");
    int pos = lista_buscar(&l, 20);
    printf("Busca pelo valor 20 (existente): Posicao %d\n", pos);
    pos = lista_buscar(&l, 99);
    printf("Busca pelo valor 99 (inexistente): %d\n\n", pos);
    
    printf("=== Teste 6: Remocao no inicio ===\n");
    lista_remover(&l, 0, &valor_removido);
    printf("Valor removido: %d\n", valor_removido);
    lista_imprimir(&l);
    printf("\n");
    
    printf("=== Teste 7: Remocao no meio ===\n");
    lista_remover(&l, 1, &valor_removido);
    printf("Valor removido (esperado 15): %d\n", valor_removido);
    lista_imprimir(&l);
    printf("\n");
    
    printf("=== Teste 8: Remocao no final ===\n");
    lista_remover(&l, lista_tamanho(&l)-1, &valor_removido);
    printf("Valor removido: %d\n", valor_removido);
    lista_imprimir(&l);
    printf("\n");
    
    printf("=== Teste 9: Lista vazia ===\n");
    Lista l_vazia;
    lista_inicializar(&l_vazia);
    printf("Tentativa de remover em lista vazia: %s\n", lista_remover(&l_vazia, 0, &valor_removido) ? "Sucesso" : "Falha");
    printf("Busca em lista vazia: %d\n\n", lista_buscar(&l_vazia, 10));
    
    printf("=== Teste 10: Lista cheia ===\n");
    Lista l_cheia;
    lista_inicializar(&l_cheia);
    for(int i = 0; i < CAPACIDADE; i++) {
        lista_inserir(&l_cheia, i, i * 10);
    }
    printf("Lista totalmente preenchida: ");
    lista_imprimir(&l_cheia);
    printf("Tentativa de inserir mais um elemento (lista cheia): ");
    int res = lista_inserir(&l_cheia, CAPACIDADE, 999);
    printf("%s\n\n", res ? " Sucesso" : " Falha (Correto)");
    
    printf("=== Teste 11: Posicao invalida ===\n");
    printf("Tentativa de inserir na posicao -1: %s\n", lista_inserir(&l, -1, 50) ? "Sucesso" : "Falha");
    printf("Tentativa de remover na posicao tamanho + 1: %s\n", lista_remover(&l, lista_tamanho(&l) + 1, &valor_removido) ? "Sucesso" : "Falha");
    
    return 0;
}


/*
Respostas à Análise das Operações

Qual é a complexidade da operação de busca?
    É O(N) no pior caso. A busca linear num vetor precisa de percorrer todos os elementos se o valor procurado estiver na última posição ou se não existir na lista.
Qual é a complexidade da inserção?
    É O(N) no pior caso. Se inserir no início (índice 0), todos os elementos existentes precisarão de ser deslocados para a direita.
Qual é a complexidade da remoção?
    É O(N) no pior caso. Se remover o primeiro elemento, terá de deslocar todos os restantes elementos para a esquerda.
Por que a inserção e a remoção podem exigir o deslocamento de elementos?
    Não havendo alocação dinâmica e devendo manter a estrutura linear sem espaços vazios, é necessário "deslocar para o lado" os elementos para acomodar um novo, 
    ou "puxá-los de volta" para fechar o buraco deixado por uma remoção.
Qual é a diferença entre capacidade e tamanho da lista?
    A capacidade é o limite físico do vetor, definido em tempo de compilação (ex: #define CAPACIDADE 10), que indica o número máximo de itens que a estrutura suporta. 
    O tamanho é a quantidade lógica atual de elementos válidos e inseridos na lista num determinado momento
*/