#include <stdio.h>

typedef struct {
    int grupo;
} Segmento;

int main() {
    int n, l, x, y;
    Segmento seg[101];

    scanf("%d %d", &n, &l);

    /* no início, cada segmento está sozinho no seu grupo */
    for (int i = 1; i <= n; i++)
        seg[i].grupo = i;

    for (int i = 0; i < l; i++) {
        scanf("%d %d", &x, &y);

        int antigo = seg[y].grupo;
        int novo = seg[x].grupo;

        /* todo mundo do grupo de Y passa para o grupo de X */
        for (int j = 1; j <= n; j++) {
            if (seg[j].grupo == antigo)
                seg[j].grupo = novo;
        }
    }

    /* está completo se todos ficaram no mesmo grupo */
    int completo = 1;
    for (int i = 2; i <= n; i++) {
        if (seg[i].grupo != seg[1].grupo) {
            completo = 0;
            break;
        }
    }

    if (completo)
        printf("COMPLETO\n");
    else
        printf("INCOMPLETO\n");

    return 0;
}