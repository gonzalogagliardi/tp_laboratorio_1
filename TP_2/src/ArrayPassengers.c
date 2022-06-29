<<<<<<< HEAD
/*
 * ArrayPassengers.c
 *
 *  Created on: 14 may. 2022
 *      Author: NBGonza
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "getIO.h"
#include "ArrayPassengers.h"

int initPassenger(Passenger* lista, int len)
{
    int retorno = -1;

    if( lista != NULL && len > 0)
    {
        retorno = 0;
        for(int i=0; i < len; i++)
        {
            lista[i].isEmpty = 1;
        }

    }

    return retorno;
}


int menu ()
{

int opcion;

    system("cls");

    printf("*** Menu Pasajero *** \n\n");
    printf("1-Alta Pasajero\n");
    printf("2-Modificar Pasajero\n");
    printf("3-Baja Pasajero\n");
    printf("4-Informes Pasajeros\n");
    printf("5-Salir\n");
    opcion = Get_IntMinMax("\nIngrese una opcion: ","\nError. Ingrese una opcion: ",1,5);


    return opcion;
}


int findFree(Passenger* lista, int len)
{
    int indice = -1;

    if(lista != NULL && len > 0)
    {
     for(int i=0; i < len; i++)
        {
            if(lista[i].isEmpty == 1)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;

}

int findPassengerById(Passenger* lista, int len, int id)
{
    int indice= -1;

     for(int i=0; i < len; i++)
        {
            if(lista[i].id == id && lista[i].isEmpty == 0)
            {
                indice = i;
                break;
            }
        }

    return indice;

}

int addPassenger(Passenger* lista, int len, int id, char name[], char lastName[], float price, int typePassenger, char flyCode[])
{
    int todoOk = -1;
    int indice;

        if(lista != NULL && len > 0 && name != NULL && lastName != NULL && price > 0 && typePassenger > 0 && flyCode != NULL)
        {
            indice = findFree(lista,len);
            lista[indice].id = id;
            lista[indice].price = price;
            lista[indice].isEmpty = 0;
            lista[indice].typePassenger = typePassenger;
            strcpy(lista[indice].name, name);
            strcpy(lista[indice].lastName, lastName);

            strcpy(lista[indice].flyCode, flyCode);
            todoOk = 1; //Ver si por esto da error

        }
        return todoOk;
}



int nuevoPassenger(Passenger* lista, int len, int* id)
{
    int todoOk = -1;
    int indice;
    int auxiliarId;
    Passenger auxiliarEmployee;

        if(lista != NULL && len > 0 )
        {
            indice = findFree(lista,len);
            if(indice != -1)
            {
                printf("    *** Alta Pasajero ***\n");
                printf("-----------------------------\n");
                auxiliarId = *id;
                (*id)++;

                getStringLetras("\nIngrese el nombre: ", auxiliarEmployee.name);
                getStringLetras("\nIngrese el apellido: ", auxiliarEmployee.lastName);
                auxiliarEmployee.price = getFloat("\nIngrese el precio: ");
                auxiliarEmployee.typePassenger = Get_IntMinMax("\nIngrese el tipo de pasajero (1 a 15): ", "\nError. Reingrese el tipo de pasajero: ",0,15);
                 getStringLetras("\nIngrese el codigo de vuelo: ", auxiliarEmployee.flyCode);

                todoOk = addPassenger(lista,len,auxiliarId,auxiliarEmployee.name,auxiliarEmployee.lastName,auxiliarEmployee.price,auxiliarEmployee.typePassenger, auxiliarEmployee.flyCode);

                if(todoOk == -1)
                {
                    printf("Error al cargar pasajero.");
                }
                else
                {
                    printf("pasajero cargado con exito!!\n");
                }
            }
            else
            {
                printf("No hay espacio para cargar pasajero.");
            }
        }


    return todoOk;
}


int removePassenger(Passenger* lista, int len)
{
    int retorno = 0;
    int id;
    int indice;
    char confirma;

        if (lista != NULL && len > 0)
        {
                system("cls");
                printf("     *** Baja Pasajero ***\n");
                printPassengers(lista, len);
                printf("\nIngrese id: ");
                scanf("%d", &id);

                indice = findPassengerById(lista,len,id);
                if(indice == -1)
                {
                    printf("\nEl id: %d no esta registrado.", id);
                }
                else
                {
                       printPassenger(lista[indice]);
                       getStringLetras("\nConfirma la baja? s/n: ", &confirma);

                        if(confirma == 's')
                        {
                            lista[indice].isEmpty = 1;
                            retorno = 1;
                        }
                        else
                        {
                            printf("Baja cancelada por el usuario\n");
                        }

                }
        }



    return retorno;
}

void printPassenger(Passenger lista)
{
    printf("   %d       %-10s           %-10s         $%.2f        %d        %-10s \n", lista.id,lista.name, lista.lastName, lista.price, lista.typePassenger, lista.flyCode);
}




int printPassengerOrder(Passenger lista[],int len, int order)
{
    int retorno = 0;

        if(lista != NULL && len > 0)
        {

            //order = menuOrdenamiento();
           sortPassenger(lista,len,order);

            if(order != -1)
            {
            system("cls");
            printf("                      *** Lista de Pasajeros ***                      \n");
            printf("--------------------------------------------------------------------------\n");
            printf("   ID         Nombre               Apellido          Precio        Tipo de Pasajero  \n");
            printf("--------------------------------------------------------------------------\n");


               for(int i=0; i < len; i++)
                {

                    if(!lista[i].isEmpty)
                    {
                        printPassenger(lista[i]);
                    }

                }

            }
            else{
            informesPrecios(lista,len);
            }

            retorno = 1;
        }

    return retorno;
}






int printPassengers(Passenger lista[],int len)
{
    int retorno = 0;

        if(lista != NULL && len > 0)
        {




            system("cls");
            printf("                      *** Lista de Pasajeros ***                      \n");
            printf("--------------------------------------------------------------------------\n");
            printf("   ID         Nombre               Apellido          Precio        Tipo de Pasajero  \n");
            printf("--------------------------------------------------------------------------\n");


               for(int i=0; i < len; i++)
                {

                    if(!lista[i].isEmpty)
                    {
                        printPassenger(lista[i]);
                    }

                }




            retorno = 1;
        }

    return retorno;
}





//printf("5- Modificar Codigo de Vuelo\n");  Agregar en la Funcion Modificar  -----------------------!!!!!!!!!!!!!!!!!!NO OLVIDAR
int menuModificar(Passenger lista[],int len, int indice)
{
    int opcion = 0;
    system("cls");
    printf("     *** Modificar Pasajero ***\n");
    printf("-----------------------------------\n");
    printf("Para confirmar una modificacion ingrese 's'.\n\n");
    printf("\n Nombre: %s   \n Apellido: %s   \n Precio: $%.2f   \n Tipo de pasajero: %d  \n Codigo de Vuelo: %s\n\n", lista[indice].name, lista[indice].lastName, lista[indice].price, lista[indice].typePassenger, lista[indice].flyCode);
    printf("1- Modificar Nombre\n");
    printf("2- Modificar Apeliido\n");
    printf("3- Modificar Precio\n");
    printf("4- Modificar Tipo de Pasajero\n");
    printf("5- Modificar Codigo de Vuelo\n");
    printf("10- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


int modificarPassenger(Passenger lista[], int len)
{


    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    char seguir = 's';
    char quit;
    Passenger auxPassenger;
    if (lista != NULL && len > 0)
    {
        system("cls");
        printf("   *** Modificar Pasajero *** \n\n");
        printf("----------------------------------\n");
        printPassengers(lista,len);
        printf("Ingrese id del Pasajero a modificar: ");
        scanf("%d", &id);

        indice = findPassengerById(lista, len, id);

        if (indice == -1)
        {
            printf("El id: %d no esta registrado.\n", id);
        }
        else
        {
            do
            {
                switch ( menuModificar(lista, len, indice) )
                {
                case 1:
                    printf("\nModificar nombre: ");
                    fflush(stdin);
                    gets(auxPassenger.name);
                    printf("\nConfirma cambio de nombre?: ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        strcpy(lista[indice].name, auxPassenger.name);
                    }
                    else
                    {
                        printf("Modificacion cancelada\n");
                    }
                    break;
                case 2:
                    printf("\nModificar apellido: ");
                    fflush(stdin);
                    gets(auxPassenger.lastName);
                    printf("\nConfirma cambio de apellido?: ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        strcpy(lista[indice].lastName, auxPassenger.lastName);
                    }
                    else
                    {
                        printf("\nModificacion cancelada\n");
                    }
                    break;
                case 3:
                     printf("Modificar Precio: ");
                    scanf("%f", &auxPassenger.price);
                    printf("\nConfirma cambio de Precio?: ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        lista[indice].price = auxPassenger.price;
                    }
                    else
                    {
                        printf("Modificacion cancelada\n");
                    }
                    break;


                case 4:
                    printf("Modificar Tipo de pasajero: ");
                    scanf("%d", &auxPassenger.typePassenger);
                    printf("\nConfirma cambio de Tipo de pasajero?: ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        lista[indice].typePassenger = auxPassenger.typePassenger;
                    }
                    else
                    {
                        printf("Modificacion cancelada\n");
                    }
                    break;

                case 5:
                    printf("\nModificar Codigo de Vuelo: ");
                    fflush(stdin);
                    gets(auxPassenger.flyCode);
                    printf("\nConfirma cambio de Codigo de Vuelo?: ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        strcpy(lista[indice].flyCode, auxPassenger.flyCode);
                    }
                    else
                    {
                        printf("\nModificacion cancelada\n");
                    }
                    break;

                case 10:
                    printf("\nEsta seguro que quiere salir?: ");
                    fflush(stdin);
                    scanf("%c", &quit);
                    quit = toupper(quit);
                    if (quit == 'S')
                    {
                        seguir = 'n';
                    }
                    else
                    {
                        break;
                    }
                    break;
                default:
                    printf("Opcion invalida\n");
                }

            }
            while(seguir == 's');

            todoOk = 1;

        }
    }
    return todoOk;


}




int sortPassenger(Passenger* lista, int len, int order)
{
    int todoOk = -1;
    Passenger auxPassenger;

        if(lista != NULL && len > 0)
        {

            for(int i=0; i < len ; i++)
            {
                for(int j= i+1; j < len; j++)
                {
                    if(order)//Asc
                    {
                        if(strcmp(lista[i].lastName, lista[j].lastName)>0 || (strcmp(lista[i].lastName, lista[j].lastName) == 0 && lista[i].typePassenger>lista[j].typePassenger))
                        {
                            auxPassenger = lista[i];
                            lista[i] = lista[j];
                            lista[j] = auxPassenger;
                        }
                    }
                    else{//desc

                        if(strcmp(lista[i].lastName,lista[j].lastName)<0 || (strcmp(lista[i].lastName, lista[j].lastName) == 0 && lista[i].typePassenger<lista[j].typePassenger))
                        {
                            auxPassenger = lista[i];
                            lista[i] = lista[j];
                            lista[j] = auxPassenger;
                        }

                    }
                }
            }

            todoOk = 0;
        }










    return todoOk;
}



int menuOrdenamiento()
{
    int retorno;
    int opcion;

     system("cls");
     printf("1_ Ordenar Pasajeros ascendente\n");
     printf("2_ Ordenar Pasajeros descendente\n");
     printf("3_ Mostrar informes de precios.\n");
     opcion = Get_IntMinMax("\nSelecciona una opcion: ","Error. Selecciona una opcion : ",1,3);

     switch(opcion)
     {
     case 1:
        retorno = 0;
        break;

     case 2:
        retorno = 1;
        break;

     case 3:
         retorno = -1;

        break;
     }

     return retorno;
}





int informesPrecios(Passenger lista[], int len)
{
    int retorno = 0;
    float promPrecio;
    float AcumuladorPrecio = 0;
    int contadorPasajeros = 0;
    int contPrecioPromMayor = 0;
    int flag = 1;

            if( lista != NULL && len > 0 )
            {
                for( int i = 0; i< len; i++)
                {
                    if(lista[i].isEmpty == 0)
                    {
                        AcumuladorPrecio += lista[i].price;
                        contadorPasajeros++;
                    }
                }


            if(contadorPasajeros != 0)
            {
                promPrecio = (float) AcumuladorPrecio / contadorPasajeros;
            }

            for(int i=0; i<len; i++)
            {
                if(lista[i].isEmpty == 0&& lista[i].price > promPrecio)
                {
                    contPrecioPromMayor++;
                }
            }
            retorno = 1;
            flag = 0;
            }

            if(flag == 0)
            {
                printf("\n\n*El total de los precios es %.2f\n",AcumuladorPrecio);
                printf("**El promedio de los precios es %2.f\n", promPrecio);
                printf("***La cantidad de pasajeros que superan el precio promedio es %d\n\n", contPrecioPromMayor);
            }
            else{
                printf("No se pudo la informacion.");
            }


    return retorno;
}
=======
/*
 * ArrayPassengers.c
 *
 *  Created on: 14 may. 2022
 *      Author: NBGonza
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "getIO.h"
#include "ArrayPassengers.h"

int initPassenger(Passenger* lista, int len)
{
    int retorno = -1;

    if( lista != NULL && len > 0)
    {
        retorno = 0;
        for(int i=0; i < len; i++)
        {
            lista[i].isEmpty = 1;
        }

    }

    return retorno;
}


int menu ()
{

int opcion;

    system("cls");

    printf("*** Menu Pasajero *** \n\n");
    printf("1-Alta Pasajero\n");
    printf("2-Modificar Pasajero\n");
    printf("3-Baja Pasajero\n");
    printf("4-Informes Pasajeros\n");
    printf("5-Salir\n");
    opcion = Get_IntMinMax("\nIngrese una opcion: ","\nError. Ingrese una opcion: ",1,5);


    return opcion;
}


int findFree(Passenger* lista, int len)
{
    int indice = -1;

    if(lista != NULL && len > 0)
    {
     for(int i=0; i < len; i++)
        {
            if(lista[i].isEmpty == 1)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;

}

int findPassengerById(Passenger* lista, int len, int id)
{
    int indice= -1;

     for(int i=0; i < len; i++)
        {
            if(lista[i].id == id && lista[i].isEmpty == 0)
            {
                indice = i;
                break;
            }
        }

    return indice;

}

int addPassenger(Passenger* lista, int len, int id, char name[], char lastName[], float price, int typePassenger, char flyCode[])
{
    int todoOk = -1;
    int indice;

        if(lista != NULL && len > 0 && name != NULL && lastName != NULL && price > 0 && typePassenger > 0 && flyCode != NULL)
        {
            indice = findFree(lista,len);
            lista[indice].id = id;
            lista[indice].price = price;
            lista[indice].isEmpty = 0;
            lista[indice].typePassenger = typePassenger;
            strcpy(lista[indice].name, name);
            strcpy(lista[indice].lastName, lastName);

            strcpy(lista[indice].flyCode, flyCode);
            todoOk = 1; //Ver si por esto da error

        }
        return todoOk;
}



int nuevoPassenger(Passenger* lista, int len, int* id)
{
    int todoOk = -1;
    int indice;
    int auxiliarId;
    Passenger auxiliarEmployee;

        if(lista != NULL && len > 0 )
        {
            indice = findFree(lista,len);
            if(indice != -1)
            {
                printf("    *** Alta Pasajero ***\n");
                printf("-----------------------------\n");
                auxiliarId = *id;
                (*id)++;

                getStringLetras("\nIngrese el nombre: ", auxiliarEmployee.name);
                getStringLetras("\nIngrese el apellido: ", auxiliarEmployee.lastName);
                auxiliarEmployee.price = getFloat("\nIngrese el precio: ");
                auxiliarEmployee.typePassenger = Get_IntMinMax("\nIngrese el tipo de pasajero (1 a 15): ", "\nError. Reingrese el tipo de pasajero: ",0,15);
                 getStringLetras("\nIngrese el codigo de vuelo: ", auxiliarEmployee.flyCode);

                todoOk = addPassenger(lista,len,auxiliarId,auxiliarEmployee.name,auxiliarEmployee.lastName,auxiliarEmployee.price,auxiliarEmployee.typePassenger, auxiliarEmployee.flyCode);

                if(todoOk == -1)
                {
                    printf("Error al cargar pasajero.");
                }
                else
                {
                    printf("pasajero cargado con exito!!\n");
                }
            }
            else
            {
                printf("No hay espacio para cargar pasajero.");
            }
        }


    return todoOk;
}


int removePassenger(Passenger* lista, int len)
{
    int retorno = 0;
    int id;
    int indice;
    char confirma;

        if (lista != NULL && len > 0)
        {
                system("cls");
                printf("     *** Baja Pasajero ***\n");
                printPassengers(lista, len);
                printf("\nIngrese id: ");
                scanf("%d", &id);

                indice = findPassengerById(lista,len,id);
                if(indice == -1)
                {
                    printf("\nEl id: %d no esta registrado.", id);
                }
                else
                {
                       printPassenger(lista[indice]);
                       getStringLetras("\nConfirma la baja? s/n: ", &confirma);

                        if(confirma == 's')
                        {
                            lista[indice].isEmpty = 1;
                            retorno = 1;
                        }
                        else
                        {
                            printf("Baja cancelada por el usuario\n");
                        }

                }
        }



    return retorno;
}

void printPassenger(Passenger lista)
{
    printf("   %d       %-10s           %-10s         $%.2f        %d        %-10s \n", lista.id,lista.name, lista.lastName, lista.price, lista.typePassenger, lista.flyCode);
}




int printPassengerOrder(Passenger lista[],int len, int order)
{
    int retorno = 0;

        if(lista != NULL && len > 0)
        {

            //order = menuOrdenamiento();
           sortPassenger(lista,len,order);

            if(order != -1)
            {
            system("cls");
            printf("                      *** Lista de Pasajeros ***                      \n");
            printf("--------------------------------------------------------------------------\n");
            printf("   ID         Nombre               Apellido          Precio        Tipo de Pasajero  \n");
            printf("--------------------------------------------------------------------------\n");


               for(int i=0; i < len; i++)
                {

                    if(!lista[i].isEmpty)
                    {
                        printPassenger(lista[i]);
                    }

                }

            }
            else{
            informesPrecios(lista,len);
            }

            retorno = 1;
        }

    return retorno;
}






int printPassengers(Passenger lista[],int len)
{
    int retorno = 0;

        if(lista != NULL && len > 0)
        {




            system("cls");
            printf("                      *** Lista de Pasajeros ***                      \n");
            printf("--------------------------------------------------------------------------\n");
            printf("   ID         Nombre               Apellido          Precio        Tipo de Pasajero  \n");
            printf("--------------------------------------------------------------------------\n");


               for(int i=0; i < len; i++)
                {

                    if(!lista[i].isEmpty)
                    {
                        printPassenger(lista[i]);
                    }

                }




            retorno = 1;
        }

    return retorno;
}





//printf("5- Modificar Codigo de Vuelo\n");  Agregar en la Funcion Modificar  -----------------------!!!!!!!!!!!!!!!!!!NO OLVIDAR
int menuModificar(Passenger lista[],int len, int indice)
{
    int opcion = 0;
    system("cls");
    printf("     *** Modificar Pasajero ***\n");
    printf("-----------------------------------\n");
    printf("Para confirmar una modificacion ingrese 's'.\n\n");
    printf("\n Nombre: %s   \n Apellido: %s   \n Precio: $%.2f   \n Tipo de pasajero: %d  \n Codigo de Vuelo: %s\n\n", lista[indice].name, lista[indice].lastName, lista[indice].price, lista[indice].typePassenger, lista[indice].flyCode);
    printf("1- Modificar Nombre\n");
    printf("2- Modificar Apeliido\n");
    printf("3- Modificar Precio\n");
    printf("4- Modificar Tipo de Pasajero\n");
    printf("5- Modificar Codigo de Vuelo\n");
    printf("10- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


int modificarPassenger(Passenger lista[], int len)
{


    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    char seguir = 's';
    char quit;
    Passenger auxPassenger;
    if (lista != NULL && len > 0)
    {
        system("cls");
        printf("   *** Modificar Pasajero *** \n\n");
        printf("----------------------------------\n");
        printPassengers(lista,len);
        printf("Ingrese id del Pasajero a modificar: ");
        scanf("%d", &id);

        indice = findPassengerById(lista, len, id);

        if (indice == -1)
        {
            printf("El id: %d no esta registrado.\n", id);
        }
        else
        {
            do
            {
                switch ( menuModificar(lista, len, indice) )
                {
                case 1:
                    printf("\nModificar nombre: ");
                    fflush(stdin);
                    gets(auxPassenger.name);
                    printf("\nConfirma cambio de nombre?: ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        strcpy(lista[indice].name, auxPassenger.name);
                    }
                    else
                    {
                        printf("Modificacion cancelada\n");
                    }
                    break;
                case 2:
                    printf("\nModificar apellido: ");
                    fflush(stdin);
                    gets(auxPassenger.lastName);
                    printf("\nConfirma cambio de apellido?: ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        strcpy(lista[indice].lastName, auxPassenger.lastName);
                    }
                    else
                    {
                        printf("\nModificacion cancelada\n");
                    }
                    break;
                case 3:
                     printf("Modificar Precio: ");
                    scanf("%f", &auxPassenger.price);
                    printf("\nConfirma cambio de Precio?: ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        lista[indice].price = auxPassenger.price;
                    }
                    else
                    {
                        printf("Modificacion cancelada\n");
                    }
                    break;


                case 4:
                    printf("Modificar Tipo de pasajero: ");
                    scanf("%d", &auxPassenger.typePassenger);
                    printf("\nConfirma cambio de Tipo de pasajero?: ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        lista[indice].typePassenger = auxPassenger.typePassenger;
                    }
                    else
                    {
                        printf("Modificacion cancelada\n");
                    }
                    break;

                case 5:
                    printf("\nModificar Codigo de Vuelo: ");
                    fflush(stdin);
                    gets(auxPassenger.flyCode);
                    printf("\nConfirma cambio de Codigo de Vuelo?: ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        strcpy(lista[indice].flyCode, auxPassenger.flyCode);
                    }
                    else
                    {
                        printf("\nModificacion cancelada\n");
                    }
                    break;

                case 10:
                    printf("\nEsta seguro que quiere salir?: ");
                    fflush(stdin);
                    scanf("%c", &quit);
                    quit = toupper(quit);
                    if (quit == 'S')
                    {
                        seguir = 'n';
                    }
                    else
                    {
                        break;
                    }
                    break;
                default:
                    printf("Opcion invalida\n");
                }

            }
            while(seguir == 's');

            todoOk = 1;

        }
    }
    return todoOk;


}




int sortPassenger(Passenger* lista, int len, int order)
{
    int todoOk = -1;
    Passenger auxPassenger;

        if(lista != NULL && len > 0)
        {

            for(int i=0; i < len ; i++)
            {
                for(int j= i+1; j < len; j++)
                {
                    if(order)//Asc
                    {
                        if(strcmp(lista[i].lastName, lista[j].lastName)>0 || (strcmp(lista[i].lastName, lista[j].lastName) == 0 && lista[i].typePassenger>lista[j].typePassenger))
                        {
                            auxPassenger = lista[i];
                            lista[i] = lista[j];
                            lista[j] = auxPassenger;
                        }
                    }
                    else{//desc

                        if(strcmp(lista[i].lastName,lista[j].lastName)<0 || (strcmp(lista[i].lastName, lista[j].lastName) == 0 && lista[i].typePassenger<lista[j].typePassenger))
                        {
                            auxPassenger = lista[i];
                            lista[i] = lista[j];
                            lista[j] = auxPassenger;
                        }

                    }
                }
            }

            todoOk = 0;
        }










    return todoOk;
}



int menuOrdenamiento()
{
    int retorno;
    int opcion;

     system("cls");
     printf("1_ Ordenar Pasajeros ascendente\n");
     printf("2_ Ordenar Pasajeros descendente\n");
     printf("3_ Mostrar informes de precios.\n");
     opcion = Get_IntMinMax("\nSelecciona una opcion: ","Error. Selecciona una opcion : ",1,3);

     switch(opcion)
     {
     case 1:
        retorno = 0;
        break;

     case 2:
        retorno = 1;
        break;

     case 3:
         retorno = -1;

        break;
     }

     return retorno;
}





int informesPrecios(Passenger lista[], int len)
{
    int retorno = 0;
    float promPrecio;
    float AcumuladorPrecio = 0;
    int contadorPasajeros = 0;
    int contPrecioPromMayor = 0;
    int flag = 1;

            if( lista != NULL && len > 0 )
            {
                for( int i = 0; i< len; i++)
                {
                    if(lista[i].isEmpty == 0)
                    {
                        AcumuladorPrecio += lista[i].price;
                        contadorPasajeros++;
                    }
                }


            if(contadorPasajeros != 0)
            {
                promPrecio = (float) AcumuladorPrecio / contadorPasajeros;
            }

            for(int i=0; i<len; i++)
            {
                if(lista[i].isEmpty == 0&& lista[i].price > promPrecio)
                {
                    contPrecioPromMayor++;
                }
            }
            retorno = 1;
            flag = 0;
            }

            if(flag == 0)
            {
                printf("\n\n*El total de los precios es %.2f\n",AcumuladorPrecio);
                printf("**El promedio de los precios es %2.f\n", promPrecio);
                printf("***La cantidad de pasajeros que superan el precio promedio es %d\n\n", contPrecioPromMayor);
            }
            else{
                printf("No se pudo la informacion.");
            }


    return retorno;
}
>>>>>>> 9acf80ea7da607509c31569bddd26f1bd7d51ea7
