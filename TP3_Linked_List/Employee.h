#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

 #include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


/** \brief Aloja en memoria un empleado con campos precargados en 0
 *
 * \return Employee*
 *
 */
Employee* employee_new();


/** \brief Aloja en memoria un empleado con los campos pasados por parametros
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);


/** \brief Libera memoria de un empleado
 *
 * \param this Employee*
 * \return void
 *
 */
void employee_delete(Employee* this);


/** \brief Setea "id" a "this"
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* this,int id);

/** \brief Devuelve "id" de "this"
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* this,int* id);


/** \brief Setea "nombre" a "this"
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief Devuelve "nombre" de "this"
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre);


/** \brief Setea "horasTrabajadas" a "this"
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief Devuelve "horasTrabajadas" de "this"
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);


/** \brief Setea "sueldo" a "this"
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief Devuelve "sueldo" de "this"
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);


/** \brief Imprime un empleado en consola
 *
 * \param empleado Employee*
 * \return void
 *
 */
void printEmployee(Employee* empleado);

/** \brief Imprime todos los empleados cargados en los punteros alojados en "lista"
 *
 * \param lista LinkedList*
 * \return int
 *
 */
int printEmployees(LinkedList* lista);


/** \brief Compara dos empleados por nombre
 *
 * \param empleadoA void*
 * \param empleadoB void*
 * \return int
 *
 */
int employeeSortByName(void* empleadoA, void* empleadoB);

/** \brief Compara dos empleados por ID
 *
 * \param empleadoA void*
 * \param empleadoB void*
 * \return int
 *
 */
int employeeSortById(void* empleadoA, void* empleadoB);

/** \brief Compara dos empleados por horasTrabajadas
 *
 * \param empleadoA void*
 * \param empleadoB void*
 * \return int
 *
 */
int employeeSortByWorkHours(void* empleadoA, void* empleadoB);

/** \brief Compara dos empleados por sueldo
 *
 * \param empleadoA void*
 * \param empleadoB void*
 * \return int
 *
 */
int employeeSortBySalary(void* empleadoA, void* empleadoB);

/** \brief Busca un empleado por "id" en "lista" y devuelve el indice del puntero a empleado que tiene "id" en el campo id
 *         o -1 si no existe
 * \param lista LinkedList*
 * \param id int
 * \return int
 *
 */
int employee_searchById(LinkedList* lista, int id);

#endif // employee_H_INCLUDED
