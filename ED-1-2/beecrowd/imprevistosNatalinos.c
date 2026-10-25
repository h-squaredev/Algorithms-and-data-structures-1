/*
Contabilizar o numero de compuradores que funcionarão em um dia especifico de acordo
com a quantidade total de alunos nesse dia. Se não for suficiente, = sem aula
*/

#include <stdio.h>
 
int main() {
    // A = quantidade de alunos
    // C = quantidade de computadores

    // X = computadores queimados por Caio
    // Y = computadores que sem compiladores
    int A, C, X, Y;
    scanf("%d %d %d %d", &A, &C, &X, &Y);

    if((C - X - Y >= A + 1)){
        printf("Igor feliz!\n");
    }else{
        if((X > (Y / 2))){
            printf("Caio, a culpa eh sua!\n");
        }else{
            printf("Igor bolado!\n");
        }
    }
 
    return 0;
}