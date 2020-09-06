#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int opcion, calculo=0;
    double a=0, b=0, suma, resta, mult, div;
    long long int factA, factB;
    do
    {
        opcion = menu(a, b);
        switch(opcion)
        {
        case 1:
            a = getDouble("Ingrese el operando A: ");
            if(a == (int)a)
            {
                printf("Operando A: %d\n", (int)a);
            }
            else
            {
                printf("Operando A: %.2lf\n", a);
            }
            if(calculo)
            {
                calculo = 0;
            }
            break;
        case 2:
            b = getDouble("Ingrese el operando B: ");
            if(b == (int)b)
            {
                printf("Operando B: %d\n", (int)b);
            }
            else
            {
                printf("Operando B: %.2lf\n", b);
            }
            if(calculo)
            {
                calculo = 0;
            }
            break;
        case 3:
            system("cls");
            printf("--------------------Calculadora--------------------\n\n");
            suma= operation('+', a, b);
            resta= operation('-', a, b);
            mult= operation('*', a, b);
            div= operation('/', a, b);
            factA= fact(a);
            factB= fact(b);
            printf("Operaciones calculadas\n");
            calculo=1;
            break;
        case 4:
            system("cls");
            printf("--------------------Calculadora--------------------\n\n");
            if(calculo)
            {
                informResult(a, b, suma, '+');
                informResult(a, b, resta, '-');
                informDiv(a, b, div);
                informResult(a, b, mult, '*');
                informFact(a, factA, b, factB);
            }
            else
            {
                printf("Para informar las operaciones hay que calcularlas\n");
            }
            break;
        case 5:
            system("cls");
            printf("--------------------Calculadora--------------------\n\n");
            printf("//////////////////////////////\n//////////////////////////////\n//////////////////////////////\n//////////////////////////////\n//////////////////////////////\n");
            printf("//Saliendo de la calculadora//\n");
            printf("//////////////////////////////\n//////////////////////////////\n//////////////////////////////\n//////////////////////////////\n//////////////////////////////\n");
            break;
        default:
            printf("Opcion invalida.\n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcion!=5);
    return 0;
}
