int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/*
 * brief Controla que lo que se este llamando desde un texto sea correcto
 * \param pFile Puntero al archivo a ser leido
 * \param pArrayListEmployee Puntero a la lista
 * \return retorna 1 si todo salió bien, -1 si algún parámetro tiene NULL como valor, 0 si algo anduvo mal
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/*
 * brief Controla que lo que se este llamando o creando desde un texto sea correcto y crea un archivo binario
 * \param pFile Puntero al archivo a ser leido
 * \param pArrayListEmployee Puntero a la lista
 * \return retorna 1 si todo salió bien, -1 si algún parámetro tiene NULL como valor, 0 si algo anduvo mal
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);
/*
 * brief Controla que todos los parametros pasados a un Empleado al agregarlo tengan un valor correcto.
 * \param pArrayListEmployee Puntero a la lista
 * \return retorna 1 si todo salió bien, -1 si algún parámetro tiene NULL como valor, 0 si algo anduvo mal
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/*
 * brief Lee mediante el id a un empleado y modifica los datos seleccionados.
 * \param pArrayListEmployee Puntero a la lista
 * \return retorna 1 si todo salió bien, -1 si algún parámetro tiene NULL como valor, 0 si algo anduvo mal
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/*
 * brief Selecciona mediante su id a un empleado y lo elimina.
 * \param pArrayListEmployee Puntero a la lista
 * \return retorna 1 si todo salió bien, -1 si algún parámetro tiene NULL como valor, 0 si algo anduvo mal
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/*
 * brief Lee y muestra los datos de la lista.
 * \param pArrayListEmployee Puntero a la lista
 * \return retorna 1 si todo salió bien, -1 si algún parámetro tiene NULL como valor, 0 si algo anduvo mal
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/*
 * brief Lee y ordena según criterio seleccionado.
 * \param pArrayListEmployee Puntero a la lista
 * \return retorna 1 si todo salió bien, -1 si algún parámetro tiene NULL como valor, 0 si algo anduvo mal
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/*
 * brief Controla que lo que se este guardando desde un texto sea correcto
 * \param pFile Puntero al archivo a ser leido
 * \param pArrayListEmployee Puntero a la lista
 * \return retorna 1 si todo salió bien, -1 si algún parámetro tiene NULL como valor, 0 si algo anduvo mal
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
/*
 * brief Controla que lo que se este guardando desde un archivo binario sea correcto.
 * \param pFile Puntero al archivo a ser leido
 * \param pArrayListEmployee Puntero a la lista
 * \return retorna 1 si todo salió bien, -1 si algún parámetro tiene NULL como valor, 0 si algo anduvo mal
 */
