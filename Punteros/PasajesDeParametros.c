#include <stdio.h>

/*int suma (int a, int b) {
    return a + b;
}

int main () {

    int x = 5, y=3;
    int n = suma (x,y); // Pasaje de Parametros por Valor 



    return 0;
}*/

// Pasaje de parametros por Referencia 

void sumar (int *a) {
    *a = *a + 10; // modifica el valor de la variable original
    printf("Valor dentro de la funcion : %d\n" , *a);
}
//void modificarValor (int *a) {
    //*a = 99;
//}
void SumarValor (int *a) {
    *a = *a + 1;
}


int main () {

    int n = 5;
    sumar(&n); // se pasa la direccion de memoria de n
    printf("Valor fuera de la funcion: %d\n", n);
    //modificarValor(&n);
    //printf("Valor Modificado: %d\n", n);
    SumarValor(&n);
    printf("Valor Nuevo: %d\n", n);
}