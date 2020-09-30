#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
#define SIZE 1000
#define NAMES 51
#define EMPTY 1
#define OCCUPIED 0
#include "menu.h"
#include "getfunctions.h"


typedef struct
{
    int id;
    char name[NAMES];
    char lastName[NAMES];
    float salary;
    int sector;
    int isEmpty;
} eEmployee;

int initEmployees(eEmployee employeeList[], int len);

int addEmployee(eEmployee employeeList[], int len, int id);

eEmployee createNewEmployee(eEmployee newEmployee, int id);

int findFreeSlot(eEmployee employeeList[], int len);

int findOccupiedSlot(eEmployee employeeList[], int len);

int findEmployeeById(eEmployee employeeList[], int len,int id);

int removeEmployee(eEmployee employeeList[], int len, int id);

int sortEmployees(eEmployee employeeList[], int len, int order);

int printEmployees(eEmployee employeeList[], int length);

void printAnEmployee(eEmployee anEmployee);

eEmployee changeField(eEmployee anEmployee);

int modifyEmployee(eEmployee employeeList[], int len, int id);

int reportInformation(eEmployee employeeList[], int len);


#endif // ARRAYEMPLOYEES_H_INCLUDED
