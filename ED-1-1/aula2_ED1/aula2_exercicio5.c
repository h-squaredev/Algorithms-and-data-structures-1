#include <stdio.h>
#include <stdlib.h>

int main () {
    int num, multi3;
   
    printf("Informe seu primeiro numero: ");
    scanf ("%d", &num);

    multi3 = num % 3;
    
     if (multi3 == 0) {
    printf("É múltiplo de 3!\n");

    } else {
    printf("NÃO é múltiplo de 3!\n");
    }
return 1;
}
