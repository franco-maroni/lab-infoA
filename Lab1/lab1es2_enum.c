/*
 es2.c
 InfoA-16-17
 ESERCIZIO 2 - Area e perimetro
 Scrivere un programma in C che, selezionata una forma geometrica (rettangolo, quadrato, cerchio, triangolo, triangolo equilatero) e forniti in input i dati necessari, ne stampi area e perimetro.
 Il programma all’inizio deve richiedere all’utente di specificare la forma geometrica di interesse, la quale può essere identificata da un intero (ad esempio 1—>quadrato, 2->triangolo rettangolo, ecc.. ).
 Successivamente, in base alla scelta effettuata, deve richiedere uno ad uno i dati necessari (e.g. lato per  quadrato e triangolo equilatero, base e altezza per il triangolo generico, raggio per il cerchio) e fornire in output i valori relativi ad area e perimetro della figura.
 */
#include <stdio.h>
#include <math.h>

int main(void) {
    int scelta;
    typedef enum {
        QUADRATO=1,
        TRIANGOLO_EQUILATERO,
        CERCHIO,
        RETTANGOLO,
        TRIANGOLO_RETTANGOLO
    } Forma;
    float lato, base, altezza, raggio, area, perimetro, rad_3_4, ipotenusa;
    do {
        printf("Selezionare la forma geometrica:\n%d->Quadrato\n%d->Triangolo Equilatero\n%d->Cerchio\n%d->Rettangolo\n%d->Triangolo Rettangolo\n", QUADRATO, TRIANGOLO_EQUILATERO, CERCHIO, RETTANGOLO, TRIANGOLO_RETTANGOLO);
        scanf("%d", &scelta);
    } while (scelta < QUADRATO || scelta > TRIANGOLO_RETTANGOLO);
    
    
    switch (scelta) {
        case QUADRATO: // quadrato
            do {
                printf("Hai scelto il quadrato\nInserire la misura del lato\n");
                scanf("%f", &lato);
            } while (lato < 0);
            area = lato * lato;
            perimetro = 4 * lato;
            break;
        case TRIANGOLO_EQUILATERO: //trangolo equilatero
            do {
                printf("Hai scelto il Triangolo equilatero\nInserire la misura del lato\n");
                scanf("%f", &lato);
            } while (lato < 0);
            rad_3_4 = sqrt(3) / 4 ; // valore che serve per calcolare l'area del triangolo equilatero dato il lato
            area = lato * lato * rad_3_4;
            perimetro = 3 * lato;
            break;
        case CERCHIO: //cerchio
            do {
                printf("Hai scelto il Cerchio\nInserire la misura del raggio\n");
                scanf("%f", &raggio);
            } while (raggio < 0);
            area = (raggio * raggio) * M_PI; // il valore del Pi Greco è definito in math.h come M_PI
            perimetro = 2 * raggio * M_PI;
            break;
        case RETTANGOLO: //rettangolo
            do {
                printf("Hai scelto il rettangolo\nInserire la misura della base\n");
                scanf("%f", &base);
                printf("Inserire la misura dell'altezza\n");
                scanf("%f", &altezza);
            } while (base < 0 || altezza < 0);
            area = base * altezza;
            perimetro = 2 * (base + altezza);
            break;

        case TRIANGOLO_RETTANGOLO: //triangolo rettangolo
            do {
                printf("Hai scelto il Triangolo Rettangolo\nInserire la misura della base\n");
                scanf("%f", &base);
                printf("Inserire la misura dell'altezza\n");
                scanf("%f", &altezza);
            } while (base < 0 || altezza < 0);
            area = base * altezza / 2;
            ipotenusa = sqrt(pow(base, 2) + pow(altezza, 2));
            perimetro = base + altezza + ipotenusa;
            break;
        default: // dato che effettuo il controllo sull'inut nel primo do-while, non dovrei mai ricadere nel caso default
            printf("valore non valido!\n");
            break;
    }
    
    printf("Area: %f\n", area);
    printf("Perimetro: %f\n", perimetro);

    return 0;
}
