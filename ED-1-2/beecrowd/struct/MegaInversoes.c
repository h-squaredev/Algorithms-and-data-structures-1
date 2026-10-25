#include <stdio.h>

typedef struct {
    int valor;
    int indice;
} Elemento;

Elemento v[100000], aux[100000];
long long maiorEsq[100000];
long long menorDir[100000];

void mergeSort(int ini, int fim) {
    if (ini >= fim) return;

    int meio = (ini + fim) / 2;
    mergeSort(ini, meio);
    mergeSort(meio + 1, fim);

    int i = ini, j = meio + 1, k = ini;

    while (i <= meio || j <= fim) {
        if (j > fim || (i <= meio && v[i].valor <= v[j].valor)) {
            menorDir[v[i].indice] += j - (meio + 1);
            aux[k++] = v[i++];
        } else {
            maiorEsq[v[j].indice] += meio - i + 1;
            aux[k++] = v[j++];
        }
    }

    for (k = ini; k <= fim; k++)
        v[k] = aux[k];
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i].valor);
        v[i].indice = i;
        maiorEsq[i] = 0;
        menorDir[i] = 0;
    }

    mergeSort(0, n - 1);

    long long total = 0;
    for (int i = 0; i < n; i++)
        total += maiorEsq[i] * menorDir[i];

    printf("%lld\n", total);
    return 0;
}