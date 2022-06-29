/*
 * getIO.h
 *
 *  Created on: 29 jun. 2022
 *      Author: Principal
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#ifndef GETIO_H_
#define GETIO_H_

int Validate_IntMinMax (char numero[], int min, int max);

/** \brief Pide un entero al usuario
 *
 * \param mensaje es el mensaje para pedir numero
 * \param El mensaje de error, en caso que lo haya.
 * \param min el minimo numero deseado
 * \param max el maximo deseado
 * \return retorna el entero
 */
int Get_IntMinMax (char message[], char errorMessage[], int min, int max);

int esSoloLetras(char str[]);

int getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);

int getStringLetras(char mensaje[],char input[]);


/** \brief
 *
 * \param mensaje es el mensaje para pedir string
 * \param input Array donde se cargará el texto ingresado
 * \return void
 *
 */
void getString(char mensaje[],char input[]);

miStrlen(char vect[]);

int mayusculaPrimerCaracter(char cadena[]);

int pedirCadena(char cadena[], char mensaje[], int limite);

int validarCadena(char vect[]);

int getFloat(float* entry, char* message, char* errorMessage, float minimum, float maximum, int attempts);

int utn_getCadena(char* pResultado, int lenMin, int lenMax, char* mensaje, char* mensajeError, int reintentos);

int getCadena(char* pResultado, int longitud);


/** \brief Pide un flotante
 *
 * \param mensaje es el mesnaje para pedir numero
 * \param
 * \return el numero
 *
 */
float getFloat(char mensaje[]);

/** \brief Pide un entero
 *
 * \param mensaje es el mesnaje para pedir numero
 * \param
 * \return retorna el numero
 *
 */
int getInt(char mensaje[]);


int validarEntero(int *pResultado, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos);

#endif /* GETIO_H_ */
