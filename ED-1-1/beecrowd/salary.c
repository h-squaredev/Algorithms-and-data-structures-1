#include <stdio.h>


int main() {

    double salary, new_salary;
    int percent;

    printf("Digite seu salario e veja o reajuste: ");
    scanf("%lf", &salary);

    if (salary >= 0 && salary <= 400.00){
        new_salary = salary * 0.15;
    }
    else if (salary <= 800.00){
        new_salary = salary * 0.12;
    }
    else if (salary <= 1200.00){
        new_salary = salary * 0.10;
    }
    else if (salary <= 2000.00){
        new_salary = salary * 0.07;
    }
    else {
        new_salary = salary * 0.04;
    }
    percent = (new_salary / salary) * 100;

    printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: %d %%", salary + new_salary, new_salary, percent);




    return 0;
}