#include <stdio.h>
#include <stdlib.h>

int main () {
    int max, min, num;

    printf("Insira o limite inferior do intervalo: ");
    scanf ("%d", &min);
    printf("Insira o limite superior do intervalo: ");
    scanf ("%d", &max);

    for (num = min; num <= max; num++) {
        if (num % 6 == 0) {
            printf("%d\n", num);
        }
    }
   return 1;
}