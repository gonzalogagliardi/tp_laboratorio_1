/*
 * funciones.c
 *
 *  Created on: 25 abr. 2022
 *      Author: Principal
 */
#include "funciones.h"

float tarjetaDebito(float x)
{

    float descuento = 0.2;




    x = x - (x * descuento);


    return x;


}

float tarjetaCredito(float x)
{

	float interes = 1.25;

    x = x * interes;

	return x;


}

float bitcoin(float x)
{
    float bitcoin = 4606954.55;

    x = x / bitcoin;

    return x;


}

float precioPorKm(float x, float km)
{
   x = x / km;

    return x;
}

float diferenciaPrecio(float precioA, float precioL)
{
     float diferencia = 0;

     if(precioA > precioL)
     {
    	 diferencia = precioA - precioL;

     }
     else if(precioL > precioA)
     {
    	 diferencia = precioL - precioA;
     }
     return diferencia;
}
