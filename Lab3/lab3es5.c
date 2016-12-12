/*
 ESERCIZIO 5
 Scrivere una funzione ricorsiva in C (e un main che la esegua) la quale, avendo in input due interi positivi, ne restituisca in output il massimo comune divisore.
 */

#include <stdio.h>

int mcd1(int x, int y);
int mcd2(int x, int y);
int main(int argc, const char * argv[]) {
    int n1, n2;
    printf("Inserire due numeri interi positivi: \n");
    scanf("%d %d", &n1, &n2);
    printf("M.C.D. di %d e %d è:  %d.\n", n1, n2, mcd2(n1,n2));
    return 0;
}

/* Versione vista a lezione */
int mcd1(int x, int y) {
    if (y==x)
        return x;
    else if (y > x)
        return mcd1(x,y-x);
    else
        return mcd1(x-y,x);
}

/* Versione  più concisa con operatore '%' */
int mcd2(int x, int y)
{
    if (y != 0){
        printf("\n%d %% %d = %d\n", x, y, x%y);
        return mcd2(y, x%y);
    }
    else
        return x;
}
