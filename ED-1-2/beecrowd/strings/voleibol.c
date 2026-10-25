#include <stdio.h>

int main() {
    int n;
    char nome[100];
    int s, b, a;
    int s1, b1, a1;
    
    // Variáveis para armazenar o total de tentativas
    int total_s = 0, total_b = 0, total_a = 0;
    
    // Variáveis para armazenar o total de acertos
    int total_s1 = 0, total_b1 = 0, total_a1 = 0;

    // Leitura do número de jogadores
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        // Leitura do nome do jogador
        scanf("%s", nome);
        
        // Leitura das tentativas (Saques, Bloqueios, Ataques)
        scanf("%d %d %d", &s, &b, &a);
        
        // Leitura dos sucessos (Saques, Bloqueios, Ataques)
        scanf("%d %d %d", &s1, &b1, &a1);

        // Somar aos totais da equipa
        total_s += s;
        total_b += b;
        total_a += a;

        total_s1 += s1;
        total_b1 += b1;
        total_a1 += a1;
    }

    // Calcular as percentagens e imprimir conforme a formatação exigida
    double perc_s = ((double)total_s1 / total_s) * 100.0;
    double perc_b = ((double)total_b1 / total_b) * 100.0;
    double perc_a = ((double)total_a1 / total_a) * 100.0;

    printf("Pontos de Saque: %.2lf %%.\n", perc_s);
    printf("Pontos de Bloqueio: %.2lf %%.\n", perc_b);
    printf("Pontos de Ataque: %.2lf %%.\n", perc_a);

    return 0;
}
