// Desarrollar una función recursiva para realizar una búsqueda binaria en un vector.

#include <stdio.h>

#define MF 10

typedef int Tvec[MF];

int binary_search(Tvec vect, int n)
{
    return 0;
}

int main()
{
    Tvec vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int pos, n = 10;
    pos = binary_search(vec, n);
    printf("La posición del elemento %d, es %d", n, pos);
    return 0;
}