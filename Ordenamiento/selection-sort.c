// It works by repeatedly selecting the minimum (or maximum) element from the unsorted portion and moving it to the beginning (or end) of the sorted portion.

#include <stdio.h>

#define MF 15

typedef int Tvec[MF];

void print_vec(Tvec vec, int ml)
{
    int i;
    printf("Your vector: \n");
    for(i = 0; i < ml; i++)
        printf("%d", vec[i]);
    printf("\n\n");
}

void selection_sort(Tvec vec, int ml)
{
    int i, j, min, aux;
    for(i = 0; i < ml; i++)
    {
        min = i;
        for(j = i + 1; j < ml; j++)
            if(vec[min] > vec[j])
                min = j;

        aux = vec[i];
        vec[i] = vec[min];
        vec[min] = aux;
    }
}

int main()
{
    Tvec vec = {3, -1, -6, 10, 22, -390, 390, 0, 54, 43, 31};
    print_vec(vec, 11);
    selection_sort(vec, 11);
    print_vec(vec, 11);
    
    return 0;
}