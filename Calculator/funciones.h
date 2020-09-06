#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int menu(double a, double b);

void opcion1(double a);

void opcion2(double b);

double getDouble(char mensaje[]);

int intNum(double num);

void calculateOperations(double a, double b, double suma, double resta, double mult, double div, long long int factA, long long int factB);

double operation(char op, double a, double b);

long long int fact(double numero);

int informResult(double a, double b, double r, char c);

int informDiv(double a, double b, double r);

int informFact(double a, long long int factA, double b, long long int factB);

#endif // FUNCIONES_H_INCLUDED
