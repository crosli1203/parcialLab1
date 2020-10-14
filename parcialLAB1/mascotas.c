#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
#include "validaciones.h"


void mostrarTipo(eTipo* tipos,int tamTipo)
{

    printf("********Tipos de mascotas********\n");

    for(int i = 0; i< tamTipo; i++)
    {
        printf("id: %d.         Descripcion: %s \n",tipos[i].id, tipos[i].descripcion);
    }

}

void mostrarColor(eColor *colores, int tamColor)
{
printf("********Colores********\n");

    for(int i = 0; i< tamColor; i++)
    {
        printf("id: %d.         Descripcion: %s \n",colores[i].id, colores[i].nombreColor);
    }
}




int altaMascota(eMascota* mascota,int tam,int idSiguiente, eTipo* tipo,int tamTipo, eColor* color,int tamColor)
{

    int funciona = 0;
    char nombreMascota[20];
    int auxTipo;
    int auxColor;
    int auxEdad;
    int valorValido;

    system("cls");
    printf("******Alta mascota******\n\n");


//verifico que la siguiente mascota a ingresar no sobrepase los limites del sistema
    if(idSiguiente < tam && mascota[idSiguiente].isEmpty == 1)
    {


        printf("El id de la mascota sera: %d\n\n",idSiguiente);

        printf("ingrese el nombre de la mascota: ");
        myGets(nombreMascota,sizeof(nombreMascota));


        mostrarTipo(tipo,tamTipo);
        do
        {
            valorValido = utn_getNumero(&auxTipo,"Ingrese el tipo de mascota: ","\nError. El valor ingresado no es valido\n",1000,(1000+tamTipo),5);
        }
        while(valorValido < 0);

        mostrarColor(color,tamColor);
        do
        {
            valorValido = utn_getNumero(&auxColor,"Ingrese el color de mascota: ","\nError. El valor ingresado no es valido\n",5000,(5000+tamColor),5);
        }
        while(valorValido < 0);

        do
        {
            valorValido = utn_getNumero(&auxEdad,"Ingrese el edad de mascota: ","\nError. El valor ingresado no es valido\n",0,125,5);
        }
        while(valorValido < 0);


        strcpy(mascota[idSiguiente].nombreMascota, nombreMascota);
        mascota[idSiguiente].idTipo = auxTipo;
        mascota[idSiguiente].idColor = auxColor;
        mascota[idSiguiente].edad = auxEdad;
        mascota[idSiguiente].isEmpty = 0;
        funciona = 1;
    }
    else
    {
        printf("\nSistema completo. No se pueden cargar mas mascotas\n");
    }


    return funciona;
}


/*int mostrarMascotas(eMascota* mascota,int tam, eTipo* tipo,int tamTipo, eColor* color,int tamColor){
   int flag= -1;// indica si se muestran o no mascotas
    printf("\n\n**********Mascotas**********\n\n");
    printf("Id  Nombre      Tipo        Color       Edad ");
    for(int i = 0; i<tam; i++){
        if(mascota[i].isEmpty == 0){
            mostrarMascota(mascota[i],tam,tipo,tamTipo,color,tamColor);
            flag = 1;
        }
    }
    if(flag == -1){
        printf("\nNo hay mascotas que mostrar\n");
    }
return flag;
}
void mostrarMascota(eMascota mascota,int tam, eTipo* tipo,int tamTipo, eColor* color,int tamColor){
    char descripcionTipo[20];
    cargarDescripcionTipo(descripcionTipo,mascota.idTipo,tipo,tamTipo);
    char descripcionColor[20];
    cargarDescripcionColor(descripcionColor,mascota.idColor,color,tamColor);
    printf("%d  %s  %s    %s    %d \n",mascota.id,mascota.nombreMascota, descripcionTipo , descripcionColor, mascota.edad  );
}
*/




void mostrarMascota(eMascota x,eTipo* tipos, int tamTipos, eColor* colores,int tamColores)
{
    char descripcionTipo[20];
    cargarDescripcionTipo(descripcionTipo,x.idTipo,tipos,tamTipos);
    char descripcionColor[20];
    cargarDescripcionColor(descripcionColor,x.idColor,colores,tamColores);

    int id;
int isEmpty;
char nombreMascota[20];
int idTipo;
int idColor;
int edad;

    printf("%d %s      %s      %s      %d\n", x.id, x.nombreMascota, descripcionTipo, descripcionColor, x.edad);

}
void mostrarMascotas(eMascota* mascotas,int tam, eTipo* tipos, int tamTipos, eColor* colores, int tamColores)
{

    int flag = 0;
    printf("\n\n**********Mascotas**********\n\n");
    printf("Id  Nombre      Tipo        Color       Edad \n\n");

    for(int i = 0; i <tam; i++)
    {
        if(mascotas[i].isEmpty == 0)  // si esta lleno
        {
            flag = 1;
            mostrarMascota(mascotas[i], tipos, tamTipos,colores, tamColores);
        }
    }
    if (flag == 0)
    {
        printf("No hay Mascotas que listar\n\n");
    }
}


















void inicializarMascotas(eMascota* mascotas,int tam){

for (int i = 0; i< tam; i++){
    mascotas[i].isEmpty = 1;

}
}

int cargarDescripcionTipo(char descripcion[],int id,eTipo* tipos, int tam){

 int todoOk = 0;

    for( int i = 0; i< tam; i++){
        if(tipos[i].id == id){
         strncpy(descripcion,tipos[i].descripcion, 20);
         todoOk = 1;
        }
    }

    return todoOk;

}
int cargarDescripcionColor(char descripcion[],int id,eColor* color, int tam){

 int todoOk = 0;

    for( int i = 0; i< tam; i++){
        if(color[i].id == id){
         strncpy(descripcion,color[i].nombreColor, 20);
         todoOk = 1;
        }
    }

    return todoOk;

}


void bajaMascotas(eMascota* mascotas, int tam, eTipo* tipos, int tamTipos, eColor* colores, int tamColores ){

    system("cls");
    int idBaja;
    char baja;

    printf("*****Baja Mascota*****\n\n");


    utn_getNumero(&idBaja,"Ingrese el id de la mascota: ","Error. No se encuentra ese id",0,tam,5);


    if(mascotas[idBaja].isEmpty == 0){

        printf("Confirma la baja?('s' para verificar) \n\n");
        mostrarMascota(mascotas[idBaja],tipos, tamTipos,colores, tamColores);
        fflush(stdin);
        myGets(&baja,1);

        if(baja== 's'){
            mascotas[idBaja].isEmpty = 1;
            printf("\n\nSe le dio de baja a la mascota\n\n");
        }else{
            printf("\nSe ha cancelado la operacion\n");
        }

    }else{
        printf("Esa mascota ya fue dada de baja o no existe");
    }

}
