#ifndef ANIMALES_H_INCLUDED
#define ANIMALES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "parser.h"

typedef struct
{
    int id;
    char nombre[20];
    char especie[20];
    int edad;
}eAnimal;

eAnimal* animal_new();
eAnimal* animal_newParametros(char* idStr,char* nombreStr,char* especieStr, char* edadStr);
void animal_delete(eAnimal* this);

int animal_setId(eAnimal* this, int id);
int animal_setNombre(eAnimal* this,char* nombre);
int animal_setEspecie(eAnimal* this,char* especie);
int animal_setEdad(eAnimal* this,int edad);

int animal_getId(eAnimal* this, int* id);
int animal_getNombre(eAnimal* this,char* nombre);
int animal_getEspecie(eAnimal* this,char* especie);
int animal_setEdad(eAnimal* this,int edad);

void animal_printAll(LinkedList* lista);
                                                                        //USA ll_newLinkedList en main
int animal_printCantidadTotal(LinkedList* animales);                    //USA ll_len
int animal_fillList(char* path, LinkedList* animales);                  //USA ll_add, a su vez usa addNode
int animal_informarXPosicion(LinkedList* animales, int indice);         //USA ll_get
int animal_cambiarUltimoXPrimero(LinkedList* animales);                 //USA ll_set
int animal_eliminarADundee(LinkedList* animales);                       //USA ll_remove
int animal_vaciarPerros(LinkedList* perros);                            //USA ll_clear
                                                                        //USA ll_deleteLinkedList en main
int animal_devolverPosicionDeDumbo(LinkedList* animales);               //USA ll_indexOf
                                                                        //USA ll_isEmpty en main (case 12)
int animal_duplicarAnimalDelFinal(LinkedList* animales);                //USA ll_push
int animal_eliminarAnimalDelFinal(LinkedList* animales);                //USA ll_pop
int animal_checkPerros(LinkedList* animales, LinkedList* perros);       //USA ll_containsAll, a su vez usa ll_contains
LinkedList* animal_subListaPrimerosTres(LinkedList* animales);          //USA ll_subList
LinkedList* animal_clonarLista(LinkedList* animales);                   //USA ll_clone
int animal_compararEdad(void* pElementA, void* pElementB);              //para usar con ll_sort
int animal_ordenarXEdad(LinkedList* animales);                          //USA ll_sort
                                                                        //USA ll_filter en main (case 4 y 5)
int filtrarPerros(void* pElement);                                      //para usar con ll_filter

int filtrarMayoresDe10(void* pElement);                                 //Para usar con ll_filter



#endif // ANIMALES_H_INCLUDED
