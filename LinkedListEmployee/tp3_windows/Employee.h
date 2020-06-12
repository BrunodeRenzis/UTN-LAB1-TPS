#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
int employee_isValidEmp(Employee* emp);
int automaticId(LinkedList* this);
int maxId(LinkedList* this);
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void showHeaderEmployee();
void showEmployee(Employee* pArrayList);
int menuModify();
int sortMenu();
int employee_sortById(void* empA, void* empB);
int employee_sortByName(void* empA, void* empB);
int employee_sortByHours(void* empA, void* empB);
int employee_sortBySalary(void* empA, void* empB);
#endif // employee_H_INCLUDED
