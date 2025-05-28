// Here's how insertion sort works:
// Start with the second element in the array.
// Compare the current element with the elements before it.
// If the current element is smaller than the previous element, swap them.
// Continue comparing and swapping until the current element is in its correct sorted position.
// Move to the next unsorted element and repeat steps 2-4.
// The algorithm finishes when all elements are sorted.

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

void insertion_sort(Tvec vec, int ml)
{
    int j, i, key;
    for(j = 1; j < ml; j++)
    {
        key = vec[j];
        i = j - 1;
        while(i >= 0 && key < vec[i])
        {
            vec[i + 1] = vec[i];
            i--;
        }
        vec[i + 1] = key;
    }
}

int main()
{
    Tvec vec = {3, -1, -6, 10, 22, -390, 390, 0, 54, 43, 31};
    print_vec(vec, 11);
    insertion_sort(vec, 11);
    print_vec(vec, 11);
    
    return 0;
}