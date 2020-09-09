#include <iostream>
#include <cassert>
#include "SLL.h"
#include "Zooloska.h"

using namespace std;

int main()
{
    SLL<Zivotno> zivotni;
    cout<<"0-Dodadi zivotno"<<endl;
    cout<<"1-Prikazi brojna sostojba"<<endl;
    cout<<"2-Prikazi zivotni od dadena grupa"<<endl;
    cout<<"3-Prikazi site zivotni"<<endl;
    cout<<"4-Prikazi zivotni koi treba da se vakciniraat za 1 nedela"<<endl;
    cout<<"5-END"<<endl;
    int choice;
    cin>>choice;
    while(choice!=5){
        switch (choice) {
        case 0:
        {
            cout<<"0-Vlekac\n1-Cicac\n2-Ptica"<<endl;
            int tip;
            cin>>tip;

            cout<<"Vnesi datum na ragjanje(den mesec godina), datum koga e doneseno, pol(m/z), ime, datum na vakcinacija"<<endl;
            int den_r, mesec_r, godina_r, den_d, mesec_d, godina_d, den_v, mesec_v, godina_v;
            char pol;
            char *ime;
            ime=new char[30];
            assert(ime!=0);
            cin>>den_r>>mesec_r>>godina_r>>den_d>>mesec_d>>godina_d>>pol>>ime>>den_v>>mesec_v>>godina_v;
            Datum *datumDoneseno=new Datum(den_d, mesec_d, godina_d);
            Datum *datumRodeno=new Datum(den_r, mesec_r, godina_r);
            Datum *datumVakcinacija=new Datum(den_v, mesec_v, godina_v);
            if(tip==0){
                cout<<"Vnesi datum na sledna vakcinacija"<<endl;
                int den_sv, mesec_sv, godina_sv;
                cin>>den_sv>>mesec_sv>>godina_sv;
                Datum *datumSlednaVakcina=new Datum(den_sv, mesec_sv, godina_sv);
                Vlekaci *v=new Vlekaci(*datumRodeno, *datumDoneseno, pol, ime, *datumVakcinacija, *datumSlednaVakcina);
                zivotni.setLast(v);
                delete datumSlednaVakcina;
            }
            else if(tip==1){
                cout<<"vnesi d(za prezivar) ili ne vo sprotivno"<<endl;
                char prezivar;
                cin>>prezivar;
                Cicaci *c=new Cicaci(*datumRodeno, *datumDoneseno, pol, ime, *datumVakcinacija, prezivar);
                zivotni.setLast(c);
            }
            else if(tip==2){
                char letac;
                cout<<"Vnesi d(deka leta) ili n(deka ne leta)"<<endl;
                cin>>letac;
                Ptici *p=new Ptici(*datumRodeno, *datumDoneseno, pol, ime, *datumVakcinacija, letac);
                zivotni.setLast(p);
            }
            else{
                cout<<"Invalid input"<<endl;
            }
            delete [] ime;
            delete datumRodeno;
            delete datumDoneseno;
            delete datumVakcinacija;
            break;
        }
        case 1:
        {
            cout<<"Vkupno ima "<<Zivotno::getBrZivotni()<<" zivotni"<<endl;
            cout<<"Vkupno ima "<<Cicaci::getBrCicaci()<<" cicaci"<<endl;
            cout<<"Vkupno ima "<<Ptici::getBrPtici()<<" ptici"<<endl;
            cout<<"Vkupno ima "<<Vlekaci::getBrVlekaci()<<" vlekaci"<<endl;
            break;
        }
        case 2:
        {
            cout<<"0-Cicaci\n1-Vlekaci\n2-Ptici"<<endl;
            int tip;
            cin>>tip;
            if(tip==0){
                cout<<"Cicaci:"<<endl;
                SLLNode<Zivotno> *f=zivotni.getFirst();
                while(f!=NULL){
                    Cicaci *c=dynamic_cast<Cicaci *>(f->getData());
                    if(c!=0)
                        c->prikazi_podatoci();
                    f=f->getNext();
                }
            }
            else if(tip==1){
                cout<<"Vlekaci:"<<endl;
                SLLNode<Zivotno> *f=zivotni.getFirst();
                while(f!=NULL){
                    Vlekaci *v=dynamic_cast<Vlekaci *>(f->getData());
                    if(v!=0)
                        v->prikazi_podatoci();
                    f=f->getNext();
                }
            }
            else if(tip==2){
                cout<<"Ptici:"<<endl;
                SLLNode<Zivotno> *f=zivotni.getFirst();
                while(f!=NULL){
                    Ptici *p=dynamic_cast<Ptici *>(f->getData());
                    if(p!=0)
                        p->prikazi_podatoci();
                    f=f->getNext();
                }
            }
            else{
                cout<<"Invalid input"<<endl;
            }
            break;
        }
        case 3:
        {
            cout<<"Site zivotni:"<<endl;
            SLLNode<Zivotno> *f=zivotni.getFirst();
            while(f!=NULL){
                f->getData()->prikazi_podatoci();
                f=f->getNext();
            }
            break;
        }
        case 4:
        {
            int den, mesec, godina;
            cout<<"Vnesi denesen datum(den mesec godina)"<<endl;
            cin>>den>>mesec>>godina;
            Datum *d=new Datum(den, mesec, godina);
            cout<<"Treba da se vakciniraat slednite zivotni:"<<endl;
            SLLNode<Zivotno> *f=zivotni.getFirst();
            while(f!=NULL){
                if(f->getData()->presmetaj_vakcinacija(*d)!=-1){
                    f->getData()->prikazi_podatoci();
                    cout<<endl;
                }
                f=f->getNext();
            }
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
