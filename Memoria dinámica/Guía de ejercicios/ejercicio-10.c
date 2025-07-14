// Utilizar memoria dinámica para almacenar una cierta cantidad de n palabras ingresadas por el usuario. Crear una estructura de datos dinámica de dos dimensiones que permita almacenar esta información. Mostrar toda la información de la estructura luego de haber sido cargada. 
// Liberar toda la memoria al finalizar el programa.

// typedef char* t_palabra;
// typedef t_palabra* t_vec;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char* t_palabra;
typedef t_palabra* t_vec;

int solicitar_n(int *n)
{
    printf("Ingrese la cantidad de palabras a almacenar: ");
    scanf("%d", n);
    return 0;
}

int ingresar_palabras(t_vec vec, int n)
{
    int i;
    char *str;
    for(i = 0; i < n; i++)
    {
        printf("Ingrese la palabra N*%d.\n", i + 1);
        scanf(" %30[^\n]s", str);
        vec[i] = malloc(strlen(str) * sizeof(char) + 1);
        strcpy(vec[i], str);
    }

    return 0;
}

int mostrar_palabras(t_vec vec, int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%s ", vec[i]);
    return 0;
} 

int main()
{
    int n, i;
    t_vec vec;
    solicitar_n(&n);
    vec = malloc(n * sizeof(t_vec));
    if(vec != NULL)
    {
        ingresar_palabras(vec, n);
        mostrar_palabras(vec, n);
    }

    for(i = 0; i < n; i++)
        free(vec[i]);
    free(vec);
    return 0;
}