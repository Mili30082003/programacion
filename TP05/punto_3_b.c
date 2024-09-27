#include <stdio.h>
#include <string.h>
#include <ctype.h>


void concatenar (char nombre[], char apellido[],  char nombreCompleto[]);

int main () {

char Nombre [40];
char Apellido [40];
 char nombreCompleto[100];

printf ("Ingresar su Nombre: ");
scanf ("%s", &Nombre);
printf ("Ingrese su Apellido: ");
scanf ("%s", &Apellido);



concatenar (Nombre, Apellido, nombreCompleto);

printf ("Nombre Completo: %s\n", nombreCompleto);


return 0;
}

void concatenar (char nombre[], char apellido[],  char nombreCompleto[]){

int i = 0 ;

while (nombre [i] != '\0')
{
     nombreCompleto[i] = nombre [i];
     i++;
}



int j = 0;
while (apellido [j] != '\0')
{
   nombreCompleto[i] = apellido [j];  
   i++;
   j++;


}
nombreCompleto[i] = '\0';
}