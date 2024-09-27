#include <stdio.h>
#define tama 50

void main()
{
    //--varaibles--//
    char frase[tama];
    char aux=' ';
    int CantBlancos=0, i, CantPalabras=0;
    char letra;

    puts("ingrese una frase: ");
    fflush(stdin);
    gets(frase);

    puts("\ningrese la letra inicial de la palabra: ");
    fflush(stdin);
    scanf("%c",&letra);


    while (frase[i] != '\0') // auto corre
    {
        if (aux==' ' && frase[i]==letra)
        {
            CantPalabras++;
            aux=frase[i];
        }
        else
        {
            if (frase[i]==' ')
            {
                CantBlancos++;
                aux=frase[i];
            }
            else
            {
                aux=frase[i];
            }      
            
        }
        
       i++; 
    }

    printf("\nla cantidad de espacios en blancos es: [ %d ]", CantBlancos);
    printf("\nla cantidad de palabras comenzadas con la letra [%c] es: [ %d ]", letra, CantPalabras);

    

}