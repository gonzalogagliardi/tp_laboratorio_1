/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];
	int isEmpty;
	int estadoVuelo;

}Passenger;

Passenger* Passenger_new();  // HACER NEW PARAMETROS CON CODIGO DE VUELO!
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr, char* precioStr, char* codigoVueloStr,char* tipoPasajeroStr. char* estadoVueloStr);
void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int menu();

int buscarMayorId(LinkedList* pArrayPassenger);
//getters 2: 25:00 clase 27/05
int buscarPasajerosId(LinkedList* pArrayListEmployee, int id);

#endif /* PASSENGER_H_ */
