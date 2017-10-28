/*
Lab 2 Es1.
Scrivere un programma che legga un numero N ed un carattere C.
Disegnare per mezzi di * e + il quadrato di lato N come riportato in seguito (caso N=5).
C == 'f'
 *****
 *****
 *****
 *****
 *****
 
C == 'v'
 *****
 *   *
 *   *
 *   *
 *****
 
C == 'p'
 *++++
 **+++
 ***++
 ****+
 *****
 
C == 'h'
 *
 **
 ***
 ****
 *****
 
*/
#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n;
    char c;
    
    //Utilizzo cicli while annidati
    //Definisco per tale ragione due contatori, uno per le linee e uno per le colonne.
    
    printf("Inserire la dimensione del quadrato da disegnare: ");
    scanf("%d%*c",&n);
    printf("Scegli che quadrato disegnare (f,v,p, h)");
    scanf("%c",&c);
    
    
    int riga;
    int colonna;

    switch (c) {
        case 'f':
            for (riga = 0; riga < n; riga++) {
                for (colonna = 0; colonna < n; colonna++) {
                    printf("*");
                    if (colonna == n-1) {
                        printf("\n");
                    }
                }
                
                }
            break;
        case 'v':
            for (riga = 0; riga < n; riga++) {
                for (colonna = 0; colonna < n; colonna++) {
                    if (riga == 0 || riga == n-1 || colonna == 0 || colonna == n-1) {
                        printf("*");
                    }
                    else {
                        printf(" ");
                    }
                    if (colonna == n-1) {
                        printf("\n");
                    }
                }
            }
            break;

        case 'p':
            for (riga = 0; riga < n; riga++) {
                for (colonna = 0; colonna < n; colonna++) {
                    if (riga >= colonna) {
                        printf("*");
                    }else{
                        printf("+");
                    }
                    if (colonna == n-1) {
                        printf("\n");
                    }
                }
            }
            break;

        case 'h':
            for (riga = 0; riga < n; riga++) {
                for (colonna = 0; colonna < n; colonna++) {
                    if (riga >= colonna) {
                        printf("*");
                    }
                }
                printf("\n");
            }
            break;
    
            
        default:
            break;
    }
    
    return 0;
}
