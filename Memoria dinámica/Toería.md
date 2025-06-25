
# 🧠 Manejo de Memoria en C

Este documento resume los conceptos clave sobre cómo se organiza y se gestiona la memoria en C, incluyendo punteros, memoria dinámica, estructuras complejas, buenas prácticas y herramientas como **Valgrind**.

---

## 🧾 ¿Qué es la Memoria?

La **memoria** permite almacenar información binaria en forma de celdas de 8 bits (1 byte), cada una con una **dirección única**. En programación en C, entender cómo se organiza y se accede a esta memoria es fundamental para escribir código eficiente y seguro.

---

## 📦 Segmentación de la Memoria en C

Cuando se ejecuta un programa en C, el sistema operativo le asigna un espacio en memoria dividido en **segmentos lógicos**. Ejemplo típico: arquitectura de 32 bits → 4 GB (3 GB para el proceso, 1 GB para el kernel).

### 🔸 Segmentos de Memoria Estática

| Segmento       | Contenido                                                                 | Características              |
|----------------|---------------------------------------------------------------------------|------------------------------|
| **Text/Code**  | Código máquina del programa                                               | Solo lectura                 |
| **Data**       | Variables globales o estáticas **inicializadas**                         | Asignadas al compilar        |
| **BSS**        | Variables globales o estáticas **no inicializadas**                      | Inicializadas a cero por el SO |

### 🟢 Segmentos de Memoria Dinámica

| Segmento | Contenido                                              | Características                                   |
|----------|--------------------------------------------------------|--------------------------------------------------|
| **Heap** | Memoria dinámica (`malloc`, `calloc`, `realloc`)      | Crece hacia direcciones más altas. Manual        |
| **Stack**| Variables locales, parámetros, direcciones de retorno | Crece hacia direcciones más bajas. Automática    |

> ⚠️ **Stack Overflow**: ocurre cuando el Stack y el Heap colisionan.

---

## 🧶 Punteros en C

Los punteros almacenan **direcciones de memoria**. Permiten manipular directamente valores en memoria y son clave para estructuras dinámicas.

```c
int x = 5;
int* p = &x;  // p apunta a x
*p = 8;       // cambia el valor de x a 8
```

### Declaración de punteros

```c
int *pi;    // puntero a entero
char *pc;   // puntero a char
```

---

## ⚙️ Funciones para Memoria Dinámica

Se definen en `<stdlib.h>`:

| Función   | Descripción                                      |
|-----------|--------------------------------------------------|
| `malloc`  | Reserva un bloque de memoria (no inicializada)   |
| `calloc`  | Igual que malloc, pero inicializa a cero         |
| `realloc` | Cambia el tamaño de un bloque previamente asignado |
| `free`    | Libera memoria previamente asignada              |

```c
int *p = (int *)malloc(sizeof(int));
*p = 10;
free(p);
```

> ⚠️ Siempre validar que `malloc` o `calloc` no devuelvan `NULL`.

---

## 🧱 Estructuras Dinámicas Comunes

### ✅ Arreglo dinámico
```c
int *p = (int *)malloc(sizeof(int) * 100);
p[0] = 5;
free(p);
```

### ✅ Struct dinámico
```c
typedef struct {
    int legajo;
    float sueldo;
} Empleado;

Empleado *pe = (Empleado *)malloc(sizeof(Empleado));
pe->legajo = 145;
free(pe);
```

### ✅ Matriz dinámica (doble puntero)
```c
int **matriz = (int **)malloc(sizeof(int *) * 4);
for (int i = 0; i < 4; i++)
    matriz[i] = (int *)malloc(sizeof(int) * 5);

// Liberar
for (int i = 0; i < 4; i++)
    free(matriz[i]);
free(matriz);
```

> 🔁 Ideal para crear **matrices irregulares** (filas de distinto tamaño)

---

## 🧠 Detalles y Buenas Prácticas

- Siempre que uses `malloc` o `calloc`, **libera la memoria** con `free`.
- Usar `sizeof(tipo)` evita errores por cambio de arquitectura.
- Verificá siempre que los punteros no sean `NULL`.
- **No hagas free de un puntero dos veces** ni de algo que no fue asignado dinámicamente.
- El `heap` permite crear datos que sobreviven al retorno de una función:

```c
int* crear() {
    int* p = (int *)malloc(sizeof(int));
    *p = 123;
    return p;
}
```

---

## 🧪 Herramienta: Valgrind

**Valgrind** es un conjunto de herramientas para Linux/Mac que detecta errores de memoria. La más usada es `memcheck`.

### Detecta:
- Uso de memoria no inicializada
- Lectura/escritura en memoria ya liberada
- Overflows en bloques asignados
- Fugas de memoria

### 🔧 Instalación

```bash
# Debian/Ubuntu
sudo apt-get install valgrind

# Arch
sudo pacman -S valgrind

# Fedora
sudo dnf install valgrind

# MacOS (con Homebrew)
brew install valgrind
```

### ▶️ Ejecución

```bash
gcc -g -o programa programa.c
valgrind --leak-check=full ./programa
```

### 🪟 Alternativa en Windows

[Dr. Memory](https://drmemory.org/page_download.html) es una alternativa compatible.

---

## 📚 Bibliografía útil

- *Programación en C*, Joyanes Aguilar – McGraw-Hill
- *Computer Systems: A Programmer’s Perspective*, Bryant & O’Hallaron – Pearson
- *The C Programming Language*, Kernighan & Ritchie – Prentice Hall
- [Man page malloc(3)](https://man7.org/linux/man-pages/man3/malloc.3.html)