// Se tienen los siguientes datos de los empleados de una empresa:
// Apellido (35 caracteres)
// Nombre (35 caracteres)
// Fecha de Nacimiento (día, mes y año)
// Fecha de Ingreso (día, mes y año)
// Sueldo Básico
// Se conoce la cantidad N de empleados y la fecha de procesamiento.

// Se pide: Imprimir un listado con los apellidos y nombres de las personas que cumplan años en el mes y calcular e informar una suma de regalo equivalente al uno por mil del sueldo por cada año cumplido.

// Tipos de estructuras propuestas:

#include <stdio.h>

#define MF_CHARS 36
#define MF_EMPLEADOS 3

typedef char t_string[MF_CHARS];

typedef struct {
 int dia;
 int mes;
 int anio;
} t_fecha;

typedef struct {
 t_string apellido;
 t_string nombre;
 t_fecha fecha_nacimiento;
 t_fecha fecha_ingreso;
 float sueldo_basico;
} t_empleado;

void cargar_fecha(t_fecha Fecha)
{
    printf("Dia:\n");
    scanf("%d", Fecha.dia);

    printf("Mes:\n");
    scanf("%d", Fecha.mes);

    printf("Año:\n\n");
    scanf("%d", Fecha.anio);

    return;
}

void cargar_empleado(t_empleado Empleados[MF_EMPLEADOS])
{
    int i;
    for(i = 0; i < MF_EMPLEADOS; i++)
    {
        printf("\nIngrese el Nombre:\n");
        scanf("%s",Empleados[i].nombre);

        printf("Ingrese el Apellido:\n");
        scanf("%s",&Empleados[i].apellido);

        printf("Ingrese el Sueldo Basico:\n");
        scanf("%f",Empleados[i].sueldo_basico);

        printf("Ingrese la fecha de nacimiento:\n");
        cargar_fecha(Empleados[i].fecha_nacimiento);

        printf("Ingrese la fecha de ingreso:\n");
        cargar_fecha(Empleados[i].fecha_ingreso);
    }
}