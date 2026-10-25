#include <stdio.h>

typedef struct {
    char nome[13];
} Participante;

int main() {
    int n;
    double l, q;
    Participante roda[10];

    scanf("%d %lf %lf", &n, &l, &q);

    for (int i = 0; i < n; i++)
        scanf("%s", roda[i].nome);

    int garrafa = (int)(l * 10 + 0.5);
    int cuia = (int)(q * 10 + 0.5);

    int cuias = (garrafa + cuia - 1) / cuia;
    int ultima = garrafa % cuia;
    if (ultima == 0)
        ultima = cuia;

    int rico = (cuias - 1) % n;

    printf("%s %d.%d\n", roda[rico].nome, ultima / 10, ultima % 10);

    return 0;
}