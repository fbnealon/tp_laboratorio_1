#include "menu.h"

int menu()
{
    int opcion;
    printf("--------------------------------------------------------------------------\n");
    printf("--------------------------------PRUEBA ANIMALES---------------------------\n");
    printf("--------------------------------------------------------------------------\n");
    printf("\n\n");
    printf("1. Cargar lista de animales\n");
    printf("2. Informar animales\n");
    printf("3. Informar cantidad total de animales\n");
    printf("4. Cargar perros e informar\n");
    printf("5. Informar animales mayores a 10 anios\n");
    printf("6. Informar si los perros se encuentran en lista original\n");
    printf("7. Informar el animal por indice\n");
    printf("8. Cambiar posiciones del primero con el ultimo\n");
    printf("9. Eliminar al cocodrilo Dundee\n");
    printf("10. Vaciar lista de perros\n");
    printf("11. Informar posicion de Dumbo\n");
    printf("12. Informar recarga de lista de perros\n");
    printf("13. Duplicar ultimo animal de lista\n");
    printf("14. Eliminar ultimo animal de lista y mostrarlo\n");
    printf("15. Crear sublista de primeros tres animales, mostrarla y eliminarla\n");
    printf("16. Clonar lista de animales, ordenarla por edad, mostrarla y eliminarla\n");
    printf("17. Salir\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
