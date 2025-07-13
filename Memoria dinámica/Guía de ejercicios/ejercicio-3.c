// Asumiendo que ya existe un puntero que apuntan a un bloque de memoria previamente reservada con malloc de tamaño (n * int), redimensionar dicha memoria a un tamaño de (2 * n *int).

#include <stdio.h>
#include <stdlib.h>

int solicitar_n(int *n)
{
    printf("Ingrese la cantidad n de enteros a cargar: ");
    scanf("%d", n);
    return 0;
}

int main()
{
    int n;
    int *val = NULL;
    solicitar_n(&n);
    val = malloc(n * sizeof(int));
    if(val != NULL)
    {
        val = realloc(val, 2 * n * sizeof(int));

        for(int i = 0; i < 2 * n; i++)
            val[i] = i * 10;  // Escribir algo

        for(int i = 0; i < 2 * n; i++)
            printf("%d ", val[i]);  // Leer todo
    }
    else
        printf("No se pudo reservar memoria correctamente.");

    free(val);
    return 0;
}