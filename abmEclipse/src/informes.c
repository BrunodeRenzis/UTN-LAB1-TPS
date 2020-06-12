#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "utn.h"
#include "arrayEmployees.h"
#include "informes.h"

int counterEmoloyees(eEmployee vecEmployees[],int tamEmployees)
{
    int counter=0;
    for(int i=0; i<tamEmployees; i++)
    {
        if(vecEmployees[i].isEmpty==0)
        {
            counter++;
        }
    }
    return counter;
}

int reportMenu()
{
    int option;
    printf("1-Listado de empleados ordenados alfabeticamente y por sector.\n2-Total y promedio de salarios, empleados por encima de la media.\n3-Salario mas alto\n4-Sector con mas empleados\n5-Salir\nIngrese una opcion: ");
    scanf("%d",&option);
    return option;
}

void reports(eEmployee vecEmployees[],int tamEmployees,eSector sectorVec[],int tamSector)
{
    char seguir='s';
    do
    {
        switch(reportMenu())
        {
        case 1:
            sortEmployeesUpwardByLastName(vecEmployees,tamEmployees,sectorVec,tamSector);
            showEmployees(vecEmployees,tamEmployees,sectorVec,tamSector);
            break;

        case 2:
            wageReport(vecEmployees,tamEmployees);
            break;

        case 3:
            salaryReport(vecEmployees,tamEmployees);
            break;

        case 4:
            counterEmployeesSector(vecEmployees,tamEmployees);
            break;

        case 5:
            seguir='n';
            break;

        }
        system("pause");
        system("cls");
    }
    while(seguir=='s');
}
void salaryReport(eEmployee vecEmployees[],int tamEmployees)
{
    printf("El mayor sueldo es de: %.2f \n",mayorSueldo(vecEmployees,tamEmployees));
}
int getActiveEmployees(eEmployee vecEmployees[],int tamEmployees)
{
    int activeCounter=0;
    for(int i=0; i<tamEmployees; i++)
    {
        if(vecEmployees[i].isEmpty==0)
        {
            activeCounter++;
        }
    }
    return activeCounter;
}

float totalWages(eEmployee vecEmployees[],int tamEmployees)
{
    float wageAccumulator=0;

    for(int i=0; i<tamEmployees; i++)
    {
        if(vecEmployees[i].salary>0)
        {
            wageAccumulator=wageAccumulator+vecEmployees[i].salary;
        }
    }
    return wageAccumulator;
}

float mediaWages(eEmployee vecEmployees[],int tamEmployees)
{
    float media;
    media=(totalWages(vecEmployees,tamEmployees)/getActiveEmployees(vecEmployees,tamEmployees));
    return media;
}

void wageReport(eEmployee vecEmployees[],int tamEmployees)
{
    printf("La totalidad de sueldos es %.2f.\nLa media es: %.2f \nLa cantidad de empleados que la superan es de %d",totalWages(vecEmployees,tamEmployees),mediaWages(vecEmployees,tamEmployees),exceedsAverage(vecEmployees,tamEmployees));
}

int exceedsAverage(eEmployee vecEmployees[],int tamEmployees)
{
    float average;
    average=mediaWages(vecEmployees,tamEmployees);
    int counterExceeds=0;
    for(int i=0; i<tamEmployees; i++)
    {
        if(vecEmployees[i].salary>average)
        {
            counterExceeds++;
        }
    }
    return counterExceeds;
}

float mayorSueldo(eEmployee vecEmployees[],int tamEmployees)
{
    float elMayor=0;

    for(int i=0; i<tamEmployees; i++)
    {
        if(vecEmployees[i].salary>elMayor)
        {
            elMayor=vecEmployees[i].salary;
        }
    }
    return elMayor;
}




void counterEmployeesSector(eEmployee vecEmployees[],int tamEmployees)
{
    int contadorSistemas=0,contadorComercializacion=0,contadorAtAlCliente=0,contadorRRHH=0;
    for(int i=0; i<tamEmployees; i++)
    {
        if(vecEmployees[i].isEmpty==0)
        {
            switch(vecEmployees[i].sector)
            {
            case 1:
                contadorSistemas++;
                break;
            case 2:
                contadorComercializacion++;
                break;
            case 3:
                contadorAtAlCliente++;
                break;
            case 4:
                contadorRRHH++;
                break;
            }
        }
    }
    printf("El sector sistemas tiene: %d empleados\nEl sector Comercializacion tiene: %d empleados\nEl sector At al cliente tiene: %d empleados\nEl sector RRHH tiene: %d empleados\n",contadorSistemas,contadorComercializacion,contadorAtAlCliente,contadorRRHH);
}
