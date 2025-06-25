# 🔁 Recursividad en C

## ¿Qué es la recursividad?
Una técnica de programación donde una función se llama a sí misma, directa o indirectamente.

### ✔️ Componentes
- **Caso base**: condición de corte. Debe existir sí o sí.
- **Caso recursivo**: reduce el problema acercándose al caso base.

### ✳️ Ejemplo clásico: Factorial
```c
int factorial(int numero) {
    if (numero == 0)
        return 1;
    return numero * factorial(numero - 1);
}
```

## Recursividad vs Iteración

| Aspecto         | Recursividad                 | Iteración                     |
|-----------------|------------------------------|-------------------------------|
| Modo de repetición | Llamadas a sí misma          | Ciclos `for`, `while`         |
| Terminación     | Caso base                    | Condición booleana            |
| Legibilidad     | Más clara en estructuras complejas | Más eficiente en recursos     |

### ✔️ Cuándo usar recursividad
- Para estructuras recursivas (árboles, torres de Hanoi).
- Para claridad o correspondencia matemática.

### ❌ Cuándo **NO** usarla
- Cuando hay mucha memoria en juego (arrays grandes).
- Cuando el control del flujo es impredecible.
- Cuando la iteración es más clara y eficiente.

## Clasificación de recursividad
- **Directa**: una función se llama a sí misma.
- **Indirecta**: dos o más funciones se llaman mutuamente.

## Modos de expansión
- **Profundidad**: se llama una vez por iteración.
- **Frondosidad**: se llama múltiples veces por iteración.