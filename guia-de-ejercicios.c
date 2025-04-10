#include <stdio.h>
/* SECUENCIA */
/*
1) Hallar la superficie de un triángulo conociendo la base y la altura. Solicitarle los
datos de entrada al usuario.

int main()
{
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

int main()
{
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

int main()
{
    int radius = 0;
    printf("Ingrese el radio de la esfera: \n");
    scanf("%d", &radius);
    printf("El volumen es: %.2f\n", 4 * 3.14 * (radius * radius * radius) / 3);
}
*/

/*
4) Calcular y mostrar la suma de los n primeros números naturales. Siendo n un
número ingresado por el usuario. Usar fórmula [ n.(n+1) ] / 2

int main()
{
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

int main()
{
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
*/

/*
6) Ingresar tres números y hallar el mayor.

int main()
{
    int num1 = 0, num2 = 0, num3 = 0;

    printf("Ingrese tres numeros:\n");
    scanf("%d %d %d", &num1, &num2, &num3);

    if (num1 > num2 && num1 > num3)
        printf("El mayor es el numero %d\n", num1);
    else
        if (num2 > num1 && num2 > num3)
            printf("El mayor es el numero %d\n", num2);
        else
            printf("El mayor es el numero %d\n", num3);
    
    return 0;
}
*/

/*
7) Ingresar un número (del 1 al 7) que representa un día de la semana, escribir el
nombre del día correspondiente. En el caso de haber ingresado un número fuera de
rango indicarle del error al usuario.

int main()
{
    int day = 0;
    printf("Ingresar un número (del 1 al 7) que representará un día de la semana.\n");
    scanf("%d", &day);

    switch (day)
    {
    case 1:
        printf("El día es lunes.\n");
        break;
    case 2:
        printf("El día es martes.\n");
        break;
    case 3:
        printf("El día es miércoles.\n");
        break;
    case 4:
        printf("El día es jueves.\n");
        break;
    case 5:
        printf("El día es viernes.\n");
        break;
    case 6:
        printf("El día es sábado.\n");
        break;
    case 7:
        printf("El día es domingo.\n");
    default:
        printf("El numero ingresado no es valido (debe ser del 1 al 7).\n");
        break;
    }

    return 0;
}
*/

/*
8) Ingresar un número (del 1 al 12) que representa un mes, indicar la cantidad de
días de dicho mes.

int main()
{
    int month = 0;
    printf("Ingresar un número (del 1 al 12) que representará un mes.\n");
    scanf("%d", &month);

    switch (month)
    {
    case 1:
        printf("El mes es enero.\n");
        break;
    case 2:
        printf("El mes es febrero.\n");
        break;
    case 3:
        printf("El mes es marzo.\n");
        break;
    case 4:
        printf("El mes es abril.\n");
        break;
    case 5:
        printf("El mes es mayo.\n");
        break;
    case 6:
        printf("El mes es junio.\n");
        break;
    case 7:
        printf("El mes es julio.\n");
        break;
    case 8:
        printf("El mes es agosto.\n");
        break;
    case 9:
        printf("El mes es septiembre.\n");
        break;
    case 10:
        printf("El mes es octubre.\n");
        break;
    case 11:
        printf("El mes es noviembre.\n");
        break;
    case 12:
        printf("El mes es diciembre.\n");
        break;
    default:
        printf("El numero ingresado no es valido (debe ser del 1 al 12).\n");
        break;
    }
    return 0;
}
*/

/*
9) Solicitar al usuario el ingreso de una temperatura (puede tener decimales por
ejemplo 24.5) y la unidad en la que se encuentra (siendo solo un carácter F ó C).
Luego el programa debe mostrar la temperatura ingresada, convertida en la otra
unidad.
La relación entre temperaturas Celsius y Fahrenheit está dada por la fórmula:
C=5.0 / 9.0 * (F − 32)
*/

int main()
{
    float temp = 0;
    char unit = "";
    printf("Ingrese la temperatura:\n");
    scanf("%f", &temp);
    getchar();
    printf("Ingrese la unidad (C o F):\n");
    scanf("%c", &unit);

    switch (unit)
    {
        case 'C':
            printf("La temperatura en Fahrenheit es: %.2f\n", temp * 9.0 / 5.0 + 32);
            break;
        case 'F':
            printf("La temperatura en Celsius es: %.2f\n", temp * 5.0 / 9.0 - 32);
            break;
        default:
            printf("La unidad ingresada no es valida (debe ser C o F).\n");
            break;
    }
    return 0;
}