#include <stdio.h>

/*
a)
Solicitar un número entero positivo al usuario y calcular su factorial. En el caso de
ingresar un número negativo mostrar un mensaje que diga “no se puede calcular el factorial del número ingresado”.
Recordar que por definición factorial(0) = 1 y factorial(1) = 1
Utilizar el tipo de dato "long" para el resultado del calculo.
Utilizar valores comprendidos entre 0 y 20 inclusives para las pruebas.
*/

int main() {
    int num, i;
    long long fact = 1;

    printf("Ingrese un valor para calcular su factorial:\n");
    scanf("%d", &num);

    if(num >= 0) {
        for(i = 1; i <= num; i++) {
            fact *= i;
        }
        printf("El factorial de %d es %lld.\n\n", num, fact);
    } else {
        printf("No se puede calcular el factorial del número ingresado\n\n");
    }
}