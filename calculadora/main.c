#include <stdio.h>
#include <stdlib.h>
#include "derenzis.h"
#include "validaciones.h"

int main()
{
    char continuar='s';
    char respuesta='s';
    int valorX=0,valorY=0;
    int flagX=0,flagY=0;

    do
    {
        switch(menu(valorX,valorY,flagX,flagY))
        {
        case 1:
            valorX=getInt("Ingrese un numero: ","Error, no ha ingresado un numero valido.\n");
            flagX=1;
            break;

        case 2:
            if(flagX==0)
            {
                printf("No se puede cargar el valor de Y si no esta cargado el valor de X");
                system("pause");
            }
            else
            {
                valorY=getInt("Ingrese un numero: ","Error, no ha ingresado un numero valido.\n");
                flagY=1;
            }
            break;

        case 3:
            if(flagX==0 || flagY==0)
            {
                printf("No se pueden realizar las operaciones si no estan ambos valores cargados");
            }
            else
            {
                operaciones(valorX,valorY);
            }
            system("pause");
            break;

        case 4:
            if(flagX==0 || flagY==0)
            {
                printf("No se pueden mostrar las operaciones si no estan ambos valores cargados");
            }
            else
            {
                showResults(valorX,valorY);
            }
            system("pause");
            break;

        case 5:
            flagX=0;
            flagY=0;
            break;

        case 6:
            printf("Desea salir?: ");
            fflush(stdin);
            scanf("%c",&respuesta);

            if(respuesta=='s')
            {
                printf("Hasta luego");
                continuar='n';
            }

            break;

        default:
            printf("La opcion ingresada es incorrecta.");
            break;
        }
        system("cls");
    }
    while(continuar=='s');

    return 0;
}
