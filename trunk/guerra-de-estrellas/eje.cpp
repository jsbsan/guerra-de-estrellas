/*
* Basado en el ejemplo de:  Javier Abellán. 26 de Marzo de 2003
*
* Programa de demo de la función popen()
* http://www.chuidiang.com/clinux/funciones/funciones.php#popen
*/
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(int argc, const char* argv[])
{
  /* Fichero con el que abriremos */
  FILE *fichero=NULL;
  
  /* Variable auxiliar para leer el fichero */
  char aux[1000];
  
  
  // escribo argumentos

  for( int i = 0; i < argc; i++ )
  {
    printf( "arg %d: %s\n", i, argv[i] );
  }
  
  
  /* Se abre el fichero lftp, pasándole el parámetro  y se comprueba
  * que se ha podido abrir correctamente */
  // lftp -u nombre,clave direccionftp
  fichero = popen ("lftp -u USUARIO,CLAVE FTP","w");
  

  if (fichero == NULL)
  {
    perror ("No se puede abrir /bin/lftps");
    return -1;
  }
  

  
  //subo el archivo que me pasan...
    strcpy(aux,"mput ");
  
    strcat(aux, argv[1] );
    strcat(aux,"\n");
  
    cout << "\n";
    cout << aux <<"\n";
    cout << "\n";
    fprintf(fichero,aux);
  
 
  
  // termino el programa
  fprintf(fichero,"quit\n");

  /* Se cierra el fichero */
  pclose (fichero);
}
