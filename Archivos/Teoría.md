### Archivos
Conexión de datos; que tienen una relación entre si. Se almacenan como unidad en un dispositivo, nos habilita a almacenar los datos por largos periodos de tiempo.

## Caractrísticas

# Son dinámicos:
Su tamaño no es fijo (Algo que hasta ahora no habíamos usado).
Están limitados por el medio que se use para almacenarlos.

# Tipos
- Binarios.
- De Text; .csv, .txt. A cada byte le asigna un caracter. Archivos de texto plano.

## Modalidad de acceso
Esto nos permite clasificarlos. Según la modalidad elegida, se manipularán de una forma u otra.

# Secuenciales
- Accedemos elemento a elemento y así lo trataremos; uno por uno.
- Siempre comenzaremos por el primero de los elementos.
- Solo podremos agregar elementos al final del archivo (**NO** permite intercambiar elementos).
- Los elementos que ya están en el archivo **NO** pueden modificarse.

# Directo o Aleatorio
- Tiene ventajas sobre el anterior; si conocemos la ubicación de un elemento, podremos acceder directamente al mismo. (Azcurra solo abarca secuenciales).
- Se pueden agregar archivos al final.
- Se pueden modificar elementos ya existentes.

## Marca de fin
Todos los archivos tienen una flag o marca que señaliza el final del mismo.

### Pasos para usar un archivo

## 1. Declaramos una variable de tipo puntero a una estructura FILE
```c
    FILE *archivo
```

## 2. Abrir el archivo
Utilizaremos una funcion llamada fopen("<ruta> <nombre_del_archivo>", "<modo_de_apertura>"). Si no puede abrir el archivo nos va a devolver **null**.

```c
    archivo = fopen("C:\\datos\\productos.dat", "r+");
```

# Modo de apertura 
- "r" --> Solo lectura. **(Exige que exista el archivo)**
- "r+" --> Lectura y escritura. **(Exige que exista el archivo)**
- "w" --> Sobreescritura. **(Si no existe lo crea, si ya existe se sobreescribe)**
- "a" --> Agregar datos. **(Si no existe lo crea)**
- "b" --> Indica archivo binario.

### Pasos para leer un archivo
Utilizaremos la funcion fread(<puntero_registro>, <tamaño>, <cantidad>, <dir_archivo>). Esta función nos retorna el numero de registros leídos (Siempre devuelve 1 en este caso).


## Puntero
Dirección en la cual se deja la información leida del archivo. Un puntero a un struct que me permita almacenar los datos que traigo del archivo.

## Tamaño
Cantidad de bytes a leer del archivo, se vincula con la cantidad de bytes que tiene mi struct.

## Cantidad
Elementos a leer, o sea de a cuantos; siempre usaremos 1.

## Dirección del archivo
Vamos a usar el puntero archivo de tipo FILE, que declaramos antes.

## Ejemplo
```c
    fread(&registro, sizeof(registro), 1, archivo);
```

### Pasos para escribir un archivo
Utilizaremos la funcion  fwrite(<puntero_registro>, <tamaño>, <cantidad>, <dir_archivo>). Esta función nos retorna el numero de registros grabados (Siempre devuelve 1 en este caso).

## Puntero
Dirección a partir de la cual voy a extraer información para escribirla en el archivo. Un puntero a un struct que me permita extraer los datos que envio al archivo.

## Tamaño
Cantidad de bytes a leer del archivo, se vincula con la cantidad de bytes que tiene mi struct.

## Cantidad
Elementos a leer, o sea de a cuantos; siempre usaremos 1.

## Dirección del archivo
Vamos a usar el puntero archivo de tipo FILE, que declaramos antes.

## Ejemplo
```c
    fwrite(&registro, sizeof(registro), 1, archivo);
```

## Control de fin de archivo
Para determinar si un archivo termino utilizamos la funcion feof(). Devuelve 0 si es el final, en caso contrario devuelve otro valor.

# Definición:
```c
    int feof(FILE *fichero)
```

# Ejemplo:
```c
    while ( !feof( archivo ) )
    {
        ...
    }
```

## Cierre del archivo
Una vez se terminan de realizar las operaciones respectivas, se debe cerrar el archivo. No es forma adecuada cerrar el programa directamente, ya que podrían perderse datos.
Evitar varias aperturas y cierres en un mismo programa.

# Definición:
```c
    int fclose(FILE *fichero)
```

# Ejemplo
```c
    fclose( archivo );
```

### Archivos de texto
Solo están formados por caracteres, a cada caracter se le corresponde un byte. Esto permite una interpretación inmediata.

## Tipos
- ".csv" --> Delimitados por coma.
- ".txt" --> Sin delimitadores.
- Otro tipo de delimitadores; tabulaciones, o longitud fija.

## Acceso
Utilizaremos el formato secuancial, como veniamos haciendo antes con los binarios.

# Leer
Tenemos tres alternativas:

- fgetc(<puntero_al_archivo>)

- fgets(<cadena_destino>, <cantidad_bytes>, <puntero_al_archivo>)

- fscanf(<puntero_al_archivo>, <cadena_destino>)

# Escribir
Tenemos tres alternativas:

- fputc(<caracter>, <puntero_al_archivo>)
    
- fputs(<cadena>, <puntero_al_archivo>)

- fprintf(<puntero_al_archivo>, <cadena>)