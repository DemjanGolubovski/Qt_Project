#include <iostream>
#include <cstring>
#include <cassert>
#include "Stedac.h"

using namespace std;

float Stedac::kamata = 0.0;
int Stedac::brojStedaci = 0;

float Stedac::getKamata(){ return kamata; }
int Stedac::getStedaci(){ return brojStedaci; }
void Stedac::setKamata(float cashKamata){ kamata=cashKamata; }

Covek::Covek(char *name, char *lastN, char *add, char *tel){
    setIme(name);
    setPrezime(lastN);
    setAddresa(add);
    setTel(tel);
}
Covek::~Covek(){
    delete [] ime;
    delete [] prezime;
}
void Covek::setIme(char *name){
    ime=new char[strlen(name) + 1];
    assert(ime!=0);
    strcpy(ime, name);
}
void Covek::setPrezime(char *lastN){
    prezime=new char[strlen(lastN) + 1];
    assert(prezime!=0);
    strcpy(prezime, lastN);
}
void Covek::setAddresa(char *add){
    adresa=new char[strlen(add) + 1];
    assert(adresa!=0);
    strcpy(adresa, add);
}
void Covek::setTel(char *tel){
    telefon=new char[strlen(tel) + 1];
    assert(telefon!=0);
    strcpy(telefon, tel);
}
char* Covek::getTel() const{
    return telefon;
}
char* Covek::getIme() const{
    return ime;
}
char* Covek::getPrezime() const{
    return prezime;
}
char* Covek::getAdresa() const{
    return adresa;
}

Stedac::Stedac(char *name, char *lastN, char *add, char *tel, int bil, int kred): lice(name, lastN, add, tel){
    bilans=bil;
    kredit=kred;
    brojStedaci++;
}
Stedac::~Stedac(){
    brojStedaci--;
}
void Stedac::setKredit(int kred){
    kredit=kred;
}
void Stedac::setBilans(int bil){
    bilans=bil;
}
void Stedac::setLice(Covek c){
    lice=c;
}
int Stedac::getKredit() const{
    return kredit;
}
int Stedac::getBilans() const{
    return bilans;
}
Covek Stedac::getLice() const{
    return lice;
}
