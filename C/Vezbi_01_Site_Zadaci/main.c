/*
-----Zadaca 1-----
a. scanf("%d", &vrednost);
b. printf("Proizvodot na %d i %d e %d\n", x, y, x*y);
c. sumaBroevi = prvBroj + vtorBroj;*/
/* d. Programata naogja maksimum od dva broja */
// e. scanf("%d", &nekojBroj);

/*
-----Zadaca 2-----
#include <stdio.h>

int main()
{
    int num1, num2, num3, num4;
    scanf("%d%d%d%d", &num1, &num2, &num3, &num4);
    printf("Suma %d\n", num1 + num2 + num3 + num4);
    return 0;
}
*/

/*
-----Zadaca 3-----
#include <stdio.h>

int main(){
    // a.
    printf("1 2 3 4\n");
    // b.
    printf("%d %d %d %d\n", 1,2,3,4);
    // c.
    printf("1 ");
    printf("2 ");
    printf("3 ");
    printf("4\n");
    return 0;
}
*/

/*
-----Zadaca 4-----
#include <stdio.h>

int main(){
    int num1, num2, num3;
    scanf("%d%d%d", &num1, &num2, &num3);
    printf("Celobrojna sredna vrednost: %d\n", (num1 + num2 + num3)/3);
    printf("Proizvod: %d\n", num1 * num2 * num3);
    printf("Suma: %d\n", num1 + num2 + num3);
    return 0;
}
*/

/*
-----Zadaca 5-----
#include <stdio.h>

int main(){
    // a.
    for(int i=0; i<7; i++){
        if(i==0 || i==6)
            printf("*****\n");
        else
            printf("*   *\n");
    }
    // b.
    for(int i=0; i<7; i++){
        if(i==0 || i==6)
            printf("  ***  \n");
        else if(i==1 || i==5)
            printf(" *   * \n");
        else
            printf("*     *\n");
    }
    // c.
    for(int i=0; i<7; i++){
        if(i!=1 && i!=2)
            printf("   *   \n");
        else if(i==1)
            printf("  ***  \n");
        else
            printf("*******\n");
    }
    // d.
    printf("   *   \n"
           "  * *  \n"
           " *   * \n"
           "*     *\n"
           " *   * \n"
           "  * *  \n"
           "   *   \n");
    return 0;
}
*/

#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);
    int dig1 = num/10000;
    if(dig1==0){
        printf("Ne validen vlez");
        return 0;
    }
    else{
        int dig2 = (num/1000)%10;
        int dig3 = (num/100)%10;
        int dig4 = (num/10)%10;
        int dig5 = num%10;
        printf("%-4d%-4d%-4d%-4d%d\n", dig1, dig2, dig3, dig4, dig5);
    }
    return 0;
}
