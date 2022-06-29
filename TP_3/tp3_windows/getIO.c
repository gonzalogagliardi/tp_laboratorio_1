/*
 * getIO.c
 *
 *  Created on: 29 jun. 2022
 *      Author: Principal
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "getIO.h"

int Get_IntMinMax (char message[], char errorMessage[], int min, int max)
{
	char auxiliar[256];
	int result;

	printf ("%s", message);

	fflush(stdin);
	scanf("%s", auxiliar);

	while (Validate_IntMinMax(auxiliar, min, max) == 0)
	{
		printf("%s", errorMessage);
		fflush(stdin);
		scanf("%s", auxiliar);
	}

	result = atoi(auxiliar);



	return result;
}

int Validate_IntMinMax (char numero[], int min, int max)
{
	int i;
	int result;
	int flagMinus;
	int entero;

	flagMinus = 0;

	result = 1;

	for (i=0; i<strlen(numero); i++)
	{
		if(!isdigit(numero[i]) && numero[i] != '-')
		{
			result = 0;
			break;
		}
		else
		{
			if(numero[i]== '-')
			{
				flagMinus++;
			}
		}
		if(flagMinus > 1)
		{
			result = 0;
			break;
		}

		entero = atoi(numero);

		if(entero>max || entero<min)
		{
			result = 0;
			break;
		}
	}
	return result;
}


/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf ("%s", input);
}
int miStrlen(char vect[]) {
	int cantidad = 0;
	int i = 0;
	if (vect != NULL) {
		while (vect[i] != '\0') {
			cantidad++;
			i++;
		}
	}
	return cantidad;
}

int validarCadena(char vect[]) {
	int todoOk = 0;
	for (int i = 0; i < miStrlen(vect); i++) {
		if (!(isalpha(vect[i]))) {
			todoOk = 1;
			break;
		}
	}
	return todoOk;
}

int pedirCadena(char cadena[], char mensaje[], int limite) {
	int todoOk = 0;
	char auxCad[100];
	if (cadena != NULL && mensaje != NULL) {
		todoOk = 1;
		printf("%s", mensaje);
		fflush(stdin);
		gets(auxCad);

		while (miStrlen(auxCad) > limite || validarCadena(auxCad) == 1) {
			printf("Por favor ingresar solo letras (maximo %d): ", limite);
			fflush(stdin);
			gets(auxCad);
		}

		mayusculaPrimerCaracter(auxCad);

		strcpy(cadena, auxCad);
	}
	return todoOk;
}

int mayusculaPrimerCaracter(char cadena[]) {
	int todoOk = 0;
	if (cadena != NULL) {
		todoOk = 1;
		strlwr(cadena);
		cadena[0] = toupper(cadena[0]);
	}
	return todoOk;
}

float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}
int getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do
	{
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s", mensajeError);
		reintentos--;
	}while(reintentos >= 0);

	return retorno;
}

int getFloat(float* entry, char* message, char* errorMessage, float minimum, float maximum, int attempts) {
	int Return = -1;
	float aux;
	if(entry != NULL && message != NULL && errorMessage != NULL &&
	   (minimum == -1 || maximum == -1 || minimum <= maximum) && (attempts == -1 || attempts > 0)) {
		do {
			printf("%s", message);
			if(!auxGetFloat(&aux) &&
			   ((minimum == -1 && aux <= maximum) || (maximum == -1 && aux >= minimum) || (aux >= minimum && aux <= maximum))) {
				*entry = aux;
				Return = 0;
				break;
			}
			printf("%s", errorMessage);
			if(attempts == 0) {
				break;
			}
			if(attempts != -1) {
				attempts--;
			}
		} while(attempts == -1 || attempts > 0);
	}
	return Return;
}
int getCadena(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(getString(buffer, sizeof(buffer)) == 0 && esCadena(buffer, sizeof(buffer)) && strnlen(buffer, sizeof(buffer)) < longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

int utn_getCadena(char* pResultado, int lenMin, int lenMax, char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while (reintentos >= 0)
	{
		reintentos--;
		printf("%s", mensaje);
		if(getCadena(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < lenMax && strnlen(bufferString, sizeof(bufferString)) > lenMin)
		{
			strncpy(pResultado, bufferString, lenMax);
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
	}
	return retorno;
}


int validarEntero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	int todoOk = 0;
	int buffer;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {
		do {
			printf("%s", mensaje);

			if (getInt(&buffer) == 0 && buffer >= minimo && buffer <= maximo) {
				*pResultado = buffer;
				todoOk = 1;
				break;
			}
			reintentos--;
			printf("%s", mensajeError);
		} while (reintentos >= 0);
	}
	return todoOk;
}
