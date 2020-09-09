#include <iostream>
#include <cstring>
#include <cassert>
#include "Zooloska.h"

using namespace std;

int Zivotno::brZivotni=0;
int Cicaci::brCicaci=0;
int Vlekaci::brVlekaci=0;
int Ptici::brPtici=0;

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
ostream& operator<<(ostream &output, const Datum &date){
    output<<date.getDen()<<"/"<<date.getMesec()<<"/"<<date.getGodina();
    return output;
}

Zivotno::Zivotno(Datum datumRagjanje, Datum datumDoneseno, char pol, char *ime, Datum datumVakcinirano){
    this->datumRagjanje=datumRagjanje;
    this->datumDoneseno=datumDoneseno;
    this->pol=pol;
    this->ime=new char[strlen(ime) +1];
    assert(this->ime!=0);
    strcpy(this->ime, ime);
    this->datumVakcinirano=datumVakcinirano;
    brZivotni++;
}
int Zivotno::getBrZivotni(){
    return brZivotni;
}
Zivotno::~Zivotno(){
    delete [] ime;
}
void Zivotno::prikazi_podatoci(){
    cout<<"Ime: "<<ime<<", Pol: "<<pol<<endl;
    cout<<"Datum na ragjanje: "<<datumRagjanje<<", Datum doneseno vo zoo: "<<datumDoneseno<<", Datum na posledna vakcinacija: "<<datumVakcinirano;
}

Vlekaci::Vlekaci(Datum datumRagjanje, Datum datumDoneseno, char pol, char *ime, Datum datumVakcinirano,
                 Datum datumSlednaVakcinacija):Zivotno(datumRagjanje, datumDoneseno, pol, ime, datumVakcinirano){
    this->datumSlednaVakcinacija=datumSlednaVakcinacija;
    brVlekaci++;
}
int Vlekaci::getBrVlekaci(){
    return brVlekaci;
}
void Vlekaci::prikazi_podatoci(){
    Zivotno::prikazi_podatoci();
    cout<<", Datum na sledna vakcinacija: "<<datumSlednaVakcinacija;
}
int Vlekaci::presmetaj_vakcinacija(Datum currDate){
    int target_den, target_mesec, target_godina;
        if(currDate.getMesec()==2 && (((currDate.getGodina() % 4 == 0) && (currDate.getGodina() % 100 != 0)) || (currDate.getGodina() % 400 == 0))){
            int denovi[12]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if(currDate.getDen()+7>denovi[currDate.getMesec()-1]){
                if(currDate.getMesec()+1>12){
                    target_den=currDate.getDen()+7-denovi[currDate.getMesec()-1];
                    target_mesec=1;
                    target_godina=currDate.getGodina()+1;
                }
                else{
                    target_den=currDate.getDen()+7-denovi[currDate.getMesec()-1];
                    target_mesec=currDate.getMesec()+1;
                    target_godina=currDate.getGodina();
                }
            }
            else{
                    target_den=currDate.getDen()+7;
                    target_mesec=currDate.getMesec();
                    target_godina=currDate.getGodina();
                }
        }
        else{
            int denovi[12]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if(currDate.getDen()+7>denovi[currDate.getMesec()-1]){
                if(currDate.getMesec()+1>12){
                    target_den=currDate.getDen()+7-denovi[currDate.getMesec()-1];
                    target_mesec=1;
                    target_godina=currDate.getGodina()+1;
                }
                else{
                    target_den=currDate.getDen()+7-denovi[currDate.getMesec()-1];
                    target_mesec=currDate.getMesec()+1;
                    target_godina=currDate.getGodina();
                }
            }
            else{
                target_den=currDate.getDen()+7;
                target_mesec=currDate.getMesec();
                target_godina=currDate.getGodina();
            }
        }
        if(target_den==datumSlednaVakcinacija.getDen() && target_mesec==datumSlednaVakcinacija.getMesec() && target_godina==datumSlednaVakcinacija.getGodina())
            return 1;
        return -1;
}

Ptici::Ptici(Datum datumRagjanje, Datum datumDoneseno, char pol, char *ime, Datum datumVakcinirano,
             char letac):Zivotno(datumRagjanje, datumDoneseno, pol, ime, datumVakcinirano){
    this->letac=letac;
    brPtici++;
}
int Ptici::getBrPtici(){
    return brPtici;
}
void Ptici::prikazi_podatoci(){
    Zivotno::prikazi_podatoci();
    if(letac=='d')
        cout<<", leta";
    else
        cout<<", ne leta";
}
int Ptici::presmetaj_vakcinacija(Datum currDate){
    int target_den, target_mesec, target_godina;
        if(currDate.getMesec()==2 && (((currDate.getGodina() % 4 == 0) && (currDate.getGodina() % 100 != 0)) || (currDate.getGodina() % 400 == 0))){
            int denovi[12]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if(currDate.getDen()+7>denovi[currDate.getMesec()-1]){
                if(currDate.getMesec()+1>12){
                    target_den=currDate.getDen()+7-denovi[currDate.getMesec()-1];
                    target_mesec=1;
                    target_godina=currDate.getGodina()+1;
                }
                else{
                    target_den=currDate.getDen()+7-denovi[currDate.getMesec()-1];
                    target_mesec=currDate.getMesec()+1;
                    target_godina=currDate.getGodina();
                }
            }
            else{
                    target_den=currDate.getDen()+7;
                    target_mesec=currDate.getMesec();
                    target_godina=currDate.getGodina();
                }
        }
        else{
            int denovi[12]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if(currDate.getDen()+7>denovi[currDate.getMesec()-1]){
                if(currDate.getMesec()+1>12){
                    target_den=currDate.getDen()+7-denovi[currDate.getMesec()-1];
                    target_mesec=1;
                    target_godina=currDate.getGodina()+1;
                }
                else{
                    target_den=currDate.getDen()+7-denovi[currDate.getMesec()-1];
                    target_mesec=currDate.getMesec()+1;
                    target_godina=currDate.getGodina();
                }
            }
            else{
                target_den=currDate.getDen()+7;
                target_mesec=currDate.getMesec();
                target_godina=currDate.getGodina();
            }
        }

        if(datumVakcinirano.getMesec()+6>12){
            if(target_den==datumVakcinirano.getDen() && target_mesec==(datumVakcinirano.getMesec()-6) && target_godina==datumVakcinirano.getGodina()+1)
                return 1;
            return -1;
        }
        else{
            if(target_den==datumVakcinirano.getDen() && target_mesec==datumVakcinirano.getMesec()+6 && target_godina==datumVakcinirano.getGodina())
                return 1;
            return -1;
        }
}
Cicaci::Cicaci(Datum datumRagjanje, Datum datumDoneseno, char pol, char *ime, Datum datumVakcinirano,
               char prezivar):Zivotno(datumRagjanje, datumDoneseno, pol, ime, datumVakcinirano){
    this->prezivar=prezivar;
    brCicaci++;
}
int Cicaci::getBrCicaci(){
    return brCicaci;
}
void Cicaci::prikazi_podatoci(){
    Zivotno::prikazi_podatoci();
    if(prezivar=='d')
        cout<<", prezivar";
    else
        cout<<", ne e prezivar";
}
int Cicaci::presmetaj_vakcinacija(Datum currDate){
    int target_den, target_mesec, target_godina;
        if(currDate.getMesec()==2 && (((currDate.getGodina() % 4 == 0) && (currDate.getGodina() % 100 != 0)) || (currDate.getGodina() % 400 == 0))){
            int denovi[12]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if(currDate.getDen()+7>denovi[currDate.getMesec()-1]){
                if(currDate.getMesec()+1>12){
                    target_den=currDate.getDen()+7-denovi[currDate.getMesec()-1];
                    target_mesec=1;
                    target_godina=currDate.getGodina()+1;
                }
                else{
                    target_den=currDate.getDen()+7-denovi[currDate.getMesec()-1];
                    target_mesec=currDate.getMesec()+1;
                    target_godina=currDate.getGodina();
                }
            }
            else{
                    target_den=currDate.getDen()+7;
                    target_mesec=currDate.getMesec();
                    target_godina=currDate.getGodina();
                }
        }
        else{
            int denovi[12]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if(currDate.getDen()+7>denovi[currDate.getMesec()-1]){
                if(currDate.getMesec()+1>12){
                    target_den=currDate.getDen()+7-denovi[currDate.getMesec()-1];
                    target_mesec=1;
                    target_godina=currDate.getGodina()+1;
                }
                else{
                    target_den=currDate.getDen()+7-denovi[currDate.getMesec()-1];
                    target_mesec=currDate.getMesec()+1;
                    target_godina=currDate.getGodina();
                }
            }
            else{
                target_den=currDate.getDen()+7;
                target_mesec=currDate.getMesec();
                target_godina=currDate.getGodina();
            }
        }

        if(target_den==datumVakcinirano.getDen() && target_mesec==datumVakcinirano.getMesec() && target_godina==datumVakcinirano.getGodina()+1)
            return 1;
        return -1;
}
