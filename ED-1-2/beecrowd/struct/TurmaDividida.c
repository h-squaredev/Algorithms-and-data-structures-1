#include <stdio.h>

typedef struct {
    int altura;
    int esq;
    int dir;
    int nivel;
} Crianca;

Crianca arvore[250];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arvore[i].altura);
        arvore[i].esq = -1;
        arvore[i].dir = -1;
        arvore[i].nivel = 0;

        if (i == 0) continue;

        int atual = 0;
        int nivel = 1;

        while (1) {
            if (arvore[i].altura < arvore[atual].altura) {
                if (arvore[atual].esq == -1) {
                    arvore[atual].esq = i;
                    break;
                }
                atual = arvore[atual].esq;
            } else {
                if (arvore[atual].dir == -1) {
                    arvore[atual].dir = i;
                    break;
                }
                atual = arvore[atual].dir;
            }
            nivel++;
        }

        arvore[i].nivel = nivel;
    }

    int menor[250];
    int maxNivel = 0;

    for (int i = 0; i < 250; i++)
        menor[i] = 1000;

    for (int i = 0; i < n; i++) {
        int nv = arvore[i].nivel;
        if (arvore[i].altura < menor[nv])
            menor[nv] = arvore[i].altura;
        if (nv > maxNivel)
            maxNivel = nv;
    }

    for (int i = 0; i <= maxNivel; i++)
        printf("%d %d\n", i, menor[i]);

    return 0;
}