// Desarrollar un programa que solicite al usuario el ingreso de un número entero y calcule el máximo común divisor de forma recursiva.

#include <stdio.h>

int MCD(int num_1, int num_2)
{
    if(num_2 == 0)
        return num_1;
    else
        return MCD(num_2, num_1 % num_2);
}

int main()
{
    int a = 12, b = 18;
    printf("MCD entre %d y %d es %d.", a, b, MCD(a, b));
    return 0;
}