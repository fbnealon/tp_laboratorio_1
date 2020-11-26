/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "animales.h"
#include "menu.h"

int main(void)
{
    startTesting(1);  // ll_newLinkedList
    startTesting(2);  // ll_len
    startTesting(3);  // getNode - test_getNode
    startTesting(4);  // addNode - test_addNode
    startTesting(5);  // ll_add
    startTesting(6);  // ll_get
    startTesting(7);  // ll_set
    startTesting(8);  // ll_remove
    startTesting(9);  // ll_clear
    startTesting(10); // ll_deleteLinkedList
    startTesting(11); // ll_indexOf
    startTesting(12); // ll_isEmpty
    startTesting(13); // ll_push
    startTesting(14); // ll_pop
    startTesting(15); // ll_contains
    startTesting(16); // ll_containsAll
    startTesting(17); // ll_subList
    startTesting(18); // ll_clone
    startTesting(19); // ll_sort
    system("pause");
    system("cls");

    int opcion, primera=1, check=0;
    LinkedList* animales=NULL;
    LinkedList* perros=NULL;
    LinkedList* mayoresA10=NULL;
    LinkedList* primerosTres=NULL;
    LinkedList* clonada=NULL;
    do
    {
        opcion=menu();
        switch(opcion)
        {
        case 1:
            if(primera)
            {
                animales=ll_newLinkedList();
                animal_fillList("animales.csv", animales);
                primera=0;
                printf("Lista cargada con exito\n\n");
            }
            else
            {
                printf("Lista ya cargada\n");
            }
            break;
        case 2:
            animal_printAll(animales);
            break;
        case 3:
            animal_printCantidadTotal(animales);
            break;
        case 4:
            perros=ll_newLinkedList();
            perros= ll_filter(animales, filtrarPerros);
            animal_printAll(perros);
            break;
        case 5:
            mayoresA10=ll_newLinkedList();
            mayoresA10=ll_filter(animales, filtrarMayoresDe10);
            animal_printAll(mayoresA10);
            break;
        case 6:
            if(animales==NULL || perros==NULL)
            {
                printf("Cargar listas por favor\n\n");
            }
            check=animal_checkPerros(animales, perros);
            if(check==1)
            {
                printf("Los perros se encuentran en lista original\n\n");
            }
            break;
        case 7:
            animal_informarXPosicion(animales, 5);
            break;
        case 8:
            animal_cambiarUltimoXPrimero(animales);
            animal_printAll(animales);
            break;
        case 9:
            if(animal_eliminarADundee(animales))
            {
                printf("Cocodrilo Dundee eliminado\n\n");
            }
            break;
        case 10:
            if(perros!=NULL)
            {
                animal_printAll(perros);
                if(animal_vaciarPerros(perros))
                {
                    printf("Lista de perros vaciada\n\n");
                }
            }
            break;
        case 11:
            if(animales!=NULL)
            {
                printf("El indice de Dumbo en la lista es el %d\n\n", animal_devolverPosicionDeDumbo(animales));
            }
            break;
        case 12:
            if(perros!=NULL && ll_isEmpty(perros))
            {
                printf("La lista de perros esta vacia, debe cargarla de nuevo\n\n");
            }
            break;
        case 13:
            animal_duplicarAnimalDelFinal(animales);
            animal_printAll(animales);
            break;
        case 14:
            if(!ll_isEmpty(animales))
            {
                animal_eliminarAnimalDelFinal(animales);
            }
            break;
        case 15:
            primerosTres=ll_newLinkedList();
            if(primerosTres!=NULL)
            {
                primerosTres= animal_subListaPrimerosTres(animales);
                animal_printAll(primerosTres);
                ll_deleteLinkedList(primerosTres);
            }
            break;
        case 16:
            clonada=ll_newLinkedList();
            if(clonada!=NULL)
            {
                clonada= animal_clonarLista(animales);
                animal_printAll(clonada)                ;
                animal_ordenarXEdad(clonada);
                animal_printAll(clonada);
                ll_deleteLinkedList(clonada);
            }
            break;
        case 17:
            ll_deleteLinkedList(animales);
            ll_deleteLinkedList(perros);
            ll_deleteLinkedList(mayoresA10);
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcion!=17);

    return 0;
}

































