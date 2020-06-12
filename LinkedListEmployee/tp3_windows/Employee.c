#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"


Employee* employee_new(){
	Employee* this = malloc(sizeof(Employee));
	if(this!=NULL){
	   employee_setId(this,0);
	   employee_setNombre(this," ");
	   employee_setHorasTrabajadas(this,0);
	   employee_setSueldo(this,0);
	}
	return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo){
	Employee* this=NULL;
		if(idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldo!=NULL){
			this=employee_new();
			if(this!=NULL){

				if(!employee_setId(this,atoi(idStr))|| !employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr))||
				   !employee_setNombre(this,nombreStr)|| !employee_setSueldo(this,atoi(sueldo))){

				free(this);
				this=NULL;
			}
		}
	}
		return this;
}
void employee_delete(Employee* this){
	if(this!=NULL){
		free(this);
	}
}

int employee_setId(Employee* this,int id){
	int todoOk=-1;
	if(this!=NULL && id>0){
		this->id = id;
		todoOk=1;
	}
	return todoOk;
}
int employee_getId(Employee* this,int* id){
	int todoOk=-1;
	if(this!=NULL && id>0){
		*id = this->id;
		todoOk=1;
	}
	return todoOk;
}

int employee_setNombre(Employee* this,char* nombre){
	int todoOk=-1;
	if(this!=NULL && strlen(nombre)>0){
		strcpy(this->nombre,nombre);
		todoOk=1;
	}
	return todoOk;
}
int employee_getNombre(Employee* this,char* nombre){
	int todoOk=-1;
	if(this!=NULL){
		strcpy(nombre,this->nombre);
		todoOk=1;
	}
	return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int todoOk=-1;
	if(this!=NULL && horasTrabajadas>=0){
		this->horasTrabajadas = horasTrabajadas;
		todoOk=1;
	}
	return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int todoOk=-1;
	if(this!=NULL && horasTrabajadas >= 0){
		*horasTrabajadas = this->horasTrabajadas;
		todoOk=1;
	}
	return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo){
	int todoOk=-1;
	if(this!=NULL && sueldo >= 0){
		this->sueldo = sueldo;
		todoOk=1;
	}
	return todoOk;
}
int employee_getSueldo(Employee* this,int* sueldo){
	int todoOk=-1;
	if(this!=NULL && sueldo>=0){
		*sueldo = this->sueldo;
		todoOk=1;
	}
	return todoOk;
}

void showHeaderEmployee(){
	printf("   ID       NOMBRE    HORAS TRABAJADAS    SUELDO\n");
}

void showEmployee(Employee* pArrayList){

		if(pArrayList!=NULL){
			printf("%5d %10s %10d %17d\n",pArrayList->id,pArrayList->nombre,pArrayList->horasTrabajadas,pArrayList->sueldo);
		}

		else{
			msg("No hay empleados para mostrar. ");
		}
}


int employee_sortByName(void* empA, void* empB){
	int todoOk=-1;
	Employee* emp1=NULL;
	Employee* emp2=NULL;
	char nombre1[20];
	char nombre2[20];


	if(empA!=NULL && empB!=NULL){
		emp1=(Employee*)empA;
		emp2=(Employee*)empB;
		employee_getNombre(emp1,nombre1);
		employee_getNombre(emp2,nombre2);
		if(stricmp(nombre1,nombre2)==1)
		{
			todoOk=1;
		}

		else if(stricmp(nombre1,nombre2)==-1){
			todoOk=0;
		}

	}
	return todoOk;
}

int employee_sortBySalary(void* empA, void* empB){
	int todoOk=-1;
	Employee* emp1=NULL;
	Employee* emp2=NULL;

	if(empA!=NULL && empB!=NULL){
		emp1=(Employee*)empA;
		emp2=(Employee*)empB;
		int sueldo1,sueldo2;
		employee_getSueldo(emp1,&sueldo1);
		employee_getSueldo(emp2,&sueldo2);
		if(sueldo1 > sueldo2)
		{
			todoOk=1;
		}

		else if(sueldo1 < sueldo2){
			todoOk=0;
		}

	}
	return todoOk;
}

int employee_sortByHours(void* empA, void* empB){
	int todoOk=-1;
	Employee* emp1=NULL;
	Employee* emp2=NULL;

	if(empA!=NULL && empB!=NULL){
		emp1=(Employee*)empA;
		emp2=(Employee*)empB;
		int horas1,horas2;
		employee_getHorasTrabajadas(emp1,&horas1);
		employee_getHorasTrabajadas(emp2,&horas2);
		if(horas1 > horas2)
		{
			todoOk=1;
		}

		else if(horas1 < horas2){
			todoOk=0;
		}

	}
	return todoOk;
}

int employee_sortById(void* empA, void* empB){
	int todoOk=-1;
	Employee* emp1=NULL;
	Employee* emp2=NULL;

	if(empA!=NULL && empB!=NULL){
		emp1=(Employee*)empA;
		emp2=(Employee*)empB;
		int id1;
		int id2;
		employee_getId(emp1,&id1);
		employee_getId(emp2,&id2);
		if(id1 > id2)
		{
			todoOk=1;
		}

		else if(id1 < id2){
			todoOk=0;
		}

	}
	return todoOk;
}

int sortMenu(){
	int option;
	printf("1-Ordenar por Nombre\n2-Ordenar por Horas trabajadas\n3-Ordenar por sueldo\n4-Ordenar Por Id\n5-Salir\n");
	option=inputValidInt("Ingrese una opcion: ","\nNo ha ingresado una opcion valida, intente nuevamente: ",1,5,5);
	return option;
}

int menuModify(){
	int option;
	printf("1-Modificar Nombre\n2-Modificar Horas trabajadas\n3-Modificar sueldo\n4-Salir\n");
	option=inputValidInt("Ingrese una opcion: ","\nNo ha ingresado una opcion valida, intente nuevamente: ",1,4,5);
	return option;
}

int employee_isValidEmp(Employee* emp){
    int id,hours,salary;
    int todoOk = 0;
    char name[50];

    if(emp != NULL){
        employee_getId(emp,&id);
        employee_getHorasTrabajadas(emp,&hours);
        employee_getSueldo(emp,&salary);
        employee_getNombre(emp,name);

        if(id > 0 && hours > 0 && salary > 0 && name != NULL){
            todoOk=1;
        }
    }
    return todoOk;
}


int automaticId(LinkedList* this)
{
	int idMaximo,id;
	static int saveId;
	Employee* anEmployee;
	if(this!=NULL)
	{
		for(int i=0;i<ll_len(this);i++)
		{
			anEmployee=(Employee*)ll_get(this,i);
			employee_getId(anEmployee,&id);

			if(i==0 && id>0)
			{
				idMaximo=id;
			}
			else if(id>idMaximo)
			{
				idMaximo=id;
			}

		}

	}
		if(idMaximo>saveId)
			saveId=idMaximo+1;

		else
			saveId++;

	return saveId;
}

int maxId(LinkedList* this){
	int idMaximo,id;
	Employee* anEmployee;
	if(this!=NULL)
	{
		for(int i=0;i<ll_len(this);i++)
		{
			anEmployee=(Employee*)ll_get(this,i);
			employee_getId(anEmployee,&id);

			if(i==0 && id>0)
			{
				idMaximo=id;
			}
			else if(id>idMaximo)
			{
				idMaximo=id;

			}
		}

	}

	return idMaximo;
}
