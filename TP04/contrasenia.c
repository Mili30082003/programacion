
/* 
ALGORITMO: contraseña_validacion
ENTRADA: contraseña: cc,  cantCarcateres: z+
        mayuscula, minuscula, num, caracterEspecial: int
A0_INICIALIZAR
    canCarcteres <-- 0
    mayuscula <-- 0
    minuscula <-- 0
    num <-- 0
    caracterEspecial <-- 0
A1_ LEER (contraseña)
A2_Validar_Contraseña
    MIENTRAS (contraseña <> '.')
        SI (mayuscula = 1) ENTONCES
            contraseña = mayusucula
          FIN_SI
         SI (minuscula = 1) ENTONCES
            contraseña = minuscula
          FIN_SI 
         SI (num = 1) ENTONCES
            contraseña = num
          FIN_SI
          SI (caracterEspecial = 1) ENTONCES
                contraseña = caracterEspecial
            FIN_SI 
         LEER (contraseña)     
       FIN_MIENTRAS
     SI (cantCarcteres >= 8 AND mayuscula AND minuscula AND num AND caracterEspecial) ENTONCES
            ESCRIBIR ("La contraseña es valida")
      SINO 
            ESCRIBIR ("La contraseña no es valida, debe tener al menos: ")
            SI (carcteres  >= 8) ENTONCES  
                    ESCRIBIR ("8 caracteres")
             SINO 
             SI (contraseña <> mayuscula) ENTONCES
                    ESCRIBIR ("debe tener al menos una letra mayuscula")
              SINO
              SI (contraseña <> minuscula) ENTONCES
                    ESCRIBIR ("debe tener al menos una letra mayuscula")
               SINO
                SI (contraseña <> num) ENTONCES
                    ESCRIBIR ("debe tener al menos un numero")
                 SINO
                SI (contraseña <> caracterEspecial) ENTONCES
                    ESCRIBIR ("debe tener al menos un caracter especial")
                   FIN_SI
                    FIN_SI
                    FIN_SI
                    FIN_SI                      
*/

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