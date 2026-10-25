#include <stdio.h>

int main() {
    int n;
    long long t;

    // Lê o número de casos de teste
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        // Lê a quantidade de anos transcorridos
        scanf("%lld", &t);

        // Verifica se o ano é Antes ou Depois de Cristo
        if (t < 2015) {
            printf("%lld D.C.\n", 2015 - t);
        } else {
            // Soma-se 1 porque não existe o ano 0
            printf("%lld A.C.\n", t - 2015 + 1);
        }
    }

    return 0;
}