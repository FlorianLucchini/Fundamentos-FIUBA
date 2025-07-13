// Desarrollar una función recursiva que compruebe si un número es binario. Un número binario está formado únicamente por ceros y unos.

#include <stdio.h>
#include <stdbool.h>

bool es_binario(long long int num)
{
    int dig;
    if(num == 0)
        return true;
    else
    {
        dig = num % 10;
        if(dig != 1 && dig != 0)
            return false;
        else
            return es_binario(num / 10);
    }
}

int main()
{
    long long int num = 11111101001;
    bool es = es_binario(num);
    if(es)
        printf("El numero (%lld) ingresado es binario", num);
    else
        printf("El numero (%lld) ingresado no es binario", num);
}