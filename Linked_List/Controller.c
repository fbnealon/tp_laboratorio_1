#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "menu.h"
#include "input.h"

#define ASC 1
#define DESC 0

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int ok=0;
    FILE* pFile;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        printf("-----------------------------------------------------------------------------------\n");
        printf("------------------------------    CARGA POR TEXTO    ------------------------------\n");
        printf("-----------------------------------------------------------------------------------\n\n");
        pFile=fopen(path, "r");
        if(pFile!=NULL)
        {
            if(!parser_EmployeeFromText(pFile, pArrayListEmployee))
            {
                ok=1;
            }
            fclose(pFile);
        }
    }
    return ok;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int ok=0;
    FILE* pFile=fopen(path, "rb");
    if(pFile!=NULL)
    {
        printf("-----------------------------------------------------------------------------------\n");
        printf("-----------------------------    CARGA POR BINARIO    -----------------------------\n");
        printf("-----------------------------------------------------------------------------------\n\n");
        parser_EmployeeFromBinary(pFile, pArrayListEmployee);
        ok=1;
        fclose(pFile);
    }
    else
    {
        printf("No existe el archivo\n\n");
    }
    return ok;
}

int obtenerId(int* id)
{
    int ok=0;
    if(id!=NULL)
    {
        *id=1001;
    }
    FILE* pFile=fopen("proximoId.bin", "rb");
    if(pFile!=NULL)
    {
        fread(id, sizeof(int), 1, pFile);
        fclose(pFile);
        ok=1;
    }
    return ok;
}

int actualizarId(int id)
{
    int ok=0;
    id++;
    FILE* pFile=fopen("proximoId.bin", "wb");
    if(pFile!=NULL)
    {
        fwrite(&id, sizeof(int), 1, pFile);
        fclose(pFile);
        ok=1;
    }
    return ok;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ok=0;
    char confirma='n';
    char nombreStr[128];
    int id;
    char idStr[128];
    char horasStr[128];
    char sueldoStr[128];
    Employee* newEmployee=employee_new();
    if(pArrayListEmployee!=NULL)
    {
        printf("-----------------------------------------------------------------------------------\n");
        printf("-------------------------------    ALTA EMPLEADO    -------------------------------\n");
        printf("-----------------------------------------------------------------------------------\n\n");

        obtenerId(&id);
        sprintf(idStr, "%d", id);


        getAlphaString("Ingrese el nombre del empleado: ", "Error, intente de nuevo: ", 128, nombreStr);
        employee_setNombre(newEmployee, nombreStr);;


        getNumberString("Ingrese las horas trabajadas: ", "Error, intente de nuevo: ", 128, horasStr);


        getNumberString("Ingrese el sueldo del empleado: ", "Error, intente de nuevo: ", 128, sueldoStr);


        confirma=getLetter("Confirma alta?: ", "Caracter invalido, intente de nuevo: ");

        if(confirma=='s')
        {
            newEmployee=employee_newParametros(idStr, nombreStr, horasStr, sueldoStr);
            ll_add(pArrayListEmployee, newEmployee);
            actualizarId(id);
        }
        ok=1;
    }
    return ok;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int ok=0;
    int auxId;
    int index=-1;
    char idStr[128];
    Employee* anEmployee;
    char confirma='n';
    if(pArrayListEmployee!=NULL)
    {
        printf("-----------------------------------------------------------------------------------\n");
        printf("-------------------------------    BAJA EMPLEADO    -------------------------------\n");
        printf("-----------------------------------------------------------------------------------\n\n");

        if(printEmployees(pArrayListEmployee))
        {
            getNumberString("Ingrese el ID del empleado a eliminar: ", "Error, intente de nuevo: ", 128, idStr);
            auxId= atoi(idStr);
            index= searchEmployee(pArrayListEmployee, auxId);
            if(index!=-1)
            {
                anEmployee= ll_get(pArrayListEmployee, index);
                confirma= getLetter("\nConfirma baja?: ", "Caracter invalido, intente de nuevo: ");
                if(confirma=='s')
                {
                    ll_remove(pArrayListEmployee, index);
                    printf("Empleado dado de baja!!\n\n");
                }
                else
                {
                    printf("Baja cancelada!\n\n");
                }
            }
            else
            {
                printf("No hay empleado con el ID ingresado\n\n");
            }
            ok=1;
        }

    }
    return ok;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int ok=0;
    if(pArrayListEmployee!=NULL)
    {
        if(printEmployees(pArrayListEmployee))
        {
            ok=1;
        }
    }
    return ok;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int option;
    if(pArrayListEmployee!=NULL)
    {
        printf("-----------------------------------------------------------------------------------\n");
        printf("-------------------------    ORDENAMIENTO DE EMPLEADOS    -------------------------\n");
        printf("-----------------------------------------------------------------------------------\n\n");
        option=sortMenu();
        switch(option)
        {
        case 1:
            ll_sort(pArrayListEmployee, employeeSortById, DESC);
            break;
        case 2:
            ll_sort(pArrayListEmployee, employeeSortByName, DESC);
            break;
        case 3:
            ll_sort(pArrayListEmployee, employeeSortByWorkHours, DESC);
            break;
        case 4:
            ll_sort(pArrayListEmployee, employeeSortBySalary, DESC);
            break;
        case 5:
            printf("Saliendo\n\n");
            break;
        default:
            printf("Opcion invalida!\n\n");
            break;
        }
    }
    return option;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int ok=0;
    int tam;
    FILE* pFile;
    Employee* auxEmployee;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path, "w");
        fprintf(pFile, "ID,Nombre,HorasTrabajadas,Sueldo\n");
        tam=ll_len(pArrayListEmployee);
        for(int i=0; i<tam; i++)
        {
            auxEmployee=(Employee*)ll_get(pArrayListEmployee, i);
            if(auxEmployee!=NULL)
            {
                fprintf(pFile, "%d,%s,%d,%d\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
            }
        }
        ok=1;
        free(auxEmployee);
        fclose(pFile);
    }
    return ok;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int ok=0;
    FILE* pFile=fopen(path, "wb");
    Employee* auxEmployee;
    int tam= ll_len(pArrayListEmployee);
    if(pArrayListEmployee!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            auxEmployee= (Employee*)ll_get(pArrayListEmployee, i);
            if(auxEmployee!=NULL)
            {
                fwrite(auxEmployee, sizeof(Employee), 1, pFile);
            }
        }
        fclose(pFile);
        printf("El archivo fue guardado correctamente\n");
        ok=1;
    }
    else
    {
        printf("El archivo no pudo guardarse correctamente...\n");
    }
    return ok;
}

