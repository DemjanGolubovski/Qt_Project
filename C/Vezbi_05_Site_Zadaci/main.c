/*
-----Zadaca 1-----
#include <stdio.h>

int main()
{
    int sum;
    int number;
    for(number=2, sum=0; number<=100; sum+=number, number+=2);
    printf( "Sumata e %d\n", sum);
    return 0;
}
*/

/*
-----Zadaca 2-----
#include <stdio.h>
#include <math.h>

int main(){
    double amount;
    double principal = 1000.0;
    double rate = .05;
    int year;

    printf( "%4s%25s\n", "Godina", "Vrednost na depozitot" );
    for ( year = 1; year <= 10; year++ ) {
        amount = principal * pow( 1.0 + rate, year );
        printf( "%4d\t%-25.2f\n", year, amount );
       }
    return 0;
}
*/

/*
-----Zadaca 3-----
#include <stdio.h>
#include <math.h>

int main(){
    for(int a=1; a<=100; a++){
        for(int b=1; b<=100; b++){
            float c = sqrt(pow(a,2) + pow(b,2));
            if((int)c - c==0 && c<=100)
                printf("(a,b,c) = (%d,%d,%d)\n", a, b, (int)c);
        }
    }
    return 0;
}
*/

/*
-----Zadaca 4-----
#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);
    while(num!=0){
        if(num>=1000){
            printf("M");
            num-=1000;
        }
        else if(num>=900){
            printf("CM");
            num-=900;
        }
        else if(num>=500){
            printf("D");
            num-=500;
        }
        else if(num>=400){
            printf("CD");
            num-=400;
        }
        else if(num>=100){
            printf("C");
            num-=100;
        }
        else if(num>=90){
            printf("XD");
            num-=90;
        }
        else if(num>=50){
            printf("L");
            num-=50;
        }
        else if(num>=40){
            printf("XL");
            num-=40;
        }
        else if(num>=10){
            printf("X");
            num-=10;
        }
        else if(num>=9){
            printf("IX");
            num-=9;
        }
        else if(num>=5){
            printf("V");
            num-=5;
        }
        else if(num>=4){
            printf("IV");
            num-=4;
        }
        else{
            printf("I");
            num-=1;
        }
    }
    printf("\n");
    return 0;
}
*/

/*
-----Zadaca 5-----
*/
#include <stdio.h>

int main(){
    for(int i=1; i<=100 ; i++){
        if(i%3==0)
            printf("%d e deliv so 3\n", i);
        else
            continue;
    }
    return 0;
}
