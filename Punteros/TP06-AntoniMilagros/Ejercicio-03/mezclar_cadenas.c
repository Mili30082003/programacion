/* Lea dos cadenas de caracteres alfabéticos y un número. La tarea consiste en insertar la segunda
 cadena en la primera, a partir del carácter que está en la posición indicada por el número. Muestre
 la primera cadena modificada.
 Use el siguiente prototipo, considerando una cadena auxiliar para formar la mezcla de salida:
 void mezclarCadenas(char *cad1, char *cad2, int pos);
 Nota: Realizar los controles que sean necesarios, realice una reserva de memoria para las cadenas
 de entrada con un tamaño por defecto y ajuste una vez leídas. No use la función concatenar de la
 biblioteca string.h
 Sugerencia: Si para resolver el ejercicio usó un arreglo auxiliar de apoyo, intente llevar a
 cabo la tarea de mezcla sin el uso del mismo. Implemente mediante otra función.
 Ejemplo:
 Cadena 1: “Primavera”- Cadena 2: “Florecer”- Número: 4
 Cadena 1 de Salida: PriFlorecermavera*/

 #include <stdio.h>
 #include <string.h>

void mezclarCadenas(char *cadena1, char *cadena2, char *resultado, int tama){

    // Recorro la primera cadena
    tama = strlen(cadena1);
    for (int i = 0; i < tama; i++)
    {
        *resultado = *cadena1;
        cadena1++;
        resultado++;
    }
    

}

 void main () {
    char cadena1[50], cadena2[50], resultado[100];
    
    printf("Ingrese la primera cadena: ");
    gets(cadena1);

    printf("Ingrese la segunda cadena: ");
    gets(cadena2);




 }