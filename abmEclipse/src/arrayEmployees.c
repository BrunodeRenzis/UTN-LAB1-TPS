#include "arrayEmployees.h"
#include "utn.h"
#include "informes.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int menu()
{
    int option;
    printf("\n1-ALTA\n2-MODIFICAR\n3-BAJA\n4-INFORMES\n5-SALIR\n");
    option=inputValidInt("\nIngrese una opcion: ","No ha ingresado un numero. Intente de nuevo: ",1,5,3);
    return option;
}

eEmployee newEmployee(int id,char name[],char lastName[],float salary,int sector)
{

    eEmployee emp;
    emp.id = id;
    strcpy(emp.name,name);
    strcpy(emp.lastName,lastName);
    emp.salary = salary;
    emp.sector = sector;
    emp.isEmpty = 0;

    return emp;
}

void initEmployees(eEmployee vecEmployees[],int tamEmployees)
{
    for(int i=0; i<tamEmployees; i++)
    {
        vecEmployees[i].isEmpty=1;
        vecEmployees[i].id=0;
        strcpy(vecEmployees[i].name," ");
        strcpy(vecEmployees[i].lastName," ");
        vecEmployees[i].salary=0;
        vecEmployees[i].sector=0;
    }
}

int findFree(eEmployee vecEmployees[],int tamEmployees)
{
    int emptySpace=-1;
    for(int i=0; i<tamEmployees; i++)
    {
        if(vecEmployees[i].isEmpty==1)
        {
            emptySpace=i;
            printf("\nSe ha asignado la posicion %d\n",i);
            break;
        }
    }

    return emptySpace;
}

int automaticId()
{
    static int idEmpl=1000;
    return idEmpl++;
}

int addEmployees(eEmployee vecEmployees[],int tamEmployees,eSector vecSectors[],int tamSector)
{
    char name[SIZENAME],lastName[SIZELASTNAME];
    int emptySpace,idSector;
    int id=automaticId();
    float salary;
    emptySpace=findFree(vecEmployees,tamEmployees);
    if(emptySpace==-1)
    {
        printf("No hay mas lugar para agregar empleados");
    }
    else
    {
        utn_getCadena(name,20,3,"Ingrese un nombre: ","Ese no es un nombre valido");

        utn_getCadena(lastName,20,3,"Ingrese un apellido: ","Ese no es un apellido valido");

        salary=inputValidFloat("Ingrese el sueldo del empleado: ",999999);

        showSectors(vecSectors,tamSector);

        idSector=inputValidInt("Ingrese sector: ","Error, ingrese un sector que se muestre en las opciones: ",1,4,3);

        vecEmployees[emptySpace]=newEmployee(id,name,lastName,salary,idSector);

        printf("Empleado registrado! Se lo ha registrado con el id: %d\n",id);

    }
    return emptySpace;
}



void showDataEmployees()
{
    printf("  ID     Nombre     Apellido     Sueldo     Sector\n");
}

void showSector(eSector aSector)
{
    printf("%d-%s  ",aSector.idSector,aSector.description);
}

void showSectors(eSector vecSectors[],int tamSectors)
{
    for(int i=0; i<tamSectors; i++)
    {
        showSector(vecSectors[i]);
    }
}
int sectorDesc(int id, eSector vecSector[], int tamSector, char* desc)
{
    int todoOk = 0;

    for(int i=0; i < tamSector; i++)
    {
        if( id == vecSector[i].idSector)
        {
            strcpy(desc, vecSector[i].description);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

void showEmployee(eEmployee anEmployee,eSector vecSector[],int tamSector)
{
    char desc[SIZESECTORNAME];
    sectorDesc(anEmployee.sector,vecSector,tamSector,desc);
    printf("%5d %9s %12s %12.2f %10s\n",anEmployee.id,anEmployee.name,anEmployee.lastName,anEmployee.salary,desc);
}


void showEmployees(eEmployee vecEmployees[],int tamEmployees,eSector vecSector[],int tamSector)
{
    showDataEmployees();
    for(int i=0; i<tamEmployees; i++)
    {
        if(vecEmployees[i].isEmpty==0)
        {
            showEmployee(vecEmployees[i],vecSector,tamSector);
        }
    }
}

void removeEmployee(eEmployee vecEmployees[],int tamEmployees,eSector vecSector[],int tamSector)
{
    int id;
    showEmployees(vecEmployees,tamEmployees,vecSector,tamSector);
    id=findEmployeeById(vecEmployees,tamEmployees);
    for(int i=0; i<tamEmployees; i++)
    {
        if(vecEmployees[i].id==id)
        {
            vecEmployees[i].isEmpty=1;
            vecEmployees[i].salary=0;
            vecEmployees[i].sector=0;
            strcpy(vecEmployees[i].name," ");
            strcpy(vecEmployees[i].lastName," ");
            printf("Empleado removido con exito!");
            break;
        }

        else if(vecEmployees[i].id!=id)
        {
            continue;
        }

        else if(vecEmployees[i].id!=id && i<tamEmployees-1)
        {
            printf("No se ha ingresado un id valido");
        }

    }
    system("cls");
}


int findEmployeeById(eEmployee vecEmployees[],int tamEmployees)
{
	int id;
    id=inputInt("Ingrese numero de id: ");
    for(int i=0; i<tamEmployees; i++)
    {
        if(vecEmployees[i].id==id)
        {
            printf("El empleado es: %s %s id numero: %d",vecEmployees[i].name,vecEmployees[i].lastName,vecEmployees[i].id);
            break;
        }
        else{
        	printf("No se ha encontrado el id.");
        	break;
        }
    }
    return id;
}

int modificationMenu()
{
    int option;
    printf("\n1-Modificar Nombre\n2-Modificar Apellido\n3-Modificar sueldo\n4-Modificar Sector\n5-Salir\nIngrese opcion:");
    scanf("%d",&option);
    return option;
}

void modifyEmployees(eEmployee vecEmployees[],int tamEmployees,eSector vecSector[],int tamSector)
{
    int id=0,flag=0;
    char newName[SIZENAME],newLastName[SIZELASTNAME],respuesta[3];
    float newSalary;
    int newSector;
    do
    {
        showEmployees(vecEmployees,tamEmployees,vecSector,tamSector);
        id=findEmployeeById(vecEmployees,tamEmployees);
        for(int i=0; i<tamEmployees; i++)
        {
            if(vecEmployees[i].id==id)
            {
                switch(modificationMenu())
                {
                case 1:
                    utn_getCadena(newName,25,3,"Ingrese nuevo Nombre: ","Ha ingresado un nombre incorrecto. Intente de nuevo: ");
                    strcpy(vecEmployees[i].name,newName);
                    break;

                case 2:
                    utn_getCadena(newLastName,25,3,"Ingrese nuevo Apellido: ","Ha ingresado un apellido incorrecto. Intente de nuevo: ");
                    strcpy(vecEmployees[i].lastName,newLastName);
                    break;

                case 3:
                    newSalary=inputValidFloat("Ingrese nuevo sueldo: ",999999);
                    vecEmployees[i].salary=newSalary;
                    break;

                case 4:
                    showSectors(vecSector,tamSector);
                    newSector=inputValidInt("Ingrese el nuevo sector: ","No ha ingresado un sector valido. Intente de nuevo",1,4,3);
                    vecEmployees[i].sector=newSector;
                    break;

                default:
                    printf("Ingreso una opcion incorrecta");
                    break;
                }
            }

            else if(vecEmployees[i].id!=id && i<tamEmployees-1)
            {
                continue;
            }


        }
        printf("Desea realizar alguna otra modificacion? Si/No: ");
        fflush(stdin);
        gets(respuesta);
        if(stricmp(respuesta,"No")==0)
        {
            flag=1;
        }
    }
    while(flag==0);
}



void sortEmployees(eEmployee vecEmployees[],int tamEmployees,eSector vecSector[],int tamSector)
{
    switch(sortMenu())
    {
    case 1:
        sortEmployeesUpwardByLastName(vecEmployees,tamEmployees,vecSector,tamSector);
        break;

    case 2:
        sortEmployeesFallingByLastName(vecEmployees,tamEmployees,vecSector,tamSector);
        break;

    default:
        printf("ha ingresado una opcion incorrecta");
        break;
    }

}

int sortMenu()
{
    int option;
    printf("1-Ordenar por apellido de manera ascendente\n2-Ordenar por apellido de manera descendente\nIngrese una opcion");
    scanf("%d",&option);
    return option;
}

void sortEmployeesUpwardByLastName(eEmployee vecEmployees[],int tamEmployees,eSector vecSector[],int tamSector)
{
    eEmployee auxEmployee;
    for(int i=0; i<tamEmployees-1; i++)
    {
        for(int j=i+1; j<tamEmployees; j++)
        {
            if(stricmp(vecEmployees[j].lastName,vecEmployees[i].lastName)==-1)
            {
                auxEmployee=vecEmployees[i];
                vecEmployees[i]=vecEmployees[j];
                vecEmployees[j]=auxEmployee;
            }

            else if(stricmp(vecEmployees[j].lastName,vecEmployees[i].lastName)==0 && stricmp(vecSector[j].description,vecSector[j].description)==-1)
            {
                auxEmployee=vecEmployees[i];
                vecEmployees[i]=vecEmployees[j];
                vecEmployees[j]=auxEmployee;

            }
        }
    }
}

void sortEmployeesFallingByLastName(eEmployee vecEmployees[],int tamEmployees,eSector vecSector[],int tamSector)
{
    eEmployee auxEmployee;
    for(int i=0; i<tamEmployees-1; i++)
    {
        for(int j=i+1; j<tamEmployees; j++)
        {
            if(stricmp(vecEmployees[j].lastName,vecEmployees[i].lastName)==1 && stricmp(vecSector[j].description,vecSector[i].description)==1)
            {
                auxEmployee=vecEmployees[i];
                vecEmployees[i]=vecEmployees[j];
                vecEmployees[j]=auxEmployee;
            }
        }
    }
}


