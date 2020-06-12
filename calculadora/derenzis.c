#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "derenzis.h"

void operaciones(int valorX,int valorY)
{
    suma(valorX,valorY);
    resta(valorX,valorY);
    multiplicacion(valorX,valorY);
    division(valorX,valorY);
    factorialX(valorX);
    factorialY(valorY);
    printf("Las operaciones han sido calculadas");
}

int menu(int valorX, int valorY,int flagX,int flagY)
{
    int opcion;
    system("cls");
    printf("1-Ingresar 1er operando (A=x)\n");
    printf("2-Ingresar 2do operando (B=y)\n");
    printf("3-Calcular todas las operaicones\n");
    printf("   a)Calcular la suma (A+B)\n");
    printf("   b)Calcular la resta (A-B)\n");
    printf("   c)Calcular la division (A/B)\n");
    printf("   d)Calcular la multiplicacion (A*B)\n");
    printf("   e)Calcular los factoriales (!A)(!B)\n");
    printf("4-Informar resultados\n");

    if(flagX==1 && flagY==0)
    {
        system("cls");
        printf("1-Ingresar 1er operando (A=%d)\n",valorX);
        printf("2-Ingresar 2do operando (B=Y)\n");
        printf("3-Calcular todas las operaicones\n");
        printf("   a)Calcular la suma (%d+B)\n",valorX);
        printf("   b)Calcular la resta (%d-B)\n",valorX);
        printf("   c)Calcular la division (%d/B)\n",valorX);
        printf("   d)Calcular la multiplicacion (%d*B)\n",valorX);
        printf("   e)Calcular los factoriales (!%d)(!B)\n",valorX);

    }

    else if(flagX==1 &&  flagY==1)
    {
        system("cls");
        printf("1-Ingresar 1er operando (A=%d)\n",valorX);
        printf("2-Ingresar 2do operando (B=%d)\n",valorY);
        printf("3-Calcular todas las operaicones\n");
        printf("   a)Calcular la suma (%d+%d)\n",valorX,valorY);
        printf("   b)Calcular la resta (%d-%d)\n",valorX,valorY);
        printf("   c)Calcular la division (%d/%d)\n",valorX,valorY);
        printf("   d)Calcular la multiplicacion (%d*%d)\n",valorX,valorY);
        printf("   e)Calcular los factoriales (!%d)(!%d)\n",valorX,valorY);
    }

    printf("4-Mostrar resultados\n");
    printf("5-Restablecer valores\n");
    printf("6-Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);
    return opcion;
}

int suma(int valorX,int valorY)
{

    return (valorX+valorY);

}

int resta(int valorX,int valorY)
{
    return (valorX-valorY);
}

int multiplicacion(int valorX,int valorY)
{
    return (valorX*valorY);
}

float division(int valorX,int valorY)
{
    if(valorY==0)
    {
        return -1;
    }
    else
    {
        return ((float)valorX/(float)valorY);
    }
}

double factorialX(int valorX)
{
    if(valorX<=1)
    {
        return 1;
    }

    else
    {
        return (valorX*factorialX(valorX-1));
    }
}

double factorialY(int valorY)
{
    if(valorY<=1)
    {
        return 1;
    }

    else
    {
        return (valorY*factorialX(valorY-1));
    }
}

void showResults(int valorX, int valorY)
{
    printf("El resultado de A+B es: %d\n",suma(valorX,valorY));
    printf("El resultado de A-B es: %d\n",resta(valorX,valorY));
    printf("El resultado de A*B es: %d\n",multiplicacion(valorX,valorY));
    division(valorX,valorY);
    if(division(valorX,valorY)!=-1)
        printf("El resultado de A/B es: %.2f\n",division(valorX,valorY));

    else
        printf("No se puede dividir por cero\n");

    printf("El factorial de A es: %.2f y el factorial de B es: %.2f\n",factorialX(valorX),factorialY(valorY));
}
