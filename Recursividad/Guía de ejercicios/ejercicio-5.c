// Desarrollar una función recursiva para obtener en mayor valor en un vector de números enteros.   

#include <stdio.h>
#define MF 10

typedef int Tvec[MF];

int mayor_valor_vector_recu(Tvec vec, int ml)
{
    if (ml == 1) {
        return vec[0];
    } else {
        int max_restante = maximo(vec, ml - 1);
        if (vec[ml - 1] > max_restante) {
            return vec[ml - 1];
        } else {
            return max_restante;
        }
    }
}

int mayor_valor_vector(Tvec vec, int ml)
{
    int aux, i;
    aux = vec[0];
    for(i = 1; i < ml; i++)
        if(aux < vec[i])
            aux = vec[i];

    return aux;
}

int main()
{
    Tvec vec = {2, 50, 40, 22, 10, 1, 3, -3, 54};
    int ml, res;
    ml = 10;
    res = mayor_valor_vector_recu(vec, ml);
    printf("El mayor valor es %d.", res);
    return 0;
}