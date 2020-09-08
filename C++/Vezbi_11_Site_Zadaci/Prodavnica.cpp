#include <iostream>
#include <cassert>
#include <cstring>
#include "Prodavnica.h"

using namespace std;

Datum::Datum(int den, int mesec, int godina){
    this->den=den;
    this->mesec=mesec;
    this->godina=godina;
}
void Datum::setDen(const int den){
    this->den=den;
}
void Datum::setMesec(const int mesec){
    this->mesec=mesec;
}
void Datum::setGodina(const int godina){
    this->godina=godina;
}
int Datum::getDen() const{
    return den;
}
int Datum::getMesec() const{
    return mesec;
}
int Datum::getGodina() const{
    return godina;
}
ostream &operator<<(ostream &output, const Datum &d){
    output<<d.den<<"/"<<d.mesec<<"/"<<d.getGodina();
    return output;
}

Artikl::Artikl(char *ime, char *golemina, int cena, Datum datum_donesen){
    this->ime=new char[strlen(ime) + 1];
    assert(this->ime!=0);
    strcpy(this->ime, ime);
    this->golemina=new char[strlen(golemina) + 1];
    assert(this->golemina!=0);
    strcpy(this->golemina, golemina);
    this->cena=cena;
    this->datum_donesen=datum_donesen;
}
Artikl::~Artikl(){
    delete [] ime;
    delete [] golemina;
}
void Artikl::prikazi_podatoci() const{
    cout<<"Ime: "<<ime<<", Golemina: "<<golemina<<", Cena: "<<cena<<", Datum koga e doneseno: "<<datum_donesen;
}

Pantaloni::Pantaloni(char *ime, char *golemina, int cena, Datum datum_donesen, Datum datum_sledna_nabavka)
    :Artikl(ime, golemina, cena, datum_donesen){
    this->datum_sledna_nabavka=datum_sledna_nabavka;
}
void Pantaloni::prikazi_podatoci() const{
    cout<<"Pantaloni:"<<endl;
    Artikl::prikazi_podatoci();
    cout<<", Datum na sledna nabavka: "<<datum_sledna_nabavka;
}
int Pantaloni::presmetaj_nabavka(Datum currDate){
    int targetDen, targetMesec, targetGodina;
    targetDen=currDate.getDen();
    if(currDate.getMesec()+1>12){
        targetMesec=1;
        targetGodina=currDate.getGodina()+1;
    }
    else{
        targetMesec=currDate.getMesec()+1;
        targetGodina=currDate.getGodina();
    }
    if(targetDen==datum_sledna_nabavka.getDen() && targetMesec==datum_sledna_nabavka.getMesec() && targetGodina==datum_sledna_nabavka.getGodina())
        return cena;
    else
        return -1;
}

Kosuli::Kosuli(char *ime, char *golemina, int cena, Datum datum_donesen):Artikl(ime, golemina, cena, datum_donesen){}
void Kosuli::prikazi_podatoci() const{
    cout<<"Kosuli:"<<endl;
    Artikl::prikazi_podatoci();
}
int Kosuli::presmetaj_nabavka(Datum currDate){
    return -1;
}
