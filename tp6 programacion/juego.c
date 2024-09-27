/*Programar un prototipo para un juego llamado Adivinando la Palabra. El juego funciona así:
● Primero se debe ingresar una palabra. Luego, basándose en la longitud de la palabra
ingresada, el programa muestra guiones incógnitos que representan cada carácter de la
palabra.
● Un usuario tiene que adivinar la palabra ingresando alguna letra.
○ Si la letra está en la palabra, el programa actualiza los guiones incógnitos,
revelando las letras adivinadas.
○ Si el jugador introduce una letra que no está en la palabra, se le resta un intento. El
jugador tiene un límite de 3 intentos.
El juego continúa hasta que el jugador adivine la palabra o agote sus 3 intentos. Si el jugador
adivina la palabra, el programa muestra un mensaje de felicitación. Si el jugador agota sus 3
intentos sin adivinar la palabra, el programa muestra un mensaje de derrota y revela la palabra
correcta.
Ejemplo:
1- Jugador 1: Ingresa palabra: programacion
2- Muestra en pantalla: - - - - - - - - - - - -
3- Jugador 2: Ingresa una letra: a
4- Muestra en pantalla: - - - - - a - a - - - - Intentos: 3
5- Jugador 2: Ingresa una letra: e (No hay letra e en la palabra)
6- Muestra en pantalla: - - - - - a - a - - - - Intentos: 2*/


#include<stdio.h>
#include<string.h>
#define tama 50

void main()
{
    char palabraSecreta[tama];
    char palabraAUX[tama];
    char letra;
    int vidas=3, bandera=0;

    puts("ingrese la palabra: ");
    fflush(stdin);
    gets(palabraSecreta);

    int longitud=strlen(palabraSecreta);
    for (int i = 0; i <longitud ; i++)
    {
       palabraAUX[i]='_';
    }

    for (int i = 0; i <longitud ; i++)
    {
        printf (" %c ",palabraAUX[i]);
    }
    while (vidas>0)
    {
        puts("ingrese la letra: ");
        fflush(stdin);
        scanf("%c",&letra);
        
        for (int i = 0; i < longitud; i++)
        {
            if (letra==palabraSecreta[i])
            {
                palabraAUX[i]=letra;
                bandera=1;
            }   
        }
        if(bandera==0)
        {
            puts("\nla letra no esta en la palabra -1 vida");
            vidas--;
        }
        bandera=0;

        for (int i = 0; i <longitud ; i++)
        {
             printf (" %c ",palabraAUX[i]);
        }

        if (strncmp(palabraSecreta,palabraAUX,longitud)==0)
        {
            printf("felicidades gano! su palabra es:  ");
            puts(palabraSecreta);
            break;
        }
        if (vidas==0)
        {
            printf ("perdio todas sus vidas");
        }
        
        
        
    }
    

}