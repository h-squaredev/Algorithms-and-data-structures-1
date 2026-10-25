#include <stdio.h>
#include <stdlib.h>

int main () {
    int num;
    printf("numeros multiplos de 5 entre 1 e 500? Ta na mao\n");
    num = 1;
    while (num <= 500) {
        if (num % 5 == 0) {
            printf("%d\n", num);
        }
        num++;
    }
    return 1;
}