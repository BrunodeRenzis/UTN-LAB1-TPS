#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	option=menu();
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;

            case 2:
            	controller_loadFromBinary("databin.csv",listaEmpleados);
            	break;

            case 3:
            	controller_addEmployee(listaEmpleados);
            	break;

            case 4:
            	controller_editEmployee(listaEmpleados);
            	break;

            case 5:
            	controller_removeEmployee(listaEmpleados);
            	break;

            case 6:
            	controller_ListEmployee(listaEmpleados);
            	break;

            case 7:
            	controller_sortEmployee(listaEmpleados);
            	break;

            case 8:
            	controller_saveAsText("data.csv",listaEmpleados);
            	break;

            case 9:
            	controller_saveAsBinary("databin.csv",listaEmpleados);
            	break;

            case 10:
            	msg("Hasta luego");
            	break;
        }
        system("pause");
        system("cls");
    }while(option != 10);
    return 0;
}

