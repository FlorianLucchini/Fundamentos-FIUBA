// Escribir un programa en Python, C - o pseudocódigo- que le solicite al usuario que ingrese su número
// de padrón y devuelva por pantalla todos los divisores del padrón ingresado.
// En la lista se deben omitir el 1 y el propio padrón.

#include <stdio.h>

int main() {
    // Mi numero de padron es 113278.
    int numPadron;
    printf("Ingrese su numero de padron:\n");
    scanf("%d", &numPadron);
    printf("\n");

    for(int i = 2; i < numPadron; i++) {
        if(numPadron % i == 0) {
            printf("El numero %d es divisor.\n", i);
        }
    }
    return 0;
}