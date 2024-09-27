/*b. A partir del nombre completo de una persona (al menos un apellido y dos nombres),
compactar la frase en el mismo arreglo, es decir, eliminar los espacios en blanco. Además,
agregue un punto al final.
Por Ejemplo:
Entrada: “Héctor Eduardo Reglero Montaner\0”
Salida: “HéctorEduardoRegleroMontaner.”*/
#include<stdio.h>
#define tama 50

void main()
{
    char nombre1[tama];
    
    puts("ingrese el nombre completo: ");
    fflush(stdin);
    gets(nombre1);

    int i = 0;
    int j = 0;

    // Compactar la frase eliminando espacios en blanco
    while (nombre1[i] != '\0')
    {
        if (nombre1[i] != ' ')
        {
            nombre1[j++] = nombre1[i];
        }
        i++;
    }

    // Agregar un punto al final
    nombre1[j] = '.';
    nombre1[j + 1] = '\0';
    printf("%s", nombre1);
}