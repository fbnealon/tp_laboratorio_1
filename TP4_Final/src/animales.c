#include "animales.h"

eAnimal* animal_new()
{
    eAnimal* newAnimal=(eAnimal*) malloc(sizeof(eAnimal));
    if(newAnimal!=NULL)
    {
        newAnimal->id=0;
        strcpy(newAnimal->nombre, "N/A");
        strcpy(newAnimal->especie, "N/A");
        newAnimal->edad=0;
    }
    return newAnimal;
}
eAnimal* animal_newParametros(char* idStr,char* nombreStr,char* especieStr, char* edadStr)
{
    eAnimal* newAnimal=animal_new();

    int idAux = atoi(idStr);
    int edadAux = atoi(edadStr);

    if(newAnimal!=NULL)
    {
        if(!(animal_setId(newAnimal, idAux) && animal_setNombre(newAnimal, nombreStr) && animal_setEspecie(newAnimal, especieStr) && animal_setEdad(newAnimal, edadAux)))
        {
            free(newAnimal);
            newAnimal=NULL;
        }
    }
    return newAnimal;
}
void animal_delete(eAnimal* this)
{
    free(this);
}

int animal_setId(eAnimal* this, int id)
{
    int ok=0;
    if(this!=NULL&&id>0)
    {
        this->id=id;
        ok=1;
    }

    return ok;
}
int animal_getId(eAnimal* this, int* id)
{
    int ok=0;
    if(this!=NULL && id!=NULL)
    {
        ok=1;
        *id=this->id;
    }
    return ok;
}

int animal_setNombre(eAnimal* this,char* nombre)
{
    int ok=0;
    if(this!=NULL&&nombre!=NULL && strlen(nombre)<30 && strlen(nombre)>1)
    {
        strcpy(this->nombre, nombre);
        ok=1;
    }
    return ok;
}
int animal_getNombre(eAnimal* this,char* nombre)
{
    int ok=0;
    if(this!=NULL && nombre!=NULL && strlen(nombre)<30 && strlen(nombre)>1)
    {
        strcpy(nombre, this->nombre);
        ok=1;
    }
    return ok;
}

int animal_setEspecie(eAnimal* this,char* especie)
{
    int ok=0;
    if(this!=NULL&&especie!=NULL && strlen(especie)<30 && strlen(especie)>1)
    {
        strcpy(this->especie, especie);
        ok=1;
    }
    return ok;
}
int animal_getEspecie(eAnimal* this,char* especie)
{
    int ok=0;
    if(this!=NULL && especie!=NULL && strlen(especie)<30 && strlen(especie)>1)
    {
        strcpy(especie, this->especie);
        ok=1;
    }
    return ok;
}

int animal_setEdad(eAnimal* this,int edad)
{
    int ok=0;
    if(this!=NULL&&edad>0)
    {
        this->edad=edad;
        ok=1;
    }
    return ok;
}
int animal_getEdad(eAnimal* this,int* edad)
{
    int ok=0;
    if(this!=NULL&&edad!=NULL)
    {
        *edad=this->edad;
        ok=1;
    }

    return ok;
}

void animal_printOne(eAnimal* animal)
{
    printf("%3d %20s %20s               %3d\n", animal->id, animal->nombre, animal->especie, animal->edad);
}

void animal_printAll(LinkedList* lista)
{
    int tam;
    if(lista!=NULL)
    {
        tam=ll_len(lista);
        printf(" ID               NOMBRE              ESPECIE              EDAD\n");
        printf("---------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            animal_printOne(ll_get(lista, i));
        }
        printf("\n\n");
    }
}

int filtrarPerros(void* pElement)
{
    int esPerro=0;
    eAnimal* animal=NULL;
    if(pElement!=NULL)
    {
        animal=(eAnimal*)pElement;
        if(!stricmp(animal->especie, "Perro"))
        {
            esPerro=1;
        }
    }
    return esPerro;
}

int filtrarMayoresDe10(void* pElement)
{
    int esMayorDe10=0;
    eAnimal* animal=NULL;
    if(pElement!=NULL)
    {
        animal=(eAnimal*)pElement;
        if(animal->edad>10)
        {
            esMayorDe10=1;
        }
    }
    return esMayorDe10;
}

/** \brief Utiliza ll_newLinkedList y ll_add
 *
 * \return LinkedList*
 *
 */
int animal_fillList(char* path, LinkedList* animales)
{
    int ok=0;
    FILE* pFile;
    if(path!=NULL && animales!=NULL)
    {
        pFile=fopen(path, "r");
        if(pFile!=NULL)
        {
            if(!parser_AnimalFromText(pFile, animales))
            {
                ok=1;
            }
            fclose(pFile);
        }
    }
    return ok;
}

int animal_printCantidadTotal(LinkedList* animales)
{
    int ok=0;
    if(animales!=NULL)
    {
        printf("La cantidad total de animales es de %d\n\n", ll_len(animales));
        ok=1;
    }
    return ok;
}

int animal_checkPerros(LinkedList* animales, LinkedList* perros)
{
    int ok=0;
    if(animales!=NULL&&perros!=NULL)
    {
        ok=ll_containsAll(animales, perros);
    }
    return ok;
}

int animal_informarXPosicion(LinkedList* animales, int indice)
{
    int ok=0;

    if(animales!=NULL && ll_len(animales)>=indice)
    {
        animal_printOne((eAnimal*) ll_get(animales, (indice-1)));
        ok=1;
    }
    return ok;
}

int animal_cambiarUltimoXPrimero(LinkedList* animales)
{
    int ok=0, tam;
    eAnimal* auxAnimal;
    if(animales!=NULL)
    {
        auxAnimal=ll_get(animales, 0);
        tam=ll_len(animales);
        ll_set(animales, 0, ll_get(animales, (tam-1)));
        ll_set(animales, (tam-1), auxAnimal);
        ok=1;
    }
    return ok;
}

int animal_eliminarADundee(LinkedList* animales)
{
    int ok=0, tam;
    eAnimal* auxAnimal;
    if(animales!=NULL)
    {
        tam=ll_len(animales);
        for(int i=0; i<tam; i++)
        {
            auxAnimal=ll_get(animales, i);
            if(!strcmp(auxAnimal->nombre, "Dundee"))
            {
                ll_remove(animales, i);
                ok=1;
                break;
            }
        }
    }
    return ok;
}

int animal_vaciarPerros(LinkedList* perros)
{
    int ok=0;
    if(perros!=NULL)
    {
        if(!ll_clear(perros))
        {
            ok=1;
        }
    }
    return ok;
}

int animal_devolverPosicionDeDumbo(LinkedList* animales)
{
    int returnAux=-1, tam;
    eAnimal* auxAnimal=NULL;
    if(animales!=NULL)
    {
        tam=ll_len(animales);
        for(int i=0; i<tam; i++)
        {
            auxAnimal=ll_get(animales, i);
            if(!strcmp(auxAnimal->nombre, "Dumbo"))
            {
                returnAux=ll_indexOf(animales, auxAnimal);
            }
        }
    }
    return returnAux;
}

int animal_duplicarAnimalDelFinal(LinkedList* animales)
{
    int ok=0, tam;
    eAnimal* auxAnimal=NULL;
    if(animales!=NULL)
    {
        tam=ll_len(animales);
        auxAnimal= ll_get(animales, tam-1);
        ll_push(animales, tam, auxAnimal);
        ok=1;
    }
    return ok;
}

int animal_eliminarAnimalDelFinal(LinkedList* animales)
{
    int ok=0, tam;
    eAnimal* auxAnimal=NULL;
    if(animales!=NULL)
    {
        tam=ll_len(animales);
        auxAnimal= ll_pop(animales, tam-1);
        animal_printOne(auxAnimal);
        ok=1;
    }
    return ok;
}

LinkedList* animal_subListaPrimerosTres(LinkedList* animales)
{
    LinkedList* primerosTres=NULL;
    if(animales!=NULL && ll_len(animales)>=3)
    {
        primerosTres=ll_newLinkedList();
        if(primerosTres!=NULL)
        {
            primerosTres= ll_subList(animales, 0, 3);
        }
    }

    return primerosTres;
}

LinkedList* animal_clonarLista(LinkedList* animales)
{
    LinkedList* clonada=NULL;
    if(animales!=NULL)
    {
        clonada=ll_newLinkedList();
        if(clonada!=NULL)
        {
            clonada= ll_clone(animales);
        }
    }
    return clonada;
}

int animal_compararEdad(void* pElementA, void* pElementB)
{
    int ok=0;
    int edadA;
    int edadB;

    if(pElementA!=NULL && pElementB!=NULL)
    {
        animal_getEdad((eAnimal*)pElementA, &edadA);
        animal_getEdad((eAnimal*)pElementB, &edadB);

        if(edadA>edadB)
        {
            ok=1;
        }
        else if(edadA<edadB)
        {
            ok=-1;
        }
        else
        {
            ok=0;
        }
    }
    return ok;

}

int animal_ordenarXEdad(LinkedList* animales)
{
    int ok=0;
    if(animales!=NULL)
    {
        if(!ll_sort(animales, animal_compararEdad, 1))
        {
            ok=1;
        }
    }
    return ok;
}
