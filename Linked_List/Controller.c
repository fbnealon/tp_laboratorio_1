#include <stdio.h>
#include <stdlib.h>
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
    char auxNombre[128];
    int id;
    int horas;
    int sueldo;
    Employee* newEmployee=employee_new();
    if(pArrayListEmployee!=NULL)
    {
        printf("-----------------------------------------------------------------------------------\n");
        printf("-------------------------------    ALTA EMPLEADO    -------------------------------\n");
        printf("-----------------------------------------------------------------------------------\n\n");

        obtenerId(&id);
        employee_setId(newEmployee, id);

        getStrings("Ingrese el nombre del empleado: ", "Error, intente de nuevo: ", 128, auxNombre);
        employee_setNombre(newEmployee, auxNombre);;

        horas=getInt("Ingrese la cantidad de horas trabajadas: ", "Error, intente de nuevo: ", 0, 10000);
        employee_setHorasTrabajadas(newEmployee, horas);

        sueldo=getInt("Ingrese el sueldo del empleado: ", "Error, intente de nuevo: ", 0, 999999);
        employee_setSueldo(newEmployee, sueldo);

        confirma=getLetter("Confirma alta? ", "Caracter invalido, intente de nuevo: ");
        if(confirma=='s')
        {
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
    int ok=0;
    char confirma='n';
    if(pArrayListEmployee!=NULL)
    {
        printf("-----------------------------------------------------------------------------------\n");
        printf("-------------------------------    BAJA EMPLEADO    -------------------------------\n");
        printf("-----------------------------------------------------------------------------------\n\n");


    }
    return ok;
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

    return 1;
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
            ll_sort(pArrayListEmployee, employeeSortById, ASC);
            break;
        case 2:
            ll_sort(pArrayListEmployee, employeeSortByName, ASC);
            break;
        case 3:
            ll_sort(pArrayListEmployee, employeeSortByWorkHours, ASC);
            break;
        case 4:
            ll_sort(pArrayListEmployee, employeeSortBySalary, ASC);
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
