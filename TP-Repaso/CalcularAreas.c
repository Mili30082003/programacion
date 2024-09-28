#include <stdio.h>
#define PI 3.14
float CalculoAreaTriangulo (float base, float altura);
float CalculoAreaCirculo (float pi , float radio);
float CalculoAreaRectangulo (float base, float altura);

int main () {
float base, radio, altura;
float AreaTriangulo, AreaCirculo, AreaRectangulo;
int menu;

printf ("Elegir Area: \n");
printf ("\t Area Triangulo\n");
printf ("\t Area Circulo\n");
printf ("\t Area Rectangulo\n");
printf ("\t Salir\n");
scanf ("%d", &menu);
do
{
   switch (menu)
   {
   case 1:
               
                    printf ("\nIngresar base: ");
                    scanf ("%f", &base);       
                    printf ("Ingresar altura: ");
                    scanf ("%f", &altura);
                    AreaTriangulo = CalculoAreaTriangulo(base, altura);
                    printf ("El Area del Triangulo es: %.2f", AreaTriangulo);             
       break;
               
                 
                        
   case 2:
                printf ("\nIngresar radio: ");
                scanf ("%f", &radio);       
                AreaCirculo = CalculoAreaCirculo(PI, radio);
                printf ("El Area del Circulo es: %.2f", AreaCirculo);             
       break;           
   case 3:
                printf ("\nIngresar base: ");
                scanf ("%f", &base);       
                printf ("Ingresar altura: ");
                scanf ("%f", &altura);    
                AreaRectangulo = CalculoAreaRectangulo(base, altura);
                printf ("El Area del Rectangulo es: %.2f", AreaRectangulo);             
       break;      
         case 4:
                printf ("\nsaliendo... ");
                  break;
   default:
            printf ("Opcion Ingresada Incorrecta");
    break;
   }
} while (menu != 4);

return 0;
}

float CalculoAreaTriangulo (float base, float altura){
float Area;

Area = 0.5 * base * altura;

return Area;

}

float CalculoAreaCirculo (float pi , float radio){
float Area;

Area = pi * radio * radio;

return Area;

}

float CalculoAreaRectangulo (float base, float altura){
    float Area;

    Area = base * altura;

    return Area;
}