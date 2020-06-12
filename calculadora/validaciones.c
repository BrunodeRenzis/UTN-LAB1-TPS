#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
/*
isInt
isFloat
isChar
isString
areSure
*/

int getInt(char* message,char* msgError)
{
    int valor;
        while(utn_getNumero(&valor,message,msgError,0,100,3)!=0)
        {
            printf("%s",msgError);
            scanf("%d",&valor);
        }

   return valor;
}

int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
    int retorno=-1;
    int bufferInt;
    if(pResultado!=NULL && mensaje !=NULL &&mensajeError!=NULL && minimo<=maximo && reintentos>=0)
    {
        do
        {
            printf("%s",mensaje);
            scanf("%d",&bufferInt);
            if(bufferInt>=minimo && bufferInt<=maximo)
            {
                *pResultado=bufferInt;
                retorno=0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos--;
            }
        }
        while(reintentos>=0);
    }
    return retorno;

}

float getFloat(char* message)
{
    float auxiliar;
    printf("%s",message);
    fflush(stdin);
    scanf("%f",&auxiliar);
    return auxiliar;
}

char* getChar(char* message)
{
    char* auxiliar=NULL;
    printf("%s",message);
    scanf("%s",auxiliar);
    return auxiliar;
}

int validNumber(char* str)
{
    int i=0;
    int validation = 1;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            atoi(str);
            validation = 0;
        }
        i++;
    }
    return validation;
}
