//
//  main.c
//  Es4
//
//  Created by Paolo Perego on 06/11/16.
//  Copyright © 2016 Paolo Perego. All rights reserved.
//

#include <stdio.h>
#include "string.h"

int main(int argc, char *argv[]) {
    int i,cnt;
    unsigned long len;
    char ch;
    char stringa[50];
    
    scanf( "%s" ,stringa);
    len = strlen(stringa);
    
    // controlla la stringa
    cnt = 0;
    for(i=0;i<len;i++){
        ch = stringa[i];
        if(ch == '('){
            cnt++;
        }
        if(ch == ')'){
            cnt--;
        }
    }
    
    //  Print del risultato
    if(cnt == 0){
        printf("\n\r La stringa Ë parentisizzata  !!");
    }else{		
        printf("\n\r La stringa NON Ë parentisizzata !!");
    }	
    return 0;
}