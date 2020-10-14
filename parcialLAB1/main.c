#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
#include "validaciones.h"



typedef struct
{

    int dia;
    int mes;
    int anio;


} eFecha;




typedef struct
{

    int idServicio;
    char descripcion[25];
    int precio;


} eServicio;
typedef struct
{

    int id;
    int idMascota;
    int idServicio;
    eFecha fecha;


} eTrabajo;

#define TAM 5
#define TAMTRABAJOS 20



int menuModMascota();




int menu();


int main()
{
//Hardcode tipos de mascota
    eTipo tipos[] = { {1000,"Ave"}, {1001, "Perro"}, {1002, "Gato"}, { 1003,"Roedor"}, {1004, "Pez"} };
    int tamTipos = 5;

//Hardcode colores
    eColor colores[] = {{5000,"Negro"}, {5001,"Blanco"},{5002, "Gris"},{5003, "Rojo"}, {5004,"Azul"}};
    int tamColores = 5;

//Hardcode servicios

    eServicio servicios[] = {{20000,"Corte", 250}, {20001,"Desparasitado", 300}, {20002,"Castrado",400}};
    int tamServicios = 3;

    eMascota mascota[TAM];
    eTrabajo trabajos[TAMTRABAJOS];


    int opcion;
    int continuar = 1;
    int idSiguiente = 0;
    inicializarMascotas(mascota, TAM);

    do
    {
        opcion = menu();

        switch(opcion)
        {
        case 1:
            if(altaMascota(mascota,TAM,idSiguiente,tipos,tamTipos,colores,tamColores))
            {
                printf("\nMascota dada de alta\n");
                idSiguiente++;
            }
            else
            {
                printf("\nHa ocurrido un error al intentar cargar la mascota\n");
            }
            break;
        case 2:

            if(idSiguiente > 0)
            {
            modMascota(mascota,TAM,tipos,tamTipos,colores,tamColores);
            }
            else
            {
                printf("\nNo hay mascotas ingresadas en el sistema\n");
            }

            break;
        case 3:
            bajaMascotas(mascota,TAM,tipos,tamTipos,colores,tamColores);

            break;
        case 4:
            mostrarMascotas(mascota,TAM,tipos,tamTipos,colores,tamColores);
            break;
        case 5:
            mostrarTipo(tipos, tamTipos);
            break;
        case 6:
            mostrarColor(colores,tamColores);
            break;
        case 7:

            break;
        case 8:

            break;
        case 9:

            break;
        case 10:
            continuar = 0;
            break;
        default:
            printf("\nHa ocurrido un error, vuelva a intentarlo\n");
            break;
        }
        system("pause");


    }
    while(continuar);






    return 0;
}

int menu()
{
    system("cls");
    int opcion = -1;
    printf("\n\n********  Menu de Opciones  ********\n\n\n");
    printf("1) Alta mascota \n");
    printf("2) Modificar mascota \n");
    printf("3) Baja mascota \n");
    printf("4) Listar mascotas \n");
    printf("5) Listar tipos \n");
    printf("6) Listar colores \n");
    printf("7) Listar servicios \n");
    printf("8) Alta trabajo \n");
    printf("9) Listar trabajos \n");
    printf("10)Salir \n");

    utn_getNumero(&opcion,"\n\n Ingrese una opcion del Menu: ","Error. Vuelva a intentarlo",1,10,5);

    return opcion;
}



int modMascota(eMascota* mascota, int tam, eTipo* tipos, int tamTipos,eColor* colores, int tamColores){

    int retorno = -1;
    int idBuscado;
    int opcion;
    int valorValido;
    int auxTipo;
    int auxColores;

    system("cls");
    printf("********* Modificar mascota *********");

    mostrarMascotas(mascota,tam,tipos,tamTipos,colores,tamColores);
    utn_getNumero(&idBuscado,"Ingrese el id de la mascota a modificar: ","\nError. Mascota no encontrada\n",0,tam,5);

    if(mascota[idBuscado].isEmpty== 0){

        opcion = menuModMascota();
        switch(opcion){
    case 1:
        mostrarTipo(tipos,tamTipos);
        mostrarTipo(tipos,tamTipos);
        do
        {
            valorValido = utn_getNumero(&auxTipo,"Ingrese el tipo de mascota: ","\nError. El valor ingresado no es valido\n",1000,(1000+tamTipos),5);
        }
        while(valorValido < 0);



        retorno = 0;
        break;
    case 2:
        mostrarColor(colores,tamColores);
        do
        {
            valorValido = utn_getNumero(&auxColores,"Ingrese el color de mascota: ","\nError. El valor ingresado no es valido \n",5000,(5000+tamColores),5);
        }
        while(valorValido < 0);
        mostrarColor(colores,tamColores);

        retorno = 0;
        break;
    default:
        printf("\nEl valor ingresado es invalido\n");
        retorno = -1;
        break;
        }


    }else{
        printf("\nError. La mascota buscada esta dada de baja o nunca existio\n");
        retorno = -1;
    }



    return retorno;
}

int menuModMascota(){
    int opcion = -1;
    int auxIngreso;
    system("cls");
    printf("********* Modificar mascota *********\n\n");
    printf("1.Modificar tipo\n");
    printf("2.Modificar edad\n");

    do{
       auxIngreso = utn_getNumero(&opcion,"Ingrese un numero valido ","Error. Se ha ingresado un numero invalido ",1,2,5);
    }while(auxIngreso == -1);

    return opcion;
}
