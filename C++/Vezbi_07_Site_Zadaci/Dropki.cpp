#include <iostream>
#include <cmath>
#include "Dropki.h"

using namespace std;

int gcd(int a, int b)
{
    a=abs(a);
    b=abs(b);
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
void Dropki::print(){
    cout<<broitel<<"/"<<imenitel<<endl;
}
void Dropki::print_realNumber(){
    cout<<"Real number: "<<(float)broitel/imenitel<<endl;
}
Dropki Dropki::operator*(Dropki &d){
    Dropki tmpObj;
    tmpObj.imenitel=imenitel*d.imenitel;
    tmpObj.broitel=broitel*d.broitel;
    int gcd_num=gcd(tmpObj.broitel, tmpObj.imenitel);
    tmpObj.imenitel=tmpObj.imenitel/gcd_num;
    tmpObj.broitel=tmpObj.broitel/gcd_num;
    return tmpObj;
}
Dropki Dropki::operator*(int broj){
    Dropki tmpObj;
    tmpObj.imenitel=imenitel;
    tmpObj.broitel=broitel*broj;
    int gcd_num=gcd(tmpObj.broitel, tmpObj.imenitel);
    tmpObj.imenitel=tmpObj.imenitel/gcd_num;
    tmpObj.broitel=tmpObj.broitel/gcd_num;
    return tmpObj;
}
Dropki Dropki::operator/(Dropki &d){
    Dropki tmpObj;
    tmpObj.imenitel=imenitel*d.broitel;
    tmpObj.broitel=broitel*d.imenitel;
    int gcd_num=gcd(tmpObj.broitel, tmpObj.imenitel);
    tmpObj.imenitel=tmpObj.imenitel/gcd_num;
    tmpObj.broitel=tmpObj.broitel/gcd_num;
    return tmpObj;
}
Dropki Dropki::operator/(int broj){
    Dropki tmpObj;
    tmpObj.imenitel=imenitel*broj;
    tmpObj.broitel=broitel;
    int gcd_num=gcd(tmpObj.broitel, tmpObj.imenitel);
    tmpObj.imenitel=tmpObj.imenitel/gcd_num;
    tmpObj.broitel=tmpObj.broitel/gcd_num;
    return tmpObj;
}
Dropki Dropki::operator+(Dropki &d){
    Dropki tmpObj;
    tmpObj.broitel=broitel*d.imenitel + d.broitel*imenitel;
    tmpObj.imenitel=imenitel*d.imenitel;
    int gcd_num=gcd(tmpObj.broitel, tmpObj.imenitel);
    tmpObj.imenitel=tmpObj.imenitel/gcd_num;
    tmpObj.broitel=tmpObj.broitel/gcd_num;
    return tmpObj;
}
Dropki Dropki::operator+(int broj){
    Dropki tmpObj;
    tmpObj.broitel=broitel + broj*imenitel;
    tmpObj.imenitel=imenitel;
    int gcd_num=gcd(tmpObj.broitel, tmpObj.imenitel);
    tmpObj.imenitel=tmpObj.imenitel/gcd_num;
    tmpObj.broitel=tmpObj.broitel/gcd_num;
    return tmpObj;
}
Dropki Dropki::operator-(Dropki &d){
    Dropki tmpObj;
    tmpObj.broitel=broitel*d.imenitel - d.broitel*imenitel;
    tmpObj.imenitel=imenitel*d.imenitel;
    int gcd_num=gcd(tmpObj.broitel, tmpObj.imenitel);
    tmpObj.imenitel=tmpObj.imenitel/gcd_num;
    tmpObj.broitel=tmpObj.broitel/gcd_num;
    return tmpObj;
}
Dropki Dropki::operator-(int broj){
    Dropki tmpObj;
    tmpObj.broitel=broitel - broj*imenitel;
    tmpObj.imenitel=imenitel;
    int gcd_num=gcd(tmpObj.broitel, tmpObj.imenitel);
    tmpObj.imenitel=tmpObj.imenitel/gcd_num;
    tmpObj.broitel=tmpObj.broitel/gcd_num;
    return tmpObj;
}
