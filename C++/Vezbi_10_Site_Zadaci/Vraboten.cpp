#include <iostream>
#include <cstring>
#include <cassert>
#include "Vraboten.h"

using namespace std;

Vraboten::Vraboten(char *name, char *lastN, int year){
    ime=new char[strlen(name) + 1];
    assert(ime!=0);
    strcpy(ime, name);
    prezime=new char[strlen(lastN) + 1];
    assert(prezime!=0);
    strcpy(prezime, lastN);
    godina_vrabotuvanje=year;
}
Vraboten::~Vraboten(){
    delete [] ime;
    delete [] prezime;
}
void Vraboten::postavi(char *name, char *lastN, int year){
    ime=new char[strlen(name) + 1];
    assert(ime!=0);
    strcpy(ime, name);
    prezime=new char[strlen(lastN) + 1];
    assert(prezime!=0);
    strcpy(prezime, lastN);
    godina_vrabotuvanje=year;
}
void Vraboten::prikazi_podatoci(){
    cout<<"Ime: "<<ime<<", Prezime: "<<prezime<<", Vraboten na: "<<godina_vrabotuvanje<<endl;
}
Profesor::Profesor(char *name, char *lastN, int year, char *job, char *field, int numSubj):Vraboten(name, lastN, year){
    zvanje=new char[strlen(job) + 1];
    assert(zvanje!=0);
    strcpy(zvanje, job);
    oblast=new char[strlen(field) + 1];
    assert(oblast!=0);
    strcpy(oblast, field);
    br_predmeti=numSubj;
}
Profesor::~Profesor(){
    delete [] zvanje;
    delete [] oblast;
}
void Profesor::postavi(char *name, char *lastN, int year, char *job, char *field, int numSubj){
    Vraboten::postavi(name, lastN, year);
    zvanje=new char[strlen(job) + 1];
    assert(zvanje!=0);
    strcpy(zvanje, job);
    oblast=new char[strlen(field) + 1];
    assert(oblast!=0);
    strcpy(oblast, field);
    br_predmeti=numSubj;
}
void Profesor::prikazi_podatoci(){
    cout<<"Profesor:"<<endl;
    Vraboten::prikazi_podatoci();
    cout<<"Zvanje: "<<zvanje<<", Oblast: "<<oblast<<", Br predmeti: "<<br_predmeti<<endl;
}
Asistent::Asistent(char *name, char *lastN, int year,
                   char *job, char *teach, int numSubj):Vraboten(name, lastN, year){
    zvanje=new char[strlen(job) + 1];
    assert(zvanje!=0);
    strcpy(zvanje, job);
    mentor=new char[strlen(teach) + 1];
    assert(mentor!=0);
    strcpy(mentor, teach);
    br_predmeti=numSubj;
}
Asistent::~Asistent(){
    delete [] zvanje;
    delete [] mentor;
}
void Asistent::postavi(char *name, char *lastN, int year, char *job, char *teach, int numSubj){
    Vraboten::postavi(name, lastN, year);
    zvanje=new char[strlen(job) + 1];
    assert(zvanje!=0);
    strcpy(zvanje, job);
    mentor=new char[strlen(teach) + 1];
    assert(mentor!=0);
    strcpy(mentor, teach);
    br_predmeti=numSubj;
}
void Asistent::prikazi_podatoci(){
    cout<<"Asistent:"<<endl;
    Vraboten::prikazi_podatoci();
    cout<<"Zvanje: "<<zvanje<<", Mentor: "<<mentor<<", Br predmeti: "<<br_predmeti<<endl;
}
Demonstrator::Demonstrator(char *name, char *lastN, int year, char *workHours):Vraboten(name, lastN, year){
    rabotno_vreme=new char[strlen(workHours) + 1];
    assert(rabotno_vreme!=0);
    strcpy(rabotno_vreme, workHours);
}
Demonstrator::~Demonstrator(){
    delete [] rabotno_vreme;
}
void Demonstrator::postavi(char *name, char *lastN, int year, char *workHours){
    Vraboten::postavi(name, lastN, year);
    rabotno_vreme=new char[strlen(workHours) + 1];
    assert(rabotno_vreme!=0);
    strcpy(rabotno_vreme, workHours);
}
void Demonstrator::prikazi_podatoci(){
    cout<<"Demonstrator:"<<endl;
    Vraboten::prikazi_podatoci();
    cout<<"Rabotno vreme: "<<rabotno_vreme<<endl;
}
