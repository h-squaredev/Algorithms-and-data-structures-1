//beecrowd | 1555

#include <stdio.h>

void funcoes(int x, int y){
    int Rafael = ((3 * x) * (3 * x)) + (y * y);

    int Beto = (2 * (x * x)) + ((5 * y)* (5 * y));

    int Carlos = ((-100 * x) + (y * y * y));

    if((Rafael > Beto) && (Rafael > Carlos)) printf("Rafael ganhou\n");
    else if((Beto > Rafael) && (Beto > Carlos)) printf("Beto ganhou\n");
    else printf("Carlos ganhou\n");

}

int main() {
    int N, x, y;
    scanf("%d", &N);

    for (int i = 0; i < N; i++){
        scanf("%d %d", &x, &y);
        funcoes(x, y);
    }

    return 0;
}