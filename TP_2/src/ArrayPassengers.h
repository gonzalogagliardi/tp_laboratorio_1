/*
 * ArrayPassengers.h
 *
 *  Created on: 14 may. 2022
 *      Author: NBGonza
 */
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef ARRAYPASSENGERS_H_
#define ARRAYPASSENGERS_H_

struct
{
int id;
char name[51];
char lastName[51];
float price;
char flyCode[10];
int typePassenger;
int isEmpty;
}typedef Passenger;


#endif /* ARRAYPASSENGERS_H_ */


/** \brief menu principal
 * \return  Retorna la opcion elegida del menu
 *
 */
int menu ();

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassenger(Passenger* lista, int len);


/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addPassenger(Passenger* lista, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[]);



int nuevoPassenger(Passenger* lista, int len, int* id);


/** \brief busca empeleado inicializado
 *
 * \param lista de empleados
 * \param tamaño
 * \return 1 todoOk - 0 error
 *
 */
int findFree(Passenger* lista, int let);


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removePassenger(Passenger* lista, int len);

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*/
void printPassenger(Passenger lista);


/** \brief imprime todos los empleados y pregunta en que orden
 *
 * \param tamaño
 * \param order - orden en que se imprime ascendente o descendente
 * \return retorna 1 si todoOK - 0 si hay error
 *
 */
int printPassengerOrder(Passenger lista[],int len, int order);


int printPassengers(Passenger lista[],int len);

int menuModificar(Passenger lista[],int len, int indice);


/** \brief Modifica los datos la lista de pasajeros
 *
 * \param tamaño de la misma
 * \param indice representa un id
 * \return 1 todoOk - 0 error
 */
int modificarPassenger(Passenger lista[], int len);


/** \brief Sort the elements in the array of pasajeros, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int sortPassenger(Passenger* lista, int len, int order);



/** \brief menu de ordenamiento de la lista
 * \return la opcion seleccionada del menu
 *
 */
int menuOrdenamiento();


/** \brief Informes de precios
 *
 * \param lista de pasajeros
 * \param tamaño
 * \return 1 si todoOk - 0 si hay error
 *
 */
int informesPrecios(Passenger lista[], int len);

int findFree(Passenger* lista, int len);
