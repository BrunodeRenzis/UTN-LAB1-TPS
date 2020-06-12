#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "utn.h"
#include "arrayEmployees.h"

void inputStr(char* msg, char* str)
{
    printf("%s",msg);
    fflush(stdin);
    gets(str);
}

int esNumerico(char* cadena)
{
    int i=0;
    int retorno=1;

    while(cadena[i]!='\0')
    {
        if(cadena[i]<'0' || cadena[i]>'9')
        {
            retorno=0;
        }
        i++;
    }
    return retorno;
}

int inputInt(char* cadena)
{
    int numero;

    printf("%s",cadena);
    scanf("%d",&numero);
    return numero;
}


int inputValidInt(char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
    int numero;
    char auxNum[20];

    if(mensaje!=NULL && mensajeError!=NULL && minimo>0 && maximo>=minimo)
    {
        do
        {
            inputStr(mensaje,auxNum);

            if(esNumerico(auxNum))
            {
                if(maximo==0 || ((atoi(auxNum)<=maximo) && atoi(auxNum)>=minimo))
                {
                    numero=atoi(auxNum);
                    break;
                }
                else
                {
                    printf("Error debe introducir un numero entre %d y %d ",minimo,maximo);
                }
            }
            else
            {
                printf("%s",mensajeError);
                reintentos--;
            }
        }
        while(reintentos>0);

    }
    return numero;
}


int validFloat(char str[])
{
    int i=0;
    int validation = 1;
    int contDot = 0;
    int contNum = 0;

    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9' )
        {
            if( str[i] != '.')
            {
                validation = 0;
            }
            else if( str[i] == '.')
            {
                contDot++;
            }
        }
        else
        {
            contNum++;
        }
        i++;
    }
    if(contDot > 1)
    {
        validation = 0;
    }

    if(contDot == 1 && contNum < 1)
    {
        validation = 0;
    }
    if(str[0] == '.')
    {
        validation = 0;
    }

    return validation;
}

float inputValidFloat(char message[], int max)
{
    float value;
    char input[500] ;
    int length;
    int loop = 1;

    do
    {
        if(max < 0)
        {
            printf("Error de configuracion: inputValidFloat(.. max) debe ser un numero positivo \n\n");
            break;
        }
        inputStr(message,input);
        length = strlen (input);
        if(length > 0)
        {
            if(validFloat(input))
            {
                if(max == 0 || atoi(input) <= max)
                {
                    value = atof(input);
                    loop = 0;
                }
                else
                {
                    printf("Error, debe introducir un numero entre 0 y %d. \n\n",max);
                }
            }
            else
            {
                printf("Error, debe introducir solo numeros o un punto \n\n");
            }
        }
        else
        {
            if(length == 0)
            {
                printf("Error, este campo es Obligatorio. \n\n");
            }
            else
            {
            }
        }

    }
    while(loop);

    return value;
}

int utn_getCadena(char *pAux,int limite,int reintentos,char* msj,char*msjError)
{
    int todoOk=-1;
    char auxString[limite];
    if(pAux!=NULL && limite >0 && reintentos >=0)
    {
        do
        {
            reintentos--;
            printf("%s",msj);
            if(getCadena(auxString,limite)==0 && isLetras(auxString)==0)
            {
                strncpy(pAux,auxString,limite);
                todoOk=0;
                break;
            }
            else
                printf("%s",msjError);
        }
        while(reintentos>=0);
    }
    return todoOk;
}

int isLetras(char*pAux)
{
    int todoOk=-1;
    int i=0;
    if(pAux!=NULL)
    {
        do
        {
            if(((*(pAux+i)<65 && *(pAux+i)!=32)||*(pAux+i)>90) && (*(pAux+i)<97||*(pAux+i)>122))
            {
                break;
            }
            i++;
        }
        while(i<strlen(pAux));
        if(i==strlen(pAux))
        {
            todoOk=0;
        }
    }
    return todoOk;
}

int getCadena(char* pAux,int limite)
{
    char auxString[2000];
    int todoOk =-1;
    if (pAux != NULL && limite >0)
    {
        fflush(stdin);
        fgets(auxString,sizeof(auxString),stdin);
        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= limite)
        {
            strncpy(pAux,auxString,limite);
            todoOk=0;
        }
    }
    return todoOk;
}
