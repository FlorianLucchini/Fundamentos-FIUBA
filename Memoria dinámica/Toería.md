# 🧠 Manejo de Memoria en C

## Definición
Dispositivo que permite almacenar información en forma binaria, mediante celdas que almacenan bits agrupados en bytes (8 bits). Cada celda tiene una dirección única, y múltiples celdas forman lo que llamamos **memoria**.

## 📦 División de la Memoria en un Programa

**Arquitectura: Ejemplo en 32 bits — 4 GB totales, 3 GB para el proceso**

La memoria se divide en **segmentos lógicos**:

### 🟠 Memoria Estática

1. **Text/Code Segment**
   - Contiene el código máquina compilado del programa.
   - Es de **solo lectura**.

2. **Data Segment**
   - Variables globales o estáticas **inicializadas**.
   - Asignadas en tiempo de compilación.

3. **BSS Segment**
   - Variables globales o estáticas **no inicializadas**.
   - El sistema las inicializa automáticamente a cero.

### 🟢 Memoria Dinámica

4. **Heap (Montículo)**
   - Se utiliza para asignación dinámica de memoria mediante `malloc()`, `calloc()`, `realloc()` y se libera con `free()`.
   - Crece **hacia direcciones de memoria más altas**.
   - Su gestión **depende del programador**.

5. **Stack (Pila)**
   - Guarda variables locales, parámetros y dirección de retorno.
   - Se organiza como **estructura LIFO** (Last In, First Out).
   - Crece **hacia direcciones más bajas**.
   - Su gestión es **automática por el compilador**.

> ⚠️ Si el Stack y el Heap colisionan → **Stack Overflow** o comportamiento indefinido.

---

## 🧶 Punteros y Memoria Dinámica

### ¿Qué es un puntero?
Variable especial que **almacena una dirección de memoria**.

```c
int x = 5;
int* p = &x; // p apunta a x
*p = 8;      // cambia el valor de x a 8
```

### 💡 Declaración de punteros
```c
int *pi; // puntero a entero
char *pc; // puntero a char
```

### ⚙️ Memoria dinámica con `malloc`

```c
int *p = (int *)malloc(sizeof(int));
*p = 10; // uso normal de la memoria dinámica
free(p); // liberar memoria
```

> ⚠️ Si no se libera → fuga de memoria (leak), incluso si el programa termina.

---

## 🧱 Estructuras dinámicas

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

### ✅ Matriz dinámica (punteros dobles)
```c
int **matriz = (int **)malloc(sizeof(int *) * 4);
for (int i = 0; i < 4; i++)
    matriz[i] = (int *)malloc(sizeof(int) * 5);

// Liberar memoria
for (int i = 0; i < 4; i++)
    free(matriz[i]);
free(matriz);
```

> 🔁 Permite construir matrices irregulares

---

## 🧠 Detalles útiles e interesantes

- El **stack** es ideal para funciones temporales (recursividad, llamadas simples).
- El **heap** permite estructuras dinámicas que persisten más allá de un bloque.
- Variables dinámicas pueden sobrevivir a las funciones si se devuelve su dirección.

```c
int* crear() {
    int* p = (int *)malloc(sizeof(int));
    *p = 123;
    return p;
}
```