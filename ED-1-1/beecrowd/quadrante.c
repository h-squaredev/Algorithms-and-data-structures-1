#include <stdio.h>

int main() {

    int x, y;

    printf("Digite as coordenadas X e Y: ");

    while (scanf("%d %d", &x, &y) == 2){

        if (x == 0 || y == 0){
            break;
        }
        else if (x > 0 && y > 0){
            printf("primeiro\n");
        }
        else if (x < 0 && y > 0){
            printf("segundo\n");
        }
        else if (x < 0 && y < 0){
            printf("terceiro\n");
        }
        else if (x > 0 && y < 0){
            printf("quarto\n");
        }
    }

    return 0;
}