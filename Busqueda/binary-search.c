#include <stdio.h>
#include <stdbool.h>

#define MF 20

typedef int Tvec[MF];

int binary_search(Tvec vec, int ml, int value)
{
    int min, max, mid, pos;
    bool finished;

    finished = false;
    min = 0;
    max = ml - 1;
    pos = -1;

    while(!finished)
    {
        if(value < vec[min] || value > vec[max])
        {
            pos = -1;
            finished = true;
        }
        else
        {
            mid = min + ((max - min) / 2);
            if(value == vec[mid])
            {
                finished = true;
                pos = mid;
            }
            else
            {
                if(value > vec[mid])
                    min = mid + 1;
                else
                    max = mid - 1;
            }
        }
    }

    return pos;
}