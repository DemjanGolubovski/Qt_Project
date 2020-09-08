#include <iostream>
#include <cstring>
#include <cassert>
#include "SLL.h"
#include "Prodavnica.h"
using namespace std;

int main()
{
    SLL<Artikl> artikli;
    cout<<"0-Dodadi artikl"<<endl;
    cout<<"1-Prikazi artikl od dadena grupa"<<endl;
    cout<<"2-Prikazi gi site artikli"<<endl;
    cout<<"3-Prikazi site artikli koi treba da se nabavat"<<endl;
    cout<<"4-END"<<endl;
    int choice;
    cin>>choice;
    while(choice!=4){
        switch (choice) {
        case 0:
        {
            int insArtikl;
            cout<<"0-vnesi pantaloni\n1-Vnesi kosula"<<endl;
            cin>>insArtikl;
            char *ime, *golemina;
            int cena;
            ime=new char[30];
            assert(ime!=0);
            golemina=new char[30];
            assert(golemina!=0);
            if(insArtikl==0){
                int den_d, mesec_d, godina_d, den_n, mesec_n, godina_n;
                cout<<"Vnesi ime, golemin, cena, datum koga e donesen(den mesec godina), datum za nov da se nabavi"<<endl;
                cin>>ime>>golemina>>cena>>den_d>>mesec_d>>godina_d>>den_n>>mesec_n>>godina_n;
                Datum *datumDoneseno=new Datum(den_d, mesec_d, godina_d);
                Datum *datumNabavka=new Datum(den_n, mesec_n, godina_n);
                Pantaloni *p=new Pantaloni(ime, golemina, cena, *datumDoneseno, *datumNabavka);
                artikli.setLast(p);
                delete datumNabavka;
                delete datumDoneseno;
            }
            else if(insArtikl==1){
                int den_d, mesec_d, godina_d;
                cout<<"Vnesi ime, golemin, cena, datum koga e donesen(den mesec godina), datum za nov da se nabavi"<<endl;
                cin>>ime>>golemina>>cena>>den_d>>mesec_d>>godina_d;
                Datum *datumDoneseno=new Datum(den_d, mesec_d, godina_d);
                Kosuli *k=new Kosuli(ime, golemina, cena, *datumDoneseno);
                artikli.setLast(k);
                delete datumDoneseno;
            }
            else{
                cout<<"Invalid choice"<<endl;
            }
            delete [] ime;
            delete [] golemina;
            break;
        }
        case 1:
        {
            int chose;
            cout<<"0-Prikazi site pantaloni\n1-Prikazi site kosuli"<<endl;
            cin>>chose;
            if(chose==0){ // pantaloni
                SLLNode<Artikl> *f=artikli.getFirst();
                while(f!=NULL){
                    Pantaloni *p=dynamic_cast<Pantaloni *>(f->getData());
                    if(p!=0)
                        p->prikazi_podatoci();
                    f=f->getNext();
                }
            }
            else if(chose==1){
                SLLNode<Artikl> *f=artikli.getFirst();
                while(f!=NULL){
                    Kosuli *k=dynamic_cast<Kosuli *>(f->getData());
                    if(k!=0){
                        k->prikazi_podatoci();
                        cout<<endl;
                    }
                    f=f->getNext();
                }
            }
            else{
                cout<<"Invalid choice"<<endl;
            }
            break;
        }
        case 2:
        {
            SLLNode<Artikl> *f=artikli.getFirst();
            while(f!=NULL){
                f->getData()->prikazi_podatoci();
                cout<<endl;
                f=f->getNext();
            }
            break;
        }
        case 3:
        {
            SLLNode<Artikl> *f=artikli.getFirst();
            int flag=0, suma=0;;
            cout<<"Vnesi denesen datum(den mesec godina)"<<endl;
            int den, mesec, godina;
            cin>>den>>mesec>>godina;
            Datum *d=new Datum(den, mesec, godina);
            cout<<"Treba da se nabavat slednite artikli:"<<endl;
            while(f!=NULL){
                flag=f->getData()->presmetaj_nabavka(*d);
                if(flag!=-1){
                    f->getData()->prikazi_podatoci();
                    cout<<endl;
                    suma+=flag;
                }
                f=f->getNext();
            }
            cout<<"Vkupno kje kosta: "<<suma<<endl;
            delete d;
            break;
        }
        default:
            break;
        }
        cin>>choice;
    }
    return 0;
}
