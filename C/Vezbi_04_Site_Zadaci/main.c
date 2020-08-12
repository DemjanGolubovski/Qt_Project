/*
-----Zadaca 1-----
#include <stdio.h>

int main()
{
    int test=1;
    // Deka case 1 e prviot pat koga case kje bide ispolneto i deka nema nikade break posle toa site naredni naredbi kje prodolzat da se izvrsuvaat
    // se dodeka ne se dojde do break ili do kraj na switch naredbata
    switch (test) {
    case 1:
        printf("This is one\n");
    case 5:
        printf("This is five\n");
    case 3:
        printf("This is three\n");
    case 2:
        printf("This is two\n");
    case 4:
        printf("This is four\n");
    default:
        printf("I need a \"break;\"\n");
    }
    return 0;
}
*/

/*
-----Zadaca 2 i Zadaca 3-----
#include <stdio.h>

int main()
{
   int counter;
   int grade;
   int total;
   float average;

   total = 0;
   scanf("%d", &counter);
   average = 1.0/counter;
   while (counter) {
      printf( "Vnesi ocena: " );
      scanf( "%d", &grade );
      total = total + grade;
      counter--;
   }
   average = average * total;

   printf( "Srednata vrednost na klasot e %.3f\n", average );
   return 0;
}
*/

/*
-----Zadaca 4-----
#include <stdio.h>

int main(){
    int suma=0;
    for(int i=1; i<=10; i++)
        suma+=i;
    printf("Suma: %d\n", suma);
    return 0;
}
*/

/*
-----Zadaca 5-----
#include <stdio.h>

int main(){
    int proizvod=1;
    int broj;
    for(int i=0; i<10; i++){
        scanf("%d", &broj);
        proizvod*=broj;
    }
    printf("Proizvod: %d\n", proizvod);
    return 0;
}
*/

/*
-----Zadaca 6-----
#include <stdio.h>

int main(){
    int suma=0;
    int broj;
    scanf("%d", &broj);
    while(broj!=-1){
        suma+=broj;
        scanf("%d", &broj);
    }
    printf("Suma: %d\n", suma);
    return 0;
}
*/

/*
-----Zadaca 7-----
#include <stdio.h>

int main(){
    int broj;
    int suma=0;
    char znak;
    do{
        printf("Vnesi broj: ");
        scanf("%d", &broj);
        suma+=broj;
        printf("Ushte? (d\\n): ");
        scanf(" %c", &znak);
    }while(znak!='n');

    printf("Suma: %d\n", suma);
    return 0;
}
*/

/*
-----Zadaca 8-----
#include <stdio.h>

int main(){
    float proizvodi[5]={0}; // niza kade kje za sekoj proizvod kolkava kolicina e prodadena, inicijalno site se 0
    int proizvod;
    float kolicina;
    char flag='d';
    while(flag!='n'){
        printf("Vnesi proizvod i kolicina: ");
        scanf("%d%f", &proizvod, &kolicina);
        switch(proizvod){
        case 1:
            proizvodi[0]+=kolicina;
            break;
        case 2:
            proizvodi[1]+=kolicina;
            break;
        case 3:
            proizvodi[2]+=kolicina;
            break;
        case 4:
            proizvodi[3]+=kolicina;
            break;
        case 5:
            proizvodi[4]+=kolicina;
            break;
        default:
            printf("Ne postoi takov produkt");
        }
        printf("Dali ima uste proizvodi? (d\\n) :");
        scanf(" %c", &flag);
    }
    printf("Prodadena kolicina za proizvod 1: %.2f\n", proizvodi[0]);
    printf("Prodadena kolicina za proizvod 2: %.2f\n", proizvodi[1]);
    printf("Prodadena kolicina za proizvod 3: %.2f\n", proizvodi[2]);
    printf("Prodadena kolicina za proizvod 4: %.2f\n", proizvodi[3]);
    printf("Prodadena kolicina za proizvod 5: %.2f\n", proizvodi[4]);
    printf("Vkupna suma: %.2f\n", proizvodi[0]*50.5 + proizvodi[1]*45.6 + proizvodi[2]*32.8 + proizvodi[3]*65.3 + proizvodi[4]*20);
    return 0;
}
*/

/*
-----Zadaca 9-----
*/
#include <stdio.h>

int main(){
    float promet;
    printf("Vnesi promet vo evra (-1 za kraj): ");
    scanf("%f", &promet);
    while(promet!=-1){
        printf("Platata e: %.2f\n", 200 + promet*0.09);
        printf("Vnesi promet vo evra (-1 za kraj): ");
        scanf("%f", &promet);
    }
    return 0;
}
