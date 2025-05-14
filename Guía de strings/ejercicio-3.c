// Escribir una función en C, que reciba como parámetro una cadena de tipo t_cadena, y devuelva la cantidad de palabras que hay en la cadena.
// Considerar que una palabra está separada de otra, por uno ó más blancos.
// No recorrer la cadena más de una vez.
// Declare un tipo t_cadena acorde.
// Escribir el programa que incluya a la función y las invocaciones con los siguientes caso de prueba:

// cant_palabras("El sol es amarillo.") devuevle 4
// cant_palabras(" Hoy es 30 de Junio de 2021 ") devuevle 7
// cant_palabras("30/06/2021") devuelve 1
// cant_palabras("El precio es $2.000.- ") devuelve 4
// cant_palabras(" ") devuelve 0 

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MF 101

typedef char Tstr[MF];

int cant_palabras(Tstr str)
{
    int i, cant = 0;
    bool en_palabra = false;

    i = 0;
    while(str[i] != '\0')
    {
        if(str[i] != ' ' && !en_palabra)
        {
            cant++;
            en_palabra = !en_palabra;
        }
        else if (str[i] == ' ' && en_palabra)
        {
            en_palabra = !en_palabra;
        }
        
        i++;
    }
    return cant;
}

int main()
{
    Tstr str;
    int cant;

    strcpy(str, "El sol es amarillo.");
    cant = cant_palabras(str);
    printf("La cantidad de palabras en '%s' es de: %d.\n", str, cant);

    strcpy(str, " Hoy es 30 de Junio de 2021 ");
    cant = cant_palabras(str);
    printf("La cantidad de palabras en '%s' es de: %d.\n", str, cant);

    strcpy(str, "30/06/2021");
    cant = cant_palabras(str);
    printf("La cantidad de palabras en '%s' es de: %d.\n", str, cant);

    strcpy(str, "El precio es $2.000.- ");
    cant = cant_palabras(str);
    printf("La cantidad de palabras en '%s' es de: %d.\n", str, cant);

    strcpy(str, " ");
    cant = cant_palabras(str);
    printf("La cantidad de palabras en '%s' es de: %d.\n", str, cant);
    
    return 0;
}