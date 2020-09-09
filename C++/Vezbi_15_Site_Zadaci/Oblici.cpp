#include <iostream>
#include "Oblici.h"
#include "SLL.h"

using namespace std;

float Oblik::plostina(){return 0.0;}
float Oblik::volumen(){return 0.0;}
Oblik::~Oblik(){}

void DvoDimenzionalni::print(){
    cout<<"2D oblik"<<endl;
}

void TroDimenzionalni::print(){
    cout<<"3D oblik"<<endl;
}

Krug::Krug(float radius){
    this->radius=radius;
}
void Krug::print(){
    DvoDimenzionalni::print();
    cout<<"Krug so radius "<<radius<<endl;
}
float Krug::plostina(){
    return radius*radius*3.14;
}

Kvadrat::Kvadrat(float strana){
    this->strana=strana;
}
void Kvadrat::print(){
    DvoDimenzionalni::print();
    cout<<"Kvadrat so strana "<<strana<<endl;
}
float Kvadrat::plostina(){
    return strana*strana;
}

Triagolni::Triagolni(float visina, float strana){
    this->visina=visina;
    this->strana=strana;
}
void Triagolni::print(){
    DvoDimenzionalni::print();
    cout<<"Triagolni so strana "<<strana<<" i visina "<<visina<<endl;
}
float Triagolni::plostina(){
    return (strana*visina)/2;
}

Topka::Topka(float radius){
    this->radius=radius;
}
void Topka::print(){
    TroDimenzionalni::print();
    cout<<"Topka so radius "<<radius<<endl;
}
float Topka::plostina(){
    return 4*3.14*radius*radius;
}
float Topka::volumen(){
    return (4*3.14*radius*radius*radius)/3;
}

Kocka::Kocka(float strana){
    this->strana=strana;
}
void Kocka::print(){
    TroDimenzionalni::print();
    cout<<"Kocka so strana "<<strana<<endl;
}
float Kocka::plostina(){
    return 6*strana*strana;
}
float Kocka::volumen(){
    return strana*strana*strana;
}

Cilindar::Cilindar(float visina, float radius){
    this->visina=visina;
    this->radius=radius;
}
void Cilindar::print(){
    TroDimenzionalni::print();
    cout<<"Cilindar so radius "<<radius<<" i so visina "<<visina<<endl;
}
float Cilindar::plostina(){
    return 2*3.14*radius*visina + 2*3.14*radius*radius;
}
float Cilindar::volumen(){
    return 3.14*radius*radius*visina;
}
