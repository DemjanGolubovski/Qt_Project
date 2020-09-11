/*
-----Zadaca 1-----
#include <iostream>

using namespace std;

template<class T>
T sum(T *niza, int start, int end,  T suma = T()) {
    for(int i=start; i<end; i++){
        suma+=niza[i];
    }
    return suma;
}

int main()
{
    int niza[10]={3, 5, 2, 1, 1, 1, 8, 6, 10, 10};
    cout<<"Sumata e "<< sum(niza, 1, 5)<<endl;

    float f_niza[5]={3.2, 1.55, 22.2, 5.1, 77.1};
    cout<<"Sumata e "<< sum(f_niza, 0, 3)<<endl;
    return 0;
}
*/

/*
-----Zadaca 2-----
#include <iostream>

using namespace std;

class Kvadrat{
    int strana;
public:
    Kvadrat(int strana=0){
        this->strana=strana;
    }
    int plostina(){return strana*strana;}
    void setStrana(int strana){this->strana=strana;}
    void print(){
        cout<<"Kvadrat so strana: "<<strana<<endl;
    }
};

class Pravoagolnik{
    int sirina, visina;
public:
    Pravoagolnik(int sirina=0, int visina=0){
        this->sirina=sirina;
        this->visina=visina;
    }
    int plostina(){return sirina*visina;}
    void setDimenzii(int sirina, int visina){
        this->sirina=sirina;
        this->visina=visina;
    }
    void print(){
        cout<<"Pravoagolnik so dimensii: "<<sirina<<" "<<visina<<endl;
    }
};
template<class T>
void pecatiPole(T niza[], int numElem){
    for(int i=0; i<numElem; i++){
        niza[i].print();
    }
}

template<class T>
void sortirajPole(T niza[], int numElem){
    for(int i=0; i<numElem; i++){
        for(int j=i+1; j<numElem; j++){
            if(niza[i].plostina()>niza[j].plostina()){
                T tmp=niza[i];
                niza[i]=niza[j];
                niza[j]=tmp;
            }
        }
    }
}

int main(){
    Kvadrat *kvadrati=new Kvadrat[5];
    int str;
    for(int i=0; i<5; i++){
        cin>>str;
        kvadrati[i].setStrana(str);
    }
    cout<<"Kvadrati"<<endl;
    cout<<"Ne sortirano:"<<endl;
    pecatiPole(kvadrati, 5);
    sortirajPole(kvadrati, 5);
    cout<<"Sortirano: "<<endl;
    pecatiPole(kvadrati, 5);

    Pravoagolnik *pravoagolnici=new Pravoagolnik[5];
    int sirina, visina;
    for(int i=0; i<5; i++){
        cin>>sirina>>visina;
        pravoagolnici[i].setDimenzii(sirina, visina);
    }
    cout<<"Pravoagolnici"<<endl;
    cout<<"Ne sortirano:"<<endl;
    pecatiPole(pravoagolnici, 5);
    sortirajPole(pravoagolnici, 5);
    cout<<"Sortirano: "<<endl;
    pecatiPole(pravoagolnici, 5);

    delete [] kvadrati;
    delete [] pravoagolnici;
    return 0;
}
*/

/*
-----Zadaca 3-----
*/

#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdlib>

using namespace std;

template <class T> class Lice{
    char *imeiprezime, *adresa, *matbroj;
    int vozrast;
    T kod;
public:
    // constructor
    Lice(char *imeiprezime="", char *adresa="", char *matbroj="", int vozrast=0, T kod=0){
        this->vozrast=vozrast;
        this->kod=kod;

        this->imeiprezime=new char[strlen(imeiprezime) + 1];
        assert(this->imeiprezime!=0);
        strcpy(this->imeiprezime, imeiprezime);

        this->adresa=new char[strlen(adresa) + 1];
        assert(this->adresa!=0);
        strcpy(this->adresa, adresa);

        this->matbroj=new char[strlen(matbroj) + 1];
        assert(this->matbroj!=0);
        strcpy(this->matbroj, matbroj);
    }
    // copy constructor
    Lice(const Lice<T> &l){
        vozrast=l.vozrast;
        kod=l.kod;

        imeiprezime=new char[strlen(l.imeiprezime) + 1];
        assert(imeiprezime!=0);
        strcpy(imeiprezime, l.imeiprezime);

        adresa=new char[strlen(l.adresa) + 1];
        assert(adresa!=0);
        strcpy(adresa, l.adresa);

        matbroj=new char[strlen(l.matbroj) + 1];
        assert(matbroj!=0);
        strcpy(matbroj, l.matbroj);
    }
    // destructor
    ~Lice(){
        delete [] imeiprezime;
        delete [] adresa;
        delete [] matbroj;
    }
    Lice& operator=(const Lice<T> &l){
        if(this!=&l){
            delete [] imeiprezime;
            delete [] adresa;
            delete [] matbroj;

            vozrast=l.vozrast;
            kod=l.kod;

            imeiprezime=new char[strlen(l.imeiprezime) + 1];
            assert(imeiprezime!=0);
            strcpy(imeiprezime, l.imeiprezime);

            adresa=new char[strlen(l.adresa) + 1];
            assert(adresa!=0);
            strcpy(adresa, l.adresa);

            matbroj=new char[strlen(l.matbroj) + 1];
            assert(matbroj!=0);
            strcpy(matbroj, l.matbroj);
        }
        return *this;
    }
    void print(){
        cout<<"Ime i prezime: "<<imeiprezime<<", Maticen broj: "<<matbroj<<", Adresa: "<<adresa<<endl;
        cout<<"Vozrast: "<<vozrast<<", Kod: "<<kod<<endl;
    }
};

class Vraboten{
    int kod;
public:
    Vraboten(int kod=0){
        this->kod=kod;
    }
    friend ostream &operator<<(ostream &output, const Vraboten &v);
};
ostream &operator<<(ostream &output, const Vraboten &v){
    output<<v.kod;
    return output;
}

class Klient{
    char *kod;
public:
    // constructor
    Klient(char *kod=""){
        this->kod=new char[strlen(kod) + 1]; // Tuka nastanuva prekin, ne moze da alocira memorija
        assert(this->kod!=0);
        strcpy(this->kod, kod);
    }
    // copy constructor
    Klient(const Klient &k){
        kod=new char[strlen(k.kod) + 1];
        assert(kod!=0);
        strcpy(kod, k.kod);
    }
    // destructor
    ~Klient(){
        delete [] kod;
    }
    Klient& operator=(const Klient &k){
        if(this!=&k){
            delete [] kod;
            kod=new char[strlen(k.kod) + 1];
            assert(kod!=0);
            strcpy(kod, k.kod);
        }
        return *this;
    }
    friend ostream &operator<<(ostream &output, const Klient &k);
};
ostream &operator<<(ostream &output, const Klient &k){
    output<<k.kod;
    return output;
}

int main(){
    Lice<Vraboten> *vraboteni=new Lice<Vraboten>[3];
    char ime[50], adresa[50], matbroj[50];
    int vozrast, kod;
    for(int i=0; i<3; i++){
        cin>>ime>>adresa>>matbroj>>vozrast>>kod;
        Vraboten v(kod);
        Lice<Vraboten> tmp(ime, adresa, matbroj, vozrast, v);
        vraboteni[i]=tmp;
    }
    for(int i=0; i<3; i++){
        vraboteni[i].print(); // cout<<vraboteni[i] javuvase greska koga imav preoptovareno operatorot <<
    }

    // nastanuva greshka kaj konstruktorot na Klient
//    Lice<Klient> *klienti=new Lice<Klient>[3];
//    char kod_c[50];
//    for(int i=0; i<3; i++){
//        cin>>ime>>adresa>>matbroj>>vozrast>>kod_c;
//        Klient k(kod_c);
//        Lice<Klient> tmp(ime, adresa, matbroj, vozrast, k);
//        klienti[i]=tmp;
//    }
//    for(int i=0; i<3; i++){
//        klienti[i].print();
//    }

    delete [] vraboteni;
//    delete [] klienti;
    return 0;
}
