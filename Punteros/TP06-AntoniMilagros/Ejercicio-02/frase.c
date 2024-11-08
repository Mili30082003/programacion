
/*  Lea y almacene una línea de texto en minúscula en un arreglo de nombre frase[100]. Cuente las
 consonantes y conviértelas a mayúsculas.
 Use variables punteros para manejar los contadores */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool EsVocal (char letra) 
{
switch (letra)
{
case 'a':
case 'e':
case 'i':
case 'o':
case 'u':
            return true;
default:
        return false;

}

}

void main (){

    // 1 - creo la variable frase 
        char frase [100];
        
        int cantConsonantes = 0;

        printf("Ingresa una frase: ");
        // 2 - Debo guardar la frase en el Arreglo frase[100]
        gets(frase);

        // 3 - Variable puntero para manejar los contadores
        int tama = strlen(frase); // tamaño del arreglo
        for (int i = 0; i < tama ; i++)
        {
          // Contar Consonantes
            if (isalpha(frase[i]) && !EsVocal(frase[i]))
            {
                frase[i] = toupper(frase[i]);
                cantConsonantes++;
            }
            
        }
        printf("Cantidad de consonantes: %d\n", cantConsonantes);
        printf("Frase Modificada: %s", frase);
}