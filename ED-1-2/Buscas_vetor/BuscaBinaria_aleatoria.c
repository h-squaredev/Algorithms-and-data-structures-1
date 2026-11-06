//IMPLEMENTACAO de uma BUSCA BINARIA aleatoria
#include <stdio.h>
#include <stdlib.h>

#define N 2000000
#define EXECUCOES 10

long long contador = 0;

int buscaBinaria(int v[], int n, int x){
    int esquerda = 0;
    int direita = n - 1;

    while (esquerda <= direita){
        int meio = (rand() % (direita - esquerda + 1)) + esquerda;
        
        contador++;
        if(v[meio] == x)
            return meio;
        contador++;
        if(v[meio] < x) 
            esquerda = meio + 1;
        else 
            direita = meio - 1;
    }
    return -1;
}

void imprimir(int v[], int n, int x, const char *descricao){
    long long total = 0, min = -1, max = 0;
    int pos = -1;
    for (int i = 0; i < EXECUCOES; i++){
        contador = 0;
        pos = buscaBinaria(v, n, x);
        total += contador;
        if (min < 0 || contador < min) min = contador;
        if (contador > max) max = contador;
    }
    printf("%-30s x=%-8d pos=%-8d media=%8.1f  min=%-4lld max=%lld\n",
           descricao, x, pos, (double) total / EXECUCOES, min, max);
}
 
void testar(int v[], int n, const char *titulo, int passo){
    printf("\n=== %s ===\n", titulo);
    // elementos existentes em diferentes posicoes
    int idx[] = {0, 1, n/4, n/2 - 1, n/2, 3*n/4, n - 2, n - 1};
    int ni = sizeof(idx) / sizeof(idx[0]);
    for (int i = 0; i < ni; i++)
        imprimir(v, n, v[idx[i]], "existente");
    // inexistentes
    imprimir(v, n, 0, "inexistente (menor que todos)");
    imprimir(v, n, v[n-1] + 1, "inexistente (maior que todos)");
    if (passo == 2){
        imprimir(v, n, v[0] + 1, "inexistente (entre elementos)");
        imprimir(v, n, v[n/2] + 1, "inexistente (entre elementos)");
        imprimir(v, n, v[n-1] - 1, "inexistente (entre elementos)");
    }
}
 
int main(int argc, char *argv[]){
    int *v = malloc(N * sizeof(int));
    if (!v) return 1;
 
    unsigned semente = (argc > 1) ? (unsigned) atoi(argv[1])
                                  : (unsigned) (size_t) v ^ (unsigned) (size_t) &argc;
    srand(semente);
    printf("BUSCA BINARIA ALEATORIA (%d execucoes por elemento, semente=%u)\n", EXECUCOES, semente);
 
    for (int i = 0; i < N; i++) v[i] = i + 1;        // 1, 2, 3, ..., 2000000
    testar(v, N, "Caso 1: consecutivos (passo 1)", 1);
 
    for (int i = 0; i < N; i++) v[i] = 2 * i + 1;    // 1, 3, 5, ..., 3999999
    testar(v, N, "Caso 2: passo 2 (impares)", 2);
 
    free(v);
    return 0;
}