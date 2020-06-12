/*
 * parser.h
 *
 *  Created on: 6 jun. 2020
 *      Author: USUARIO
 */

#ifndef PARSER_H_
#define PARSER_H_



#endif /* PARSER_H_ */


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
/*
 * brief Parsea un archivo desde un archivo de texto
 * \param pFile Puntero al archivo a ser leido
 * \param pArrayListEmployee Puntero a la lista
 * \return retorna 1 si todo salió bien, -1 si algún parámetro tiene NULL como valor, 0 si algo anduvo mal
 */

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
/*
 * brief Parsea un archivo desde un archivo binario
 * \param pFile Puntero al archivo a ser leido
 * \param pArrayListEmployee Puntero a la lista
 * \return retorna 1 si todo salió bien, -1 si algún parámetro tiene NULL como valor, 0 si algo anduvo mal
 */
