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
	char caract[100];
	char id[100];
	char nombre[100];
	char apellido[100];
	char precio[100];
	char tipoPasajero[100];
	char codigoVuelo[100];
	char estadoVuelo[100];
	Passenger* auxPasajero = NULL;

		if(pFile != NULL && pArrayListPassenger != NULL  )
		{
			fscanf(pFile, "%s", caract);

			while(!feof(pFile))
			{
				if(caract < 7)
				{
					break;
				}

				auxPasajero = Passeenger_newParametros(id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo );

				if(auxPasajero != NULL)
				{
					ll_add(pArrayListPassenger, auxPasajero );

					todoOk = 1;
				}
			}
		}

	return todoOk;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	Passenger* auxPasajero;
	int cant;


		if( pFile != NULL && pArrayListPassenger != NULL)
		{
			while(!feof(pFile))
			{
				auxPasajero  = Passenger_new();

				if( auxPasajero != NULL)
				{
					cant = fread (auxPasajero, sizeof(Passenger), 1, pFile );

					if(cant == 1)
					{
						ll_add(pArrayListPassenger, auxPasajero);
						todoOk = 1;
					}
				}
			}
		}


    return todoOk;
}
