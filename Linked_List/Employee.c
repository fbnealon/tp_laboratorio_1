#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new()
{
    Employee* newEmployee=(Employee*) malloc(sizeof(Employee));
    if(newEmployee!=NULL)
    {
        newEmployee->id=0;
        strcpy(newEmployee->nombre, "N/A");
        newEmployee->horasTrabajadas=0;
        newEmployee->sueldo=0;
    }
    return newEmployee;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* newEmployee=employee_new();

    int auxId = atoi(idStr);
    int auxHoras = atoi(horasTrabajadasStr);
    int auxSueldo = atoi(sueldoStr);

    if(newEmployee!=NULL)
    {
        if(!(employee_setId(newEmployee, auxId) && employee_setNombre(newEmployee, nombreStr) && employee_setHorasTrabajadas(newEmployee, auxHoras) && employee_setSueldo(newEmployee, auxSueldo)))
        {
            free(newEmployee);
            newEmployee=NULL;
        }
    }
    return newEmployee;
}
void employee_delete(Employee* this)
{
        free(this);
}

int employee_setId(Employee* this, int id)
{
    int ok=0;
    if(this!=NULL&&id>0)
    {
        this->id=id;
        ok=1;
    }

    return ok;
}
int employee_getId(Employee* this, int* id)
{
    int ok=0;
    if(this!=NULL && id!=NULL)
    {
        ok=1;
        *id=this->id;
    }
    return ok;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int ok=0;
    if(this!=NULL&&nombre!=NULL && strlen(nombre)<128 && strlen(nombre)>1)
    {
        strcpy(this->nombre, nombre);
        ok=1;
    }
    return ok;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int ok=0;
    if(this!=NULL && nombre!=NULL && strlen(nombre)<128 && strlen(nombre)>1)
    {
        strcpy(nombre, this->nombre);
        ok=1;
    }
    return ok;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int ok=0;
    if(this!=NULL&&horasTrabajadas>=0)
    {
        this->horasTrabajadas=horasTrabajadas;
        ok=1;
    }
    return ok;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int ok=0;
    if(this!=NULL&&horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        ok=1;
    }

    return ok;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int ok=0;
    if(this!=NULL&&sueldo>0)
    {
        this->sueldo=sueldo;
        ok=1;
    }
    return ok;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int ok=0;
    if(this!=NULL&&sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        ok=1;
    }

    return ok;
}

void printEmployee(Employee* empleado)
{
    if(empleado!=NULL)
    {
        printf("%5d\t%30s\t%16d\t%10d\n", empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
    }
}

int printEmployees(LinkedList* lista)
{
    int ok=0, f=0;
    Employee* auxEmployee;
    int tam=ll_len(lista);

    if(lista!=NULL)
    {
        ok=1;
        printf("%5s\t%30s\t%16s\t%10s\n", "ID", "NOMBRE", "HORAS TRABAJADAS", "SUELDO");
        printf("--------------------------------------------------------------------------\n");
        for(int i=0;i<tam;i++)
        {
            auxEmployee= (Employee*)ll_get(lista, i);
            if(auxEmployee!=NULL)
            {
                f=1;
                printEmployee(auxEmployee);
            }
        }
        if(!f)
        {
            printf("No hay empleados\n\n");
            ok=0;
        }
        printf("\n");
    }

    return ok;
}

void printEmployeeText(FILE* pFile, Employee* empleado)
{
    if(pFile!=NULL && empleado!=NULL)
    {
    }
}

int employeeSortByName(void* empleadoA, void* empleadoB)
{
    int ok=0;
    char nombreA[128];
    char nombreB[128];

    if(empleadoA!=NULL && empleadoB!=NULL && nombreA!=NULL && nombreB!=NULL)
    {
        employee_getNombre((Employee*)empleadoA, nombreA);
        employee_getNombre((Employee*)empleadoB, nombreB);

        ok=strcmp(nombreA, nombreB);
    }

    return ok;
}
int employeeSortById(void* empleadoA, void* empleadoB)
{
    int ok=0;
    int idA;
    int idB;

    if(empleadoA!=NULL && empleadoB!=NULL)
    {
        employee_getId((Employee*)empleadoA, &idA);
        employee_getId((Employee*)empleadoB, &idB);

        if(idA>idB)
        {
            ok=1;
        }
        else if(idA<idB)
        {
            ok=-1;
        }
        else
        {
            ok=0;
        }
    }
    return ok;
}
int employeeSortByWorkHours(void* empleadoA, void* empleadoB)
{
    int ok=0;
    int horasA;
    int horasB;

    if(empleadoA!=NULL && empleadoB!=NULL)
    {
        employee_getHorasTrabajadas((Employee*)empleadoA, &horasA);
        employee_getHorasTrabajadas((Employee*)empleadoB, &horasB);

        if(horasA>horasB)
        {
            ok=1;
        }
        else if(horasA<horasB)
        {
            ok=-1;
        }
        else
        {
            ok=0;
        }
    }
    return ok;
}
int employeeSortBySalary(void* empleadoA, void* empleadoB)
{
    int ok=0;
    int sueldoA;
    int sueldoB;

    if(empleadoA!=NULL && empleadoB!=NULL)
    {
        employee_getSueldo((Employee*)empleadoA, &sueldoA);
        employee_getSueldo((Employee*)empleadoB, &sueldoB);

        if(sueldoA>sueldoB)
        {
            ok=1;
        }
        else if(sueldoA<sueldoB)
        {
            ok=-1;
        }
        else
        {
            ok=0;
        }
    }
    return ok;
}

int employee_searchById(LinkedList* lista, int id)
{
    int index=-1;
    Employee* auxEmployee;
    int tam=ll_len(lista);
    if(lista!=NULL)
    {
        for(int i=0;i<tam;i++)
        {
            auxEmployee=(Employee*) ll_get(lista, i);
            if(auxEmployee!=NULL && id==auxEmployee->id)
            {
                index=ll_indexOf(lista, auxEmployee);
                printf("Empleado encontrado\n\n");
                printEmployee(auxEmployee);
            }
        }
        if(index==-1)
        {
            printf("No se encontro al empleado con el ID ingresado\n\n");
        }
    }
    return index;
}
