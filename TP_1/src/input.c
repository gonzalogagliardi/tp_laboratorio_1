/*
 * input.c
 *
 *  Created on: 25 abr. 2022
 *      Author: Principal
 */
#include "input.h"

float get_Float(char* MSJ)
{
    float numero = 0;

    printf(MSJ);
    scanf("%f", &numero);

    return numero;
}

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}
