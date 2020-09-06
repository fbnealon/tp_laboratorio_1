#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Menu de opciones
 *
 * \param a double
 * \param b double
 * \return int
 *
 */
int menu(double a, double b);

/** \brief Imprime en consola la opcion uno del menu, con o sin coma en el operando a
 *
 * \param a double
 * \return void
 *
 */
void opcion1(double a);

/** \brief Imprime en consola la opcion dos del menu, con o sin coma en el operando b
 *
 * \param b double
 * \return void
 *
 */
void opcion2(double b);

/** \brief Obtiene un numero de tipo double
 *
 * \param mensaje[]: cadena a mostrar en consola
 * \return double
 *
 */
double getDouble(char mensaje[]);

/** \brief Realiza la operacion indicada con el caracter "op"
 *
 * \param op char: el operador a utilizar, debe ser '+', '-', '*' o '/'
 * \param a double
 * \param b double
 * \return double
 *
 */
double operation(char op, double a, double b);

/** \brief calcula el factorial de "numero"
 *
 * \param numero double
 * \return long long int
 *
 */
long long int fact(double numero);

/** \brief Informa los resultados de las operaciones
 *
 * \param a double
 * \param b double
 * \param r double
 * \param c char
 * \return int
 *
 */
int informResult(double a, double b, double r, char c);

/** \brief Informa los resultados de la division, o si no es posible realizarla
 *
 * \param a double
 * \param b double
 * \param r double
 * \return int
 *
 */
int informDiv(double a, double b, double r);

/** \brief Informa el factorial de los operandos posibles
 *
 * \param a double
 * \param factA long longint
 * \param b double
 * \param factB long longint
 * \return int
 *
 */
int informFact(double a, long long int factA, double b, long long int factB);

#endif // FUNCIONES_H_INCLUDED
