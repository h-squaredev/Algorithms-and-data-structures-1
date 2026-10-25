#include <stdio.h>
 
int main() {
 
    int valores[5], contador = 0;

    printf("Digite o primeiro valor inteiro: ");
    scanf("%d", &valores[0]);
    printf("Digite o segundo valor inteiro: ");
    scanf("%d", &valores[1]);
    printf("Digite o terceiro valor inteiro: ");
    scanf("%d", &valores[2]);
    printf("Digite o quarto valor inteiro: ");
    scanf("%d", &valores[3]);
    printf("Digite o quinto valor inteiro: ");
    scanf("%d", &valores[4]);

    for (int i = 0; i < 5; i++){
        if (valores[i] % 2 == 0){
            contador++;
        }
    }

    printf("%d valores pares\n", contador);

    return 0;
}