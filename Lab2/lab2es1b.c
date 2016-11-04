//Disegno di quadrati

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n;
    char c;
    
    //Utilizzo cicli while annidati
    //Definisco per tale ragione due contatori, uno per le linee e uno per le colonne.
    int contCol,contRows,contPlus;
    
    printf("Inserire la dimensione del quadrato da disegnare: ");
    scanf("%d",&n);
    
    printf("Scegli che quadrato disegnare (f,v,h,p)");
    scanf(" %c",&c);
    
    
    contRows = 0;
    contPlus = 0;
    do{
        contCol=0;
        do{
            if (contRows == 0)
            {
                switch(c)
                {
                    case 'f':
                    case 'v':
                        printf("*");
                        break;
                    case 'h':
                        if (contCol==0)
                            printf("*");
                        break;
                    case 'p':
                        if (contCol==0)
                            printf("*");
                        else if(contCol>=1)
                            printf("+");
                        break;
                }
            }
            else if ((contRows>0) && (contRows<n-1))
            {
                switch(c)
                {
                    case 'f':
                            printf("*");
                        break;
                    case 'v':
                        if (contCol==0)
                            printf("*");
                        else if(contCol==n-1)
                            printf("*");
                        else
                            printf(" ");
                        break;
                    case 'h':
                        if (contPlus<=contRows)
                            printf("*");
                        contPlus++;
                        break;
                    case 'p':
                        if (contPlus<=contRows)
                            printf("*");
                        else
                            printf("+");
                        contPlus++;
                        break;
                }
            }
            else
            {
                switch(c)
                {
                    case 'f':
                    case 'v':
                    case 'h':
                    case 'p':
                        printf("*");
                        break;
                }
            }
            if(contCol==n-1)
                printf("\n");
            contCol++;
            
        }while (contCol<n);
        contRows++;
        contPlus = 0;
    }while (contRows<n);
    return 0;
}
