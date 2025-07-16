// Desarrollar una función recursiva que compruebe si un número pasado como parámetro es capicúa.

#include <stdbool.h>
#include <stdio.h>

int invertir(int num, int inv)
{
    if(num == 0)
        return inv;
    else
        return invertir(num / 10, (num % 10) + (inv * 10));
}

bool es_capicua(int num)
{
    int inv;
    inv = invertir(num, 0);
    if(num == inv)
        return true;
    else
        return false;
}

int mostrar_resultado(bool es_capicua, int num)
{
    if(es_capicua)
        printf("El numero %d es capicua.", num);
    else
        printf("El numero %d no es capicua", num);
    return 0;
}

int main()
{
    int num = 102;
    mostrar_resultado(es_capicua(num), num);
    return 0;
}