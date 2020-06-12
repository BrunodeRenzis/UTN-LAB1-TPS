#ifndef DERENZIS_H_INCLUDED
#define DERENZIS_H_INCLUDED



#endif // DERENZIS_H_INCLUDED
int menu(int valorX, int valorY,int flagX,int flagY);
/** \brief Despliega un menu de opciones con valores que se modifican a medida que el usuario ingresa los suyos.
 * \param int valorX
 * \param int valorY
 * \param int flagX
 * \param int flagY
 * \return opcion
 *
 */


void operaciones(int valorX,int valorY);
/** \brief Realiza todas las operaciones en simultaneo e informa al usuario.
 *
 * \param int valorX
 * \param int valorY
 * \return void
 *
 */

int suma(int valorX, int valorY);
/** \brief Suma dos valores ingresados por el usuario
 *
 * \param int valorX
 * \param int valorY
 * \return (valorX+valorY)
 *
 */

int resta(int valorX, int valorY);
/** \brief Resta dos valores ingresados por el usuario
 *
 * \param int valorX
 * \param int valorY
 * \return (valorX-valorY)
 *
 */

int multiplicacion(int valorX, int valorY);
/** \brief Multiplica dos valores ingresados por el usuario
 *
 * \param int valorX
 * \param int valorY
 * \return (valorX*valorY)
 *
 */

float division(int valorX, int valorY);
/** \brief Divide dos valores ingresados por el usuario, a menos que el divisor sea 0, situacion en la cual
           aparecera un mensaje advirtiendo que dicha cuenta no se puede realizar
 *
 * \param int valorX
 * \param int valorY
 * \return (valorX/valorY)
 *
 */

double factorialX(int valorX);
/** \brief Realiza el factorial del primer valor ingresado.
 * \param int valorX
 * \return (valorX*factorialX(valorX-1))
 *
 */

double factorialY(int valorY);
/** \brief Realiza el factorial del segundo valor ingresado.
 * \param int valorY
 * \return (valorY*factorialY(valorY-1))
 *
 */

 void showResults(int valorX, int valorY);
 /** \brief Muestra resultados de las cuentas efectuadas
  *
  * \param int valorX
  * \param int valorY
  * \return void
  *
  */

