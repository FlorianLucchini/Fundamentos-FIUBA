// Escribir una función para validar una nueva clave de acceso.
// La función deberá recibir una cadena de caracteres, que contendrá la clave candidata, ingresada previamente por el usuario.
// Devolverá true o false, dependiendo de si cumple o no con las siguientes condiciones:
// - La clave debe estar formada únicamente por, entre 4 y 8 caracteres numéricos
// - Los caracteres no pueden ser todos iguales

// Ejemplos:
// validar("j2020") devuevle false
// validar("2021a") devuevle false
// validar("20X21") devuevle false
// validar("2220") devuelve true
// validar("23445776") devuelve true
// validar("089") devuelve false
// validar("027845321") devuelve false
// validar("02784532") devuelve true
// validar("33333") devuelve false

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LONG 9
#define MIN_LONG 4

typedef char Tclave[MAX_LONG];

void obtener_clave(Tclave clave)
{
    fgets(clave, MAX_LONG, stdin);
    fflush(stdin);
    clave[strcspn(clave, "\n")] = '\0';
}

bool logitud_correcta(int ml)
{
    return MIN_LONG <= ml && ml <= (MAX_LONG - 1);
}

bool es_digito(char c)
{
    return c <= '9' && c >= '0';
}

bool todos_iguales(Tclave clave, int ml)
{
    bool iguales = true;
    int i = 1;
    char ref = clave[0];

    while (i < ml && iguales)
    {
        if (clave[i] != ref)
            iguales = false;

        i++;
    }

    return iguales;
}

bool validar(Tclave clave)
{
    bool es_valida = false;
    int len = strlen(clave), i;

    if(logitud_correcta(len))
        es_valida = true;

    i = 0;
    while(i < len && es_valida)
    {
        if(!es_digito(clave[i]))
            es_valida = false;

        i++;
    }

    if(todos_iguales(clave, len) && es_valida)
        es_valida = false;

    return es_valida;
}

int main()
{
    Tclave clave;
    bool es_valida;
    obtener_clave(clave);
    es_valida = validar(clave);
    printf("%d\n", es_valida);

    return 0;
}