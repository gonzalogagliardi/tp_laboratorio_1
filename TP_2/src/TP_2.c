/*
 ============================================================================
 Name        : TP_2.c
 Author      : Gonzalo Gagliardi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassengers.h"

#define TAM 1000

int main(void) {

		setbuf(stdout, NULL);

	 char confirmar;
	    char seguir;
	    int id = 2000;
	    Passenger lista[TAM];
	    int flag = 0;
	    int menuOrd;



	            if(!initPassenger(lista, TAM))
	            {
	               printf("Problemas al inicializar\n");
	            }

	                do{

	                    switch(menu())
	                    {

	                    case 1:
	                            if(!nuevoPassenger(lista,TAM,&id))
	                            {
	                                printf("No se pudo cargar el pasajero\n");

	                            }
	                            else{
	                                printf("\nCarga exitosa!\n");
	                            }
	                            flag = 1;
	                                break;
	                    case 2:
	                                if(flag == 0)
	                                    {
	                                        printf("Primero debe cargar un pasajero\n");
	                                    }
	                                else{
	                                            if(!modificarPassenger(lista,TAM))
	                                            {
	                                            printf("\nNo se pudo realizar la modificacion.");
	                                            }
	                                    }

	                                break;
	                    case 3:
	                            if(flag == 0)
	                                    {
	                                        printf("Primero debe cargar un pasajero\n");
	                                    }
	                                else{

	                                       if(!removePassenger(lista, TAM))
	                                        {
	                                            printf("No se pudo realizar la baja.\n");
	                                        }
	                                }


	                        break;
	                    case 4:
	                            if(flag == 0)
	                            {
	                                printf("Primero debe cargar un pasajero\n");
	                            }
	                            else
	                            {
	                                menuOrd = menuOrdenamiento();

	                                if(!printPassengerOrder(lista,TAM,menuOrd))
	                                {
	                                printf("\nNo se pudo realizar la baja.");
	                                }
	                            }
	                        break;
	                    case 5:

	                            printf("\nEsta seguro que quiere salir?: ");
	                            fflush(stdin);
	                            scanf("%c", &confirmar);
	                            if(confirmar == 's')
	                            {
	                               seguir = 'n';
	                            }
	                            else
	                            {
	                                printf("\nVolivendo al menu..");

	                            }


	                            break;
	                    default:
	                        printf("Opcion invalida\n");
	                        break;

	                    }

	                    system("pause");


	                }while(seguir != 's');





	        printf("\ndespues del while");

	return EXIT_SUCCESS;
}
