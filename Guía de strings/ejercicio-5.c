// 5. Escribir una función para validar una nueva clave de acceso. La función deberá recibir una cadena de caracteres, que contendrá la clave candidata, que ya fue ingresada previamente por el usuario. Devolverá true o false, dependiendo de si cumple o no, con las siguientes condiciones:
//  - La clave debe estar formada únicamente por, entre 6 y 12 caracteres numéricos
//  - La cantidad de dígitos pares debe ser mayor a la de los impares.'

// A los sumo debe recorrer una vez la cadena.
// Evite realizar ciclos innecesarios.

// Compruebe el correcto funcionamiento, incluyendo los siguientes casos de prueba:
// validar("j20893") devuevle false
// validar("20893a") devuevle false
// validar("208X930") devuevle false
// validar("20201") devuelve false
// validar("23445776") devuelve false
// validar("089010") devuelve true
// validar("02784532132567") devuelve false
// validar("027845320011") devuelve true 

#include <stdio.h>
#include <stdbool.h>

#define MF 50
#define MIN_LONG_CLAVE 6
#define MAX_LONG_CLAVE 12
#define DIGITO_MENOR '0'
#define DIGITO_MAYOR '9'
#define CHAR_NULL '\0'
#define DIGITOS_PARES '02468'
#define DIGITOS_IMPARES '13579'

typedef char Tclave[50];

void solicitar_clave(Tclave clave)
{
    printf("Ingrese a continuacion la clave de acceso a validar: ");
    fgets(clave, MF, stdin);
}

bool es_digito(char c)
{
    return c <= DIGITO_MAYOR && c >= DIGITO_MENOR;
}

bool long_es_correcta(int tamanio)
{
    return MIN_LONG_CLAVE < tamanio && tamanio < MAX_LONG_CLAVE;
}

bool termino_el_texto(char c)
{
    return c == CHAR_NULL;
}

bool es_par(char c)
{
    char strchar[] = {c, CHAR_NULL};
    return strstr(DIGITOS_PARES, strchar) != NULL;
}

bool es_impar(char c)
{
    char strchar[] = {c, CHAR_NULL};
    return strstr(DIGITOS_IMPARES, strchar) != NULL;
}

bool validar(Tclave clave)
{
    int i = 0, pares = 0, impares = 0;
    bool es_valida;

    if(!long_es_correcta(strlen(clave)))
        es_valida = false;

    while((!termino_el_texto(clave[i])) && es_valida)
    {
        if(( es_digito(clave[i]) ))
        {
            es_valida = true;
            i++;

            if(es_par(clave[i]))
                pares++;

            else if (es_impar(clave[i]))
                impares++;
        }
        else
        {
            es_valida = false;
        }
    }

    if(pares > impares)
        es_valida = true;
    else
        es_valida = false;

    return es_valida;
}

int main()
{
    Tclave clave;

    solicitar_clave(clave);
    validar(clave);
}