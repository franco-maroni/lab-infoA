

#include <stdio.h>

int main(int argc, const char * argv[]) {

    int num,cont,numCont;
    float media;
    
    cont = 0;
    media = 0;
    numCont = 0;
    
    printf("Inserisci numeri (max 100), per terminare inserisci 0\n");
    do
    {
        printf(">> ");
        scanf("%d",&num);
        if (num!=0)
        {
            if (num%3==0)
                printf("Il numero inserito e' multiplo di 3\n");
        
            if (num%2==0)
            {
                media = media+num;
                cont++;
            }
        }
    }while ((num!=0) && (numCont<100));
    media = media/cont;
    printf("La media dei pari è: %.2f\n",media);
    getchar();
    return 0;
}
