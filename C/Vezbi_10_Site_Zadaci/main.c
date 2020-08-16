/*
-----Zadaca 1-----
Mora koga gi deklarirame nizite da bideme sigurni deka str1 ima dovolno mesto za moze da se iskopira str2 vo nego, odnosno
goleminata na str1 mora da e barem ista kako str2
*/

/*
-----Zadaca 2-----
Se deklarira kako const char * za da bideme sigurni deka nema da moze preku pokazuvacot da smenime vrednost vo originalnio string koj
se prakja po referenca, odnosno operacija kako *s2='q' kje javi greska od kompajlerot
*/

/*
-----Proekt 2-----
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void meshaj( int wDeck[][ 13 ] );
void deli(int wDeck[][ 13 ], const char *wFace[], const char *wSuit[] );

int main()
{
   // inicijaliziraj ja nizata na boi
   const char *boja[ 4 ] = { "Srce", "Karo", "List", "Detelina" };

   // inicijaliziraj ja nizata na brojki
   const char *brojka[ 13 ] =
      { "As", "Dva", "Tri", "Chetiri",
        "Pet", "Shest", "Sedum", "Osum",
        "Devet", "Deset", "Dzandar", "Dama", "Pop" };

   // inicijaliziraj niza na spil
   int spil[ 4 ][ 13 ] = { 0 };

   srand( time( 0 ) ); // generator na sluchajni broevi

   meshaj( spil );
   deli(spil, brojka, boja);

   return 0; // uspeshen kraj

} // kraj main

// meshaj gi kartite vo shpilot
void meshaj( int wDeck[][ 13 ] )
{
   int row;    // broj na red
   int column; // broj na kolona
   int card;   // brojach

   // za sekoja od 52-te karti,
   // odberi sluchajno mesto vo shpilot
   for ( card = 1; card <= 52; card++ ) {

      // biraj nova sluchajna lokacija dodeka ne najdesh
      // slobodno mesto
      do {
         row = rand() % 4;
         column = rand() % 13;
      } while( wDeck[ row ][ column ] != 0 ); // kraj do...while

      // pojtavi ja kartata na izbranoto mesto vo spilot
      wDeck[ row ][ column ] = card;
   } // kraj for
} // kraj na funkcijata meshaj

// deli gi kartite vo shpilot
void deli(int wDeck[][13], const char *wFace[], const char *wSuit[] ){
    int izvleceniKarti[10]={0};
    int counter=0;
    for(int i=0; i<5; i++){
        int row, column;
        do{
            row = rand() % 4;
            column = rand() % 13;
        }while(wDeck[row][column]==-1);
        wDeck[row][column]=-1;
        izvleceniKarti[counter++]=row;
        izvleceniKarti[counter++]=column;
    }
    printf("Izvleceni karti(row, column): ");
    for(int i=0; i<10; i+=2){
        printf("%d-%d ", izvleceniKarti[i], izvleceniKarti[i+1]);
    }
    printf("\n");

    // a. b. c. d.
    int broj[13]={0};
    for(int i=1; i<=5; i++){
        broj[izvleceniKarti[(2*i)-1]]++;
    }
    for(int i=0; i<13; i++){
        if(broj[i]!=0 && broj[i]!=1){
            printf("Izvleceni se %d %s\n", broj[i], wFace[i]);
        }
    }

    // e.
    int flag=1;
    for(int i=0; i<4; i++){
        if(izvleceniKarti[2*i]!=izvleceniKarti[2*(i+1)])
            flag=0;
    }
    if(flag){
        printf("Site kart se od boja: %s", wSuit[izvleceniKarti[0]]);

        // f.
        int kenta=1;
        for(int i=0; i<12; i++){
            if(broj[i]==1 && broj[i+1]==1){
                kenta++;
            }
        }
        if(kenta==5)
            printf("Ima Kenta");
    }
}
*/

/*
-----Proekt 2a-----
Ne se opfateni granicnite slucai koga na primer dvajca igraci kje imaat flush vo raka ili koga dvajca igraci kje imaat po 2 As vo raka itn.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void meshaj( int wDeck[][ 13 ] );
int deli(int wDeck[][ 13 ], const char *wFace[], const char *wSuit[] );

int main()
{
   // inicijaliziraj ja nizata na boi
   const char *boja[ 4 ] = { "Srce", "Karo", "List", "Detelina" };

   // inicijaliziraj ja nizata na brojki
   const char *brojka[ 13 ] =
      { "As", "Dva", "Tri", "Chetiri",
        "Pet", "Shest", "Sedum", "Osum",
        "Devet", "Deset", "Dzandar", "Dama", "Pop" };

   // inicijaliziraj niza na spil
   int spil[ 4 ][ 13 ] = { 0 };

   srand( time( 0 ) ); // generator na sluchajni broevi

   meshaj( spil );
   int raka1 = deli(spil, brojka, boja);
   int raka2 = deli(spil, brojka, boja);
   if(raka1 < raka2)
       printf("Igrac broj 1 pobedi");
   else if(raka1 > raka2)
       printf("Igrac broj 2 pobedi");
   else
       printf("Granicen slucaj");

   return 0; // uspeshen kraj

} // kraj main

// meshaj gi kartite vo shpilot
void meshaj( int wDeck[][ 13 ] )
{
   int row;    // broj na red
   int column; // broj na kolona
   int card;   // brojach

   // za sekoja od 52-te karti,
   // odberi sluchajno mesto vo shpilot
   for ( card = 1; card <= 52; card++ ) {

      // biraj nova sluchajna lokacija dodeka ne najdesh
      // slobodno mesto
      do {
         row = rand() % 4;
         column = rand() % 13;
      } while( wDeck[ row ][ column ] != 0 ); // kraj do...while

      // pojtavi ja kartata na izbranoto mesto vo spilot
      wDeck[ row ][ column ] = card;
   } // kraj for
} // kraj na funkcijata meshaj

// deli gi kartite vo shpilot
int deli(int wDeck[][13], const char *wFace[], const char *wSuit[] ){
    int izvleceniKarti[10]={0};
    int counter=0;
    int points=-1;

    for(int i=0; i<5; i++){
        int row, column;
        do{
            row = rand() % 4;
            column = rand() % 13;
        }while(wDeck[row][column]==-1);
        wDeck[row][column]=-1;
        izvleceniKarti[counter++]=row;
        izvleceniKarti[counter++]=column;
    }
    printf("Izvleceni karti(row, column): ");
    for(int i=0; i<10; i+=2){
        printf("%d-%d ", izvleceniKarti[i], izvleceniKarti[i+1]);
    }
    printf("\n");

    int broj[13]={0};
    for(int i=1; i<=5; i++){
        broj[izvleceniKarti[(2*i)-1]]++;
    }

    // 1. Check Royal Flush
    int istaBoja=1;
    for(int i=0; i<4; i++){
        if(izvleceniKarti[2*i]!=izvleceniKarti[2*(i+1)])
            istaBoja=0;
    }
    if(istaBoja){
        if(broj[12]==broj[11]==broj[10]==broj[9]==broj[0]==1)
            return 1;
    }
    // 2. Check Straight Flush
    int strFlush=1;
    if(istaBoja){
        for(int i=0; i<12; i++){
            if(broj[i]==1 && broj[i+1]==1){
                strFlush++;
            }
            if(strFlush==5)
                return 2;
        }
    }
    // 3. Four of a kind
    for(int i=0; i<13; i++){
        if(broj[i]==4)
            return 3;
    }
    // 4. Full house
    int three=0, two=0;
    for(int i=0; i<13; i++){
        if(broj[i]==3)
            three=1;
        if(broj[i]==2)
            two=1;
    }
    if(three && two)
        return 4;
    // 5. Flush
    if(istaBoja)
        return 5;
    // 6. Straight
    int str=1;
    for(int i=0; i<12; i++){
        if(broj[i]==1 && broj[i+1]==1){
            str++;
        }
        if(str==5)
            return 6;
    }
    // 7. Three of a kind
    if(three && !two)
        return 7;
    // 8. Two pair
    two=0;
    for(int i=0; i<13; i++){
        if(broj[i]==2)
            two++;
    }
    if(two==2)
        return 8;
    // 9. Pair
    if(two==1)
        return 9;
    // 10. High card
    int max=izvleceniKarti[1];
    for(int i=2; i<=5; i++){
        if(max<izvleceniKarti[(2*i)-1]){
            max=izvleceniKarti[(2*i)-1];
                    printf("%d\n",max);}
    }
    return (max+1)*10;
}
