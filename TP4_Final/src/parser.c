#include "parser.h"

int parser_AnimalFromText(FILE* pFile, LinkedList* pArrayAnimales)
{
    int ok=-1;
    int r;
    char buffer[4][128];
    eAnimal* unAnimal;
    if(pFile!=NULL)
    {
        //pFile=fopen("data.csv", "r");
        r=fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        do
        {
            r=fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if(r==4)
            {
                //printf("%5s\t%30s\t%10s\t%10s\n", buffer[0], buffer[1], buffer[2], buffer[3]);
                unAnimal=animal_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
                if(unAnimal!=NULL)
                {
                    ll_add(pArrayAnimales, unAnimal);
                }
            }
            else
            {
                break;
            }
        }while(!feof(pFile));
        fclose(pFile);
    }
    return ok;
}
