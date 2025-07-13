// Desarrollar una función recursiva que compruebe si un número pasado como parámetro es capicúa.

#include <stdbool.h>
#include <stdio.h>

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
    int num = 101;
    mostrar_resultado(es_capicua(num), num);
    return 0;
}