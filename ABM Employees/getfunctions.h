#ifndef GETFUNCTIONS_H_INCLUDED
#define GETFUNCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getInt(char message[], char errorMessage[], int min, int max);

float getFloat(char message[], char errorMessage[], float min, float max);

char getLetter(char message[], char errorMessage[]);

float getAverage(float sum, float counter);

void getStrings(char message[], char errorMessage[], int len, char str[]);

#endif // GETFUNCTIONS_H_INCLUDED
