/*
-----Zadaca 1-----
#include <stdio.h>

int main()
{
    int num1, num2;
    scanf("%d%d", &num1, &num2);
    if(num1==num2)
        printf("Broevite se ednakvi\n");
    else if(num1>num2)
        printf("%d e pogolem od %d\n", num1, num2);
    else
        printf("%d e pogolem od %d\n", num2, num1);
    return 0;
}
*/

/*
-----Zadaca 2-----
#include <stdio.h>

int main(){
    int num1, num2;
    scanf("%d%d", &num1, &num2);
    if(num1%2==0)
        printf("%d e paren\n", num1);
    else
        printf("%d ne e paren\n", num1);
    if(num2%2==0)
        printf("%d e paren\n", num2);
    else
        printf("%d ne e paren\n", num2);
    return 0;
}
*/

/*
-----Zadaca 3-----
#include <stdio.h>

int main(){
    // Se pecatat ASCII vrednostite za site karakteri
    printf("b: %d\nc: %d\n0: %d\n1: %d\n2: %d\n$: %d\n*: %d\n+: %d\n/: %d\nspace: %d\n",'b', 'c', '0', '1', '2', '$', '*', '+', '/', ' ');
    return 0;
}
*/

/*
-----Zadaca 4-----
#include <stdio.h>

int main(){
    printf("Odgovorot e %d\n", 1.0/3.0); // dava kompajlerot greska deka %d ocekuva int vred a dobiva double vred
    return 0;
}
*/

/*
-----Zadaca 5-----
#include <stdio.h>

int main(){
    float radius;
    scanf("%f", &radius);
    printf("Perimetar: %f\n", 2 * radius * 3.14);
    printf("Plostina: %f\n", radius * radius * 3.14);
    return 0;
}
*/

/*
-----Zadaca 6-----
#include <stdio.h>

int main(){
    char bukvi[5];
    char *broevi[]={"prva", "vtora", "treta", "chetvrta", "petta"};
    for(int i=0; i<5; i++){
        scanf(" %c", &bukvi[i]);
    }
    for(int i=0; i<5; i++){
        printf("%s bukva: %c\n", broevi[i], bukvi[i]);
    }
    printf("Se dobi: %c%c%c%c%c\n", bukvi[4], bukvi[2], bukvi[1], bukvi[0], bukvi[3]);
    return 0;
}
*/

/*
-----Zadaca 7-----
#include <stdio.h>

int main(){
    float data[5];
    data[0] = 34.0;
    data[1] = 27.0;
    data[2] = 45.0;
    data[3] = 82.0;
    data[4] = 22.0;
    float total = data[0] + data[1] + data[2] + data[3] + data[4];
    float average = total / 5.0;
    printf("Vkupno %.3f Sredna vrednost %.3f\n", total, average);
    return 0;
}
*/

/*
-----Zadaca 8-----
#include <stdio.h>

int main(){
    int x=0;
    x++;
    ++x;
    x+=1;
    x=x+1;
    return 0;
}
*/
