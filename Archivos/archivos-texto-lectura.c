#include <stdio.h>

#define MAX_FGETS 80
#define MAX_FSCANF 40

void lectura_fgetc(FILE *archivo)
{
    char caracter;

    caracter = fgetc(archivo);
    while (caracter != EOF)
    {
        printf("%c", caracter);
        caracter = fgetc(archivo);
    }

    fclose(archivo);
}

void lectura_fgets(FILE *archivo)
{
    char caracteres[MAX_FGETS];

    while (feof(archivo) == 0)
    {
        fgets(caracteres, MAX_FGETS, archivo);
        printf("%s\n", caracteres);
    }

    fclose(archivo);
}

void lectura_fscand(FILE *archivo)
{
    char cadena[MAX_FSCANF];

    fscanf(archivo, "%s", cadena);
    while (feof(archivo) == 0)
    {
        printf("%s\n", cadena);
        fscanf(archivo, "%s", cadena);
    }

    fclose(archivo);
}

void main()
{
    FILE *archivo;
    archivo = fopen("texto1.txt", "rt");

    if (archivo == NULL)
        printf("\nError de apertura del archivo. \n\n");
    else
    {
        printf("\nLectura con fgetc:\n");
        lectura_fgetc(archivo);
        printf("\nLectura con fgets:\n");
        lectura_fgets(archivo);
        printf("\nLectura con fscanf:\n");
        lectura_fscand(archivo);
    }

    return;
}
