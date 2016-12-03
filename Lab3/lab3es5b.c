/*
 ESERCIZIO 5
 Scrivere una funzione ricorsiva in C (e un main che la esegua) la quale, avendo in input due interi positivi, ne restituisca in output il massimo comune divisore.
 */

#include <stdio.h>

int mcd(int x, int y);
int main(int argc, const char * argv[]) {
    int n1, n2;
    printf("Inserire due numeri interi positivi: \n");
    scanf("%d %d", &n1, &n2);
    printf("M.C.D. di %d e %d è:  %d.\n", n1, n2, mcd(n1,n2));
    return 0;
}


int mcd(int x, int y) {
    if (y==x) return x;
    else if (y > x) return mcd(x,y-x);
    else return mcd(x-y,x);
}
