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
/*
 * brief Funcion constructora de un empleado
 * \return Un empleado nuevo
 */
int employee_isValidEmp(Employee* emp);
/*
 * brief Controla que los datos con los que se crea un empleado sean correctos.
  * \param emp puntero de la estructura empleado
 * \return retorna 1 si todo salió bien, -1 si algún parámetro tiene NULL como valor, 0 si algo anduvo mal
 */
int automaticId(LinkedList* this);
/*
 * brief Crea un id para cada empleado y se lo asigna
 * \param this Puntero a la lista
 * \return retorna el id asignado.
 */
int maxId(LinkedList* this);
/*
 * brief Recorre los id y se fija cual es el maximo
 * \param this Puntero a la lista
 * \return retorna el id maximo.
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);
/*
 * brief Asigna los valores a la función constructora
 *  \param idStr Id parseado a texto
 *  \param nombreStr nombre parseado a texto
 *  \param horasTrabajadasStr horas parseadas a texto
 *  \param sueldoStr Sueldo parseado a texto
 * \return retorna el empleado con los nuevos parámetros.
 */
void employee_delete();
/*
 * brief Elimina un empleado

 */

int employee_setId(Employee* this,int id);
/*
 * brief Setea el id de un empleado
 *  \param this Puntero a empleado
 *  \param id Guarda el id de un empleado
 * \return retorna -1 si algo salio mal 1 si todo salio bien.
 */
int employee_getId(Employee* this,int* id);
/*
 * brief Obtiene el id de un empleado
 *  \param this Puntero a empleado
 *  \param id Obtiene la direccion de memoria del id de un empleado
 * \return retorna -1 si algo salio mal 1 si todo salio bien.
 */
int employee_setNombre(Employee* this,char* nombre);
/*
 * brief Setea el nombre de un empleado
 *  \param this Puntero a empleado
 *  \param nombre Guarda el nombre de un empleado
 * \return retorna -1 si algo salio mal 1 si todo salio bien.
 */
int employee_getNombre(Employee* this,char* nombre);
/*
 * brief Obtiene el nombre de un empleado
 *  \param this Puntero a empleado
 *  \param nombre Obtiene la direccion de memoria del nombre de un empleado
 * \return retorna -1 si algo salio mal 1 si todo salio bien.
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/*
 * brief Setea las horas trabajadas de un empleado
 *  \param this Puntero a empleado
 *  \param horasTrabajadas Guarda las horas de un empleado
 * \return retorna -1 si algo salio mal 1 si todo salio bien.
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/*
 * brief Obtiene las horas de un empleado
 *  \param this Puntero a empleado
 *  \param horasTrabajadas Obtiene la direccion de memoria de las horas de un empleado
 * \return retorna -1 si algo salio mal 1 si todo salio bien.
 */
int employee_setSueldo(Employee* this,int sueldo);
/*
 * brief Setea el sueldo de un empleado
 *  \param this Puntero a empleado
 *  \param sueldo Guarda el sueldo de un empleado
 * \return retorna -1 si algo salio mal 1 si todo salio bien.
 */
int employee_getSueldo(Employee* this,int* sueldo);
/*
 * brief Obtiene el sueldo de un empleado
 *  \param this Puntero a empleado
 *  \param sueldo Obtiene la direccion de memoria del sueldo de un empleado
 * \return retorna -1 si algo salio mal 1 si todo salio bien.
 */
void showHeaderEmployee();
/*
 * brief Muestra los nombres de los datos de un empleado
 */
void showEmployee(Employee* pArrayList);
/*
 * brief Muestra empleados
 *  \param pArrayList Puntero a empleados
 */
int menuModify();
/*
 * brief Muestra menu de modificacion empleados
 */
int sortMenu();
/*
 * brief Muestra menu de ordenamiento de empleados
 */
int employee_sortById(void* empA, void* empB);
/*
 * brief Ordena empleados por id
 *  \param empA Puntero a ser casteado del primer empleado para el ordenamiento
 *  \param empB Puntero a ser casteado del segundo empleado para el ordenamiento
 */
int employee_sortByName(void* empA, void* empB);
/*
 * brief Ordena empleados por Nombre
 *  \param empA Puntero a ser casteado del primer empleado para el ordenamiento
 *  \param empB Puntero a ser casteado del segundo empleado para el ordenamiento
 */
int employee_sortByHours(void* empA, void* empB);
/*
 * brief Ordena empleados por Horas
 *  \param empA Puntero a ser casteado del primer empleado para el ordenamiento
 *  \param empB Puntero a ser casteado del segundo empleado para el ordenamiento
 */
int employee_sortBySalary(void* empA, void* empB);
/*
 * brief Ordena empleados por Sueldo
 *  \param empA Puntero a ser casteado del primer empleado para el ordenamiento
 *  \param empB Puntero a ser casteado del segundo empleado para el ordenamiento
 */
#endif // employee_H_INCLUDED
