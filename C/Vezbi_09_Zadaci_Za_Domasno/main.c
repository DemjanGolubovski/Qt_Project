/*
-----Zadaca 1-----
#include <stdio.h>
#include <math.h>
int main()
{
    int n, t;
    printf("Vnesi broj na rabovi(n) i dolzina na rab(t): ");
    scanf("%d%d", &n, &t);
    float plostina = (n * pow(t, 2)) / (4 * tan(3.14 / n));
    int perimetar = n * t;
    printf("Perimetar: %d\n", perimetar);
    printf("Plostina: %.2f\n", plostina);
    return 0;
}
*/

/*
-----Zadaca 2-----
// Pretpostavka deka sistemot e sostaven od linearni ravenki
// Resenie so metod na zamena/eliminacija
#include <stdio.h>

int main(){
    float a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3;
    printf("Koeficienti za prvata ravenka, vo format (x, y, z, d): ");
    scanf("%f%f%f%f", &a1, &b1, &c1, &d1);
    printf("Koeficienti za vtorata ravenka, vo format (x, y, z, d): ");
    scanf("%f%f%f%f", &a2, &b2, &c2, &d2);
    printf("Koeficienti za treta ravenka, vo format (x, y, z, d): ");
    scanf("%f%f%f%f", &a3, &b3, &c3, &d3);

    printf("Sistemot izgleda:\n");
    printf("%.2f*x + %.2f*y + %.2f*z = %.2f\n", a1, b1, c1, d1);
    printf("%.2f*x + %.2f*y + %.2f*z = %.2f\n", a2, b2, c2, d2);
    printf("%.2f*x + %.2f*y + %.2f*z = %.2f\n", a3, b3, c3, d3);

    float z = (d3 - (a3*d1)/a1 - d2*(b3*a1 - a3*b1)/(a1*b2 - b1*a2) + d1*a2*(b3*a1 - a3*b1)/(a1*(a1*b2-b1*a2))) / ((c3-(c1*a3)/a1)-((a1*c2-c1*a2)*(b3*a1-a3*b1))/(a1*(a1*b2-b1*a2)));
    float y = (d2 - (a2*d1)/a1 - z*(c2 - (c1*a2)/a1))/(b2 - (b1*a2)/a1);
    float x = (d1 - b1*y - c1*z)/a1;

    printf("Resenie: x = %.2f, y = %.2f, z = %.2f", x, y, z);
    return 0;
}
*/

/*
-----Zadaca 3-----
#include <stdio.h>

void sprotiven(int broj){
    if(broj!=0){
     printf("%d", broj%10);
     sprotiven(broj/10);
    }
}

int main(){
    int broj;
    scanf("%d", &broj);
    sprotiven(broj);
    return 0;
}
*/

/*
-----Zadaca 4-----
#include <stdio.h>

int perfectNum(int num){
    int suma=1;
    for(int i=2; i<=num/2; i++){
        if(num%i==0)
            suma+=i;
    }
    if(suma==num)
        return suma;
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=2; i<n; i++){
        int num = perfectNum(i);
        if(num)
            printf("%d\n", num);
    }
    return 0;
}
*/

/*
-----Zadaca 5-----
#include <stdio.h>
#include <math.h>

int isPrime(int broj){
    for(int j=2; j<=floor(sqrt(broj)); j++){
        if(broj%j==0)
            return 0;
    }
    return 1;
}

int main(){
    int broj, originalBroj;
    int proizvod=1;
    scanf("%d", &broj);
    originalBroj=broj;
    for(int i=2; i<=broj/2; i++){
        if(broj%i==0){
            if(isPrime(i)){
                int count=0;
                while(broj%i==0){
                    count++;
                    broj/=i;
                }
                proizvod=proizvod*pow(i, count);
                printf("%d^%d ", i, count);
            }
        }
    }
    if(proizvod!=originalBroj)
        printf("%d^1\n", broj);
    else
        printf("\n");
    return 0;
}
*/

/*
-----Zadaca 6-----
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<n; i++){
        int broj=i;
        int suma=0;
        while(broj!=0){
            suma=suma+pow(broj%10, 3);
            broj/=10;
        }
        if(suma==i)
            printf("%d\n", i);
    }
    return 0;
}
*/

/*
-----Zadaca 7-----
#include <stdio.h>

void sprotiven(int broj, int *novBroj){
    if(broj!=0){
        *novBroj=*novBroj*10 + broj%10;
        sprotiven(broj/10, novBroj);
    }
}

int main(){
    int n1, n2;
    scanf("%d%d", &n1, &n2);
    for(int i=n1; i<=n2; i++){
        int sprotivenBroj=0;
        sprotiven(i, &sprotivenBroj);
        if(i%sprotivenBroj==0)
            printf("%d\n", i);
    }
    return 0;
}
*/

/*
-----Zadaca 8-----
// Nacin na resavanje: za da gi ima cifrite [0, 9] po ednas vo kvadratot i kubot zaedno na eden broj toa znaci deka brojot na cifri na kvadratot i
// kubot treba da e tocno 10 a deka brojot na cifir e sekogas pogolem kaj kubot od kvadratot i deka ima ogranicuvanje vkupno da ima 10 cifri megju
// kvadratot i kubot zaedno toa se proevi koj se vo rang od 47(deka e prv priroden broj cii kvadrat ima 4 cifri a kub ima 6 cifri) i 99(deka e posleden
//  broj cii kvadrat ima 4 cifri a kub ima 6 cifri) i dopolnitelno edinstvena kombinacija e da se koristat broevi cii kvadrat ima 4 cifri a kub ima 6
#include <stdio.h>
#include <math.h>

int main(){
    for(int i=47; i<=99; i++){
        int niza[10]={0};
        int kvadrat = (int)pow(i, 2);
        int kub = (int)pow(i, 3);
        int flag=1;
        while(kvadrat!=0){
            niza[kvadrat%10]++;
            if(niza[kvadrat%10]==2){
                flag=0;
                break;
            }
            kvadrat/=10;
        }
        if(flag==0)
            continue;
        while(kub!=0){
            niza[kub%10]++;
            if(niza[kub%10]==2){
                flag=0;
                break;
            }
            kub/=10;
        }
        if(flag==1)
            printf("%d\n", i);
    }

    return 0;
}
*/

/*
-----Zadaca 9-----
#include <stdio.h>

int main(){
    int i, j, k, x, n;
    printf("(i, j, k, x, n) = : ");
    scanf("%d%d%d%d%d", &i, &j, &k, &x, &n);
    for(int min=1; min<=k; min++){
        if(min%i==0) // se delat, pretpostavka deka prvo kje se podelat pa posle kje umre nekoj procent od niv(vo slucaj koga i==j)
            n*=2;
        if(min%j==0) // umiraat
            n=n-n*x/100.0;
    }
    printf("Posle %d minuti kje ima %d bakterii", k, n);
    return 0;
}
*/

/*
-----Zadaca 10-----
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int niza[n];
    for(int i=0; i<n; i++){
        scanf("%d", &niza[i]);
    }
    int flag=0;
    for(int i=1; i<n; i++){
        if(niza[i]>niza[i-1]){
            printf("%d ", niza[i-1]);
            if(i==n-1)
               printf("%d\n", niza[i]);
            flag=1;
        }
        else{
            if(flag){
               printf("%d\n", niza[i-1]);
               flag=0;
            }
        }
    }
    return 0;
}
*/

/*
-----Zadaca 11-----
#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);
    int niza[n];
    for(int i=0; i<n; i++){
        scanf("%d", &niza[i]);
    }
    int flag=0;
    for(int i=1; i<n-1; i++){
        if((niza[i]>niza[i-1] && niza[i]>niza[i+1]) || (niza[i]<niza[i-1] && niza[i]<niza[i+1])){
            printf("%d ", niza[i-1]);
            if(i==n-2)
               printf("%d %d\n", niza[i], niza[i+1]);
            flag=1;
        }
        else{
            if(flag){
               printf("%d %d\n", niza[i-1], niza[i]);
               flag=0;
            }
        }
    }
    return 0;
}
*/

/*
-----Zadaca 12-----
#include <stdio.h>

int main(){
    int n,m;
    scanf("%d%d", &n, &m);
    int polinom1[n+1], polinom2[m+1];
    printf("Polinom 1: ");
    for(int i=n; i>=0; i--)
        scanf("%d", &polinom1[i]);
    printf("Polinom 2: ");
    for(int i=m; i>=0; i--)
        scanf("%d", &polinom2[i]);
    while(n!=m){
        if(n>m){
            printf("%+d*x^%d", polinom1[n], n);
            n--;
        }
        else{
            printf("%+d*x^%d", polinom2[m], m);
            m--;
        }
    }

    while(n!=0){
        printf("%+d*x^%d",polinom1[n]+polinom2[n], n);
        n--;
    }
    printf("%+d",polinom1[n]+polinom2[n]);
    printf("\n");
    return 0;
}
*/

/*
-----Zadaca 13-----
#include <stdio.h>

int main(){
    int m, n, count=1;
    scanf("%d%d", &m, &n);
    int matrica[m][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            matrica[j][i]=count;
            count++;
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%3d ", matrica[i][j]);
        }
        printf("\n");
    }
    return 0;
}
*/

/*
-----Zadaca 14-----
*/
#include <stdio.h>

void print(int n, int i){
    if(i>=0){
        printf("%d ", n-i);
        print(n, i-1);
    }
}

void rekurzija(int n, int i){
    if(n!=i){
        print(n, i);
        printf("\n");
        rekurzija(n, i+1);
        if(i!=n-1){
            print(n, i);
            printf("\n");
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    rekurzija(n, 0);
    return 0;
}
