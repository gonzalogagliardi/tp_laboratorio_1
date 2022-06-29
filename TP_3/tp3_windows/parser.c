#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	char id[20];
	char nombre[50];
	char apellido[50];
	char precio[50];
	char tipoPasajero[50];
	char codigoVuelo[50];

	Passenger* auxPassanger;


		if(pFile != NULL && pArrayListPassenger != NULL)
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, tipoPasajero, codigoVuelo);


		}

    return 1;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (binario.bin) (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

    return 1;
}
