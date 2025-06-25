# 📁 Archivos en C

## 🧩 ¿Qué es un archivo?
Un archivo es una unidad lógica de almacenamiento que conecta y preserva datos relacionados entre sí, permitiendo su conservación a largo plazo, incluso después de cerrar el programa.

---

## ✨ Características

- **Dinámicos:** su tamaño puede variar (a diferencia de estructuras como arrays).
- **Persistentes:** los datos se almacenan fuera de la memoria RAM.
- **Limitados por el medio físico:** disco, USB, etc.

---

## 📂 Tipos de Archivos

- **Binarios:** almacenan datos en forma cruda, sin interpretación como texto.
- **De texto:** `.txt`, `.csv`, etc. Cada byte se interpreta como un carácter.

---

## 🔄 Modalidades de Acceso

### 📜 Acceso Secuencial

- Se accede elemento por elemento, de forma lineal.
- Siempre se comienza desde el primer elemento.
- Solo permite agregar elementos al final.
- **No se pueden modificar ni reordenar elementos existentes.**

### 🎯 Acceso Directo o Aleatorio

- Se puede acceder directamente a una posición si se conoce.
- Permite modificar elementos existentes.
- También permite agregar al final.
> ℹ️ En esta cursada se aborda **acceso secuencial**.

---

## 🔚 Marca de Fin
Todos los archivos poseen una **flag** que marca el final del archivo (EOF).

---

## 🧱 Pasos para Usar un Archivo en C

### 1️⃣ Declarar un puntero a `FILE`
```c
FILE *archivo;
```

### 2️⃣ Abrir el archivo con `fopen()`
```c
archivo = fopen("C:\\datos\\productos.dat", "r+");
```
**Modos de apertura:**
| Modo | Descripción |
|------|-------------|
| `"r"`  | Solo lectura (el archivo debe existir). |
| `"r+"` | Lectura y escritura (debe existir). |
| `"w"`  | Escritura (crea o sobreescribe). |
| `"a"`  | Agregar al final (crea si no existe). |
| `"b"`  | Archivo binario (se combina con los anteriores, ej. `"rb"`). |

---

## 📥 Lectura de archivos binarios con `fread()`

```c
fread(&registro, sizeof(registro), 1, archivo);
```

- **Puntero:** dirección donde guardar los datos leídos.
- **Tamaño:** `sizeof(registro)` indica cuántos bytes leer.
- **Cantidad:** cuántos elementos leer (usualmente 1).
- **Archivo:** puntero al archivo abierto.

---

## 📤 Escritura de archivos binarios con `fwrite()`

```c
fwrite(&registro, sizeof(registro), 1, archivo);
```

- **Puntero:** dirección desde donde tomar los datos a escribir.
- **Tamaño:** cantidad de bytes a escribir.
- **Cantidad:** cuántos registros escribir (usualmente 1).
- **Archivo:** puntero al archivo abierto.

---

## 🔍 Control de fin de archivo con `feof()`

Detecta si se llegó al final del archivo.

```c
int feof(FILE *fichero);
```

### Ejemplo:
```c
while (!feof(archivo)) {
    // leer datos...
}
```

---

## 🔐 Cierre de archivo con `fclose()`

Siempre que se finaliza la manipulación de un archivo se debe cerrarlo:

```c
fclose(archivo);
```

> ⚠️ No cerrar archivos puede causar pérdida de datos o corrupción.

---

# 📄 Archivos de Texto

Archivos donde cada carácter se almacena como un byte según la codificación ASCII o similar. Son interpretables por humanos.

### 📑 Tipos comunes:

- `.txt` → texto sin delimitadores.
- `.csv` → campos separados por coma.
- Otros: delimitados por tabulaciones, longitud fija, etc.

---

## 📖 Lectura en archivos de texto

### Opciones:

```c
fgetc(archivo);        // lee un solo carácter
fgets(buffer, n, archivo); // lee una línea completa
fscanf(archivo, "..."); // lee con formato
```

---

## ✍ Escritura en archivos de texto

### Opciones:

```c
fputc('c', archivo);      // escribe un carácter
fputs("cadena", archivo); // escribe una cadena
fprintf(archivo, "...");  // escribe con formato
```