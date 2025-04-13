#include <stdio.h>
/* SECUENCIA */
/*
1) Hallar la superficie de un triángulo conociendo la base y la altura. Solicitarle los
datos de entrada al usuario.

int main()
{
    float base, altura;
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
    int hours;
    float salary_per_hour;
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
    int radius;
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
    int num;
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
    int num;
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
    int num1, num2, num3;

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
    int day;
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
    int month;
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

int main()
{
    float temp;
    char unit;
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
            printf("La temperatura en Celsius es: %.2f\n", (temp  - 32) * 5.0 / 9.0);
            break;
        default:
            printf("La unidad ingresada no es valida (debe ser C o F).\n");
            break;
    }
    return 0;
}
*/

/*
10) Dada una fecha con año, mes y día, informar si es correcta o no. Solicitarle los datos al usuario de forma independiente. Considerar años bisiestos.
*/



/*
Ingresar las 3 medidas de los lados de un triangulo y mostrar que tipo de triangulo es Equilatero, Escaleno, Isosceles.

#include <stdio.h>
int main()
{
    int lado_1, lado_2, lado_3;

    printf("Ingrese el lado 1 del triangulo: ");
    scanf("%d", &lado_1);

    printf("Ingrese el lado 2 del triangulo: ");
    scanf("%d", &lado_2);

    printf("Ingrese el lado 3 del triangulo: ");
    scanf("%d", &lado_3);

    if(lado_1 == lado_2 && lado_2==lado_3)
        printf("El triangulo es Equilatero.\n");

    else if(lado_1 != lado_2 && lado_2 != lado_3 && lado_3 != lado_1)
        printf("El triangulo es Escaleno.\n");

    else
        printf("El tirangulo es Isosceles.\n");

    return 0;
}
*/

/*
Solicitar al usuario el ingreso de la fecha actual, el ingreso de una fecha de nacimiento e indicar la edad correspondiente.

#include <stdio.h>
int main()
{
    int dia, mes, ano, dia_nacimiento, mes_nacimiento, ano_nacimiento, edad;
    printf("Ingrese la fecha actual:\n");
    printf("Día: ");
    scanf("%d", &dia);
    printf("Mes: ");
    scanf("%d", &mes);
    printf("Año: ");
    scanf("%d", &ano);

    printf("Ingrese su fecha de nacimiento:\n");
    printf("Día: ");
    scanf("%d", &dia_nacimiento);
    printf("Mes: ");
    scanf("%d", &mes_nacimiento);
    printf("Año: ");
    scanf("%d", &ano_nacimiento);

    edad = ano - ano_nacimiento;

    if (mes < mes_nacimiento || (mes == mes_nacimiento && dia < dia_nacimiento))
        edad -= 1;

    if (edad >= 0)
        printf("Usted tiene %d años.\n", edad);
    else
        printf("Las fechas ingresadas no son válidas.\n");

    return 0;
}
*/

/*
Ingresar una serie de numeros enteros finalizada en 0 y mostrar el mayor numero, el menor numero y el promedio de la serie

#include <stdio.h>
int main()
{   
    int num, mayor, menor, cantidad = 0, suma = 0;

    printf("Ingrese una serie de numeros enteros finalizada en 0:\n");
    scanf("%d", &num);

    mayor = num;
    menor = num;

    while (num != 0)
    {
        if (num > mayor)
            mayor = num;
        else if (num < menor)
            menor = num;
        suma += num;
        cantidad++;
        printf("Ingrese un numero: ");
        scanf("%d", &num);
    }

    if (cantidad > 0 ) {
        printf("El mayor numero es %d\n", mayor);
        printf("El menor numero es %d\n", menor);
        printf("El promedio es %d\n", suma / cantidad);
    } else {
        printf("No se ingresaron numeros.\n");
    }

    return 0;
}
*/

/*
// Solicitar al usuario el ingreso de una fecha e indicar que numero de dia del año es. Considerar años bisiestos.
//Ejemplo 1 de febrero es el numero 32 del año
*/

