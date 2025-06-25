# 🧾 Registros en C (Structs)

## 🧠 ¿Qué son?
Los **registros**, también conocidos como `structs` o `records`, permiten agrupar datos de **diferentes tipos** dentro de una misma variable. Son ideales cuando necesitamos representar entidades complejas, como un alumno, producto, etc.

> 🧩 A diferencia de los arrays, que solo almacenan datos del mismo tipo, los structs permiten mezclar enteros, cadenas, arreglos, etc.

---

## 🧱 Sintaxis Básica

```c
struct nombre_struct {
    tipo1 campo1;
    tipo2 campo2;
    ...
    tipoN campoN;
};
```

---

## 📌 Ejemplo

```c
struct alumno {
    char nombre[31];
    int padron;
    char email[51];
    int notas[5];
    float promedio;
} Alumno = {
    // valores opcionales
};
```

---

## ✅ Uso habitual con `typedef`

```c
typedef struct {
    char nombre[31];
    int padron;
    char email[51];
    int notas[5];
    float promedio;
} alumno;

alumno Alumno_1;
printf("%s", Alumno_1.nombre);
printf("%d", Alumno_1.padron);
```

> `typedef` nos permite evitar tener que escribir `struct` todo el tiempo.

---

## 📊 Tablas (Vectores de Structs)

Podemos construir **tablas** de registros usando arrays:

```c
alumno lista_alumnos[100];
```

Esto permite organizar información estructurada de forma ordenada y eficiente, como si fuera una **tabla de base de datos en memoria**.

---

## 📬 Paso por referencia de structs

Para **modificar un struct desde una función**, debemos pasarlo por referencia (usando punteros):

### 🔁 Definición y llamada
```c
alumno a;
modificar(&a);
```

### 🔧 Implementación
```c
void modificar(alumno *a) {
    a->padron = 123456;
    strcpy(a->nombre, "Juan Pérez");
}
```

> Usamos `->` para acceder a los campos del struct a través de un puntero (desreferenciación).

---

## 🛠️ Tips útiles

- Los structs pueden incluir arrays, otros structs o punteros.
- Se pueden usar como parámetros y retornos de funciones.
- Muy útiles para representar entidades del mundo real.