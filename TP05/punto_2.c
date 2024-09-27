/*2. Verificando contrasens
Retomando el tp anterior, escriba un programa en C que permita al usuario crear una contrasen
y verifique si cumple con los siguientes requisitos:
● Debe tener al menos 8 caracteres.
● Debe contener al menos una letra mayúscula.
● Debe contener al menos una letra minúscula.
● Debe incluir al menos un número.
El usuario deberá ingresar la contrasen dos veces para confirmar que ambas coinciden. El
programa debe mostrar un mensaje indicando si la contrasena es válida o especificar cuáles de
los requisitos no se han cumplido. El proceso debe repetirse hasta que se ingrese una contrasena
válida.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>


int EsMayuscula (char contrasena []);
int EsMinuscula (char contrasena []);
int EsDigito (char contrasena []);


int main () {

char contra_1 [8];
char contra_2[8];
int longitud;
int Mayuscula;
int Minuscula;
int Digito;
int ContraseniasIguales;

do
{
   printf ("Ingrese contraseña menor a 8 caracteres: ");
scanf ("%s", contra_1);
printf ("Ingrese de nuevo la contraseña: ");
scanf ("%s", contra_2);


ContraseniasIguales = strcmp (contra_1, contra_2);

if (ContraseniasIguales != 0)
{
    printf ("Las contraseñas no coinciden\n");
    continue;
  /*break;*/
}

longitud = strlen (contra_1);
if (longitud >= 8)
{
    printf ("La contraseña es demasiado larga. \n");
    continue;
}


Mayuscula = EsMayuscula (contra_1);
 Minuscula = EsMinuscula (contra_1);
 Digito = EsDigito (contra_1);

if (!Mayuscula)
{
    printf("La contraseña debe contener al menos una letra mayuscula\n");
}
if (!Minuscula)
{
    printf("La contraseña debe contener al menos una letra minuscula\n");
}
if (!Digito)
{
    printf("La contraseña debe contener al menos un digito\n");
}

} while (!Mayuscula || !Minuscula || !Digito || ContraseniasIguales != 0 ||longitud>= 8);

printf ("Contraseña valida\n");



return 0;
}

int EsMayuscula ( char contrasena [] ) {
    
for (int i = 0; i < strlen(contrasena) ; i++)
{
   if (isupper(contrasena [i]))
   {
            return 1;
 
}

}
return 0;
}

int EsMinuscula ( char contrasena [] ){  

for (int i = 0; i < strlen(contrasena); i++)
{
   if (islower(contrasena [i])  )
{
    return 1;
} 

}
   return 0; 

}
int EsDigito (char contrasena [] ){

for (int i = 0; i < strlen (contrasena); i++)
{
    if (isdigit(contrasena [i])  )
{
    return 1;
}

}
    return 0;

}