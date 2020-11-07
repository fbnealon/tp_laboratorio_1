#include "menu.h"

int menu(void)
{
    int option;
    printf("-----------------------------------------------------------------------------------\n");
    printf("-------------------------------    ABM EMPLEADOS    -------------------------------\n");
    printf("-----------------------------------------------------------------------------------\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &option);
    return option;
}

int sortMenu(void)
{
    int option;
    printf("Ordenar por: \n\n");
    printf("1. ID\n");
    printf("2. Nombre\n");
    printf("3. Horas trabajadas\n");
    printf("4. Sueldo\n");
    printf("5. Salir\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &option);
    return option;
}

int modificationMenu(void)
{
    int option;
    printf("1. Modificar nombre del empleado\n");
    printf("2. Modificar horas trabajadas\n");
    printf("3. Modificar sueldo\n");
    printf("4. Salir\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &option);
    return option;
}
