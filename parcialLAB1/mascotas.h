#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED



#endif // MASCOTAS_H_INCLUDED

typedef struct{

int id;
char descripcion[20];

}eTipo;

typedef struct{

int id;
char nombreColor[20];

}eColor;


typedef struct{
int id;
int isEmpty;
char nombreMascota[20];
int idTipo;
int idColor;
int edad;

}eMascota;




/** \brief Muestra los tipos de mascota en un listado
 *
 * \param eTipo * tipos: array de tipos de mascota
 * \param int tamTipo: tamanio del array de tipo de mascota
 *
 */

void mostrarTipo(eTipo* tipos,int tamTipo);


/** \brief Muestra los colores de mascota en un listado
 *
 * \param eColor* colore: array de colores
 * \param int tamColor: Tamanio del array de colores
 * \return
 *
 */

void mostrarColor(eColor* colores, int tamColor);


/** \brief
 *
 * \param eMascota mascota: Array de mascotas
 * \param int tam: tamanio del array de mascotas
 * \param int idSiguiente: id necesario para asignarle a la siguiente mascota
 * \param eTipo* tipo : array de tipo
 * \param int tamTipo: tamanio del array de tipos
 * \param eColor* color : array de colores
 * \param int tamColor: tamanio del array de colores
 * \return
 *
 */

int altaMascota(eMascota* mascota,int tam,int idSiguiente, eTipo* tipo,int tamTipo,eColor* color, int tamColor);

/** \brief
 *
 * \param eMascota mascota: Array de mascotas
 * \param int tam: tamanio del array de mascotas
 * \param eTipo* tipo : array de tipo
 * \param int tamTipo: tamanio del array de tipos
 * \param eColor* color : array de colores
 * \param int tamColor: tamanio del array de colores
 * \return
 *
 */


void mostrarMascotas(eMascota* mascotas,int tam, eTipo* tipos, int tamTipos, eColor* colores, int tamColores);



void mostrarMascota(eMascota x,eTipo* tipos, int tamTipos, eColor* colores,int tamColores);
int modMascota(eMascota* mascota, int tam, eTipo* tipos, int tamTipos,eColor* colores, int tamColores);

void inicializarMascotas(eMascota* mascotas,int tam);


int cargarDescripcionTipo(char descripcion[],int id,eTipo* tipos, int tam);

int cargarDescripcionColor(char descripcion[],int id,eColor* color, int tam);
void bajaMascotas(eMascota* mascotas, int tam, eTipo* tipos, int tamTipos, eColor* colores, int tamColores );
