#include "getfunctions.h"

int getInt(char message[], char errorMessage[], int min, int max)
{
    int x;
    printf("%s", message);
    scanf("%d", &x);
    while(x<min || x>max)
    {
        printf("%s", errorMessage);
        fflush(stdin);
        scanf("%d", &x);
    }
    return x;
}



float getFloat(char message[], char errorMessage[], float min, float max)
{
    float x;
    printf("%s", message);
    scanf("%f", &x);
    while(x<min || x>max)
    {
        printf("%s", errorMessage);
        fflush(stdin);
        scanf("%f", &x);
    }
    return x;
}

char getLetter(char message[], char errorMessage[])
{
    char letter;
    printf("%s", message);
    fflush(stdin);
    scanf("%c", &letter);
    while((letter<'a' || letter>'z') && (letter<'A' || letter>'Z'))
    {
        printf("%s", errorMessage);
        fflush(stdin);
        scanf("%c", &letter);
    }
    return letter;
}

float getAverage(float sum, float counter)
{
    float average= sum/counter;
    return average;
}

void getStrings(char message[], char errorMessage[], int len, char str[])
{
    char auxStr[100];
    printf("%s", message);
    fflush(stdin);
    gets(auxStr);

    while(strlen(auxStr) >= len)
    {
        printf("%s", errorMessage);
        fflush(stdin);
        gets(auxStr);
    }
    strcpy(str, auxStr);
    strlwr(str);
    str[0]= toupper(str[0]);

    for(int i=0; i<strlen(str); i++)
    {
        if(str[i]== ' ')
        {
            str[i+1] = toupper(str[i+1]);
        }
    }
}
