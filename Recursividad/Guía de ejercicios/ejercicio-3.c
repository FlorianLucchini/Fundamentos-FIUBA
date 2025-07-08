// Desarrollar una función recursiva para realizar una búsqueda binaria en un vector.

#include <stdio.h>

#define MF 10

typedef int Tvec[MF];

int binary_search(Tvec vect, int val, int min, int max)
{   
    int mid;
    if(val < vect[min] || vect[max] < val)
        return -1;
    else
    {
        min + ( (max - min) / 2 );
        mid = (max + min) / 2;
        if(val == vect[mid])
            return mid;
        else
        {
            if(vect[mid] < val)
                return binary_search(vect, val, mid + 1, max);
            else
                return binary_search(vect, val, min, max - 1);
        }
    }
}

int main()
{
    Tvec vec = {10, 20, 30, 40, 50, 60, 70, 80, 90, 107};
    int pos, val = 70;
    pos = binary_search(vec, val, 0, 9);
    if (pos == -1) {
        printf("Valor %d buscado no encontrado \n\n", val);
    } else {
        printf("Valor %d buscado encontrado en posicion %d \n\n", val, pos);
    }
    return 0;
}