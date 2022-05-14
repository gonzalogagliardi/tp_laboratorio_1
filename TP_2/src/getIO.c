/*
 * getIO.c
 *
 *  Created on: 14 may. 2022
 *      Author: NBGonza
 */


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
