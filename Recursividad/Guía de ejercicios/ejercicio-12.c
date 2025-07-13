// Desarrollar un programa que muestre los primeros N números naturales. El número N lo debe ingresar el usuario.

#include <stdio.h>

void solicitar_num(int *a)
{
    printf("Ingrese un numero: ");
    scanf("%d", a);
}

void primeros_N_naturales(int a)
{
    if(a > 0)
    {
        primeros_N_naturales(a - 1);
        printf("%d ", a);
    }
}

int main()
{
    int a;
    solicitar_num(&a);
    primeros_N_naturales(a);
    return 0;
}