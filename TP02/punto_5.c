/*ALGORITMO: FigurasGeometricas
ENTRADA: a, b, c ,d: z+
SALIDA: mensaje: cc, perimetro: z+
A1_ LEER ( a, b, c ,d)
A2_ Determinar_figuras
	SI a = b AND a = c AND b = a AND b = c AND c = a AND c = b ENTONCES
		perimetro <-- a + b + c + d
		mensaje <-- "Es un cuadrado"
*/
#include <stdio.h>

int main() {
    int a, b, c, d;
    int perimetro = 0;

    // Entrada de los lados de la figura
    printf("Ingresar 4 numeros enteros (ingrese 0 para el cuarto lado si es un triángulo):\n");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);

    // Caso cuadrado (todos los lados iguales)
    if (a == b && b == c && c == d) {
        printf("Es un cuadrado.\n");
        perimetro = 4 * a;
    }
    // Caso rectángulo (dos lados opuestos iguales)
    else if ((a == c && b == d) || (a == b && c == d)) {
        printf("La figura es un rectángulo.\n");
        perimetro = 2 * (a + b);
    }
    // Caso triángulo (d tiene valor 0)
    else if (d == 0) {
        if (a == b && b == c) {
            printf("La figura es un triángulo equilátero.\n");
            perimetro = 3 * a;
        } else if (a == b || b == c || a == c) {
            printf("La figura es un triángulo isósceles.\n");
            perimetro = a + b + c;
        } else {
            printf("La figura es un triángulo escaleno.\n");
            perimetro = a + b + c;
        }
    }
    // Figura no válida
    else {
        printf("La figura no es válida.\n");
    }

    printf("El perímetro es: %d cm\n", perimetro);

    return 0;
}