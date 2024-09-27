#include <stdio.h>

int main()
{
    //--variables--//
    int  kilometros;

    float agua, carbon;

    printf("Ingrese la cantidad de kilometros que recorrera el tren: ");
    fflush(stdin);
    scanf("%d", &kilometros);


    printf("\nIngrese la cantidad de agua que tendra el tren: ");
    fflush(stdin);
    scanf("%f", &agua);

    printf("\nIngrese la cantidad de carbon que tendra el tren: ");
    fflush(stdin);
    scanf("%f", &carbon);

    while (agua>0 && carbon>0 && kilometros>0)
    {
        
        kilometros= kilometros-1;   
                                                    
        agua= agua-0.33;        

        carbon= carbon-0.2;
         
    }

    if (agua<=0)
    {
        puts(" !! El tren se quedo sin agua !! ");
        printf("\nLa cantidad de carbon restante es {%2.f}",carbon);
        printf("\nLa cantidad kilometros que faltan por recorrer {%d}",kilometros);

    }
    else
    {
        if (carbon<=0)
        {
            puts(" !! El tren se quedo sin carbon !! ");
            printf("\nLa cantidad de agua restante es {%2.f }",agua);
            printf("\nLa cantidad kilometros que faltan por recorrer {%d}",kilometros);
        }
        else
        {
            puts(" \n!! El tren llego a destino !! ");
            printf("\nLa cantidad de agua restante es { %.2f }",agua);
            printf("\nLa cantidad de carbon restante es { %.2f }",carbon);

        }
        
        
        
    }
    
    
    



    return 0;
}