#include <stdio.h>
 
int main() {
 
    int N, cem, cinquenta, vinte, dez, cinco, dois, um;
    printf("Digite um valor inteiro entre 0 e 1000000: ");
    scanf("%d", &N);

    printf("%d\n", N);
    cem = N / 100;
    N = N % 100;

    cinquenta = N / 50;
    N = N % 50;

    vinte = N / 20;
    N = N % 20;

    dez = N / 10;
    N = N % 10;

    cinco = N / 5;
    N = N % 5;

    dois = N / 2;
    N = N % 2;
    
    um = N / 1;
    N = N % 1;
    
    printf("%d nota(s) de R$ 100,00\n", cem);
    printf("%d nota(s) de R$ 50,00\n", cinquenta);
    printf("%d nota(s) de R$ 20,00\n", vinte);
    printf("%d nota(s) de R$ 10,00\n", dez);
    printf("%d nota(s) de R$ 5,00\n", cinco);
    printf("%d nota(s) de R$ 2,00\n", dois);
    printf("%d nota(s) de R$ 1,00\n", um);

return 0;
    
}