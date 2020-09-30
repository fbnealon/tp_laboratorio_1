#include "ArrayEmployees.h"

int initEmployees(eEmployee employeeList[], int len)
{
    for(int i=0; i<len; i++)
    {
        employeeList[i].isEmpty= EMPTY;
    }
    return 0;
}

int addEmployee(eEmployee employeeList[], int len, int id)
{
    int index, error=2;
    eEmployee newEmployee;
    if(employeeList != NULL && len>0 && id>0)
    {
        index = findFreeSlot(employeeList, len);
        if(index != -1)
        {
            newEmployee = createNewEmployee(newEmployee, id);
            employeeList[index] = newEmployee;
            error=0;
        }
        else
        {
            printf("La nomina de empleados esta completa.\n");
            error=1;
        }
    }

    return error;
}

eEmployee createNewEmployee(eEmployee newEmployee, int id)
{
    getStrings("Ingrese el nombre: ", "Nombre muy largo, ingrese nombre mas corto: ", NAMES, newEmployee.name);

    getStrings("Ingrese el apellido: ", "Apellido muy largo, ingrese apellido mas corto: ", NAMES, newEmployee.lastName);

    newEmployee.salary = getFloat("Ingrese el salario (de 0 a 500000): ", "Valor fuera de rango, intente de nuevo (de 0 a 500000): ", 0, 500000);

    newEmployee.sector = getInt("Ingrese el sector (de 1 a 10): ", "Valor fuera de rango, intente de nuevo (de 1 a 10): ", 1, 10);

    newEmployee.isEmpty = OCCUPIED;

    newEmployee.id = id;

    return newEmployee;
}

int findFreeSlot(eEmployee employeeList[], int len)
{
    int index=-1;
    for(int i=0; i<len; i++)
    {
        if(employeeList[i].isEmpty==EMPTY)
        {
            index = i;
            break;
        }
    }
    return index;
}

int findEmployeeById(eEmployee employeeList[], int len, int id)
{
    int index=-1;

    for(int i=0; i<len; i++)
    {
        if(employeeList[i].id == id && employeeList[i].isEmpty == OCCUPIED)
        {
            printf("Empleado encontrado\n");
            index = i;
            break;
        }
    }
    return index;
}

int removeEmployee(eEmployee employeeList[], int len, int id) //0 BAJA CORRECTA, 1 OPERACION CANCELADA, 2 HUBO PROBLEMA
{
    int error=2, index;
    char confirmation;

    if(employeeList != NULL && len>0)
    {
        index=findEmployeeById(employeeList, len, id);

        if(index != -1)
        {
            printAnEmployee(employeeList[index]);
            confirmation= getLetter("Desea eliminar al empleado seleccionado?: ", "Ha ingresado un caracter invalido, intente de nuevo: ");
            if(confirmation == 's')
            {
                employeeList[index].isEmpty = EMPTY;
                error=0;
            }
            else
            {
                error=1;
            }
        }
    }
    return error;
}

int printEmployees(eEmployee employeeList[], int len)
{
    int error=-1;
    if(employeeList != NULL && len>0)
    {
       printf("%4s    %20s    %20s    %6s    %9s\n\n", "ID", "Apellido", "Nombre", "Sector", "Salario");
        for(int i=0; i<len; i++)
        {
            if(employeeList[i].isEmpty == OCCUPIED)
            {
                printAnEmployee(employeeList[i]);
            }
        }
        error=0;
    }
    return error;
}

void printAnEmployee(eEmployee anEmployee)
{
    printf("%4d    %20s    %20s    %6d    %9.2f\n", anEmployee.id, anEmployee.lastName, anEmployee.name, anEmployee.sector, anEmployee.salary);
}

eEmployee changeField(eEmployee anEmployee)

{
    eEmployee auxEmployee = anEmployee;
    char option;
    system("cls");
    do
    {
        printf("****************************************Modificaciones de empleado****************************************\n\n\n");
        printf("****************************************Empleado a modificar****************************************\n");
        printf("%4s    %20s    %20s    %6s    %9s\n", "ID", "Apellido", "Nombre", "Sector", "Salario\n");
        printAnEmployee(anEmployee);
        option= modificationMenu();
        switch(option)
        {
            case 'a':
                getStrings("Ingrese el nuevo nombre: ", "Demasiado largo, intente de nuevo: ", NAMES, auxEmployee.name);
                printf("Esta seguro de cambiar el nombre del empleado a %s?: ", auxEmployee.name);
                fflush(stdin);
                scanf("%c", &option);
                if(option == 's')
                {
                    strcpy(anEmployee.name, auxEmployee.name);
                    printf("Se modifico el nombre del empleado a: %s\n\n\n", anEmployee.name);
                }
                else
                {
                    printf("El nombre del empleado no fue modificado.\n\n\n");
                }
                break;
            case 'b':
                getStrings("Ingrese el nuevo apellido: ", "Demasiado largo, intente de nuevo: ", NAMES, auxEmployee.lastName);
                printf("Esta seguro de cambiar el apellido del empleado a %s?: ", auxEmployee.lastName);
                fflush(stdin);
                scanf("%c", &option);
                if(option == 's')
                {
                    strcpy(anEmployee.lastName, auxEmployee.lastName);
                    printf("Se modifico el apellido del empleado a %s.\n\n\n", anEmployee.lastName);
                }
                else
                {
                    printf("El apellido del empleado no fue modificado.\n\n\n");
                }
                break;
            case 'c':
                auxEmployee.salary= getFloat("Ingrese el nuevo salario del empleado: ", "No ingresó un valor aceptable, intente de nuevo: ", 0, 9999999);
                printf("Esta seguro de cambiar el salario del empleado a %.2f?: ", auxEmployee.salary);
                fflush(stdin);
                scanf("%c", &option);
                if(option == 's')
                {
                    anEmployee = auxEmployee;
                    printf("El nuevo sueldo del empleado es: %.2lf\n", anEmployee.salary);
                }
                else
                {
                    printf("El salario del empleado no fue modificado\n\n\n");
                }
                break;
            case 'd':
                auxEmployee.sector = getInt("Ingrese el nuevo sector del empleado: ", "Ha ingresado un sector invalido, intente de nuevo: ", 0, 50);
                printf("Esta seguro que quiere cambiar el sector del empleado a %d?: ", auxEmployee.sector);
                fflush(stdin);
                scanf("%c", &option);
                if(option == 's')
                {
                    anEmployee = auxEmployee;
                    printf("El nuevo sector del empleado es %d\n\n\n", anEmployee.sector);
                }
                else
                {
                    printf("El sector del empleado no fue modificado\n\n\n");
                }
                break;
            case 'e':
                printf("Saliendo de las modificaciones...\n\n\n");
                break;
            default:
                printf("Opcion incorrecta, intente de nuevo\n\n\n");
                break;
        }
        system("pause");
        system("cls");
    }while (option != 'e');
    return anEmployee;
}

int modifyEmployee(eEmployee employeeList[], int len, int id)
{
    int error=2;
    int index;
    char confirmation;

    if(employeeList != NULL && len>0)
    {
        system("cls");
        index= findEmployeeById(employeeList, len, id);
        if(index != -1)
        {
            printAnEmployee(employeeList[index]);
            confirmation = getLetter("Desea modificar este empleado?: ", "Ha ingresado un caracter invalido, intente de nuevo: ");
            if(confirmation=='s')
            {
                employeeList[index]= changeField(employeeList[index]);
                error=0;
            }
            else
            {
                error=1;
            }
        }
    }
    return error;
}

int findOccupiedSlot(eEmployee employeeList[], int len) //2 HUBO PROBLEMAS 1 NO HAY EMPLEADOS CARGADOS 0 HAY CARGADOS
{
    int error=2;

    if(employeeList != NULL && len >0)
    {
        for(int i=0; i<len; i++)
        {
            if(employeeList[i].isEmpty==OCCUPIED)
            {
                error=0;
                break;
            }
            if(i+1==len && employeeList[i].isEmpty == EMPTY)
            {
                error=1;
            }
        }
    }
    return error;
}

int reportInformation(eEmployee employeeList[], int len)
{
    int error=-1;
    double total, average;
    int counter=0, employeesAboveAverage=0;
    if(employeeList != NULL && len>0)
    {
        int option=reportMenu();
        system("cls");
        if(option==1)
        {
            sortEmployees(employeeList, len, 0);
            printEmployees(employeeList, len);
        }
        if(option==2)
        {
            for(int i=0; i<len; i++)
            {
                if(employeeList[i].isEmpty==OCCUPIED)
                {
                    total+=employeeList[i].salary;
                    counter++;
                }
            }
            average=total/counter;

            for(int i=0; i<len; i++)
            {
                if(employeeList[i].isEmpty==OCCUPIED && employeeList[i].salary>average)
                {
                    employeesAboveAverage++;
                }
            }
            printf("Total de los salarios: %.2lf\n", total);
            printf("Promedio de salarios: %.2lf\n", average);
            printf("La cantidad de empleados que supera el salario promedio es de %d\n", employeesAboveAverage);
        }
        error=0;
    }
    return error;
}

int sortEmployees(eEmployee employeeList[], int len, int order)
{
    int error=-1;
    eEmployee auxEmployee;
    if(employeeList != NULL && len>0 && (order==0 || order==1))
    {
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len;j++)
            {
                if(order == 0 && (employeeList[i].sector > employeeList[j].sector ||
                                  (employeeList[i].sector == employeeList[j].sector && stricmp(employeeList[i].lastName, employeeList[j].lastName)>0)))
                {
                    auxEmployee=employeeList[i];
                    employeeList[i]=employeeList[j];
                    employeeList[j]=auxEmployee;
                }
                else if(order == 1 && (employeeList[i].sector < employeeList[j].sector ||
                                        (employeeList[i].sector == employeeList[j].sector && stricmp(employeeList[i].lastName, employeeList[j].lastName)<0)))
                {
                    auxEmployee = employeeList[i];
                    employeeList[i] = employeeList[j];
                    employeeList[j] = auxEmployee;
                }
            }
        }
        error=0;
    }
    return error;
}
