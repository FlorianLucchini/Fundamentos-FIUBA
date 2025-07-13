// Desarrollar un programa que muestre la suma de los primeros N números naturales. El número N lo debe ingresar el usuario.

int solicitar_num(int *num)
{
    printf("Ingrese un numero: ");
    scanf("%d", num);
}

int suma_n(int num)
{
    if(num == 1)
        return 1;
    else
        return num + suma_n(num - 1);
}

int main()
{
    int num;
    solicitar_num(&num);
    printf("%d", suma_n(num));

    return 0;
}