// Implementar una función recursiva la cual calcule la potencia entre dos números enteros. Para la resolución debe basarse en el algoritmo de exponenciación binaria.

#include <stdio.h>

long long int potencia(int x, int n)
{
    int res;
    if(n == 0)
        return 1;
    else
    {
        if(n % 2)
            return x * potencia(x, n - 1);
        else
        {
            res = potencia(x, n / 2);
            return res * res;
        }
    }
}

int main()
{
    int x, n;
    x = 2;
    n = 10;
    printf("%d elevado a la %d es %lld", x, n, potencia(x, n));
    return 0;
}