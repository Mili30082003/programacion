
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
        char * p_frase = frase;
        

        int cantConsonantes = 0;
        int * p_contadorConsonantes = &cantConsonantes;
        
        printf("Ingresa una frase: ");
        // 2 - Debo guardar la frase en el Arreglo frase[100]
        gets(p_frase);

        // 3 - Variable puntero para manejar los contadores
        int tama = strlen(p_frase); // tamaño del arreglo
        for (int i = 0; i < tama ; i++)
        {
          // Contar Consonantes
            if (isalpha(*p_frase) && !EsVocal(*p_frase))
            {
               *p_frase = toupper(*p_frase);
                (*p_contadorConsonantes)++;
            }
            p_frase++;
        }
        p_frase = p_frase - tama; // le resto tama veces para volver al principio del arreglo

        printf("Cantidad de consonantes: %d\n", *p_contadorConsonantes);
        printf("Frase Modificada: %s", p_frase);
}