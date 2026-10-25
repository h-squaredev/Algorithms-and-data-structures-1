#include <stdio.h>

int main() {
    unsigned long long X, M;
    
    // Lê os dois valores enquanto não for o fim do ficheiro (EOF)
    while (scanf("%llu %llu", &X, &M) == 2) {
        
        // Condição de paragem especificada no problema
        if (X == 0 && M == 0) {
            break;
        }
        
        // Calcula e imprime o novo EXP do monstro
        unsigned long long E = X * M;
        printf("%llu\n", E);
    }
    
    return 0;
}