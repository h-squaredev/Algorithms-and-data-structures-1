#include <stdio.h>
#include <math.h>
 
int main() {
    double a, b, c, R1, R2, delta;
    
    printf("Digite os valores de a: ");
    scanf("%lf", &a);
    printf("Digite os valores de b: ");
    scanf("%lf", &b);
    printf("Digite os valores de c: ");
    scanf("%lf", &c);

    delta = pow(b, 2) - 4 * a * c;
    if (a == 0 || delta < 0) {
        printf("Impossivel calcular\n");
        return 0;
    }
    
    R1 = ((-b + sqrt(delta)) / (2 * a));
    
    R2 = ((-b - sqrt(delta)) / (2 * a));
 
    printf("R1 = %.5f\n", R1);
    printf("R2 = %.5f\n", R2);
 
    return 0;
}