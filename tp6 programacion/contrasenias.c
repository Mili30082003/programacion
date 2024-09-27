#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define tama 10

/*Escriba un programa en C que permita al usuario crear una contraseña y verificar si cumple con
los siguientes requisitos:
Debe tener al menos 8 caracteres, contener al menos una letra mayúscula, una letra minúscula y
un número. Además debe ingresar nuevamente la contraseña y corroborar si ambas son iguales.
El programa debe mostrar un mensaje indicando si la contraseña es válida o cuál de los requisitos
no se cumplió. El proceso puede repetirse hasta que se ingrese una contraseña válida.*/

int control(char contra1[]);
int confirmarcion(char contra1[], char contra2[]);

void main()
{
    //--variables--//
    char contra1[tama];
    char contra2[tama];
    

    puts("ingrese la contrasenia: ");
    fflush(stdin);
    gets(contra1);

    int valor= control(contra1);

    while (valor==0)
    {
        puts("la contrasenia no cumple con los requisitos");
        puts("ingrese la contrasenia: ");
        fflush(stdin);
        gets(contra1);
        valor= control(contra1);
    }
    
    if (valor)
    {
        puts("contrasenia valida");
    }

    puts("vuelva a ingresar la contrasenia para confirmar: ");
    fflush(stdin);
    gets(contra2);

    int valor2=confirmarcion(contra1,contra2);

    if (valor2==0)
    {
        puts("contrasenias iguales ");
    }
    else
    {
        puts("las contrasenias no coinciden");
    }

    

}

int control(char contra1[] )
{
    int i=0;
    int control1=0,control2=0,control3=0,control4=0;
    int valor;

    while (contra1[i] != '\0')
    {
       if (isupper(contra1[i]))
       {
            control1=1;
       }
       else
       {
            if (islower(contra1[i]))
            {
                control2=1;
            }
            else
            {
                if (isdigit(contra1[i]))
                {
                    control3=1;
                }
                
            }
        } 
      i++;
       
    }
    
    if (strlen(contra1)>=8)
    {
        control4=1;
    }

    if (control1==1 && control2==1 && control3==1 && control4==1)
    {
        valor=1;
    }
    else
    {
        valor=0;
    }

    return valor;
    
    
}

int confirmarcion(char contra1[], char contra2[])
{
    int control;

    control=strcmp(contra1,contra2);

    return control;
}