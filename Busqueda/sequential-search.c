#include <stdio.h>
#include <stdbool.h>

#define MF 20

typedef int Tvec[MF];

int sequential_search(Tvec vec, int ml, int num)
{
    int i = 0, idx;
    bool founded = false;
    while( (i < ml) && !founded)
    {
        if(vec[i] == num)
        {
            founded = true;
            idx = i;
        }
    }

    return idx;
}