// 1. Escribir una función que reciba como parámetro una cadena de caracteres y devuelva la cantidad de dígitos numéricos que hay en la cadena. 

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MF 50

typedef char Tcadena[MF];

void solicitar_datos(Tcadena str)
{
    printf("Ingrese a continuacion la cadena: ");
    fgets(str, MF, stdin);
}

bool es_digito(char c)
{
    return c <= '9' && c >= '0';
}

bool termino_el_texto(char c)
{
    return c == '\0';
}

int contar_digitos(const Tcadena str)
{
    int i = 0;
    int cant_digitos = 0;
    while(!termino_el_texto(str[i]))
    {
        if(es_digito(str[i]))
            cant_digitos++;
        i++;
    }
    return cant_digitos;
}

int main()
{
    Tcadena cadena;
    int cant_digitos;

    solicitar_datos(cadena);
    cant_digitos = contar_digitos(cadena);
    printf("La cantidad de digitos que hay en la cadena %s es: %d", cadena, cant_digitos);

    return 0;
}