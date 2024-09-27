/*Diptongo
    dada una frase terminada en un punto, cuente la cantidad de palabras que contienen diptongos
    Aclaracion: un diptongo se forma cuando se unen dos vocales contiguas en una misma silaba. 
    para el analisis de la vocal use una funcion.
 
 Ejemplo:
    si la frase de entrada es: " El pianista dio un concierto excepcional."
                               " El p(ia)nista d(io) un conc(ie)rto excepc(io)nal."

    las salida es: cantidad de diptongos: 4
    
    
FUNCION vocalCerrada (letra) c --> z+
        isTolower (letra)
    SEGUN letra 
        'i' RETORNA 1
        'u' Retorna 1
     FIN_SEGUN

 FIN_FUNCION

 FUNCION vocalAbierta (letra) c  <-- z+
    IsToLower (letra)
        SEGUN letra
        'a' RETORNA 1
        'e' RETORNA 1
        'o' RETORNA 1
        FIN_SEGUN
 FIN_FUNCION

ALGORITMO: Diptongo
ENTRADA:  frase: cc con MF '.,',letra: c
SALIDA: cantDiptongos: z+
VarAuxiliar: VocalCerrada, VocalAbierta
A0_INICIALIZAR
    cantDiptongos <-- 0
 A1_ Verificar_Diptongos   
        LEER (frase, letra)
            MIENTRAS frase <> MF <-- LEE TODA LA FRASE
                     MIENTRAS (frase <> ' ' AND frase <> MF) <-- LEE UNA PALABRA
                        VocalAbierta <-- vocalAbierta (letra)
                        VocalCerrada <--- vocalCerrada (letra)
                            SI (VocalCerrada(letra) == 1) && (vocalAbierta (letra)) ENTONCES
                                        cantDiptongos <-- cantDiptongos + 1; 
                             FIN_SI
                          LEER (frase)
                        FIN_MIENTRAS
                SI (frase <> MF) ENTONCES
                    LEER (frase)
                FIN_SI
             FIN_MIENTRAS
A2_ ESCRIBIR (cantDiptongos)
A3_PARAR                            
    */

#include <stdio.h>

int vocalAbierta(char letra);
int vocalCerrada(char letra);

int main()
{

    char frase, letra, anterior = ' ';
    int cantDiptongos = 0;
    char MF = '.';

       printf("Ingresar una frase Terminada en un '.': ");
    frase = getchar(); 

    while (frase != MF)
    {
       

      if ((vocalAbierta(anterior) && vocalCerrada(frase)) ||
                (vocalCerrada(anterior) && vocalAbierta(frase))) {
                cantDiptongos++;
            }
        
            anterior = frase;
            frase = getchar();
            
        }

   

    printf("La cantidad de Diptongos es: %d", cantDiptongos);

    return 0;
}

int vocalAbierta(char letra)
{

    switch (letra)
    {
    case 'a':
        return 1;
        break;
    case 'e':
        return 1;
        break;
    case 'o':
        return 1;
        break;
        default:
            return 0;
            break;
    }
}

int vocalCerrada(char letra)
{

    switch (letra)
    {
    case 'i':
        return 1;
        break;
    case 'u':
        return 1;
        break;
     default:
        return 0;
        break;   
    }

}