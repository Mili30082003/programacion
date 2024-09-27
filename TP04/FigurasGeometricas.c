#include <stdio.h>
#include <math.h>

float AreaCuadrado (float lado);
float PerimetroCuadrado (float lado);
float AreaRectangulo (float altura, float base);
float PerimetroRectangulo (float altura, float base);
float AreaCirculo(float radio);
float PerimetroCirculo (float radio);
float AreaTrianguloEquilatero(float lado);
float PerimetrosTrianguloEquilatero(float lado);


int main () { 

int figura;
float Area;
float Perimetro;
float lado, base, altura, radio;

printf ("Ingresar Figura:\n ");
printf ("\t- 1 : Cuadrado\n");
printf ("\t- 2 : Rectangulo\n");
printf ("\t- 3 : Circulo\n");
printf ("\t- 4 : Triangulo Equilatero\n");
printf ("\t- 5 : Salir del Programa\n");
scanf ("%d", &figura);

do
{
    switch (figura)
    {
    case 1:
            printf ("Ingresar lado: ");
            scanf ("%f", &lado);
            Area = AreaCuadrado (lado);
            Perimetro = PerimetroCuadrado (lado);
            printf ("Area del cuadrado: %.2f\n", Area);
            printf ("Perimetro del Cuadrado: %.2f\n", Perimetro);
        break;
        case 2:
            printf ("Ingresar base y altura: ");
            scanf ("%f %f", &base, &altura);
            Area = AreaCuadrado (lado);
            Perimetro = PerimetroCuadrado (lado);
            printf ("Area del cuadrado: %.2f\n", Area);
            printf ("Perimetro del Cuadrado: %.2f\n", Perimetro);
        break;
        case 3:
            printf ("Ingresar radio: ");
            scanf ("%f", &radio);
            Area = AreaCirculo (radio);
            Perimetro = PerimetroCirculo (radio);
            printf ("Area del cuadrado: %.2f\n", Area);
            printf ("Perimetro del Cuadrado: %.2f\n", Perimetro);
        break;
    default:
        break;
    }
} while (figura != 0);



return 0;
}



float AreaCuadrado (float lado){    
    return lado * lado;
}

float PerimetroCuadrado (float lado){    
    return  4 * lado;
}


float AreaRectangulo (float altura, float base){    
float Area;

    Area = base * altura;

    return Area;
}

float PerimetroRectangulo (float altura, float base){    
float  Perimetro;

    Perimetro = 2 * (base + altura);

    return  Perimetro;
}


float AreaCirculo(float radio) {    
    float Area;

    Area = M_PI * pow(radio, 2);  // Área = π * radio^2

    return Area;
}

float PerimetroCirculo (float radio){    
float  Perimetro;


    Perimetro = 2 * M_PI * radio;

    return Perimetro;
}

float AreaTrianguloEquilatero(float lado) {    
    float Area;

    Area = (sqrt(3) / 4) * pow(lado, 2);  // Fórmula para el área de un triángulo equilátero

    return Area;
}

float PerimetrosTrianguloEquilatero(float lado) {    
    float Perimetro;

    Perimetro = 3 * lado;  

    return Perimetro;
}


