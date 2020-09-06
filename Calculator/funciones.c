#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int menu(double a, double b)
{
    int opcion;
    printf("--------------------Calculadora--------------------\n\n");

    opcion1(a);
    opcion2(b);
    printf("3. Calcular todas las operaciones.\n");
    printf("4. Informar resultados.\n");
    printf("5. Salir\n\n");
    printf("Elija una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

void opcion1(double a)
{
    if(a==(int)a)
    {
        printf("1. Ingresar primer operando (A=%d).\n", (int)a);
    }
    else
    {
        printf("1. Ingresar primer operando (A=%.3lf)\n", a);
    }
}

void opcion2(double b)
{
    if(b==(int)b)
    {
        printf("2. Ingresar segundo operando (B=%d)\n", (int)b);
    }
    else
    {
        printf("2. Ingresar segundo operando (B=%.3lf)\n", b);
    }
}

double getDouble(char mensaje[])
{
    double valorDouble;
    printf("%s", mensaje);
    scanf("%lf", &valorDouble);
    return valorDouble;
}

void calculateOperations(double a, double b, double suma, double resta, double mult, double div, long long int factA, long long int factB)
{
    suma = operation('+', a, b);
    resta = operation('-', a, b);
    mult = operation('*', a, b);
    div = operation('/', a, b);
    factA = fact(a);
    factB = fact(b);
}

double operation(char op, double a, double b)
{
    double r;
    switch (op)
    {
    case '+':
        r = a + b;
        break;
    case '-':
        r = a - b;
        break;
    case '/':
        if (b != 0)
        {
            r = a / b;
        }
        break;
    case '*':
        r = a * b;
        break;
    }
    return r;
}

long long int fact(double numero)
{
    long long int f = 1;
    if(numero > -1 && numero < 21 && numero==(long long int)numero)
    {
        for (int i=1; i<=numero; i++)
        {
            f = f * i;
        }
    }
    else
    {
        f = 0;
    }

    return f;
}

int informResult(double a, double b, double r, char c)
{
    if(a == (int)a && b == (int)b && r == (int)r)
    {
        printf("El resultado de %d %c %d es: %d\n", (int)a, c, (int)b, (int)r);
    }
    else
    {
        if (a == (int)a && r == (int)r)
        {
            printf("El resultado de %d %c %.3lf es: %d\n", (int)a, c, b, (int)r);
        }
        else
        {
            if(b == (int)b && r == (int)r)
            {
                printf("El resultado de %.3lf %c %d es: %d\n", a, c, (int)b, (int)r);
            }
            else
            {
                if (a == (int)a)
                {
                    printf("El resultado de %d %c %.3lf es: %.3lf\n", (int)a, c, b, r);
                }
                else
                {
                    if (b == (int)b)
                    {
                        printf("El resultado de %.3lf %c %d es: %.3lf\n", a, c, (int)b, r);
                    }
                    else
                    {
                        printf("El resultado de %.3lf %c %.3lf es: %.3lf\n", a, c, b, r);
                    }
                }
            }
        }
    }
    return 0;
}

int informDiv(double a, double b, double r)
{
    if (b == 0)
    {
        printf("No se puede dividir por cero!\n");
    }
    else
    {
        if (a == (int)a && b == (int)b && r == (int)r)
        {
            printf("El resultado de %d / %d es: %d\n", (int)a, (int)b, (int)r);
        }
        else
        {
            if (a == (int)a && b == (int)b)
            {
                printf("El resultado de %d / %d es: %.3lf\n", (int)a, (int)b, r);
            }
            else
            {
                if (a == (int)a && r == (int)r)
                {
                    printf("El resultado de %d / %.3lf es: %d\n", (int)a, b, (int)r);
                }
                else
                {
                    if (a == (int)a)
                    {
                        printf("El resultado de %d / %.3lf es: %.3lf\n", (int)a, b, r);
                    }
                    else
                    {
                        if (r == (int)r)
                        {
                            printf("El resultado de %.3lf / %.3lf es: %d\n", a, b, (int)r);
                        }
                        else
                        {
                            if(b == (int)b)
                            {
                                printf("El resultado de %.3lf / %d es: %.3lf\n", a, (int)b, r);
                            }
                            else
                            {
                                printf("El resultado de %.3lf / %.3lf es: %.3lf\n", a, b, r);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int informFact(double a, long long int factA, double b, long long int factB)
{
    if (factA == 0 && factB == 0)
    {
        printf("No se pudo calcular el factorial de ningun operando.\n");
    }
    else
    {
        if (factA == 0)
        {
            printf("El factorial de %d es: %I64u\n", (int)b, factB);
        }
        else
        {
            if (factB == 0)
            {
                printf("El factorial de %d es: %I64u\n", (int)a, factA);
            }
            else
            {
                printf("El factorial de %d es %I64u y el factorial de %d es %I64u\n", (int)a, factA, (int)b, factB);
            }
        }
    }
    return 0;
}
