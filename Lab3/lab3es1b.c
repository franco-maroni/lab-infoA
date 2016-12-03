/*
  Scrivere una funzione ricorsiva (in C) che, ricevuti in input due interi, ne restituisca il prodotto.
 */

#include <stdio.h>

int prod(int x, int y);
int main(int argc, const char * argv[]) {
    printf("Inserire due valori interi\n");
    int a, b, res;
    scanf("%d %d", &a, &b);
    res = prod(a, b);
    printf("Il prodotto è %d\n", res);
    return 0;
}

int prod(int x, int y)
{
    if (x>0)
        return y + prod(x-1, y);
    else
        return 0;
}
