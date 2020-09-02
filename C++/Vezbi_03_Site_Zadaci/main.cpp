/*
-----Zadaca 1-----
#include <iostream>

using namespace std;

class Kvadar{
    int dolzina, sirina, visina;
public:
    int plostina();
    int volumen();
    void setDimenzii(int dolzina, int sirina, int visina);
    void printDimenzii();
    int najmalaPlostina();
};

int Kvadar::plostina(){
    return 2*(sirina*visina + sirina*dolzina + dolzina*visina);
}
int Kvadar::volumen(){
    return visina*sirina*dolzina;
}
void Kvadar::setDimenzii(int dolzina, int sirina, int visina){
    this->dolzina=dolzina;
    this->sirina=sirina;
    this->visina=visina;
}
void Kvadar::printDimenzii(){
    cout<<"Visina: "<<visina<<" Dolzina: "<<dolzina<<" Sirina: "<<sirina<<endl;
}
int Kvadar::najmalaPlostina(){
    if(visina!=sirina || visina!=dolzina || dolzina!=sirina){
        return this->plostina();
    }
    return -1;
}

int main()
{
    int n;
    cout<<"Broj na objekti"<<endl;
    cin>>n;
    Kvadar niza[n];
    int index=0;
    cout<<"1-Postavi gi dimenziite"<<endl;
    cout<<"2-Pecati gi dimenziite na site objekti"<<endl;
    cout<<"3-Pecati gi dimenziite na eden objekt"<<endl;
    cout<<"4-Objekt so najmala plostina, a ne e kocka"<<endl;
    cout<<"5-END"<<endl;
    int choice;
    int broj;
    cin>>choice;
    while(choice!=5){
        switch (choice) {
        case 1:
        {
            if(index<n){
            cout<<"Vnesi dolzina, sirina, visina"<<endl;
            int dolzina, sirina, visina;
            cin>>dolzina>>sirina>>visina;
            niza[index].setDimenzii(dolzina, sirina, visina);
            index++;
            }
            else
                cout<<"Invalid input"<<endl;
            break;
        }
        case 2:
        {
            for(int i=0; i<index; i++){
                niza[i].printDimenzii();
            }
            break;
        }
        case 3:
        {
            cout<<"Vnesi indeks:"<<endl;
            cin>>broj;
            if(broj<index && broj>=0)
                niza[broj].printDimenzii();
            else
                cout<<"Invalid input"<<endl;
            break;
        }
        case 4:
        {
            int min=niza[0].najmalaPlostina();
            for(int i=1; i<index; i++){
                if(min==-1 || niza[i].najmalaPlostina()<min)
                    min=niza[i].najmalaPlostina();
            }
            if(min!=-1)
                cout<<"Min plostina: "<<min<<endl;
            else
                cout<<"No such object"<<endl;
            break;
        }
        default:
            break;
        }
        cin>>choice;
    }
    return 0;
}
*/

/*
-----Zadaca 2-----
#include <iostream>
#include <cstring>

using namespace std;

class Stedac{
public:
    void vnesi_podatoci(int broj, char imeprezime[], char adresa[], long saldo);
    void prikazi_podatoci();
    void uplata(unsigned long i);
    void isplata(unsigned long i);
    long sostojba();

  private:
    int broj;
    char imeprezime[30], adresa[50];
    long saldo;
};

void Stedac::vnesi_podatoci(int br, char name[], char addr[], long sum){
    broj=br;
    strcpy(imeprezime, name);
    strcpy(adresa, addr);
    saldo=sum;
}
void Stedac::prikazi_podatoci(){
    cout<<"Broj: "<<broj<<" Ime i prezime: "<<imeprezime<<" Adresa: "<<adresa<<" Saldno: "<<saldo<<endl;
}
void Stedac::uplata(unsigned long i){
    saldo+=i;
}
void Stedac::isplata(unsigned long i){
    if(saldo>=i)
        saldo-=i;
    else
        cout<<"Not enough money"<<endl;
}
long Stedac::sostojba(){
    return saldo;
}


int main(){
    int n;
    cout<<"Maksimalen broj na stedaci"<<endl;
    cin>>n;
    Stedac stedaci[n];
    cout<<"1-Kreiraj stedac"<<endl;
    cout<<"2-Prikazi podatoci"<<endl;
    cout<<"3-Uplata"<<endl;
    cout<<"4-Isplata"<<endl;
    cout<<"5-Sostojba"<<endl;
    cout<<"6-END"<<endl;
    int choice, index=0, broj;
    cin>>choice;
    while(choice!=6){
        switch (choice) {
        case 1:
        {
            if(index<n)
            {
                cout<<"Vnesi broj, imeprezime, adresa, saldo"<<endl;
                int broj;
                char imeprezime[30], adresa[50];
                long saldo;
                cin>>broj;
                cin>>imeprezime;
                cin>>adresa;
                cin>>saldo;
                stedaci[index].vnesi_podatoci(broj, imeprezime, adresa, saldo);
                index++;
            }
            else
                cout<<"Invalid index"<<endl;
            break;
        }
        case 2:
        {
            cout<<"Vnesi broj na index"<<endl;
            cin>>broj;
            if(broj<index && broj>=0)
            {
                stedaci[broj].prikazi_podatoci();
            }
            else
                cout<<"Invalid index"<<endl;
            break;
        }
        case 3:
        {
            cout<<"Vnesi broj na index"<<endl;
            cin>>broj;
            if(broj<index && broj>=0)
            {
                long suma;
                cout<<"Vnesi suma"<<endl;
                cin>>suma;
                stedaci[broj].uplata(suma);
            }
            else
                cout<<"Invalid index"<<endl;
            break;
        }
        case 4:
        {
            cout<<"Vnesi broj na index"<<endl;
            cin>>broj;
            if(broj<index && broj>=0)
            {
                long suma;
                cout<<"Vnesi suma"<<endl;
                cin>>suma;
                stedaci[broj].isplata(suma);
            }
            else
                cout<<"Invalid index"<<endl;
            break;
        }
        case 5:
        {
            cout<<"Vnesi broj na index"<<endl;
            cin>>broj;
            if(broj<index && broj>=0)
            {
                long suma;
                suma=stedaci[broj].sostojba();
                cout<<"Momentalna sostojba: "<<suma<<endl;
            }
            else
                cout<<"Invalid index"<<endl;
            break;
        }
        default:
            break;
        }
        cin>>choice;
    }
    return 0;
}
*/
