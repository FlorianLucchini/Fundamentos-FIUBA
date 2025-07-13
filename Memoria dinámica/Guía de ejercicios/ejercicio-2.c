// Escribir un programa el cual reserve memoria dinámica para almacenar una cierta cantidad de números enteros (n * int), este valor n debe ser ingresado por el usuario. Luego solicitarle que ingresé n valores enteros ingresados de a uno y almacenarlos en la memoria previamente reservada. Mostrar luego todos los valores ingresados.
// Liberar la memoria reservada al finalizar el programa.

#include <stdio.h>
#include <stdlib.h>

int solicitar_n(int *n)
{
    printf("Ingrese la cantidad n de enteros a cargar: ");
    scanf("%d", n);
    return 0;
}

int ingresar_valores(int val[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("N*%d: ", i);
        scanf("%d", &val[i]);
    }
    return 0;
}

int mostrar_valores(int val[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("Dato N*%d es %d.\n", i, val[i]);
    return 0;
}

int main()
{
    int n;
    int *val = NULL;
    solicitar_n(&n);
    val = malloc(sizeof(int) * n);
    if(val != NULL)
    {
        ingresar_valores(val, n);
        mostrar_valores(val, n);
    }
    else
        printf("No se pudo reservar espacio en la memoria.");

    free(val);
    return 0;
}