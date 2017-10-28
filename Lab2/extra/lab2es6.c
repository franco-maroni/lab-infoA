#include <stdio.h>
#include <stdlib.h>

int win(char matrix[6][7],int x,int y);
void stampa(char matrix[6][7]);
void inserisci(char matrix[6][7],int c,int giocatore,char ch);

int main()
{
    char matrix[6][7];
    int notfull=0;
    int giocatore1, giocatore2;
    int i,j;
    int colonne[7];
    int w;
    int k=-1;
    
    //inizializza la griglia con tutti spazi vuoti
    
    for (i=0;i<6;i++){
        for (j=0;j<7;j++){
            matrix[i][j]=' ';
        }
    }
    for (int i=0; i<7; i++)
        colonne[i] = -1;
    
    stampa(matrix);
    
    while (notfull == 0){
        
        do{
            w=0;
            printf("Giocatore 1: ");
            scanf("%d",&giocatore1);
            
            if (giocatore1<=6)
            {
                if (colonne[giocatore1] == 5)
                {
                    printf("Mossa non valida\n");
                    w=1;
                }
                else
                {
                    colonne[giocatore1]++;
                    k=colonne[giocatore1];
                    inserisci(matrix,colonne[giocatore1],giocatore1,'o');
                    stampa(matrix);
                    w=0;
                }
            }
            else
            {
                printf("Input errato\n");
                w=1;
            }
        }while(w!=0);
        
        //controlla se c'e' un vincitore
        if(win(matrix,k,giocatore1)==1) {
            printf("Ha vinto il giocatore 1\n");
            return (0);
        }
        
        
        do{
            w=0;
            printf("Giocatore 2: ");
            scanf("%d",&giocatore2);
            
            if (giocatore2<=5)
            {
                if (colonne[giocatore2] == 5)
                {
                    printf("Mossa non valida\n");
                    w=1;
                }
                else
                {
                    colonne[giocatore2]++;
                    k=colonne[giocatore2];
                    inserisci(matrix,colonne[giocatore2],giocatore2,'x');
                    stampa(matrix);
                    w=0;
                }
            }
            else
            {
                printf("Input errato\n");
                w=1;
            }
            
        }while(w!=0);

        if(win(matrix,k,giocatore2)) {
            printf("Ha vinto il giocatore 2\n");
            return (0);
        }
        
        //controlla se la griglia e' esaurita
        int somma = 0;
        for (int i=0; i<6; i++)
            somma = somma + colonne[i];
        
        if (somma>=35)
        {
            notfull=1;
            printf("Game over! Nessuno ha vinto\n");
        }
        
        
    }
    return(0);
}


int win(char matrix[6][7],int x,int y){
    
    int min=0;
    int max=0;
    int m=0;
    
    //controllo colonne
    if (x>=3){
        if((matrix[x][y]==matrix[x-1][y])&&
           (matrix[x-1][y]==matrix[x-2][y])&&(matrix[x-2][y]==matrix[x-3][y]))return(1);
    }
    
    
    //Controllo righe
    //Da sinistra a destra
    //Da destra a sinistra
    
    if (y==3){
        min=0;
        max=6;}
    else if (y<3){
        min=0;
        max=y+3;
    }
    else if(y>3){
        min=y-3;
        max=6;
    }
    for (m=min;m<=max-3;m++){
        if (((matrix[x][m]==matrix[x][m+1])&&(matrix[x][m+1]==matrix[x][m+2]))&&(matrix[x][m+2]==matrix[x][m+3]))return(1);
    }
    
    
    //Controllo diagonali
    //Da destra a sinistra alto basso
    
    do{
        if(((x+1)>5)||((y+1)>6))break;
        if(((x+2)>5)||((y+2)>6))break;
        if(((x+3)>5)||((y+3)>6))break;
        if ((matrix[x][y]==matrix[x+1][y+1])&&(matrix[x+1][y+1]==matrix[x+2][y+2])&&
            (matrix[x+2][y+2]==matrix[x+3][y+3]))return(1);
    }while(0);
    
    do{
        if(((x-1)<0)||((y-1)<0))break;
        else if ((matrix[x-1][y-1]==matrix[x][y])&&(matrix[x][y]==matrix[x+1][y+1])&&
                 (matrix[x+1][y+1]==matrix[x+2][y+2]))return(1);
    }while(0);
    
    do{
        if(((x-2)<0)||((y-2)<0))break;
        else if ((matrix[x-2][y-2]==matrix[x-1][y-1])&&(matrix[x-1][y-1]==matrix[x][y])&&
                 (matrix[x][y]==matrix[x+1][y+1]))return(1);
    }while(0);
    
    do{
        if(((x-3)<0)||((y-3)<0))break;
        else if ((matrix[x-3][y-3]==matrix[x-2][y-2])&&(matrix[x-2][y-2]==matrix[x-1][y-1])&&
                 (matrix[x-1][y-1]==matrix[x][y]))return(1);
    }while(0);
    
    //Da sinistra a destra alto basso
    do{
        if(((x+1)>5)||((y-1)<0))break;
        if(((x+2)>5)||((y-2)<0))break;
        if(((x+3)>5)||((y-3)<0))break;
        if ((matrix[x][y]==matrix[x+1][y-1])&&(matrix[x+1][y-1]==matrix[x+2][y-2])&&
            (matrix[x+2][y-2]==matrix[x+3][y-3]))return(1);
    }while(0);
    
    do{
        if(((x-1)<0)||((y+1)>6))break;
        else if ((matrix[x-1][y+1]==matrix[x][y])&&(matrix[x][y]==matrix[x+1][y-1])&&
                 (matrix[x+1][y-1]==matrix[x+2][y-2]))return(1);
    }while(0);
    
    do{
        if(((x-2)<0)||((y+2)>6))break;
        else if ((matrix[x-2][y+2]==matrix[x-1][y+1])&&(matrix[x-1][y+1]==matrix[x][y])&&
                 (matrix[x][y]==matrix[x+1][y-1]))return(1);
    }while(0);
    
    do{
        if(((x-3)<0)||((y+3)>6))break;
        else if ((matrix[x-3][y+3]==matrix[x-2][y+2])&&(matrix[x-2][y+2]==matrix[x-1][y+1])&&
                 (matrix[x-1][y+1]==matrix[x][y]))return(1);
    }while(0);
    
    return(0);
    
    
}

void inserisci(char matrix[6][7],int c,int giocatore,char ch){
    matrix[c][giocatore]=ch;
}

void stampa(char matrix[6][7]){
    
    int i,j;
    for (i=5;i>-1;i--){
        for (j=0;j<7;j++){
            printf("|%c",matrix[i][j]);
        }
        printf("|\n");
    }
    printf("---------------\n");
    printf(" 0 1 2 3 4 5 6 \n");
}
