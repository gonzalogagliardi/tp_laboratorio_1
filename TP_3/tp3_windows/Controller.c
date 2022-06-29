#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "getIO.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	FILE* pFile;

	pFile = fopen(path, "r");

	if(path != NULL && pArrayListPassenger != NULL)
	{
		if(pFile == NULL)
		{
			printf("No se pudo abrir el archivo.\n");
		}

		else
		{
			 if(parser_PassengerFromText(pFile, pArrayListPassenger) )
			 {
				 printf("Carga exitosa.\n");
				 todoOk = 1;
			 }
		}
	}

	fclose(pFile);


    return todoOk;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	FILE* pFile;

	pFile = fopen(path, "rb");

		if(path != NULL && pArrayListPassenger != NULL)
		{
			if(pFile == NULL)
			{
				printf("No se pudo abrir el archivo.\n");
			}
			else
			{
				if(parser_PassengerFromText(pFile, pArrayListPassenger) )
				{
					printf("Carga exitosa.\n");
					todoOk = 1;
				}
			}
		}

	fclose(pFile);

	return todoOk;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	int id;
	char nombre[100];
	char apellido[100];
	float precio;
	char codigoVuelo[100];
	int estadoVuelo;
	int tipoPasajero;
	Passenger* auxPass;

		if(pArrayListPassenger != NULL)
		{
			system("cls");
			printf("Alta de Pasajero\n");
			auxPass = Passenger_new();
			id = buscarMayorid(pArrayListPassenger);
			id = id +1;
			pedirCadena(nombre, "\nIngrese nombre: ", 100);
			pedirCadena(apellido, "\nIngrese apellido: ", 100);
			getNumero(apellido, "\nIngrese Codigo de vuelo: ", 100);
			getFloat(&precio,"\nIngrese precio: ", "\n Error, ingrese nuevamente: ", 5);
			validarEntero(&tipoPasajero, "\nIngrese el tipo de pasajero (1-FirstClass 2-Executive 3-Economy): ","\nError al ingresar datos. Reintente: ", 1, 3, 5 );
			validarEntero(&estadoVuelo, "\nIngrese el estado de vuelo (1-en HOrario 2-Aterrizado 3-En vuelo 4-Demorado): ","\nError al ingresar datos. Reintente: ", 1, 4, 5 );
			utn_getCadena(codigoVuelo, 1, 10, "\nIngrese codigo de vuelo: ", "\n Error, ingrese nuevamente: ", 5);

				if(Passenger_setNombre(auxPass, nombre) &&
						Passenger_setId(auxPass, id) &&
						Passenger_setApellido(auxPass, apellido) &&
						Passenger_setCodigoVuelo(auxPass, codigoVuelo) &&
						Passenger_setTipoPasajero(auxPass, tipoPasajero) &&
						Passenger_setPrecio(auxPass, precio))
				{
					ll_add(pArrayListPassenger, auxPass);

					printf("\nPajero cargado con exito!.\n");
					todoOk = 1
				}
		}
		else
		{
			Passenger_delete(auxPass);
		}


    return todoOk;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{

}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
		int id;
		char nombre[100];
		char apellido[100];
		float precio;
		char codigoVuelo[100];
		int estadoVuelo;
		int tipoPasajero;
		Passenger* auxPass;

				if(pArrayListPassenger != NULL)
				{
					printf("------------------------------------------------------------------------------------------------------\n");
					printf("ID     NOMBRE           APELLIDO         PRECIO       TIPO             CODIGO DE VUELO     ESTADO DE VUELO   \n");
					printf("------------------------------------------------------------------------------------------------------\n");

						for(int i=0; i< ll_len(pArrayListPassenger); i++)
						{
							auxPass = (Passenger*) ll_get(pArrayListPassenger, i);

							if(Passenger_setNombre(auxPass, nombre) &&
							Passenger_getId(auxPass, &id) &&
							Passenger_getApellido(auxPass, apellido) &&
							Passenger_getCodigoVuelo(auxPass, &codigoVuelo) &&
							Passenger_getTipoPasajero(auxPass, &tipoPasajero) &&
							Passenger_getPrecio(auxPass, &precio))
							{
								 printf("%4d     %20s           %-20s         %10.2f       %-20s         %10.2f             %10S     %10s     %15d\n", nombre, apellido, precio, tipoPasajero, codigoVuelo, estadoVuelo);
								 todoOk= 1;
							}
						}
				}


	    return todoOk;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

