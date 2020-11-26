#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "animales.h"

int parser_AnimalFromText(FILE* pFile, LinkedList* pArrayAnimales);


#endif // PARSER_H_INCLUDED
