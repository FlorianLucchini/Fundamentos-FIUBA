
// Desarrollar una función recursiva que imprima por pantalla un rectángulo a partir de los valores de la base y la altura ingresados por teclado.

#include <stdio.h>

void imprimir_filas(int b)
{
    if(b > 0)
    {
        printf("*");
        imprimir_filas(b - 1);
    }
}

void imprimir_rectangulo(int b, int h)
{
    if(h > 0)
    {
        imprimir_filas(b);
        printf("\n");
        imprimir_rectangulo(b, h - 1);
    }
}

int main()
{
    int b, h;
    b = 4;
    h = 6;
    imprimir_rectangulo(b, h);
    return 0;
}