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



/** \brief initialises array of eEmployee
 *
 * \param employeeList[] eEmployee: array to initialise
 * \param len int: length of the array
 * \return int: (0) if ok, (-1) if Error
 *
 */
int initEmployees(eEmployee employeeList[], int len);



/** \brief adds an employee to the array if theres a free slot
 *
 * \param employeeList[] eEmployee: the array to add the employee to
 * \param len int: the length of the array
 * \param id int: the id to assign to the new employee
 * \return int: (2) if Error, (1)  if array has no free slot, (0) if ok
 *
 */
int addEmployee(eEmployee employeeList[], int len, int id);



/** \brief creates a new employee
 *
 * \param newEmployee eEmployee: the employee to create
 * \param id int: the id assigned to the new employee
 * \return eEmployee: the new employee
 *
 */
eEmployee createNewEmployee(eEmployee newEmployee, int id);



/** \brief finds a free slot in  the employee array (the first element with the isEmpty field empty)
 *
 * \param employeeList[] eEmployee: the array of employees
 * \param len int: the length of the array
 * \return int: the index of the array with a free slot, (-1) if there's no free slot
 *
 */
int findFreeSlot(eEmployee employeeList[], int len);



/** \brief finds an occupied slot in the employee array (the first element with the isEmpty field occupied)
 *
 * \param employeeList[] eEmployee: the array of employees
 * \param len int: the length of the array
 * \return int: the index of the array with an occupied slot, (-1) if there's no free slot
 *
 */
int findOccupiedSlot(eEmployee employeeList[], int len);



/** \brief finds an employee by the id inputted by user
 *
 * \param employeeList[] eEmployee: the array of employees
 * \param len int: the length of the array
 * \param id int: the id inputted by the user
 * \return int: the index of the array with the employee corresponding the inputted id, (-1) if there's no active employee with said id
 *
 */
int findEmployeeById(eEmployee employeeList[], int len,int id);



/** \brief removes employee (changes isEmpty field to empty) with the inputted id
 *
 * \param employeeList[] eEmployee: the array of employees
 * \param len int: the length of the array
 * \param id int: the id inputted by the user
 * \return int: (2) if Error, (1) if user cancels operation, (0) if employee is removed
 *
 */
int removeEmployee(eEmployee employeeList[], int len, int id);



/** \brief sorts employees by sector and last name, depending on the designated order
 *
 * \param employeeList[] eEmployee: the array of employees
 * \param len int: the length of the array
 * \param order int: the order (1) is from lowest sector to highest and from A to Z, (0) is from highest sector to lowest and from Z to A
 * \return int: (-1) if Error, (0) if ok
 *
 */
int sortEmployees(eEmployee employeeList[], int len, int order);



/** \brief prints the array of employees with active employeees
 *
 * \param employeeList[] eEmployee: the array of employees
 * \param length int: the length of the array
 * \return int: (-1) if Error, (0) if ok
 *
 */
int printEmployees(eEmployee employeeList[], int len);



/** \brief prints an employee
 *
 * \param anEmployee eEmployee: the employee to print
 *
 *
 */
void printAnEmployee(eEmployee anEmployee);



/** \brief modification submenu, modifies employee and asks for confirmation
 *
 * \param anEmployee eEmployee: the employee to modify
 * \return eEmployee: the modified or not modified employee
 *
 */
eEmployee changeField(eEmployee anEmployee);



/** \brief searches for employee with inputted id, if found redirects to modification submenu
 *
 * \param employeeList[] eEmployee: the array of employees
 * \param len int: the length of the array
 * \param id int: the inputted id
 * \return int: (2) if Error, (1) if user cancels operation, (0) if ok
 *
 */
int modifyEmployee(eEmployee employeeList[], int len, int id);



/** \brief report submenu, gives option to report sorted employees or salaries information, and prints selected option
 *
 * \param employeeList[] eEmployee: the array of employees
 * \param len int: the length of the array
 * \return int: (-1) if Error, (0) if ok
 *
 */
int reportInformation(eEmployee employeeList[], int len);


#endif // ARRAYEMPLOYEES_H_INCLUDED
