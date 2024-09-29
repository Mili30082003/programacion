/*diseñar un algoritmo que dada una frase terminada en un punto cuente la cantidad de vocales,
   consonantes y espacios en blanco.
   FUNCION esVocal (letra) caracter <-- booleano 
            SEGUN letra 
                'a'
                'e'
                'i'
                'o'
                'u' RETORNAR TRUE
               
             FIN_SEGUN
   FIN_FUNCION             
                    
   ALGORITMO: 
   ENTRADA: frase: cc con MF '.'
   SALIDA: cantVocales, cantBlancos, CantConsonantes: z+
   A0_INICIALIZAR
        cantVocales <-- 0
        cantBlancos <- 0
        cantConsonantes <- 0
    A1_ Calcular_Frase
        LEER (frase)
            MIENTRAS frase <> MF // CONTAR TODA LA FRASE
                MIENTRAS frase <> MF AND frase <> ' ' // CONTAR PALABRA
                    SI esVocal  ENTONCES
                            cantVocales <- cantVocales + 1;
                     SINO
                            cantConsonantes <-- cantConsonantes + 1 
                         SIN_SI
                       SI frase = ' ' ENTONCES
                            cantBlancos <-- cantBlancos + 1
                        fin_si 

                        LEER (frase)
                    FIN_MIENTRAS
                 SI frase <> MF ENTONCES
                        LEER (frase) 
                  FIN_SI
  A2_ ESCIBIR (cantVocales, cantConsonantes, cantBlancos)
  A3_PARAR                                            
   */

/*

6.Diptongo
    dada una frase terminada en un punto, cuente la cantidad de palabras que contienen diptongos
    Aclaracion: un diptongo se forma cuando se unen dos vocales contiguas en una misma silaba. 
    para el analisis de la vocal use una funcion.
 
 Ejemplo:
    si la frase de entrada es: " El pianista dio un concierto excepcional."
                               " El p(ia)nista d(io) un conc(ie)rto excepc(io)nal."

    las salida es: cantidad de diptongos: 4


    FUNCION VocalAbierta (letra) caracter --> z+
            SEGUN letra 
                    'a' RETORNAR 1
                    'e' RETORNAR 1
                    'o'   RETORNAR 1    
                        SINO 
                                RETORNAR 0
                
                FIN_SEGUN
    FIN_FUNCION        

      FUNCION VocalCerrada (letra) caracter --> z+
            SEGUN letra                  
                    'u' RETORNAR 1
                    'i'   RETORNAR 1    
                        SINO 
                                RETORNAR 0
                
                FIN_SEGUN
    FIN_FUNCION        

ALGORITMO: 
ENTRADA:: frase : cc con MF '.', letra: caracter
SALIDA: cantDiptongo: z+
VAR_AUX: EsAbierta, EsCerrada: z+
A0_ INICIALIZAR
    cantDiptongos <- 0
 A1_Verificar_Diptongos
        LEER (Frase)
            MIENTRAS frase <> MF
                MIENTRAS frase <> MF && frase <> ' ' 
                        lEER (letra)
                   EsAbierta <-- VocalAbierta (letra)   
                   ESCerrada <-- VocalCerrada (letra)      
                        SI  EsABierta AND VocalCerrada ENTONCES
                                    cantDiptongo <-- cantDiptongo + 1
                           FIN_SI
                           LEER (frase)
                  FIN_MIENTRAS
            SI frase <> MF ENTONCES
                LEER (frase)
             FIN_SI
  A2_ ESCRIBIR (cantDiptongo)
  A3_PARAR                                      
*/

#include <stdio.h>

int EsVocalAbierta (char letra);
int EsVocalCerrada (char letra);


int main () {
char frase, letra = ' ';
int VocalAbierta, VocalCerrada;
int CantDiptongos = 0;
printf("Ingresar una frase terminada en un punto: ");
frase = getchar();


    while (frase != '.')
    {
        while (frase != ' ' && frase != '.')
        {
        
          
          if ( frase == EsVocalAbierta(frase) )
          {
frase = getchar();
          
          } if (frase == EsVocalCerrada(frase))
          {
          frase = getchar();
            CantDiptongos++;
          }
          
      frase = getchar();

        }
        if (frase != '.')
        {
            frase = getchar();
        }
        
    }
    printf ("La cantidad de diptongos es: %d", CantDiptongos);
    
    return 0;

}

int EsVocalAbierta (char letra){
if (letra == 'a' || letra =='e'|| letra == 'o')
{
    return 1;
} else {

    return 0;
}


}
int EsVocalCerrada (char letra){
if (letra == 'u' || letra =='i')
{
    return 1;
} else {

    return 0;
}


}
/*.Diseñe un algoritmo que cuente cuantas son las palabras que tinenen mas vocales que consonantes y
  ademas que remplaze a las vocales por #
  
     FUNCION EsVocal(letra) caracter --> z+
            SEGUN letra 
                    'a' RETORNAR 1
                    'e' RETORNAR 1
                    'o'   RETORNAR 1    
                        SINO 
                                RETORNAR 0
                
                FIN_SEGUN
    FIN_FUNCION       

   ALGORITMO: 
   ENTRADA: frase: cc con MF '.', letra: caracter
   SALIDA: palabrasConsonantes: z+, CantPalabras: z+ , cantVocales : z+
   VarAux: EsVocal2: z+
   A0_INCIALIZAR
    palabrasConsonantes  <<-- 0
    CantPalabras <-- 0
    cantVocales <-- 0

   A1_Calcular_Palabras
        LEER (frase)
                MIENTRAS frase <> MF
                    MIENTRAS frase <> MF AND frase <> ' '
                            EsVocal2 <-- EsVocal (letra)
                        SI EsVocal2 ENTONCES
                            cantVocales <- cantVocales + 1
                          SINO
                            cantConsonantes <- cantConsonantes + 1
                            frase <- '#' 
                            FIN_SI    
                    LEER (frase)
                    FIIN_MIENTRAS
              SI (cantVocales < CantConsonantes) ENTONCES
                    cantPalabras<- cantPalabras + 1;    
                FIN_SI      
                SI (frase <> MF) ENTONCES
                    LEER (frase)
                 FIN_SI
            FIN_MIENTRAS
A2_ ESCRIBIR (cantVocales, CantConsonantes, cantPalabras, frase)A3_PARAR                    
              */

             

