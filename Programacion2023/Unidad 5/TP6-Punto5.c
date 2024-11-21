// ********       EJERCICIO 5    ***********

#include <stdio.h>
#include <string.h>
#define longitud 50

void cargararreglos(char palabra[],char aux[]);  //inicializa arreglos
int controlaLetra(char palabra[],char aux[], char letra); //controla que la letra este en la palabra

int main(void){
    char palabra[longitud];
    char auxiliar[longitud];
    char letra;
    int intentos=3, control;
 
    cargararreglos(palabra,auxiliar);  //inicializamos el arreglo palabra con la palabra a adivinar y auxiliar con guines
    
    do{
        printf("Adivina la palabra: %s\n", auxiliar);  //muestra el arreglo con guiones
        printf("Intentos(%d) - Ingrese una letra:  \n",intentos); //muestra cantidad de intentos
        fflush(stdin);
        scanf("%c",&letra);  
        
        control=controlaLetra(palabra,auxiliar,letra);  //returna 1 si la letra exite, 0 si no 

        //si no cambia la cantidad de guiones es porque no adivinó una letra y se quita un intento.
        if(control==0)
            intentos=intentos-1; // disminuye un intento si no econtró la letra
 
    }while((strncmp(auxiliar,palabra,strlen(palabra))!=0) && intentos>0); //repite hasta agotar intentos o los arreglos de palabra y auxiliar sean iguales (encontró la palabra)
    
    if(strncmp(auxiliar,palabra,strlen(palabra))==0)
        printf("Ganaste! Palabra: %s - Intentos(%d) \n",palabra,intentos);
    else
        printf("Perdiste! Palabra: %s - Intentos(%d)  \n ",palabra,intentos);
 
    return 0;    
}



void cargararreglos(char palabra[],char aux[]){
    puts("Ingrese la palabra:");
    fflush(stdin);
    gets(palabra);     //Guardamos en el arreglo "palabra" la palabra que hay que adivinar.
    
    for (int i = 0; i < strlen(palabra); i++){
        aux[i]='-';    //en el arreglo auxiliar inicializamos con guiones segun la cantidad de letras de la palabra
    }
    
}


int controlaLetra(char palabra[],char aux[], char letra){
    int existe=0;
    for (int i = 0; i < strlen(palabra); i++){
                //si la letra esta en el arreglo de la palabra a buscar, en el arreglo auxiliar de guiones se reemplaza por la letra
                if(palabra[i]==letra){
                    aux[i]=letra;
                    existe=1;  //si la letra existe cambia a 1
                }
            }
    return existe;
}