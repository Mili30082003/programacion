/*a. Dado el nombre y el apellido de una persona, por separado, unirlos en una única cadena
de manera que quede de la forma: “Apellido, Nombre”. No use la función strcat().


*/

#include<stdio.h>
#define tama 50



int main()
{
    //---variables---//

    char nombre1[tama];
    char nombre2[tama];
    char apellido[tama];
    char auxiliar[tama];
    int i=0,j=0,k=0;

    puts("ingrese el primer nombre: ");
    fflush(stdin);
    gets(nombre1);

    puts("ingrese el apellido: ");
    fflush(stdin);
    gets(apellido);


    while (apellido[k]!='\0')
    {
        auxiliar[k]=apellido[k];
        k++;
    }
    
    auxiliar[k]=',';
    k++;
    auxiliar[k]=' ';
    k++;
    
    while (nombre1[i]!='\0')
    {
        auxiliar[k]=nombre1[i];
        i++;
        k++;
    }
    
    return 0;
}