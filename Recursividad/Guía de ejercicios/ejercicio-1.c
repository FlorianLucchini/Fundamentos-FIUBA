// Desarrollar un programa que calcule la factorial de un número en forma recursiva.

#include <stdio.h>

int factorial(int n)
{
    if(n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    int n;
    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &n);
    
    printf("El factorial de %d es %d\n", n, factorial(n));
    
    return 0;
}