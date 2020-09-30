#include "menu.h"

int selectOption()
{
    int opcion;

    printf("****************************************ABM EMPLEADOS****************************************\n\n\n");
    printf("1. Alta de nuevo empleado\n\n");
    printf("2. Modificar empleado existente\n\n");
    printf("3. Baja de empleado\n\n");
    printf("4. Informar:\n");
    printf("\t1. Listado de empleados ordenados alfabeticamente por Apellido y Sector.\n");
    printf("\t2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n\n");
    printf("5. Salir\n\n");
    opcion = getInt("Elija una opcion: ", "Por favor, ingrese una opcion del 1 al 5: ", 1, 5);

    return opcion;
}

char modificationMenu()
{
    char option;
    printf("\nQue campo quiere modificar?\n");
    printf("\n a. Nombre.");
    printf("\n b. Apellido.");
    printf("\n c. Salario.");
    printf("\n d. Sector.");
    printf("\n e. Salir.\n");

    fflush(stdin);
    option= getLetter("Ingrese una opcion: ", "Ha ingresado una opcion invalida, intente de nuevo: ");

    return option;
}

int reportMenu()
{
    int option;
    printf("1. Reportar listado de empleados ordenados alfabeticamente por Apellido y Sector\n\n");
    printf("2. Reportar total y promedio de los salarios, y cuantos empleados superan el salario promedio\n\n");

    fflush(stdin);
    option = getInt("Elija una opcion: ", "Por favor, ingrese 1 o 2: ", 1, 2);

    return option;
}
