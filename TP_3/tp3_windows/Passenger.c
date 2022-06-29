/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */


#include "Passenger.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkedList.h"

Passenger* Passenger_new()
{						//Buena practica poner NULL al inicializar puntero
	Passenger* newPassenger = (Passenger*) malloc(sizeof(Passenger));

//
		if(newPassenger != NULL)
		{
			newPassenger ->id = 0;
			strcpy(newPassenger->nombre, "");
			strcpy(newPassenger->apellido, "");
			strcpy(newPassenger->codigoVuelo, "");
			newPassenger ->precio = 0;
			newPassenger ->tipoPasajero = 0;

		}

	return newPassenger;
}


Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr, char* precioStr, char* codigoVueloStr,char* tipoPasajeroStr, char* estadoVueloStr)
{
	Passenger* newPassenger;

		newPassenger = Passenger_new();

		// 01: 54  27/05

//	tambien usarlo en el newpassager 2.12 clase 27/05	if( !(Passenger_setId(newPassenger, idStr) &&
//			  Passenger_setNombre(newPassenger, nombreStr) &&
//			  Passenger_setApellido(newPassenger,apellidoStr) &&
//			  Passenger_setCodigoVuelo(newPassenger, codigoVueloStr) &&
//			  Passenger_setTipoPasajero(newPassenger, tipoPasajeroStr) &&
//		      Passenger_setPrecio(newPassenger, precioStr)))
//				{
//					free(newPassenger);
//					newPassenger = NULL;
//				}


		if(newPassenger != NULL)
		{

					newPassenger->id = atoi(idStr);
					strcpy(newPassenger->nombre, nombreStr);
					strcpy(newPassenger->apellido, apellidoStr);
					strcpy(newPassenger->codigoVuelo, codigoVueloStr);
					newPassenger ->precio = atof(precioStr);
					newPassenger ->tipoPasajero = atoi(tipoPasajeroStr);

		}

	return newPassenger;
}



void Passenger_delete(Passenger* pPassenger)
{
    if (pPassenger != NULL)
    {
        free(pPassenger);
    }
}



int Passenger_setId(Passenger* this,int id)
{
	int todoOk = 0;

		if(this != NULL && id < 0)
		{
			this->id = id;
			todoOk = 1;
		}

	return todoOk;
}




int Passenger_setNombre(Passenger* this,char* nombre)
{
	int todoOk = 0;

			if(this != NULL && nombre != NULL && strlen(nombre) < 20 && strlen(nombre) > 2)
			{

				strcpy(this->nombre , nombre);
				strlwr(this->nombre);
				(this->nombre)[0] = toupper((this->nombre) [0]);
				todoOk = 1;
			}

	return todoOk;

}








int Passenger_setApellido(Passenger* this,char* apellido)
{
	int todoOk = 0;

			if(this != NULL && apellido != NULL && strlen(apellido) < 20 && strlen(apellido) > 2)
			{

				strcpy(this->apellido , apellido);
				strlwr(this->apellido);
				(this->apellido)[0] = toupper((this->apellido) [0]);
				todoOk = 1;
			}

	return todoOk;

}


// Para mi tengo que poner strlen para porque es char , strl(codigoVuelo) <=7
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk = 0;

		if(this != NULL && codigoVuelo != NULL && strlen(codigoVuelo) <= 7 && strlen(codigoVuelo) > 0)
		{
			strcpy(this->codigoVuelo , codigoVuelo);
			//this->codigoVuelo = codigoVuelo;
			todoOk = 1;
		}

	return todoOk;
}


int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int todoOk = 0;

			if(this != NULL && tipoPasajero < 0)
			{
				this->tipoPasajero = tipoPasajero;
				todoOk = 1;
			}

	return todoOk;
}


int Passenger_setPrecio(Passenger* this,float precio)
{
	int todoOk = 0;

				if(this != NULL && precio < 0)
				{
					this->precio = precio;
					todoOk = 1;
				}

	return todoOk;
}



//////////////////// Getters ////////////////////


int Passenger_getId(Passenger* this,int* id)
{
	int todoOk= 0;

		if(this != NULL && id != NULL)
		{
			*id = this->id;

			todoOk = 1;
		}


	return todoOk;
}




int Passenger_getNombre(Passenger* this,char* nombre)
{
	int todoOk= 0;

			if(this != NULL && nombre != NULL)
			{

				strcpy(nombre, this->nombre);
				todoOk = 1;
			}


	return todoOk;

}


int Passenger_getApellido(Passenger* this,char* apellido)
{
	int todoOk = 0;

				if(this != NULL && apellido != NULL)
				{

					strcpy(apellido, this->apellido);
					todoOk = 1;
				}

	return todoOk;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk = 0;

				if(this != NULL && codigoVuelo != NULL)
				{

					strcpy(codigoVuelo, this->codigoVuelo);
					todoOk = 1;
				}

	return todoOk;
}


int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int todoOk = 0;

			if(this != NULL && tipoPasajero != NULL)
			{
				*tipoPasajero = this->tipoPasajero;

				todoOk = 1;
			}

	return todoOk;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int todoOk = 0;

				if(this != NULL && precio != NULL)
				{
					*precio = this->precio;

					todoOk = 1;
				}

	return todoOk;
}



int menu()
{
    	int opcion = 0;

    		system("cls");
    printf("     *** ABM - Passenger ***\n");
    printf("  1- Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("  2- Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
    printf("  3- Alta de empleado\n");
    printf("  4- Modificar datos de empleado\n");
    printf("  5- Baja de empleado\n");
    printf("  6- Listar empleados\n");
    printf("  7- Ordenar empleados\n");
    printf("  8- Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
    printf("  9- Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
    printf("  10- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    	return opcion;
}



int buscarMayorId(LinkedList* pArrayPassenger)
{
	int todoOk = 0;
	int id;
	Passenger* auxPass = NULL;
	int mayor = 0;

		if(pArrayPassenger != NULL)
		{
			for(int i = 0; i < ll_len(pArrayPassenger); i++)
			{
				auxPass = (Passenger*) ll_get(pArrayPassenger, i);
				Passenger_getId(auxPass, &id);

					if(i == 0 || id > mayor)
					{
						mayor = id;
					}
			}



		}
	return mayor;
}

int buscarPasajerosId(LinkedList* pArrayListEmployee, int id)
{

	int auxId;
	int index = -1;
	Passenger auxPass;

		for (int i=0; i < ll_len(pArrayListEmployee); i++)
		{
			auxPass = (Passenger*)ll_get(pArrayListEmployee, i);
			Passenger_getId(auxPass, &auxId);

			if(Passenger_getId(auxPass, &auxId) &&auxId == id)
			{
				index = i;
			}
		}
	return index;
}
