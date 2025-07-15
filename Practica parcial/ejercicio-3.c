// Una tienda almacena los datos de sus ventas diarias en un archivo binario Ventas.dat. Cada registro contiene:
// - ID de Venta (entero)
// - ID de Producto (entero)
// - Cantidad vendida (entero)
// - Precio unitario (flotante)
// - Nombre del vendedor (40 caracteres)

// Se pide desarrollar un programa modular en C que permita:

// a) Carga de Ventas: Implementar un módulo para registrar ventas en el archivo Ventas.dat. La carga se detiene cuando el ID de Venta ingresado es 0.

// b) Filtrar por Vendedor: Crear una función que solicite el nombre de un vendedor y cargue todas sus ventas desde Ventas.dat a una tabla en memoria (asumir un máximo de 250 ventas).

// c) Ordenar y Calcular Total:
//      1.- Ordenar la tabla del punto "b" por ID de Producto de forma ascendente utilizando el método de ordenamiento burbuja optimizado (bubble_sort_optimized).
//      2.- Mostrar la tabla ordenada por pantalla.
//      3.- Calcular y mostrar el monto total vendido por ese vendedor (sumatoria de cantidad_vendida * precio_unitario de cada registro de la tabla).

// d) Generar Reporte CSV: A partir de la tabla ya ordenada, generar un archivo de texto llamado ReporteVendedor.csv. Cada línea del archivo debe contener los datos de una venta, separados por comas: ID_Venta,ID_Producto,Cantidad,PrecioUnitario.