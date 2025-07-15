// Un club deportivo gestiona la información de sus socios en un archivo binario Socios.dat. La estructura de cada socio es:
// - Número de socio (entero)
// - Nombre y Apellido (60 caracteres)
// - Categoría (ej: "Activo", "Cadete", "Vitalicio", 30 caracteres)
// - Año de ingreso (entero)
// - Cuota al día (booleano, true o false)

// Se pide desarrollar un programa modular en C que permita:

// a) Carga de Socios: Crear un módulo para agregar socios al archivo Socios.dat. Validar que el número de socio sea mayor a cero para continuar la carga.

// b) Cargar Morosos a Memoria: Desarrollar una función que lea el archivo Socios.dat y cargue en una tabla en memoria (máximo 300 socios) únicamente a los socios que no tienen la cuota al día (cuota_al_dia == false).

// c) Ordenar y Buscar:
//      1.- Ordenar la tabla de morosos por número de socio de menor a mayor, utilizando el método de ordenamiento por inserción (insertion_sort).
//      2.- Una vez ordenada, solicitar al usuario un número de socio y utilizar la búsqueda binaria (binary_search) para encontrarlo en la tabla.
//      3.- Si se encuentra, mostrar todos sus datos por pantalla. Si no, informar que "El socio moroso no fue encontrado".

// d) Generar Archivo de Socios Antiguos: Recorrer el archivo binario completo Socios.dat y generar un nuevo archivo binario, Antiguos.dat, que contenga únicamente a los socios que ingresaron antes del año 2000. La estructura del nuevo archivo debe ser la misma.