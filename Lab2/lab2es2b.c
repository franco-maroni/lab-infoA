//Gioco dell'impiccato con 5 lettere

#include <stdio.h>

#define FOUND 1
#define NOTFOUND 0

int main(int argc, const char * argv[]) {

    char c1,c2,c3,c4,c5,c6,c;
    char fc1,fc2,fc3,fc4,fc5;
    
    int error,find = 0;
    int risp = NOTFOUND;

    fc1 = '-';
    fc2 = '-';
    fc3 = '-';
    fc4 = '-';
    fc5 = '-';
    
    printf("Inserisci la parola di 5 lettere (lettera + invio): ");
    scanf(" %c",&c1);
    scanf(" %c",&c2);
    scanf(" %c",&c3);
    scanf(" %c",&c4);
    scanf(" %c",&c5);
    
    while ((error <5) && (find<5))
    {
        switch (error)
        {
            case 0:
                printf("  +---+  \n  |   |\n      |\n      |\n      |\n      |\n=========\n");
                break;
            case 1:
                printf("  +---+  \n  |   |\n  0   |\n  |   |\n      |\n      |\n=========\n");
                break;
            case 2:
                printf("  +---+  \n  |   |\n  0   |\n /|   |\n      |\n      |\n=========\n");
                break;
            case 3:
                printf("  +---+  \n  |   |\n  0   |\n /|\\  |\n /    |\n      |\n=========\n");
                break;
            case 4:
                printf("  +---+  \n  |   |\n  0   |\n /|\\  |\n / \\  |\n      |\n=========\n");
                break;
        }
        printf("%c%c%c%c%c\n>> ",fc1,fc2,fc3,fc4,fc5);
        
        scanf(" %c",&c);
        if ((c==c1) && (fc1!=c))
        {
            fc1 = c;
            find++;
            risp = FOUND;
        }
        if ((c==c2) && (fc2!=c))
        {
            fc2 = c;
            find++;
            risp = FOUND;
        }
        if ((c==c3) && (fc3!=c))
        {
            fc3 = c;
            find++;
            risp = FOUND;
        }
        if ((c==c4) && (fc4!=c))
        {
            fc4 = c;
            find++;
            risp = FOUND;
        }
        if ((c==c5) && (fc5!=c))
        {
            fc5 = c;
            find++;
            risp = FOUND;
        }
        if (risp==NOTFOUND)
            error++;
        risp = NOTFOUND;
    }

    
    printf("La parola e %c%c%c%c%c\n>> ",fc1,fc2,fc3,fc4,fc5);
    if (find==5)
        printf("HAI VINTO con %d errori\n",error);
    else
        printf("HAI PERSO\n");
    return 0;
}
