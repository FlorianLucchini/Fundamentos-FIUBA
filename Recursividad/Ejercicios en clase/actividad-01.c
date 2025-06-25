// Escriba una función en C que determine si un arreglo de enteros es capicúa. Asumir que el máximo físico del arreglo es 30.
// Escribir un programa que invoque dicha función.

#include <stdio.h>
#include <stdbool.h>

#define MF 30

typedef int T_vec[MF];

void cargar_vect(T_vec vec, int *ml)
{
    int i, aux;
    printf("A continuación ingrese los valores del vector (0 para terminar): ");
    scanf("%d", &aux);
    i = 0;
    while(aux != 0 && i < MF)
    {
        vec[i] = aux;
        i++;
        printf("Ingrese el valor para la proxima posición: ");
        scanf("%d", &aux);
    }
    *ml = i;
    return;
}

void print_capicua(bool es_capicua)
{
    if(es_capicua)
        printf("El vector es capicua.\n");
    else
        printf("El vector no es capicua.\n");
    return;
}

bool es_capicua(T_vec vec, int ml)
{
    int i;
    bool es_capicua = true;
    i = 0;
    while(es_capicua && i < (ml / 2))
    {
        if(vec[i] != vec[ml - 1 - i])
            es_capicua = false;
        i++;
    }

    print_capicua(es_capicua);

    return es_capicua;
}

int main()
{
    T_vec vec;
    int ml;
    cargar_vect(vec, &ml);
    es_capicua(vec, ml);
    return 0;
}