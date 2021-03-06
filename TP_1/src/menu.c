/*
 * menu.c
 *
 *  Created on: 25 abr. 2022
 *      Author: Principal
 */
#include "menu.h"
#include "input.h"
#include "funciones.h"

int menuCargarPrecios ()
{
    int opcion;


        printf("\t");
        printf("\n\n\n**Menu de opciones**\n\n");
        printf("\n1. Precio vuelo Aerolíneas: ");
        printf("\n2. Precio vuelo Latam: ");
        printf("\n3. Salir.");
        printf("\n\nIndique opcion: ");
        //__fpurge(stdin);
        fflush(stdin);
        scanf("%d",&opcion);

        return opcion;
}



int menu()
{
    int opcion;


        printf("\t");
        printf("\n\n\n**Menu de opciones**\n\n");
        printf("\n1. Ingresar Kilómetros: ");
        printf("\n2. Ingresar Precio de Vuelos: ");
        printf("\n3. Calcular todos los costos: ");
        printf("\n4. Informar Resultados.");
        printf("\n5. Carga forzada de datos");
        printf("\n6. Salir.");
        printf("\n\nIndique opcion: ");
        //__fpurge(stdin);
        fflush(stdin);
        scanf("%d",&opcion);

        return opcion;
}

void menuUsuario()
{
    float x = 0;
    float y = 0;
    float z = 0;
    char seguir = 's';
    int flagKM = 0;
    int seCalculo = 0;
    int flagPrecioA = 0;
    int flagPrecioL = 0;

    float creditoA;
    float debitoA;
    float bitcoinA;
    float precioKmA;

    float creditoL;
    float debitoL;
    float bitcoinL;
    float precioKmL;


    float difPrecio;


    do{

        switch(menu())
        {
            case 1:





                   z=  get_Float("\nIngrese cantidad de KM: ");
                        printf("\nKilometros CARGADO CON EXITO!!\n");
                        flagKM++;
                    system("pause");//Para que limpie la pantalla


                    break;

            case 2:

            	switch(menuCargarPrecios())
            	{
            	case 1:
            		x =  get_Float("\nIngrese precio del vuelo con Aerolineas: ");
            		flagPrecioA = 1;
            		break;

            	case 2:
            		y =  get_Float("\nIngrese precio del vuelo con Latam: ");
            		flagPrecioL = 1;
            		break;

            	case 3:

            		break;

            	default:
            		printf("Ingrese una opcion valida (entre 1 y 3)\n");
            		system("pause");
            		break;
            	}





            break;

            case 3:
                if(flagPrecioL == 1 && flagPrecioA == 1  && flagKM == 1)
                {



                	creditoA = tarjetaCredito( x);
                	debitoA = tarjetaDebito( x);
                	bitcoinA = bitcoin( x);
                	precioKmA = precioPorKm( x, z);


                	creditoL = tarjetaCredito(y);
                	debitoL = tarjetaDebito(y);
                	bitcoinL = bitcoin(y);
                	precioKmL = precioPorKm(y, z);

                	difPrecio = diferenciaPrecio(x, y);




                    seCalculo = 1;
                 printf("Realizando operaciones..\n");
                 system("pause");
                }
                else
                {
                    printf("\nError. Antes de calcular las operaciones debe ingresar los precios y/o kilometros.\n");
                }


            break;

            case 4:

            	if(seCalculo == 1)
            	{
            		printf("Precio Aerolineas = $ %.2f", x);
            	printf("\n     Precio con tarjeta de Debito: $ %.2f ", debitoA);
            	printf("\n     Precio con tarjeta de Credito: $ %.2f",creditoA );
            	printf("\n     Precio pagando con Bitcoin:  %.8f", bitcoinA);
            	printf("\n     Mostrar precio unitario: $ %.2f", precioKmA);
            	printf("\n-------------------------------------------------\n");
                printf("Precio Latam = %.2f", y);
                printf("\n     Precio con tarjeta de Debito: $ %.2f ",debitoL );
                printf("\n     Precio con tarjeta de Credito: $ %.2f",creditoL );
                printf("\n     Precio pagando con Bitcoin:  %.8f", bitcoinL);
                printf("\n     Mostrar precio unitario: $ %.2f", precioKmL);

                printf("\n     La diferencia de precio es:$ %.2f", difPrecio);

                break;

            	}
            	else {
            		printf("\nPrimero tiene que calcular los costos..");

            		break;
            	}







            case 5:

            		x = 7090;
            		y = 162965;

            		z = 159339;

            		flagPrecioL = 1;
					flagPrecioA = 1;

					printf("Carga forzada en curso..");
					system("pause");



            break;

            default:
                printf("Opcion incorrecta.. Ingrese una opcion correcta\n");
            break;

            case 6:

            	printf("Saliendo de la calculadora.. Adios.\n");
                seguir = 'n';

            	break;
        }


        //system("pause");


    }while(seguir == 's');

}
