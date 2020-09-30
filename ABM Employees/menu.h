#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "getfunctions.h"

/** \brief Main menu for an employee ABM
 *
 * \return int option selected from the menu
 *
 */
int selectOption();

/** \brief Submenu for modification options
 *
 * \return char option selected from the menu
 *
 */
char modificationMenu();

/** \brief Submenu for reporting options
 *
 * \return int option selected from the menu
 *
 */
int reportMenu();



#endif // MENU_H_INCLUDED
