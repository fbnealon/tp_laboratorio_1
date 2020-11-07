#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
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
                if(!controller_saveAsText("data.csv", listaEmpleados))
                {
                    printf("Archivo en formato texto guardado\n\n");
                }
                else
                {
                    printf("Error al guardar archivo\n\n");
                }
                break;
            case 9:
                system("cls");
                controller_saveAsBinary("data.bin", listaEmpleados);
                break;
            case 10:
                ll_deleteLinkedList(listaEmpleados);
                break;
        }
        system("pause");
        system("cls");
    }while(option != 10);
    return 0;
}
