/*
-----Zadaca 1-----
#include <stdio.h>

int mnoziSoStepenOdDva(int broj, int stepen){
    return broj*(1<<stepen);
}

int main()
{
    int broj, stepen;
    scanf("%d%d", &broj, &stepen);
    printf("Rezultat: %d\n", mnoziSoStepenOdDva(broj, stepen));
    return 0;
}
*/

/*
-----Zadaca 2-----
#include <stdio.h>

void prevtriBitovi(unsigned broj){
    int maska=1<<31;
    unsigned tmpBroj=broj;
    printf("Pred prevrtubanje:\n");
    for(int i=1; i<=32; i++){
        putchar(maska & tmpBroj? '1':'0');
        tmpBroj<<=1;
        if(i%8==0)
            putchar(' ');
    }
    printf("\nPosle prevrtuvanje:\n");
    int maska2=1;
    for(int i=1; i<=32; i++){
        putchar(maska2 & broj? '1':'0');
        broj>>=1;
        if(i%8==0)
            putchar(' ');
    }
}

int main(){
    unsigned broj;
    scanf("%u", &broj);
    prevtriBitovi(broj);
    return 0;
}
*/

/*
-----Zadaca 3-----
#include <stdio.h>

int misterija( unsigned bitovi );

int main()
{
   unsigned x;
   printf( "Vnesi cel broj: " );
   scanf( "%u", &x );
   printf( "Rezultatot e %d\n", misterija( x ) );
   return 0;
}

int misterija( unsigned bitovi )
{
   unsigned i;
   unsigned maska = 1 << 31;
   unsigned total = 0;

   for ( i = 1; i <= 32; i++, bitovi <<= 1 ) {
      if ( ( bitovi & maska ) == maska ) {
         total++;                           // Broj kolku od od bitovite se 1
      }
   }
   return !( total % 2 ) ? 1 : 0; // Ako vkupniot broj na 1-ci e paren broj togash vrakja 1, a vo sprotivno vrakja 0
}
*/

/*
-----Proekt 4-----
#include <stdio.h>
#include <string.h>

struct Vraboten{
    int id;
    char ime[10];
    char prezime[20];
    int vozrast;
    int pol; // 0=masko 1=zensko
    int bracnaSostojba; // 0=single 1=not single
    int kredibilnost;
    char adresa[50];
    int tekovnaPlata;
    int poranesnaPlata;
};

void sort_kred(struct Vraboten *vraboteni, int brVraboteni);
void sort_tekovnaPlata(struct Vraboten *vraboteni, int brVraboteni);
void sort_minimalanPlata(struct Vraboten *vraboteni, int brVraboteni);
void koregiraj_vraboten(struct Vraboten *vraboteni, int brVraboteni);
void koregiraj_kredibilnost(struct Vraboten *vraboteni, int brVraboteni);

int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}
int min(int num1, int num2)
{
    return (num1 < num2 ) ? num1 : num2;
}

int main(){
    struct Vraboten vraboteni[50];
    void (*menu[5])(struct Vraboten *, int)={sort_kred, sort_tekovnaPlata, sort_minimalanPlata, koregiraj_vraboten, koregiraj_kredibilnost};
    int brVraboteni;
    printf("Broj na vraboteni: ");
    scanf("%d", &brVraboteni);
    for(int i=0; i<brVraboteni; i++){
        printf("Vnesi id, ime, prezime, vozrast, pol, bracnhaSostojba, kredibilnost, adres, tekovnaPlata, poranesnaPlata\n");
        int id, vozrast, pol, bracnhaSostojba, kredibilnost, tekovnaPlata, poranesnaPlata;
        char ime[10], prezime[20], adresa[50];
        scanf("%d%s%s%d%d%d%d%s%d%d", &id, ime, prezime, &vozrast, &pol, &bracnhaSostojba, &kredibilnost, adresa, &tekovnaPlata, &poranesnaPlata);
        vraboteni[i].id=id;
        strcpy(vraboteni[i].ime, ime);
        strcpy(vraboteni[i].prezime, prezime);
        vraboteni[i].vozrast=vozrast;
        vraboteni[i].pol=pol;
        vraboteni[i].bracnaSostojba=bracnhaSostojba;
        vraboteni[i].kredibilnost=kredibilnost;
        strcpy(vraboteni[i].adresa, adresa);
        vraboteni[i].tekovnaPlata=tekovnaPlata;
        vraboteni[i].poranesnaPlata=poranesnaPlata;
    }
    int choice=-1;
    while(choice!=5){
        printf("0=sort_kred\n");
        printf("1=sort_tekovnaPlata\n");
        printf("2=sort_minimalanPlata\n");
        printf("3=koregiraj_vraboten\n");
        printf("4=koregiraj_kredibilnost\n");
        printf("5=END\n");
        scanf("%d", &choice);
        if(choice==0)
            (*menu[choice])(vraboteni, brVraboteni);
        else if(choice==1)
            (*menu[choice])(vraboteni, brVraboteni);
        else if(choice==2)
            (*menu[choice])(vraboteni, brVraboteni);
        else if(choice==3)
            (*menu[choice])(vraboteni, brVraboteni);
        else if(choice==4)
            (*menu[choice])(vraboteni, brVraboteni);
        else
            break;
    }
    return 0;
}
// bubble sort vo rastecki redosled
void sort_kred(struct Vraboten vraboteni[], int brVraboteni){
    for(int i=0; i<brVraboteni; i++){
        for(int j=i+1; j<brVraboteni; j++){
            if(vraboteni[i].kredibilnost>vraboteni[j].kredibilnost){
                struct Vraboten tmpVraboten=vraboteni[i];
                vraboteni[i]=vraboteni[j];
                vraboteni[j]=tmpVraboten;
            }
        }
    }

    for(int i=0; i<brVraboteni; i++){
        printf("Vraboten: %d %s %s %d\n", vraboteni[i].id, vraboteni[i].ime, vraboteni[i].prezime, vraboteni[i].kredibilnost);
    }
}
void sort_tekovnaPlata(struct Vraboten vraboteni[], int brVraboteni){
    for(int i=0; i<brVraboteni; i++){
        for(int j=i+1; j<brVraboteni; j++){
            if(vraboteni[i].tekovnaPlata>vraboteni[j].tekovnaPlata){
                struct Vraboten tmpVraboten=vraboteni[i];
                vraboteni[i]=vraboteni[j];
                vraboteni[j]=tmpVraboten;
            }
        }
    }

    for(int i=0; i<brVraboteni; i++){
        printf("Vraboten: %d %s %s %d\n", vraboteni[i].id, vraboteni[i].ime, vraboteni[i].prezime, vraboteni[i].tekovnaPlata);
    }
}
void sort_minimalanPlata(struct Vraboten vraboteni[], int brVraboteni){
    for(int i=0; i<brVraboteni; i++){
        for(int j=i+1; j<brVraboteni; j++){
            if(vraboteni[i].poranesnaPlata>vraboteni[j].poranesnaPlata){
                struct Vraboten tmpVraboten=vraboteni[i];
                vraboteni[i]=vraboteni[j];
                vraboteni[j]=tmpVraboten;
            }
        }
    }

    for(int i=0; i<brVraboteni; i++){
        printf("Vraboten: %d %s %s %d\n", vraboteni[i].id, vraboteni[i].ime, vraboteni[i].prezime, vraboteni[i].poranesnaPlata);
    }
}
void koregiraj_vraboten(struct Vraboten vraboteni[], int brVraboteni){
    int idVrab;
    printf("Vnesi id: ");
    scanf("%d", &idVrab);
    int i;
    for(i=0; i<brVraboteni; i++){
        if(vraboteni[i].id==idVrab){
            printf("Smeni ime, prezime, vozrast, pol, bracnhaSostojba, kredibilnost, adres, tekovnaPlata, poranesnaPlata\n");
            scanf("%s", vraboteni[i].ime);
            scanf("%s", vraboteni[i].prezime);
            scanf("%d", &vraboteni[i].vozrast);
            scanf("%d", &vraboteni[i].pol);
            scanf("%d", &vraboteni[i].bracnaSostojba);
            scanf("%d", &vraboteni[i].kredibilnost);
            scanf("%s", vraboteni[i].adresa);
            scanf("%d", &vraboteni[i].tekovnaPlata);
            scanf("%d", &vraboteni[i].poranesnaPlata);
            break;
        }
    }
    printf("Azurirani podatoci:\n");
    printf("%d %s %s %d %d %d %d %s %d %d\n", vraboteni[i].id, vraboteni[i].ime, vraboteni[i].prezime, vraboteni[i].vozrast,
           vraboteni[i].pol, vraboteni[i].bracnaSostojba, vraboteni[i].kredibilnost, vraboteni[i].adresa, vraboteni[i].tekovnaPlata,
           vraboteni[i].poranesnaPlata);
}
void koregiraj_kredibilnost(struct Vraboten vraboteni[], int brVraboteni){
    for(int i=0; i<brVraboteni; i++){
        if(vraboteni[i].tekovnaPlata==vraboteni[i].poranesnaPlata)
            continue;
        else if(vraboteni[i].tekovnaPlata>vraboteni[i].poranesnaPlata){
            vraboteni[i].kredibilnost=min(vraboteni[i].kredibilnost+3, 100);
            vraboteni[i].tekovnaPlata=vraboteni[i].poranesnaPlata;
        }
        else{
            vraboteni[i].kredibilnost=max(vraboteni[i].kredibilnost-3, 0);
            vraboteni[i].tekovnaPlata=vraboteni[i].poranesnaPlata;
        }
    }
    for(int i=0; i<brVraboteni; i++){
        printf("Vraboten: %d %s %s %d %d %d\n", vraboteni[i].id, vraboteni[i].ime, vraboteni[i].prezime, vraboteni[i].tekovnaPlata,
               vraboteni[i].tekovnaPlata, vraboteni[i].kredibilnost);
    }
}
*/

/*
-----Datoteki-----
*/
/*
-----Zadaca 1-----
#include <stdio.h>
#include <string.h>

struct Proizvod{
    int kod;
    char ime[30];
    int kolicina;
    float cena;
};

void inicijalizacija(){
    FILE *fptr; //
    if((fptr=fopen("hardware.dat", "wb+"))==NULL)
        printf("Nastana greshka\n"); //
    else{
        printf("Vnesi kod(1-100) i 0 za kraj\n");
        struct Proizvod proizvod={0, "", 0, 0.0};
        scanf("%d", &proizvod.kod);
        while(proizvod.kod!=0){
            printf("Vnesi kolicina, cena: ");
            fscanf(stdin, "%d%f", &proizvod.kolicina, &proizvod.cena);
            fflush(stdin);
            printf("Vnesi ime: ");
            fgets(proizvod.ime, 30, stdin);
            fseek(fptr, (proizvod.kod - 1)*sizeof(struct Proizvod), SEEK_SET);
            fwrite(&proizvod, sizeof(struct Proizvod), 1, fptr);
            printf("Vnesi kod: ");
            scanf("%d", &proizvod.kod);
        }
        fclose(fptr);
    }
}

void sostojba(){
    FILE *fptr;
    if((fptr=fopen("hardware.dat", "rb"))==NULL)
        printf("Nastana problem\n");
    else{
        struct Proizvod proizvod={0, "", 0, 0.0};
        printf("Kod\tKolicina\tCena\t\tIme:\n");
        fread(&proizvod, sizeof (struct Proizvod), 1, fptr);
        while(!feof(fptr)){
            if(proizvod.kod!=0){
                char ime[30];
                strncpy(ime, proizvod.ime, strlen(proizvod.ime)-1);
                ime[strlen(proizvod.ime)-1]='\0';
                printf("%-5d\t%-10d\t%-5f\t%-15s\n", proizvod.kod, proizvod.kolicina, proizvod.cena, ime);
            }
            fread(&proizvod, sizeof (struct Proizvod), 1, fptr);
        }
        fclose(fptr);
    }
}

void vnesiProizvod(){
    FILE *fptr;
    if((fptr=fopen("hardware.dat", "rb+"))==NULL)
        printf("Nastana problem\n");
    else{
        struct Proizvod proizvod={0, "", 0, 0.0};
        int kod;
        printf("Vnesi kod: ");
        scanf("%d", &kod);
        fseek(fptr, (kod - 1)*sizeof (struct Proizvod), SEEK_SET);
        fread(&proizvod, sizeof (struct Proizvod), 1, fptr);
        if(proizvod.kod!=0)
            printf("Proizvod so ovoj kod vekje postoi\n");
        else{
            printf("Vnesi kolicina, cena: ");
            fscanf(stdin, "%d%f", &proizvod.kolicina, &proizvod.cena);
            fflush(stdin);
            printf("Vnesi ime: ");
            fgets(proizvod.ime, 30, stdin);
            fseek(fptr, (kod - 1)*sizeof (struct Proizvod), SEEK_SET);
            proizvod.kod=kod;
            fwrite(&proizvod, sizeof (struct Proizvod), 1, fptr);
        }
        fclose(fptr);
    }
}

void vidiProizvod(){
    FILE *fptr;
    if((fptr=fopen("hardware.dat", "rb"))==NULL)
        printf("Nastana problem\n");
    else{
        struct Proizvod proizvod={0, "", 0, 0.0};
        int kod;
        printf("Vnesi kod: ");
        scanf("%d", &kod);
        fseek(fptr, (kod - 1)*sizeof (struct Proizvod), SEEK_SET);
        fread(&proizvod, sizeof (struct Proizvod), 1, fptr);
        if(proizvod.kod==0)
            printf("Proizvod so ovoj kod ne postoi\n");
        else{
            printf("Kod\tKolicina\tCena\t\tIme:\n");
            char ime[30];
            strncpy(ime, proizvod.ime, strlen(proizvod.ime)-1);
            ime[strlen(proizvod.ime)-1]='\0';
            printf("%-5d\t%-10d\t%-5f\t%-15s\n", proizvod.kod, proizvod.kolicina, proizvod.cena, ime);
        }
        fclose(fptr);
    }
}

void azurirajProizvod(){
    FILE *fptr;
    if((fptr=fopen("hardware.dat", "rb+"))==NULL)
        printf("Nastana problem\n");
    else{
        struct Proizvod proizvod={0, "", 0, 0.0};
        int kod;
        printf("Vnesi kod: ");
        scanf("%d", &kod);
        fseek(fptr, (kod - 1)*sizeof (struct Proizvod), SEEK_SET);
        fread(&proizvod, sizeof (struct Proizvod), 1, fptr);
        if(proizvod.kod==0)
            printf("Proizvod so ovoj kod ne postoi\n");
        else{
            printf("Vnesi kolicina, cena: ");
            fscanf(stdin, "%d%f", &proizvod.kolicina, &proizvod.cena);
            fflush(stdin);
            printf("Vnesi ime: ");
            fgets(proizvod.ime, 30, stdin);
            if(proizvod.kolicina==0){
                fseek(fptr, (kod - 1)*sizeof (struct Proizvod), SEEK_SET);
                proizvod.kod=0;
                strcpy(proizvod.ime, "");
                proizvod.cena=0;
                proizvod.kolicina=0;
                fwrite(&proizvod, sizeof (struct Proizvod), 1,fptr);
            }
            else{
            fseek(fptr, (kod - 1)*sizeof (struct Proizvod), SEEK_SET);
            proizvod.kod=kod;
            fwrite(&proizvod, sizeof (struct Proizvod), 1, fptr);}
        }
        fclose(fptr);
    }
}

void prodazba(){
    FILE *fptr;
    if((fptr=fopen("hardware.dat", "rb+"))==NULL)
        printf("Nastana problem\n");
    else{
        struct Proizvod proizvod={0, "", 0, 0.0};
        int kod;
        printf("Vnesi kod: ");
        scanf("%d", &kod);
        fseek(fptr, (kod - 1)*sizeof (struct Proizvod), SEEK_SET);
        fread(&proizvod, sizeof (struct Proizvod), 1, fptr);
        if(proizvod.kod==0)
            printf("Proizvod so ovoj kod ne postoi\n");
        else{
            int kolicina;
            printf("Vnesi kolicina: ");
            scanf("%d", &kolicina);
            if(kolicina>proizvod.kolicina)
                printf("Nema dovolno na lager\n");
            else{
                printf("Prodadeno\n");
                proizvod.kolicina-=kolicina;
                if(proizvod.kolicina==0){
                    fseek(fptr, (kod - 1)*sizeof (struct Proizvod), SEEK_SET);
                    proizvod.kod=0;
                    strcpy(proizvod.ime, "");
                    proizvod.cena=0;
                    fwrite(&proizvod, sizeof (struct Proizvod), 1, fptr);
                }
                else{
                    fseek(fptr, (kod - 1)*sizeof (struct Proizvod), SEEK_SET);
                    fwrite(&proizvod, sizeof (struct Proizvod), 1, fptr);
                }
            }

        }
        fclose(fptr);
    }
}

int main()
{
   inicijalizacija();
   void (*menu[5])()={sostojba, vnesiProizvod, vidiProizvod, azurirajProizvod, prodazba};
   int choice=-1;
   while(choice!=5){
       printf("0-Vidi sostojba\n");
       printf("1-Vnesi nov proizvod\n");
       printf("2-Vidi odreden proizvod\n");
       printf("3-Azuriraj odreden proizvod\n");
       printf("4-Kupi proizvod\n");
       printf("5-END\n");
       scanf("%d", &choice);
       switch (choice) {
       case 0:
           (*menu[0])();
           break;
       case 1:
           (*menu[1])();
           break;
       case 2:
           (*menu[2])();
           break;
       case 3:
           (*menu[3])();
           break;
       case 4:
           (*menu[4])();
           break;
       default:
           break;
       }
   }
   return 0;
}
*/

/*
-----Zadaca 2-----
#include <stdio.h>
#include <string.h>

struct Telefon{
    int cifra;
    char bukva[3];
};

void inicijalizacija(){
    FILE *fptr;
    if((fptr=fopen("telefon.dat", "wb"))==NULL)
        printf("Nastana greshka\n");
    else{
        struct Telefon tel;
        for(int i=0; i<9; i++){
            printf("Vnesi cifra i bukva: ");
            fscanf(stdin, "%d%s", &tel.cifra, tel.bukva);
            fseek(fptr, (tel.cifra)*sizeof (struct Telefon), SEEK_SET);
            fwrite(&tel, sizeof (struct Telefon), 1, fptr);
        }
        fclose(fptr);
    }
}

void fromLetterToNum(char *number){
    FILE *fptr;
    if((fptr=fopen("telefon.dat", "rb"))==NULL)
        printf("Greshka\n");
    else{
        for(int i=0; i<(int)strlen(number); i++){
            rewind(fptr);
            struct Telefon tel;
            fread(&tel, sizeof (struct Telefon), 1, fptr);
            while(!feof(fptr)){
                if(tel.bukva[0]==number[i] || tel.bukva[1]==number[i] || tel.bukva[2]==number[i]){
                    printf("%d", tel.cifra);
                }
                fread(&tel, sizeof (struct Telefon), 1, fptr);
            }
        }
        fclose(fptr);
    }
}

void fromNumToLetters(int  number){
    int numbers[7];
    int i=6;
    while(number){
        numbers[i]=number%10;
        number/=10;
        i--;
    }
    FILE *fptr;
    if((fptr=fopen("telefon.dat", "rb"))==NULL)
        printf("Greshka\n");
    else{
        struct Telefon tel[8];
        for(int i=0; i<7; i++){
            fseek(fptr, numbers[i]*sizeof (struct Telefon), SEEK_SET);
            fread(&tel[i], sizeof (struct Telefon), 1, fptr);
        }
        fclose(fptr);
        int counter=0;
        for(int i=0; i<(int)strlen(tel[0].bukva); i++){
            for(int j=0; j<(int)strlen(tel[1].bukva); j++){
                for(int k=0; k<(int)strlen(tel[2].bukva); k++){
                    for(int a=0; a<(int)strlen(tel[3].bukva); a++){
                        for(int ii=0; ii<(int)strlen(tel[4].bukva); ii++){
                            for(int jj=0; jj<(int)strlen(tel[5].bukva); jj++){
                                for(int kk=0; kk<(int)strlen(tel[6].bukva); kk++){
                                    printf("%c%c%c%c%c%c%c\n", tel[0].bukva[i], tel[1].bukva[j], tel[2].bukva[k], tel[3].bukva[a], tel[4].bukva[ii],
                                            tel[5].bukva[jj], tel[6].bukva[kk]);
                                    counter++;
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("Vkupno postojat %d kombinacii\n", counter);
    }
}

int main(){
    int numbers;
    char letters[7];
    inicijalizacija();
    printf("Vnesi 7 golemi bukvi: ");
    scanf("%s", letters);
    printf("From letters to numbers: ");
    fromLetterToNum(letters);

    printf("\nVnesi 7 cifren broj: ");
    scanf("%d", &numbers);
    printf("From numbers to letters, all possible combinations: ");
    fromNumToLetters(numbers);
    return 0;
}
*/
