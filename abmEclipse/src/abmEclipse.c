#include "utn.h"
#include "arrayEmployees.h"
#include "informes.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main()
{
    setbuf(stdout,NULL);
    eEmployee vecEmployees[TAMEMPLOYEES];
    eSector   vecSector[TAMSECTOR]= {{1,"Sistemas"},{2,"Comercializacion"},{3,"RRHH"},{4,"Contabilidad"}};
    initEmployees(vecEmployees,TAMEMPLOYEES);
    char seguir='s';
    do
    {
        switch(menu())
        {
        case 1:
            addEmployees(vecEmployees,TAMEMPLOYEES,vecSector,TAMSECTOR);
            break;

        case 2:
            if(getActiveEmployees(vecEmployees,TAMEMPLOYEES)==0)
                printf("Debe haber por lo menos un empleado en el sistema para realizar esta operacion. Agregue un empleado.\n");

            else
            {
                modifyEmployees(vecEmployees,TAMEMPLOYEES,vecSector,TAMSECTOR);
            }
            break;

        case 3:
            if(getActiveEmployees(vecEmployees,TAMEMPLOYEES)==0)
                printf("Debe haber por lo menos un empleado en el sistema para realizar esta operacion. Agregue un empleado.\n");

            else
            {
                removeEmployee(vecEmployees,TAMEMPLOYEES,vecSector,TAMSECTOR);
            }
            break;

        case 4:
            if(getActiveEmployees(vecEmployees,TAMEMPLOYEES)==0)
                printf("Debe haber por lo menos un empleado en el sistema para realizar esta operacion. Agregue un empleado.\n");

            else
            {
                reports(vecEmployees,TAMEMPLOYEES,vecSector,TAMSECTOR);
            }
            break;

        case 5:
            seguir='n';
            printf("Hasta luego");
            break;

        default:
            printf("La opcion ingresada es incorrecta.");
        }
        system("pause");
        system("cls");
    }
    while(seguir=='s');
    return 0;
}
