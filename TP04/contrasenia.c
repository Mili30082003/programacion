#include <stdio.h>
#include <ctype.h>
#include<stdbool.h>

int main () { 

char contra;
int cantCaracteres = 0;
bool mayuscula = false;
bool minuscula = false;
bool numero = false;
bool caracterEspecial = false;

printf ("Ingrese una contraseña con 8 carcateres finalizada en un punto: ");
scanf ("%c", &contra);

    while (contra != '.')
    {
         
          if (isupper(contra))
          {
            mayuscula = true;
          } 
          if (islower(contra))
          {
            minuscula = true; 
          }
        if (isdigit(contra))
        {
            numero = true;
        }
        
        if (!isdigit (contra) && !isalpha(contra))
        {
            caracterEspecial = true;
        }
        
          scanf ("%c", &contra);     
    }

    
if (cantCaracteres >=8 && minuscula && mayuscula &&numero && caracterEspecial)
{
    printf ("La contraseña es valida");
}else {
        printf("La contraseña no es válida. Debe tener al menos:\n");
        if (cantCaracteres < 8) {
            printf("- 8 caracteres\n");
        }
        if (!mayuscula) {
            printf("- Al menos una letra mayúscula\n");
        }
        if (!minuscula) {
            printf("- Al menos una letra minúscula\n");
        }
        if (!numero) {
            printf("- Al menos un número\n");
        }
        if (!caracterEspecial) {
            printf("- Al menos un carácter especial\n");
        }


return 0;
}
}