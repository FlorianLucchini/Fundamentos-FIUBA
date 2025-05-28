### Registros
Se llama Registros, Structs, Records.
Permite almacenar datos de distintos tipos en una misma variable (El cual era nuestro talón de aquiles en los arrays).

## Sintaxis:
```c
struct mi_registro
{
    <tipo_1> campo_1
    <tipo_2> campo_2
    ...
    <tipo_n> campo_n
}
```
## Ejemplo
```c
struct alumno
{
    char nombre[31]
    int padron
    char email[51]
    int notas[5]
    float promedio
} Alumno = {
    ...
}
```

## Utlización
```c
typedef struct
{
    char nombre[31]
    int padron
    char email[51]
    int notas[5]
    float promedio
} alumno;

alumno Alumno_1
Alumno_1.nombre ---> %s
Alumno_1.padron ---> %d
```

### Tablas
La idea es expandir los registros, es decir, utilizar arrays de registros, esto permite utilizar Tablas; un venctor de Structs.

### Usar structs por referencia (Punteros)
Para poder pasar structs por referencia a una funcion, y de esta forma modificar un valor dentro de la funcion para el struct y que este tenga impacto a nivel total del programa, pasamos por referencia el struct:
```c
    Tstruct struct;
    function(&struct);
```

## Definicion de la funcion:
```c
    void functon(Tstruct *struct)
    {
        ...;
    }
```

### Dentro de la funcion:
```c
    ...
    struct->campo_1 = 123; // Desreferenciamos el struct y accedemos al campo.
    strcpy(struct->campo_2, "Hola"); // Lo mismo si es un string.
    ...
```