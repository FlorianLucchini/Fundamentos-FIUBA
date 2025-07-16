// Desarrollar un programa que calcule y muestre por pantalla los primeros N términos de la sucesión de Fibonacci en forma recursiva

int fibonacci(int n) 
{
    if(n <= 1)
        return n;
    else    
        return fibonacci(n - 2) + fibonacci(n - 1);
}

int main()
{
    int i, n = 6;
    for(i = 0; i < n; i++)
        printf("%d ", fibonacci(i));
    return 0;
}