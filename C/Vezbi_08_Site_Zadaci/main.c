/*
-----Zadaca 1-----
#include <stdio.h>

int main()
{
    int denovi;
    printf("Vnesi broj na denovi: ");
    scanf("%d", &denovi);
    float average = 1.0/denovi;
    float suma = 0;
    while(denovi){
        float temperatura;
        printf("Temperatura: ");
        scanf("%f", &temperatura);
        suma+=temperatura;
        denovi--;
    }
    average*=suma;
    printf("Sredna mesecna temperatura: %.2f\n", average);
    return 0;
}
*/

/*
-----Zadaca 2-----
#include <stdio.h>
#include <math.h>

void prosti(int broevi[], int n){
    for(int i=2; i<n; i++){
        int flag=0;
        for(int j=2; j<=floor(sqrt(i)); j++){
            if(i%j==0)
                flag=1;
        }
        broevi[i]=flag;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int broevi[n];
    // inicijalizacija na 1
    for(int i=0; i<n; i++){
        broevi[i]=1;
    }
    prosti(broevi, n);
    for(int i=0; i<n; i++){
        if(broevi[i]==0)
            printf("%d\n", i);
    }

    return 0;
}
*/

/*
-----Zadaca 3-----
#include <stdio.h>

int palindrom(char *str, int start, int end){
    if(start>=end)
        return 1;
    if(str[start]!=str[end])
        return 0;
    palindrom(str, start+1, end-1);
}

int main(){
    int n;
    printf("Vnesi dolzina na string: ");
    scanf("%d", &n);
    char str[n];
    scanf("%s", str);
    printf("%d\n",palindrom(str, 0, n-1));
    return 0;
}
*/

/*
-----Zadaca 4-----
#include <stdio.h>
#define MAX 100

void popolniIterativno(int matrica[][MAX], int red, int kolona){
    for(int i=0; i<red; i++){
        for(int j=0; j<kolona; j++){
            scanf("%d", &matrica[i][j]);
        }
    }
}

void pecatiIterativno(int matrica[][MAX], int red, int kolona){
    for(int i=0; i<red; i++){
        for(int j=0; j<kolona; j++){
            printf("%d ", matrica[i][j]);
        }
        printf("\n");
    }
}

void popolniRekurzivno(int matrica[][MAX], int red, int kolona, int i, int j){
    if(j==kolona){
        i++;
        j=0;
    }
    if(i!=red && j!=kolona){
        scanf("%d", &matrica[i][j]);
        j++;
        popolniRekurzivno(matrica, red, kolona, i, j);
    }
}

void pecatiRekurzivno(int matrica[][MAX], int red, int kolona, int i, int j){
    if(j==kolona){
        i++;
        j=0;
        printf("\n");
    }
    if(i!=red && j!=kolona){
        printf("%d ", matrica[i][j]);
        j++;
        pecatiRekurzivno(matrica, red, kolona, i, j);
    }
}

int main(){
    int red, kolona;
    scanf("%d%d", &red, &kolona);
    int matrica[red][kolona];

    popolniIterativno(matrica, red, kolona);
    pecatiIterativno(matrica, red, kolona);

    popolniRekurzivno(matrica, red, kolona, 0, 0);
    pecatiRekurzivno(matrica, red, kolona, 0, 0);
    return 0;
}
*/

/*
-----Zadaca 5-----
#include <stdio.h>

int minElem(int niza[], int start, int end){
    if(start==end)
        return start;
    else if(niza[start]>=niza[end])
        minElem(niza, start+1, end);
    else
        minElem(niza, start, end-1);
}

void selectionSort(int niza[], int n){
    for(int i=0; i<n; i++){
        int minElemIndex=minElem(niza, i, n-1);
        if(i!=minElemIndex){
            int tmp=niza[i];
            niza[i]=niza[minElemIndex];
            niza[minElemIndex]=tmp;
        }
    }
}

void recursiveSelectionSort(int niza[], int n, int i){
    if(i<n){
        int minElemIndex=minElem(niza, i, n-1);
        if(i!=minElemIndex){
            int tmp=niza[i];
            niza[i]=niza[minElemIndex];
            niza[minElemIndex]=tmp;
        }
        recursiveSelectionSort(niza, n, i+1);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int niza[n];
    for(int i=0; i<n; i++){
        scanf("%d", &niza[i]);
    }
    selectionSort(niza, n);
    recursiveSelectionSort(niza, n, 0);

    // pecatenje na sortirana niza
    for(int i=0; i<n; i++){
        printf("%d ", niza[i]);
    }
    return 0;
}
// Ista kompleksnost ima kako bubble sort O(n^2) deka celata niza ja izminuva i sekoj element so sekoj go sporeduva
*/

/*
-----Proekt 1-----
*/
#include <stdio.h>

int minElem(int niza[], int start, int end){
    if(start==end)
        return start;
    else if(niza[start]>=niza[end])
        minElem(niza, start+1, end);
    else
        minElem(niza, start, end-1);
}

void recursiveSelectionSort(int niza[], int n, int i){
    if(i<n){
        int minElemIndex=minElem(niza, i, n-1);
        if(i!=minElemIndex){
            int tmp=niza[i];
            niza[i]=niza[minElemIndex];
            niza[minElemIndex]=tmp;
        }
        recursiveSelectionSort(niza, n, i+1);
    }
}

void print(int niza[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", niza[i]);
    }
    printf("\n");
}

void srednaVrednost(int niza[], int n){
    int suma=0;
    for(int i=0; i<n; i++){
        suma+=niza[i];
    }
    printf("Sredna vrednost: %.2f\n", (float)suma/n);
}

void medijana(int niza[], int n){
    if(n%2==0)
        printf("Medijana: %.2f\n", (niza[n/2]+niza[n/2-1])/2.0);
    else
        printf("Medijana: %d\n", niza[n/2]);
}

void najfrekventna(int niza[], int n){
    int maxFreq=0, tmpValue=1;
    int maxFreqValue, i;
    for(i=0; i<n-1; i++){
        if(niza[i]==niza[i+1])
            tmpValue++;
        else{
            if(maxFreq<tmpValue){
                maxFreq=tmpValue;
                maxFreqValue=niza[i];
            }
            tmpValue=1;
        }
    }
    if(maxFreq<tmpValue){
        maxFreq=tmpValue;
        maxFreqValue=niza[i];
    }
    printf("Najfrekventna vrednost e: %d i se pojavuva %d pati\n", maxFreqValue, maxFreq);
}

void histogram(int niza[], int n){
    int freq=1;
    for(int i=0; i<n-1; i++){
        if(niza[i]==niza[i+1])
            freq++;
        else{
            printf("Frekvencija na %d: ", niza[i]);
            for(int j=0; j<freq; j++)
                printf("*");
            printf("\n");
            freq=1;
            if(i==n-2)
                printf("Frekvencija na %d: *\n", niza[i+1]);
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int niza[n];
    for(int i=0; i<n; i++){
        scanf("%d", &niza[i]);
    }

    recursiveSelectionSort(niza, n, 0);
    print(niza, n);
    srednaVrednost(niza, n);
    medijana(niza, n);
    najfrekventna(niza, n);
    histogram(niza, n);
    return 0;
}
