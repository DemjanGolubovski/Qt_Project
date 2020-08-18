/*
-----Zadaca 1-----
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char string[15];
    char *ptr;
    gets(string);
    ptr=strtok(string, " ");
    char *delovi[2];
    int i=0;
    while(ptr!=NULL){
        delovi[i]=ptr;
        ptr=strtok(NULL, " ");
        i++;
    }
    char drzava[4];
    strncpy(drzava, (delovi[0]+1), 3);
    drzava[3]='\0';

    char broj[8]="";
    char *pokBroj;
    pokBroj=strtok(delovi[1],"-");
    while(pokBroj!=NULL){
        strcat(broj, pokBroj);
        pokBroj=strtok(NULL, "-");
    }

    int brojDrzava=atoi(drzava);
    long telBroj=atol(broj);

    printf("Broj na drzava: %d\nBroj na telefon: %ld\n", brojDrzava, telBroj);
    return 0;
}
*/

/*
-----Zadaca 2-----
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    char *meseci[12]={"Januari", "Fevruari", "Mart", "April", "Maj", "Juni", "Juli", "Avgust", "Septemvri", "Oktomvri", "Noemvri", "Dekemvri"};
    while(n){
        char datum[11];
        printf("Datum: ");
        scanf("%s", datum);
        char *pokDatum;
        pokDatum=strtok(datum, "/");
        char *datumDelovi[3];
        int i=0;
        while(pokDatum!=NULL){
            datumDelovi[i]=pokDatum;
            i++;
            pokDatum=strtok(NULL, "/");
        }
        printf("%s %s %s\n", datumDelovi[0], meseci[atoi(datumDelovi[1])-1], datumDelovi[2]);
        n--;
    }
    return 0;
}
*/

/*
-----Zadaca 3-----
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

void toMorse(char *morseLetters[], char *morseNumbers[]){
    printf("From Morse to Normal\n");
    char c;
    while((c=getchar())!='\n'){ //now white spaces are allowed
        if(isdigit(c)){
            printf("%s ", morseNumbers[c-'0']);
        }
        if(isalpha(c)){
            printf("%s ",morseLetters[toupper(c)-'A']);
        }
    }
    printf("\n");
}

void toNormal(char *morseLetters[], char *morseNumbers[]){
    printf("From Normal to Morse\n");
    char string[MAX];
    gets(string);
    char *pokStr;
    pokStr=strtok(string, " ");
    while(pokStr!=NULL){
        if(strlen(pokStr)==5){ // number
            for(int i=0; i<10; i++){
                if(strcmp(pokStr,morseNumbers[i])==0)
                    printf("%d",i);
            }
        }
        else{ // letter
            for(int i=0; i<26; i++){
                if(strcmp(pokStr,morseLetters[i])==0){
                    printf("%c",(i+'A'));}
            }
        }
        pokStr=strtok(NULL, " ");
    }
}

int main(){
    char *morseLetters[26]={"*-", "-***", "-*-*", "-**", "*", "**-*", "--*", "****", "**", "*---", "-*-", "*-**", "--", "-*", "---",
                           "*--*", "--*-", "*-*", "***", "-", "**-", "***-", "*--", "-**-", "-*--", "--**"}; //{A,B,C,D,E,F,...Z}
    char *morseNumbers[10]={"-----", "*----", "**---", "***--", "****-", "*****", "-****", "--***", "---**", "----*"}; //{0,1,2,3,4,5,6,7,8,9}
    toMorse(morseLetters, morseNumbers);
    toNormal(morseLetters, morseNumbers);
    return 0;
}
