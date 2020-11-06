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
                if(primera)
                {
                    controller_loadFromText("data.csv",listaEmpleados);
                    primera=0;
                    printf("Cantidad: %d\n", ll_len(listaEmpleados));
                }
                else
                {
                    printf("La lista de empleados ya fue cargada\n\n");
                }
                break;
            case 2:
                if(primera)
                {
                    controller_loadFromBinary("data.bin", listaEmpleados);
                    primera=0;
                    printf("Cantidad: %d\n", ll_len(listaEmpleados));
                }
                else
                {
                    printf("La lista de empleados ya fue cargada\n\n");
                }
                break;
            case 3:
                if(controller_addEmployee(listaEmpleados))
                {
                    printf("Empleado cargado con exito!\n\n");
                }
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                if(!controller_sortEmployee(listaEmpleados))
                {
                    printEmployees(listaEmpleados);
                }
                break;
            case 8:
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
