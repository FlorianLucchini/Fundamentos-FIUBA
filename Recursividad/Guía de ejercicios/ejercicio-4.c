// Desarrollar un programa que calcule y muestre por pantalla la división de 2 números mediante restas sucesivas en forma recursiva. Ambos números deben ser ingresados por el usuario
#include <stdio.h>

int division(int num_1, int num_2)
{
    if(num_1 < num_2)
        return 0;
    else
        return 1 + division(num_1 - num_2, num_2);
}

int main()
{
    int dividendo, divisor, res;
    printf("Ingrese el numero a divir: ");
    scanf("%d", &dividendo);
    printf("Ingrese el numero por el que lo va a dividir: ");
    scanf("%d", &divisor);
    res = division(dividendo, divisor);
    printf("El resultado de la division es %d", res);
    return 0;
}