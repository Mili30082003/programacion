/*
Diseñe un algoritmo que cuente cuantas son las palabras que tinenen mas vocales que consonantes y
  ademas que remplaze a las vocales por #
*/
/*
FUNCION esVocal (letra): caracter <-- bool
        SEGUN letra
              'a'
              'e'
              'i'
              'o' RETORNA: true
              'u'
          SINO
                RETORNA: false
          FIN_SEGUN
FIN_FUNCION


ALGORITMO: Palabras_Vocales_consonantes
ENTRADA:frase: cc con MF '.'
SALIDA: cant_palabras:z+    
        frase_modificada: cc
VAR_AUXILIAR: cantidadVocal, cantidadConsonantes: z+

A0_INICIALIZAR
    cant_palabras <-- 0 
    cantVocal <-- 0
    cantidadConsonantes <-- 0

A1_modificar_clacular_frase
      LEER (frase)
          MIENTRAS (frase <> MF) <-- FRASE COMPLETA
              MIENTRAS (frase <> ' ' AND frase <> MF) <--ANALIZA UNA PALABRA
                    SI (esVocal (frase)) ENTONCES
                        cantidadVocal ++;
                      SINO
                          cantidadConsonantes++;
                          frase <-- # <-- cambio vocales por '#'
                    FIN_SI
                    ESCRIBIR (frase) <-- se ira imprimiendo el numero 
                    LEER (frase)
               fin_mientras

                SI (cantidadVocal > cantidadConsonantes) ENTONCES  <-- ANALIZO LA CANTIDAD DE PALABRAS
                    cantidadPlabras++;
                  FIN_SI
                    cantidadVocal <-- 0
                    cantidadConsonantes <-- 0

                    SI (frase <> MF ) ENTONCES <-- HAGO ESTE CONTROL PARA LEER LA MF
                        LEER (frase) <-- LEO LA SIGUIENTE PALABRA    
                    FIN_SI
           FIN_MIENTRAS    
A2_ ESCRIBIR (cantidadVocales, cantidadConsonantes, cantidadPlabras)
A3_PARAR           

*/