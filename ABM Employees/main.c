#include "ArrayEmployees.h"

int main()
{

    eEmployee listaEmpleados[SIZE];
    initEmployees(listaEmpleados, SIZE);
    int nextID = 1000, auxID;
    int rta;
    int opcion;
    do
    {
        system("cls");
        fflush(stdin);
        opcion= selectOption();
        switch(opcion)
        {
        case 1:
            system("cls");
            printf("****************************************ALTA DE NUEVO EMPLEADO****************************************\n\n\n");
            if(addEmployee(listaEmpleados, SIZE, nextID)==0)
            {
                nextID++;
                printf("Alta exitosa!!\n\n");
            }
            else
            {
                printf("No se pudo realizar el alta...\n\n");
            }
            break;
        case 2:
            system("cls");
            printf("****************************************MODIFICAR EMPLEADO EXISTENTE****************************************\n\n\n");
            rta = findOccupiedSlot(listaEmpleados, SIZE);
            if(rta==2)
            {
                printf("Hubo problemas\n\n");
            }
            else if(rta==1)
            {
                printf("No hay empleados cargados en la nomina todavia\n\n");
            }
            else
            {
                printEmployees(listaEmpleados, SIZE); //Fuera de funcion modifyEmployee debido a que el prototipo de la misma tiene id como parametro
                auxID= getInt("Ingrese el ID del empleado a modificar: ", "Ha ingresado un valor invalido, intente de nuevo: ", 0, 50000); //obtiene ID, usado como parametro en funcion modifyEmployee
                rta=modifyEmployee(listaEmpleados, SIZE, auxID);
                if(rta==2)
                {
                    printf("No hay empleado activo con el ID ingresado!\n\n");
                }
                else if(rta==1)
                {
                    printf("Operacion cancelada...\n\n");
                }
                else
                {
                    printf("Modificaciones realizadas!\n\n");
                }
            }

            break;
        case 3:
            system("cls");
            printf("****************************************ELIMINAR EMPLEADO DE NOMINA****************************************\n\n\n");
            rta = findOccupiedSlot(listaEmpleados, SIZE);
            if(rta==2)
            {
                printf("Hubo problemas\n\n");
            }
            else if(rta==1)
            {
                printf("No hay empleados cargados en la nomina todavia\n\n");
            }
            else
            {
               printEmployees(listaEmpleados, SIZE); //Fuera de funcion removeEmployee debido a que el prototipo de la misma tiene id como parametro
                auxID= getInt("Ingrese el ID del empleado a eliminar: ", "Ha ingresado un valor invalido, intente de nuevo: ", 0, 50000); //obtiene ID, usado como parametro en funcion removeEmployee
                rta= removeEmployee(listaEmpleados, SIZE, auxID);
                if(rta==0)
                {
                    printf("Baja realizada con exito!\n\n");
                }
                else if(rta==1)
                {
                    printf("Baja cancelada...\n\n");
                }
                else
                {
                    printf("No hay empleado activo con el ID ingresado...\n\n");
                }
            }

            break;
        case 4:
            system("cls");
            printf("****************************************REPORTES****************************************\n\n\n");
            printEmployees(listaEmpleados, SIZE);
            if(reportInformation(listaEmpleados, SIZE)==-1)
            {
                printf("Hubo problemas\n\n");
            }
            else
            {
                printf("Reportes finalizados\n\n");
            }
            break;
        case 5:
            system("cls");
            printf("****************************************\n****************************************\n************Saliendo del ABM************\n****************************************\n****************************************\n\n\n");
            break;
        default:
            printf("Por favor ingrese una opcion correcta\n");
            break;
        }
        system("pause");
    }while(opcion != 5);
    return 0;
}
