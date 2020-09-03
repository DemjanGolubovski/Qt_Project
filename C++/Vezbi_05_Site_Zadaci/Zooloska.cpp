#include <iostream>
#include <cstring>
#include "Zooloska.h"

using namespace std;

Datum::Datum(int d, int m, int g){
    den=d;
    mesec=m;
    godina=g;
}
int Datum::get_den(){
    return den;
}
int Datum::get_mesec(){
    return mesec;
}
int Datum::get_godina(){
    return godina;
}
void Datum::set_den(int d){
    den=d;
}
void Datum::set_mesec(int m){
    mesec=m;
}
void Datum::set_godina(int g){
    godina=g;
}
Zivotno::Zivotno(int dr_den, int dr_mesec, int dr_godina, int dz_den, int dz_mesec, int dz_godina,
                 int dv_den, int dv_mesec, int dv_godina, char t, char p, char *i):datum_ragjanje(dr_den, dr_mesec, dr_godina),
                datum_doneseno_vo_zooloska(dz_den, dz_mesec, dz_godina), datum_vakcina(dv_den, dv_mesec, dv_godina){
    tip=t;
    pol=p;
    strcpy(ime, i);
}
void Zivotno::setObjekt(int dr_den, int dr_mesec, int dr_godina, int dz_den, int dz_mesec, int dz_godina,
                        int dv_den, int dv_mesec, int dv_godina, char t, char p, char *i){
    tip=t;
    pol=p;
    strcpy(ime, i);
    datum_vakcina.set_den(dv_den);
    datum_vakcina.set_mesec(dv_mesec);
    datum_vakcina.set_godina(dv_godina);
    datum_ragjanje.set_den(dr_den);
    datum_ragjanje.set_mesec(dr_mesec);
    datum_ragjanje.set_godina(dr_godina);
    datum_doneseno_vo_zooloska.set_den(dz_den);
    datum_doneseno_vo_zooloska.set_mesec(dz_mesec);
    datum_doneseno_vo_zooloska.set_godina(dz_godina);
}
void Zivotno::prikazi_podatoci(){
    cout<<".........."<<endl;
    cout<<"Ime: "<<ime<<endl;
    cout<<"Pol: "<<pol<<endl;
    cout<<"Tip: "<<tip<<endl;
    cout<<"Datum na ragjanje: "<<datum_ragjanje.get_den()<<"/"<<datum_ragjanje.get_mesec()<<"/"<<datum_ragjanje.get_godina()<<endl;
    cout<<"Datum koga e doneseno vo zooloska: "<<datum_doneseno_vo_zooloska.get_den()<<"/"<<datum_doneseno_vo_zooloska.get_mesec()<<"/"
       <<datum_doneseno_vo_zooloska.get_godina()<<endl;
    cout<<"Datum na posledna vakcinacija: "<<datum_vakcina.get_den()<<"/"<<datum_vakcina.get_mesec()<<"/"<<datum_vakcina.get_godina()<<endl;
}
char Zivotno::getTip(){
    return tip;
}
void Zivotno::presmetaj_vakcinacija(Datum currDate){
    int target_den, target_mesec, target_godina;
    if(currDate.get_mesec()==2 && (((currDate.get_godina() % 4 == 0) && (currDate.get_godina() % 100 != 0)) || (currDate.get_godina() % 400 == 0))){
        int denovi[12]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(currDate.get_den()+7>denovi[currDate.get_mesec()-1]){
            if(currDate.get_mesec()+1>12){
                target_den=currDate.get_den()+7-denovi[currDate.get_mesec()-1];
                target_mesec=1;
                target_godina=currDate.get_godina()+1;
            }
            else{
                target_den=currDate.get_den()+7-denovi[currDate.get_mesec()-1];
                target_mesec=currDate.get_mesec()+1;
                target_godina=currDate.get_godina();
            }
        }
        else{
                target_den=currDate.get_den()+7;
                target_mesec=currDate.get_mesec();
                target_godina=currDate.get_godina();
            }
    }
    else{
        int denovi[12]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(currDate.get_den()+7>denovi[currDate.get_mesec()-1]){
            if(currDate.get_mesec()+1>12){
                target_den=currDate.get_den()+7-denovi[currDate.get_mesec()-1];
                target_mesec=1;
                target_godina=currDate.get_godina()+1;
            }
            else{
                target_den=currDate.get_den()+7-denovi[currDate.get_mesec()-1];
                target_mesec=currDate.get_mesec()+1;
                target_godina=currDate.get_godina();
            }
        }
        else{
            target_den=currDate.get_den()+7;
            target_mesec=currDate.get_mesec();
            target_godina=currDate.get_godina();
        }
    }
    // cicaci na 1 godina
    if(tip=='c'){
        if(datum_vakcina.get_den()==target_den && datum_vakcina.get_mesec()==target_mesec && datum_vakcina.get_godina()+1==target_godina)
            cout<<ime<<" treba da se vakcinira za 7 dena"<<endl;
    }
    else if(tip=='v'){ // vlekaci na 6 meseci
        if(datum_vakcina.get_den()==target_den){
            if((datum_vakcina.get_mesec()+6)>12){
                if((datum_vakcina.get_mesec()+6-12)==target_mesec && (datum_vakcina.get_godina()+1)==target_godina)
                    cout<<ime<<" treba da se vakcinira za 7 dena"<<endl;
            }else{
                if((datum_vakcina.get_mesec()+6)==target_mesec && datum_vakcina.get_godina()==target_godina)
                    cout<<ime<<" treba da se vakcinira za 7 dena"<<endl;
            }
        }
    }
    else{ // ptici na 8 meseci
        if(datum_vakcina.get_den()==target_den){
            if((datum_vakcina.get_mesec()+8)>12){
                if((datum_vakcina.get_mesec()+8-12)==target_mesec && (datum_vakcina.get_godina()+1)==target_godina)
                    cout<<ime<<" treba da se vakcinira za 7 dena"<<endl;
            }else{
                if((datum_vakcina.get_mesec()+8)==target_mesec && datum_vakcina.get_godina()==target_godina)
                    cout<<ime<<" treba da se vakcinira za 7 dena"<<endl;
            }
        }
    }
}
