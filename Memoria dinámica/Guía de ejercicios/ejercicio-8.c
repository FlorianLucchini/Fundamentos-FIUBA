// Implementar una función que retorna un puntero a un vector de n valores de tipo int, todos inicializados en cero, el cual apunta a un bloque de memoria dinámica, respetando la siguiente declaración.
// En caso de no poder reservar la memoria, retornar NULL.
// int* crear_vector_inicializado(int n);

#include <stdio.h>
#include <stdlib.h>

int solicitar_n(int *n)
{
    printf("Ingrese la cantidad de elementos que habra en el arreglo: ");
    scanf("%d", n);
    return 0;
}

int* crear_vector_inicializado(int n)
{
    return calloc(n, sizeof(int));
}

int mostrar_vector(int vec[], int n)
{
    int i;
    printf("Valores del vector: ");
    for(i = 0; i < n; i++)
        printf("%d ", vec[i]);
    return 0;
}

int main()
{
    int n;
    int *vec;
    solicitar_n(&n);
    vec = crear_vector_inicializado(n);
    if(vec != NULL)
        mostrar_vector(vec, n);
    else
        printf("No se pudo reservar la memoria.\n");
    
    free(vec);
    return 0;
}