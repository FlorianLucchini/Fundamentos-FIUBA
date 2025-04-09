#include <stdio.h>
/* SECUENCIA */
/*
1) Hallar la superficie de un triángulo conociendo la base y la altura. Solicitarle los
datos de entrada al usuario.

int main() {
    float base = 0, altura = 0;
    printf("Ingrese la base: \n");
    scanf("%f", &base);
    printf("Ingrese la altura: \n");
    scanf("%f", &altura);
    printf("La superficie es: %.2f\n", base * altura / 2);
}

*/

/*
2) Calcular el sueldo de un operario ingresando por teclado la cantidad de horas que
trabajó en el mes y el valor de la hora. Mostrarle el resultado al usuario con un
mensaje adecuado.

int main() {
    int hours = 0;
    float salary_per_hour = 0;
    printf("Ingrese la cantidad de horas trabajadas: \n");
    scanf("%d", &hours);
    printf("Ingrese el sueldo por hora: \n");
    scanf("%f", &salary_per_hour);
    printf("El sueldo es: %.2f\n", hours * salary_per_hour);
}
*/

/*
3) Ingresar el radio de una esfera y calcular el volumen.

int main() {
    int radius = 0;
    printf("Ingrese el radio de la esfera: \n");
    scanf("%d", &radius);
    printf("El volumen es: %.2f\n", 4 * 3.14 * (radius * radius * radius) / 3);
}
*/

/*
4) Calcular y mostrar la suma de los n primeros números naturales. Siendo n un
número ingresado por el usuario. Usar fórmula [ n.(n+1) ] / 2

int main() {
    int num = 0;
    printf("Ingrese el número: \n");
    scanf("%d", &num);
    printf("La suma de los n primeros números es: %d\n", (num * (num + 1)) / 2);
}
*/

/* CONDICIONALES */
/*
5) Ingresar un número entero y decir si:
a) es par o impar.
b) es mayor, menor o igual a cero.
*/

int main() {
    int num = 0;
    printf("Ingrese un numero: \n");
    scanf("%d", &num);

    // a)
    if(num % 2 == 0)
        printf("El numero es par.\n");
    else
        printf("El numero es impar.\n");
    
    // b)
    if(num > 0)
        printf("El numero es mayor que cero.\n");
    else
        if(num < 0)
            printf("El numero es menor que cero.\n");
        else
            printf("El numero es igual a cero.\n");

    return 0;
}