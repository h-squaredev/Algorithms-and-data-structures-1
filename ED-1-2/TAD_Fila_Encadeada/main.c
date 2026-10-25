#include <stdio.h>
#include "fila.h"

static int total = 0, falhas = 0;

static void check(int cond, const char *msg) {
    total++;
    if (!cond) falhas++;
    printf("  [%s] %s\n", cond ? "OK" : "FALHA", msg);
}

/* Verifica os invariantes da estrutura (inicio, fim, ultimo no, tamanho). */
static void invariantes(const Fila *f, int tamanho_esperado) {
    int contados = 0;
    const No *ultimo = NULL;
    for (const No *p = f->inicio; p != NULL; p = p->proximo) {
        contados++;
        ultimo = p;
    }
    check(f->tamanho == tamanho_esperado, "tamanho registrado esta correto");
    check(contados == f->tamanho, "tamanho bate com a contagem real dos nos");
    if (tamanho_esperado == 0) {
        check(f->inicio == NULL && f->fim == NULL,
              "fila vazia: inicio == NULL e fim == NULL");
    } else {
        check(f->fim == ultimo, "fim aponta para o ultimo no");
        check(f->fim->proximo == NULL, "ultimo no tem proximo == NULL");
    }
}

/* Remove um elemento e confere se e o esperado (ordem FIFO). */
static void remove_esperado(Fila *f, int esperado) {
    int v = -1;
    int ok = fila_desenfileirar(f, &v);
    printf("  desenfileirar -> ok=%d valor=%d (esperado %d)\n", ok, v, esperado);
    check(ok == 1 && v == esperado, "remocao respeitou a ordem FIFO");
}

int main(void) {
    Fila f;
    int v;

    printf("== 1. Inicializacao ==\n");
    fila_inicializar(&f);
    invariantes(&f, 0);

    printf("== 2. Fila vazia? ==\n");
    check(fila_vazia(&f) == 1, "fila_vazia retorna 1");

    printf("== 3. Tamanho de fila vazia ==\n");
    check(fila_tamanho(&f) == 0, "fila_tamanho retorna 0");

    printf("== 4. Desenfileirar fila vazia ==\n");
    v = 777;
    check(fila_desenfileirar(&f, &v) == 0, "retorna 0");
    check(v == 777, "*valor nao foi alterado");
    invariantes(&f, 0);

    printf("== 5. Consultar frente de fila vazia ==\n");
    v = 777;
    check(fila_frente(&f, &v) == 0, "retorna 0");
    check(v == 777, "*valor nao foi alterado");

    printf("== 6. Primeiro elemento em fila vazia ==\n");
    check(fila_enfileirar(&f, 10) == 1, "enfileirar(10) retorna 1");
    check(f.inicio == f.fim && f.inicio != NULL, "inicio == fim (um unico no)");
    check(fila_vazia(&f) == 0, "fila nao esta mais vazia");
    invariantes(&f, 1);

    printf("== 7. Varios elementos consecutivos ==\n");
    check(fila_enfileirar(&f, 20) == 1, "enfileirar(20)");
    invariantes(&f, 2);
    check(fila_enfileirar(&f, 30) == 1, "enfileirar(30)");
    invariantes(&f, 3);
    check(fila_enfileirar(&f, 40) == 1, "enfileirar(40)");
    invariantes(&f, 4);

    printf("== 8. Impressao apos insercoes ==\n");
    fila_imprimir(&f);

    printf("== 9. Frente sem remover ==\n");
    check(fila_frente(&f, &v) == 1 && v == 10, "frente = 10");
    check(fila_tamanho(&f) == 4, "tamanho continua 4");
    check(f.inicio->valor == 10, "inicio continua apontando para 10");

    printf("== 10. Remocao do primeiro ==\n");
    remove_esperado(&f, 10);
    invariantes(&f, 3);
    check(f.inicio->valor == 20, "inicio agora aponta para 20");

    printf("== 11. Elementos restantes mantem FIFO ==\n");
    fila_imprimir(&f);
    check(f.inicio->valor == 20 && f.inicio->proximo->valor == 30 &&
          f.fim->valor == 40, "ordem 20 -> 30 -> 40");

    printf("== 12. Insercao apos remocoes ==\n");
    check(fila_enfileirar(&f, 50) == 1, "enfileirar(50)");
    check(fila_enfileirar(&f, 60) == 1, "enfileirar(60)");
    invariantes(&f, 5);
    check(f.fim->valor == 60, "fim aponta para 60");
    fila_imprimir(&f);

    printf("== 13. Remover ate esvaziar ==\n");
    remove_esperado(&f, 20); invariantes(&f, 4);
    remove_esperado(&f, 30); invariantes(&f, 3);
    remove_esperado(&f, 40); invariantes(&f, 2);
    remove_esperado(&f, 50); invariantes(&f, 1);

    printf("== 14. Remocao do unico elemento ==\n");
    check(f.inicio == f.fim && f.inicio->valor == 60, "restou apenas o 60");
    remove_esperado(&f, 60);

    printf("== 15. Ponteiros apos remover o ultimo ==\n");
    check(f.inicio == NULL, "inicio == NULL");
    check(f.fim == NULL, "fim == NULL");
    check(fila_vazia(&f) == 1 && fila_tamanho(&f) == 0, "vazia e tamanho 0");
    invariantes(&f, 0);

    printf("== Reuso apos esvaziar ==\n");
    check(fila_enfileirar(&f, 1) == 1, "enfileirar(1)");
    check(fila_enfileirar(&f, 2) == 1, "enfileirar(2)");
    invariantes(&f, 2);
    fila_imprimir(&f);

    printf("== 16. Tamanho apos cada operacao (conferido acima) ==\n");
    check(fila_tamanho(&f) == 2, "tamanho final = 2");

    printf("== 17. Destruicao com elementos restantes ==\n");
    fila_destruir(&f);
    invariantes(&f, 0);
    check(fila_vazia(&f) == 1, "fila vazia apos destruir");
    fila_destruir(&f);
    check(fila_vazia(&f) == 1, "destruir duas vezes e seguro");

    printf("== 18. Parametros invalidos ==\n");
    v = 5;
    check(fila_enfileirar(NULL, 1) == 0, "enfileirar(NULL) retorna 0");
    check(fila_desenfileirar(NULL, &v) == 0, "desenfileirar(NULL, &v) retorna 0");
    check(fila_frente(NULL, &v) == 0, "frente(NULL, &v) retorna 0");
    fila_enfileirar(&f, 9);
    check(fila_desenfileirar(&f, NULL) == 0, "desenfileirar(&f, NULL) retorna 0");
    check(fila_frente(&f, NULL) == 0, "frente(&f, NULL) retorna 0");
    check(fila_tamanho(&f) == 1, "fila nao foi alterada pelos erros");
    check(fila_vazia(NULL) == 1, "fila_vazia(NULL) retorna 1");
    check(fila_tamanho(NULL) == 0, "fila_tamanho(NULL) retorna 0");
    fila_imprimir(NULL);
    fila_inicializar(NULL);
    fila_destruir(NULL);
    fila_destruir(&f);

    printf("\nResultado: %d verificacoes, %d falha(s)\n", total, falhas);
    return falhas == 0 ? 0 : 1;
}
