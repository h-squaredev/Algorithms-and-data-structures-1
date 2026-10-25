#include <stdio.h>
#include <stdlib.h>

int main () {
    int num;
    printf("numeros de 1 ate 100? Ta na mao\n");
    num = 1;
    while (num <= 100) {
        printf("%d\n", num);
        num++;
    }
    return 1;
}