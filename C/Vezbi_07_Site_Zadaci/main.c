/*
-----Zadaca 1-----
#include <stdio.h>

int paren(int num){
    if(num%2==0)
        return 1;
    return 0;
}

int main()
{
    int num;
    for(int i=0; i<10; i++){
        scanf("%d", &num);
        printf("%d", paren(num));
    }
    return 0;
}
*/

/*
-----Zadaca 2-----
#include <stdio.h>

int vreme(int hour, int min, int sec){
    return 12*60*60 - hour*60*60 - min*60 - sec;
}

int main(){
    int hour, min, sec;
    scanf("%d%d%d", &hour, &min, &sec);
    printf("%d sec\n", vreme(hour, min, sec));
    return 0;
}
*/

/*
-----Zadaca 3-----
#include <stdio.h>

int obratno(int num){
    int newNum=0;
    while(num){
        newNum=newNum*10+num%10;
        num=num/10;
    }
    return newNum;
}

int main(){
    int num;
    scanf("%d", &num);
    printf("Orignialen broj: %d - Obraten broj: %d\n", num, obratno(num));
    return 0;
}
*/

/*
-----Zadaca 4 i Zadaca 6-----
#include <stdio.h>
// Evklidov algoritam
int nzd(int num1, int num2){
    if(num2==0)
        return num1;
    nzd(num2, num1%num2);
}

int main(){
    int num1, num2;
    scanf("%d%d", &num1, &num2);
    printf("%d\n", nzd(num1, num2));
    return 0;
}
*/

/*
-----Zadaca 5-----
#include <stdio.h>
// range = kolku broevi da se ispecatat ako range = 5 kje se dobie 1 1 2 3 5
void fibonaci(int range){
    int num1=1, num2=1;
    if(range==1){
        printf("1\n");
    }
    else if(range==2){
        printf("1 1\n");
    }
    else{
        printf("1 1 ");
        for(int i=0; i<range-2; i++){
            int tmp=num2;
            num2=num2+num1;
            num1=tmp;
            printf("%d ", num2);
        }
    }
    printf("\n");
}

int main(){
    int range;
    scanf("%d", &range);
    fibonaci(range);
    return 0;
}
*/

/*
-----Zadaca 7-----
*/
#include <stdio.h>

void dzvezdi(int n){
    if(n==0)
        return;
    for(int i=0; i<n; i++)
        printf("*");
    printf("\n");
    dzvezdi(n-1);
}

int main(){
    int n;
    scanf("%d", &n);
    dzvezdi(n);
    return 0;
}
