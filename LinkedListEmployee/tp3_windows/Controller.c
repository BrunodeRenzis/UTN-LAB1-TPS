#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"
#include "controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk=-1;
	FILE* pFile;
	if(path!=NULL && pArrayListEmployee!=NULL){
		pFile = fopen(path,"r");

		if(pFile!=NULL){
			if(parser_EmployeeFromText(pFile,pArrayListEmployee)==1){
				printf("Archivo leido!");

				todoOk=1;

			}

			else if(parser_EmployeeFromText(pFile,pArrayListEmployee)==0){
				msg("Se ingreso al archivo pero no se termino de leer");
				todoOk=0;
			}

			else{
				msg("Error al cargar el archivo");
			}

		}
	}
    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk=-1;
		FILE* pFile;
		if(path!=NULL && pArrayListEmployee!=NULL)
		{
			pFile = fopen(path,"wb");

			if(pFile!=NULL)
			{
				parser_EmployeeFromBinary(pFile,pArrayListEmployee);
				printf("Archivo leido!");
				fclose(pFile);
				todoOk=1;
			}
			else
			{
				msg("Error al cargar el archivo");
				todoOk=0;
			}


		}
	    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk=-1;
	int auxId,auxHorasTrabajadas,auxSueldo;
	char auxNombre[20];
	Employee* new = employee_new();

	if(pArrayListEmployee!=NULL){

			auxId=automaticId(pArrayListEmployee);
			auxHorasTrabajadas = inputValidInt("Ingrese cantidad de horas trabajadas: ","\nError, Ingrese una cantidad mayor a 0",1,1000,5);
			auxSueldo = inputValidInt("Ingrese un sueldo: ","\nDebe ingresar una cifra mayor a 0: ",1,1000000,4);
			utn_getString(auxNombre,20,4,"Ingrese un nombre: ","\nError no ha ingresado un numero valido, intente nuevamente: ");

			if(employee_setId(new,auxId) && employee_setHorasTrabajadas(new,auxHorasTrabajadas) && employee_setNombre(new,auxNombre) && employee_setSueldo(new,auxSueldo)){
				ll_add(pArrayListEmployee,new);
				msg("Empleado Agregado");
				todoOk=1;


			}
	}

    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk=-1;
	Employee* modifyEmployee;
	int nuevasHoras,nuevoSueldo,idActual,idBusqueda;
	char nuevoNombre[30];
	int idMaximo = maxId(pArrayListEmployee);
	int sizelist = ll_len(pArrayListEmployee);
	char respuesta = 's';
	do
	{
		controller_ListEmployee(pArrayListEmployee);
		inputValidReferenceInt("Ingrese el id a modificar: ","\nError, no ha ingresado un numero valido",&idBusqueda,1,idMaximo,5);

		if(pArrayListEmployee!=NULL){
			for(int i=0;i<sizelist;i++){
				modifyEmployee=(Employee*)ll_get(pArrayListEmployee,i);
				employee_getId(modifyEmployee,&idActual);
				if(idActual==idBusqueda){
					switch(menuModify()){
						case 1:
							utn_getString(nuevoNombre,30,4,"Ingrese nuevo nombre: ","\nError, intente nuevamente");
							if(employee_setNombre(modifyEmployee,nuevoNombre)==1){
								msg("Empleado modificado");
								todoOk=1;
								respuesta=confirma("\nDesea seguir modificando? ");
							}
							break;

						case 2:
							nuevasHoras=inputValidInt("Ingrese una nueva cantidad de horas: ","\nNo ha ingresado una cantidad valida.Intente nuevamente: ",1,70,4);
							if(employee_setHorasTrabajadas(modifyEmployee,nuevasHoras)==1){
								msg("Empleado modificado");
								todoOk=1;
								respuesta=confirma("\nDesea seguir modificando? ");
							}
							break;

						case 3:
							nuevoSueldo=inputValidInt("Ingrese nuevo sueldo: ","\nNo se ha ingresado una cantidad correcta, intente nuevamente: ",1,999999,4);
							if(employee_setSueldo(modifyEmployee,nuevoSueldo)==1){
							msg("Empleado modificado");
							todoOk=1;
							respuesta=confirma("\nDesea seguir modificando? ");
							}
							break;

						case 4:
							respuesta=confirma("Desea realizar otra operacion? : ");
							break;
					}
					system("cls");
				}
				else{
					continue;
				}
			}
		}
	}while(respuesta=='s');

		if(todoOk==-1){
			msg("No se encontro el empleado.");
		}
	    return todoOk;
	}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk=-1;
	Employee* removeEmployee;
	int sizelist = ll_len(pArrayListEmployee);
	int idRemove;
	int idAux;
	int idMaximo = maxId(pArrayListEmployee);
	controller_ListEmployee(pArrayListEmployee);
	inputValidReferenceInt("Ingrese el numero de id a remover: ","\nError, no ha ingresado un numero valido",&idRemove,1,idMaximo,5);

	if(pArrayListEmployee!=NULL){
		for(int i=0;i<sizelist;i++){
			removeEmployee=(Employee*)ll_get(pArrayListEmployee,i);
			employee_getId(removeEmployee,&idAux);
			if(idAux==idRemove){
				ll_remove(pArrayListEmployee,i);
				todoOk=1;
				msg("Empeado removido");
				break;
			}
			else{
				continue;
			}
		}
		if(todoOk==-1){
			msg("No se encontro el empleado.");
		}
	}
    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk=-1;
	Employee* auxEmployee;
	int sizeList;
	if(pArrayListEmployee!=NULL){
		sizeList = ll_len(pArrayListEmployee);
		showHeaderEmployee();
		for(int i=0;i<sizeList;i++){


				auxEmployee = (Employee*)ll_get(pArrayListEmployee,i);
				showEmployee(auxEmployee);
				todoOk=1;


		}
	}
    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

	int todoOk=-1;
	char respuesta='n';
	if(pArrayListEmployee!=NULL)
	{
		if(ll_len(pArrayListEmployee)>0)
		{
			do
			{
				switch(sortMenu())
				{
					case 1:
						ll_sort(pArrayListEmployee,employee_sortByName,1);
					break;

					case 2:
						ll_sort(pArrayListEmployee,employee_sortByHours,1);
					break;

					case 3:
						ll_sort(pArrayListEmployee,employee_sortBySalary,1);
					break;

					case 4:
						ll_sort(pArrayListEmployee,employee_sortById,1);
					break;

					case 5:
						respuesta='s';
					break;
				}
				respuesta=confirma("Desea salir? s/n ");

			}while(respuesta=='n');
		}
	}

	else{
		msg("\nLa lista en el sort tira null");
	}

    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
		FILE* file;
	    Employee* emp;
	    int length = -1;
	    int id,salary,hours,i;
	    char name[50];

	    int response = 0;

	    if(path != NULL && pArrayListEmployee != NULL){
	        length = ll_len(pArrayListEmployee);
	        if(length > 0){
	            file = fopen(path,"w");
	            if(file!=NULL){
	            	fprintf(file,"ID NOMBRE HORAS TRABAJADAS SUELDO\n");
	                for(i=0;i<length;i++){
	                    emp=(Employee*)ll_get(pArrayListEmployee,i);
	                    employee_getId(emp,&id);
	                    employee_getNombre(emp,name);
	                    employee_getHorasTrabajadas(emp,&hours);
	                    employee_getSueldo(emp,&salary);
	                    fprintf(file,"%d,%s,%d,%d\n",id,name,hours,salary);
	                }
	                fclose(file);
	                if(i == length){
	                    response = 1;
	                }
	            }
	        }
	    }
	    if(response == 1)
	    {
	         	printf("Datos salvados con exito");
	    }
	    else
	    {
	        if(length == 0)
	        {
	        	printf("Ups!, la lista esta vacia. No hay datos que guardar");
	        }
	        else
	        {
	        	printf("Ups!, ocurrio un error al savar los datos");
	        }
	    }
	    return response;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* file;
	Employee* emp;
	int length = -1,i;

	int response = 0;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		length = ll_len(pArrayListEmployee);
		if(length > 0)
		{
			file = fopen(path,"wb");
			if(file!=NULL)
			{
				for(i=0;i<length;i++)
				{
					emp=ll_get(pArrayListEmployee,i);
					if(emp!=NULL){
						fwrite(emp,sizeof(Employee),1,file);
					}
				}
				fclose(file);

				if(i == length)
				{
					response = 1;
				}
			}
		}
		msg("Datos binarios guardados");
	}

	else
			{
				printf("No se pudo guardar");
			}
		return response;
}
