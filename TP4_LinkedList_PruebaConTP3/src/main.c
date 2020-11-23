#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"



/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option;
    int primera=1;
    LinkedList* empleadosQueTrabajanMasDe70Horas=NULL;
    LinkedList* empleadosQueCobranMasDe30000=NULL;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        option=menu();
        switch(option)
        {
            case 1:
                system("cls");
                if(primera)
                {
                    controller_loadFromText("data.csv",listaEmpleados);
                    primera=0;
                    printf("Carga exitosa!\n\nCantidad de empleados: %d\n\n", ll_len(listaEmpleados));
                }
                else
                {
                    printf("La lista de empleados ya fue cargada\n\n");
                }
                break;
            case 2:
                system("cls");
                if(primera)
                {
                    controller_loadFromBinary("data.bin", listaEmpleados);
                    primera=0;
                    printf("Carga exitosa!\n\nCantidad: %d\n\n", ll_len(listaEmpleados));
                }
                else
                {
                    printf("La lista de empleados ya fue cargada\n\n");
                }
                break;
            case 3:
                system("cls");
                if(controller_addEmployee(listaEmpleados))
                {
                    printf("Empleado cargado con exito!\n\n");
                }
                else
                {
                    printf("No se cargo ningun empleado nuevo\n\n");
                }
                break;
            case 4:
                system("cls");
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                system("cls");
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                system("cls");
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                system("cls");
                if(ll_len(listaEmpleados)!=0)
                {
                    if(controller_sortEmployee(listaEmpleados)!=5)
                    {
                        controller_ListEmployee(listaEmpleados);
                    }
                }
                else
                {
                    printf("\n\nNo hay empleados cargados en la nomina!!!\n\n");
                }
                break;
            case 8:
                system("cls");
                printf("-----------------Lista de empleados que trabajan mas de 70 horas-----------------\n\n\n");
                if(ll_len(listaEmpleados)!=0)
                {
                    empleadosQueTrabajanMasDe70Horas=ll_filter(listaEmpleados, employee_filterByWorkHours);
                    employee_printAll(empleadosQueTrabajanMasDe70Horas);
                    free(empleadosQueTrabajanMasDe70Horas);
                }
                break;
            case 9:
                system("cls");
                printf("-----------------Lista de empleados que cobran mas de 30000 pesos-----------------\n\n\n");
                if(ll_len(listaEmpleados)!=0)
                {
                    empleadosQueCobranMasDe30000= ll_filter(listaEmpleados, employee_filterBySalary);
                    employee_printAll(empleadosQueCobranMasDe30000);
                    free(empleadosQueCobranMasDe30000);
                }
                break;
            case 10:
                system("cls");
                if(ll_isEmpty(listaEmpleados))
                {
                    printf("Lista vacia, no se guardo ningun dato\n\n");
                }
                else
                {
                    controller_saveAsText("data.csv", listaEmpleados);
                    printf("Datos guardados\n\n");
                }
                break;
            case 11:
                system("cls");
                if(ll_isEmpty(listaEmpleados))
                {
                    printf("Lista vacia, no se guardo ningun dato\n\n");
                }
                else
                {
                    controller_saveAsBinary("data.bin", listaEmpleados);
                    printf("Datos guardados\n\n");
                }
                break;
            case 12:
                if(!ll_deleteLinkedList(listaEmpleados))
                {
                    printf("LinkedList eliminada\n");
                }
                break;
        }
        system("pause");
        system("cls");
    }while(option != 12);
    return 0;
}
