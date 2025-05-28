#include <stdio.h>
#include <stdbool.h>

#define MF 15

typedef int Tvec[MF];

void print_vec(Tvec vec, int ml)
{
    int i;
    printf("Your vector: \n");
    for (i = 0; i < ml; i++)
        printf(" %d ", vec[i]);
    printf("\n\n");
}

void bubble_sort(Tvec vec, int ml)
{
    int i, j, aux;
    for (i = 0; i < ml; i++)
    {
        for (j = 0; j < ml - i - 1; j++)
            if (vec[j + 1] < vec[j])
            {
                aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
    }   
}

void bubble_sort_optimized(Tvec vec, int ml)
{
    int i, j, aux;
    bool swamped = true;
    i = 0;
    while((i < ml) && swamped)
    {
        swamped = false;
        for (j = 0; j < ml - i - 1; j++)
            if (vec[j + 1] < vec[j])
            {
                aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
                swamped = true;
            }
        i++;
    }   
}


int main()
{
    Tvec vec = {3, -1, -6, 10, 22, -390, 390, 0, 54, 43, 31};
    print_vec(vec, 11);
    bubble_sort(vec, 11);
    print_vec(vec, 11);

    return 0;
}