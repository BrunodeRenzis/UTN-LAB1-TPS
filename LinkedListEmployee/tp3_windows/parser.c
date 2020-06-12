#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int todoOk=-1;
	int cantidad;
	char buffer[4][22];
	Employee* newEmp=NULL;

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

	if(pFile!=NULL && pArrayListEmployee!=NULL){

		while(!feof(pFile)){
			cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",buffer[0],buffer[1],buffer[2],buffer[3]);
			newEmp=employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);

			if(newEmp!=NULL && employee_isValidEmp(newEmp)){
				ll_add(pArrayListEmployee,newEmp);
				todoOk=1;
			}

			if(cantidad<4){
				if(feof(pFile)){
					break;
				}

				else{
					todoOk=0;
					break;
				}
			}
		}
	}

    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int todoOk=-1;
	int cantidad;
	Employee* newEmp=NULL;



	if(pFile!=NULL && pArrayListEmployee!=NULL){

		while(!feof(pFile)){
			cantidad = fread(newEmp,sizeof(Employee),1,pFile);
			newEmp=employee_new();

			if(newEmp!=NULL){
				ll_add(pArrayListEmployee,newEmp);
				todoOk=1;
			}

			else{
				employee_delete(newEmp);
			}


			if(cantidad<1){
				if(feof(pFile)){
					break;
				}

				else{
					todoOk=0;
					break;
				}
			}
		}
	}

    return todoOk;
}
