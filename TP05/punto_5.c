/*
ALGORITMO: Adivinar_palabra
ENTRADA: Palabra: cc
SALIDA: Espacio_blanco 
VAR_AUXILIAR: Longitud
CONSTANTE: intentos  = 3

A0_INICIALIZAR
    Espacio_blanco <-- ' -'
A1_LEER (palabra)
A2_ MIENTRAS palabra <> MF
        MIENTRAS palabra <> MF AND palabra <> ' '

    
    */

   #include <stdio.h>
   #include <string.h>

//void ActulizaPalabra (char letra, char PalabraIngresada []);


   int main () {

char PalabraIngresada [] = "programacion";
char palabraModificada [20];
char palabraI [20];
int intentos = 0;
int adivino = 0; //si adivinaa cambia a 1
strcpy(palabraModificada, PalabraIngresada); //

int longitud = strlen (PalabraIngresada);

if (longitud <= 5)
{
        for (int i = 1; i < longitud ; i++)
        {
            palabraModificada[i] = '-';
        }
        
    
} else if (longitud >= 6 && longitud <=8)
{
            for (int i = 1; i < longitud -1; i++) //  ultima palabra 
        {
            palabraModificada[i] = '-';
        }
  
} else if (longitud > 8)
{
         for (int i = 1; i < longitud -1; i++) //  ultima palabra 
        {
            palabraModificada[i] = '-';
        }
  
 
}
 printf ("la plaabra contiene las siguientes letras: ");
  printf ("\n%s", palabraModificada);

do
{
   printf ("\nIngrese la palabra correcta: \n");
   fgets (palabraI, 30, stdin);// lee la palabra ingresada, el tamaño del vector y de donde saco los caracteres de la plaabra ingresada

   int longitudPalabra = strlen (palabraI); 

   palabraI[longitudPalabra - 1] = '\0'; // hago esto para eliminar por defecto '\0'

   int resultado = strcmp (palabraI, PalabraIngresada); // veo si adivino o no la palabra

if (resultado == 0)
{
    adivino = 1;
    printf ("Felicidades, adivinaste la palabra");
    
} else {
    printf ("\nPalabra incorrecta, intentelo nuevamene");
}
intentos++;

} while (intentos < 3 && adivino != 1);
if (adivino == 0)
{
    printf ("\nAgotaste los intentos, fin del juego");
}






    return 0;
   }

