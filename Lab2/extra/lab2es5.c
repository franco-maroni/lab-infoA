#include <stdio.h>
#include <string.h>

void cifrarioCesare(char *vet, char *vetCifrato, char key);
char trovaKey(char *vet, char *vetCifrato);

int main(int argc, const char * argv[]) {

    char frase[1000];
    char fraseCifrata[1000];
    char key;
    
    printf("Inserisci frase da cifrare: \n");

    do
    {
        gets(frase);
    }while(strlen(frase)>1000);
    
    //cifratura
    printf("Seleziona la lettera chiave (a-z): ");
    fpurge(stdin);
    scanf("%c",&key);
    
    cifrarioCesare(frase, fraseCifrata, key);
    
    printf("Frase non cifrata: %s\n",frase);
    printf("Frase cifrata: %s\n",fraseCifrata);
    printf("key trovata: %c\n",trovaKey(frase,fraseCifrata));
    
    return 0;
}

void cifrarioCesare(char *vet, char *vetCifrato, char key)
{
    int c;
    for (int i=0; i<strlen(vet); i++)
    {
        //minuscole
        if ((vet[i]>=97) && (vet[i]<=122))
        {
            c = key+(vet[i]-97);
            if (c>122)
                vetCifrato[i] = c - 26;
            else
                vetCifrato[i] = c;
        }
        
        //maiuscole
        else if ((vet[i]>=65) && (vet[i]<=90))
        {
            c = key+32-(vet[i]-65);
            if (c>90)
                vetCifrato[i] = c - 26;

        }
        else
            vetCifrato[i] = vet[i];
    }
     vetCifrato[strlen(vet)] = '\0';
}

char trovaKey(char *vet, char *vetCifrato)
{
    int c;
    char frase[1000];
    
    for (char k=97; k<122; k++)
    {
        for (int i=0; i<strlen(vetCifrato); i++)
        {
            //minuscolo
            if ((vetCifrato[i]>=97) && (vetCifrato[i]<=122))
            {
                c = vetCifrato[i]-(k-97);
                if (c<97)
                    frase[i] = c + 26;
                else
                    frase[i] = c;
            }
            //maiuscolo
            else if ((vetCifrato[i]>=65) && (vetCifrato[i]<=90))
            {
                c = vetCifrato[i]-(k-32)-65;
                if (c<65)
                    frase[i] = c + 26;
                else
                    frase[i] = c;
            }
            else
                frase[i] = vet[i];

        }
        vet[strlen(frase)] = '\0';
        if (strcmp(frase,vet)==0)
        {
            return k;
        }
    }
    return 0;
}