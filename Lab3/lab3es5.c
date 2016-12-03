/*
 ESERCIZIO 5
 Scrivere una funzione ricorsiva in C (e un main che la esegua) la quale, avendo in input due interi positivi, ne restituisca in output il massimo comune divisore.
 */

#include <stdio.h>
int mcd(int n1, int n2);
int main()
{
    int n1, n2;
    printf("Inserire due numeri interi positivi: \n");
    scanf("%d %d", &n1, &n2);
    printf("M.C.D. di %d e %d è:  %d.\n", n1, n2, mcd(n1,n2));
    return 0;
}

int mcd(int n1, int n2)
{
    if (n2 != 0){
        printf("\n%d # %d = %d\n", n1, n2, n1%n2);
        return mcd(n2, n1%n2);
    }
    else
        return n1;
}
