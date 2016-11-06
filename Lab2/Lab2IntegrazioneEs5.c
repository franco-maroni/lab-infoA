//
//  main.c
//  Es5
//
//  Created by Paolo Perego on 06/11/16.
//  Copyright © 2016 Paolo Perego. All rights reserved.
//

#include <stdio.h>

int main(int argc, char *argv[]) {
    
    int i;
    int arrayChar[5];
    char ch;
    int old_val;
    int flag_check = 0;
    // acquisisce 5 caratteri minuscoli
    i = 0;
    do{
        printf("\n Inserisci il carattere %d ",i);
        fpurge(stdin);
        ch = getchar();
        
        fflush(stdin);  //  pulisce lo stdin per ignorare il CR
        if((ch <= 122 )&&( ch >= 96) ){
            //printf("-%d-",ch);
            arrayChar[i] = ch;
            i++;
        }else{
            printf("carattere %c non valido !! ", ch);
        }
    }while(i < 5);
    
    //  stampa i 5 caratteri
    printf("\n");
    for( i = 0; i < 5; i++){
        printf("%c",arrayChar[i]);
    }
    
    
    //  Controlla se i char sono in ordine
    //  flag_check viene messo a 1 quando trova una coppia di char non ordinata
    old_val = 0;
    for( i = 0; i < 5; i++){
        if(old_val > arrayChar[i]){
            flag_check = 1;
        }
        old_val = arrayChar[i];
    }
    
    //   stampa il risultato 
    if(flag_check == 1) {
        printf("\nSequenza NON ORDINATA");
    }else{ 
        printf("\nSequenza ORDINATA ");	
    }
    
    return 0;
}
