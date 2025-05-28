#include <stdio.h>
#include <stdbool.h>

#define MF 20

typedef Tvec[MF];

int binary_search(Tvec vec, int ml, int value)
{
    int inf, sup, mid;
    bool finished;
    int pos = -1;

    inf = 0;
    sup = ml - 1;
    finished = false;

    while(!finished)
    {
        if( ( value > vec[sup] ) || ( value < vec[inf] ) )
        {
            finished = true;
            pos = -1;
        }
        else
        {
            mid = (inf + sup) / 2;

            if( value == vec[mid] )
            {
                finished = true;
                pos = mid;
            }
            else
            {
                if( value > vec[mid] )
                    inf = mid + 1;
                else
                    sup = mid - 1;
            }
        }
    }
    return pos;
}