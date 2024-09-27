/*
4. Cadena de caracteres 
    i.  dada una oracion terminada en un punto, escriba un algoritmo que cuente la cantidad total de vocales
        (a, e, i, o ,u) y la cantidad por cada una de ellas.
    ii. dada una oracion terminada en un punto, escriba un algoritmo que calcule la cantidad de palabras
        que tienen al menos 3 vocales diferentes. Ademas, devolver la frase ingresada sustuyendo los espacios
        en blanco por * .

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
VAR_AUXILIAR: vocal_a, vocal_e, vocal_i, vocal_o, vocal_u: bool
                cantVocalDiferente: 

A0_INICIALIZAR
                               cantPlabras <-- 0 
                             'a':vocal_a <-- FALSE
                            'e':vocal_e <-- FALSE
                            'i':vocal_i <-- FALSE
                            'o':vocal_o <-- FALSE
                            'u':vocal_u <-- FALSE                       

A1_modificar_clacular_frase
      LEER (frase)
          MIENTRAS (frase <> MF) <-- FRASE COMPLETA
              MIENTRAS (frase <> ' ' AND frase <> MF) 
                        SEGUN frase
                            'a':vocal_a <-- TRUE
                            'e':vocal_e <-- TRUE
                            'i':vocal_i <-- TRUE
                            'o':vocal_o <-- TRUE
                            'u':vocal_u <-- TRUE
                          FIN_SEGUN

                    ESCRIBIR (frase)
                    LEER (frase)
               fin_mientras

                        SI (vocal_a) ENTONCES <-- SI LA VOCAL ESTA EN TRUE
                                cantVocalDiferente ++;
                         FIN_SI
                           SI (vocal_e) ENTONCES
                                cantVocalDiferente ++;
                         FIN_SI
                           SI (vocal_i) ENTONCES
                                cantVocalDiferente ++;
                         FIN_SI
                           SI (vocal_o) ENTONCES
                                cantVocalDiferente ++;
                         FIN_SI
                           SI (vocal_u) ENTONCES
                                cantVocalDiferente ++;
                         FIN_SI

                        SI (cantVocalDiferente > 3) ENTONCES
                                CanPalabras++;
                         FIN_SI       


                        'a':vocal_a <-- FALSE
                            'e':vocal_e <-- FALSE
                            'i':vocal_i <-- FALSE
                            'o':vocal_o <-- FALSE
                            'u':vocal_u <-- FALSE    

                    SI (frase = ' ') ENTONCES
                           ESCRIBIR (*)
                    FIN_SI
                    
                    SI (frase  <> MF) ENTONCES
                     
                        LEER (frase) <-- LEO LA SIGUIENTE PALABRA    
                    FIN_SI
           FIN_MIENTRAS    
A2_ ESCRIBIR (cantidadvocalDiferente)
A3_PARAR     


*/