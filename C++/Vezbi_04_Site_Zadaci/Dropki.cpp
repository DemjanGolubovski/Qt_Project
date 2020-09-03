#include <iostream>
#include "Dropki.h"

using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
       return b;
    if (b == 0)
       return a;

    if (a == b)
        return a;

    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

Dropki::Dropki(int br, int ime){
    if(ime!=0){
        broitel=br;
        imenitel=ime;
    }else{
        cout<<"Ne validna vrednost za imenitel"<<endl;
        broitel=-1;
        imenitel=-1;
    }
}
int Dropki::get_broitel(){
    return broitel;
}
int Dropki::get_imenitel(){
    return imenitel;
}
void Dropki::print(){
    cout<<broitel<<"/"<<imenitel<<endl;
}
void Dropki::print_realNumber(){
    cout<<"Real number: "<<(float)broitel/imenitel<<endl;
}
void Dropki::mnozenje(Dropki d){
    imenitel=imenitel*d.get_imenitel();
    broitel=broitel*d.get_broitel();
    int gcd_num=gcd(broitel, imenitel);
    imenitel=imenitel/gcd_num;
    broitel=broitel/gcd_num;
}
void Dropki::delenje(Dropki d){
    imenitel=imenitel*d.get_broitel();
    broitel=broitel*d.get_imenitel();
    int gcd_num=gcd(broitel, imenitel);
    imenitel=imenitel/gcd_num;
    broitel=broitel/gcd_num;
}
void Dropki::sobiranje(Dropki d){
    broitel=broitel*d.get_imenitel() + d.get_broitel()*imenitel;
    imenitel=imenitel*d.get_imenitel();
    int gcd_num=gcd(broitel, imenitel);
    imenitel=imenitel/gcd_num;
    broitel=broitel/gcd_num;
}
void Dropki::odzemanje(Dropki d){
    broitel=broitel*d.get_imenitel() - d.get_broitel()*imenitel;
    imenitel=imenitel*d.get_imenitel();
    int gcd_num=gcd(broitel, imenitel);
    imenitel=imenitel/gcd_num;
    broitel=broitel/gcd_num;
}
