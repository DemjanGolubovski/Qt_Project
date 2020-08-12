/*
-----Zadaca 1-----
#include <stdio.h>

int main()
{
    int fahrenheit;
    scanf("%d", &fahrenheit);
    float celsius = 5.0/9.0 * (fahrenheit - 32);
    printf("Fahrenheit:\tCelsius:\n");
    printf("%10d%+10.3f\n",fahrenheit, celsius);
    return 0;
}
*/

/*
-----Zadaca 2-----
*/
#include <stdio.h>

int main(){
    char *meseci[]={"Januari", "Fevruari", "Mart", "April", "Maj", "Juni", "Juli", "Avgust", "Septemvri", "Oktomvri", "Noemvri", "Dekemvri"};
    int den, mesec, godina;
    printf("Vnesi datum: ");
    scanf("%d%*c%d%*c%d",  &godina, &mesec, &den);
    printf("%d",den);
    printf("Vneseniot datum e: %d %s %d godina\n", den, meseci[mesec-1], godina);
    return 0;
}
