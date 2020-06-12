#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
#define TAMEMPLOYEES 20
#define TAMSECTOR 4
#define SIZENAME 20
#define SIZELASTNAME 20
#define SIZESECTORNAME 20

typedef struct
{
    int id;
    char name[SIZENAME];
    char lastName[SIZELASTNAME];
    float salary;
    int sector;
    int isEmpty;
} eEmployee;

typedef struct
{
    int idSector;
    char description[SIZESECTORNAME];
} eSector;

#endif // ARRAYEMPLOYEES_H_INCLUDED
int menu();
int sortMenu();
int modificationMenu();
void initEmployees(eEmployee vecEmpleados[],int tamEmployees);
int automaticId();
int findFree(eEmployee vecEmployee[],int tamEmployees);
int addEmployees(eEmployee vecEmployees[],int tamEmployees,eSector vecSectors[],int tamSector);
void showDataEmployees();
void showEmployee(eEmployee anEmployee,eSector vecSector[],int tamSector);
void showEmployees(eEmployee vecEmployees[],int tamEmployees,eSector vecSector[],int tamSector);
void showSector(eSector aSector);
void showSectors(eSector vecSectors[],int tamSectors);
int findEmployeeById(eEmployee vecEmployees[],int tamEmployees);
void removeEmployee(eEmployee vecEmployees[],int tamEmployees,eSector vecSector[],int tamSector);
void sortEmployees(eEmployee vecEmployees[],int tamEmployees,eSector vecSector[],int tamSector);
void sortEmployeesUpwardByLastName(eEmployee vecEmployees[],int tamEmployees,eSector vecSector[],int tamSector);
void sortEmployeesFallingByLastName(eEmployee vecEmployees[],int tamEmployees,eSector vecSector[],int tamSector);
void modifyEmployees(eEmployee vecEmployees[],int tamEmployees,eSector vecSector[],int tamSector);
eEmployee newEmployee(int id,char name[],char lastName[],float salary,int sector);
