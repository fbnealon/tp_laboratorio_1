#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int ok=-1;
    int r;
    char buffer[4][128];
    Employee* anEmployee;
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
                anEmployee=employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
                if(anEmployee!=NULL)
                {
                    ll_add(pArrayListEmployee, anEmployee);
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


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ok=-1;
    Employee* anEmployee;
    int f=0;
    if(pFile!=NULL)
    {
        do
        {
            anEmployee=employee_new();
            f=fread(anEmployee, sizeof(Employee), 1, pFile);
            if(f==1)
            {
                ll_add(pArrayListEmployee, anEmployee);
            }
        }while(!feof(pFile));
    }
    return ok;
}
