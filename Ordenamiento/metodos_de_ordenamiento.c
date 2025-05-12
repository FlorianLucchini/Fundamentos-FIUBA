#include <stdio.h>
#include <stdbool.h>

#define MF 10

typedef int Tvec[10];

void mostrar_vec(Tvec vec, int ml)
{
    int i;
    printf("El dni quedo asi: \n");
    for(i = 0; i < ml; i++)
        printf("%d", vec[i]);
    printf("\n\n");
}

void intercambiar_elementos(int *elem_1, int *elem_2)
{
    int aux;
    aux = *elem_1;
    *elem_1 = *elem_2;
    *elem_2 = aux;
}

void bubble_sort(Tvec vec, int ml)
{
    int i, j;
    for(i = 1; i < ml; i++)

        for (j = 0; j < ml - i; j)

            if (vec[j] > vec[j+1])
            {
                intercambiar_elementos(&vec[j], &vec[j + 1]);
            }
}

void bubble_sort_optimized(Tvec vec, int ml)
{
    int i = 1, j;
    bool se_intercambiaron = true;

    while ((i < ml) && se_intercambiaron)
    {
        se_intercambiaron = false;
        for (j = 0; j < ml - i; j++)

            if (vec[j] > vec[j+1])
            {
                intercambiar_elementos(&vec[j], &vec[j + 1]);
                se_intercambiaron = true;
            }
 
        i++;
    }
}

void selection_sort(Tvec vec, int ml)
{
    int i, j, min;

    for(i = 0; i < ml - 1; i++)
    {
        min = i;
        for(j = i + 1; j < ml; j++)
            if(vec[j] < vec[min])
                min = j;

        intercambiar_elementos(&vec[i], &vec[min]);
    }
}

void insertion_sort(Tvec vec, int ml)
{
    int i, j, aux;

    for (i = 1; i < ml; i++)
    {
        aux = vec[i];
        j = i - 1;
        while ((j >= 0) && (vec[j] > aux))
        {
            vec[j + 1] = vec[j];
            j = j - 1;
        }

        vec[j + 1] = aux;
    }
}

int main()
{
    Tvec vec = {4, 6, 5, 8, 1, 3, 6, 4};
    selection_sort(vec, 8);
    mostrar_vec(vec, 8);
}