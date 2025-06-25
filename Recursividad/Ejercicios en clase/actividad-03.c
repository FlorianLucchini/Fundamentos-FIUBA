// 3-Mostrar números pares entre 1 y X.

#include <stdio.h>

void mostrar_pares(int numero) {
    if (numero == 1) {
        printf("%d", numero);
    }
    else {
        mostrar_pares(numero - 1);
        if (numero % 2 == 0 ) {
            printf("%d", numero);
        }
    }
}

// 4- Mostrar de a uno los dígitos de un Número
void mostrar_digitos(int num) {
    if (num < 10) {
        printf("%d", num);
    }
    else {
        printf("%d\n", num % 10);
        mostrar_digitos(num / 10);
    }
}


// 5- Una función recursiva en C que suma los elementos en las posiciones pares de un arreglo
int suma_pares(int *arr, int ml)
{
    if(ml <= 0)
        return 0;
    else
    {
        if((ml - 1) % 2 == 0)
            return arr[ml - 1] + suma_pares(arr, ml - 1);
        else
            return suma_pares(arr, ml - 1);
    }
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // mostrar_pares(10);
    printf("%d", suma_pares(arr, 10));
    return 0;
}