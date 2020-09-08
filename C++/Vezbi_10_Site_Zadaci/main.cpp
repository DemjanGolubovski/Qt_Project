#include <iostream>
#include <cassert>
#include "SLL.h"
#include "Vraboten.h"
using namespace std;
int main()
{
    cout<<"0-Dodadi vraboten"<<endl;
    cout<<"1-Prikazi gi site vraboteni"<<endl;
    cout<<"2-END"<<endl;
    SLL<Vraboten> vraboteni;
    int choice;
    cin>>choice;
    while(choice!=2){
        switch (choice) {
        case 0:
        {
            int tip;
            cout<<"0-Profesor"<<endl;
            cout<<"1-Asistent"<<endl;
            cout<<"2-Demonstrator"<<endl;
            cin>>tip;
            cout<<"Vnesi ime, prezime, godina na vrabotuvanje"<<endl;
            char *ime, *prezime;
            int god_vrab;
            ime=new char[30];
            prezime=new char[30];
            assert(ime!=0);
            assert(prezime!=0);
            cin>>ime>>prezime>>god_vrab;
            if(tip==0){
                char *zvanje, *oblast;
                int br_pred;
                zvanje=new char[30];
                oblast=new char[30];
                assert(zvanje!=0);
                assert(oblast!=0);
                cout<<"Vnesi zvanje, oblast i br na predmeti"<<endl;
                cin>>zvanje>>oblast>>br_pred;
                Profesor *p=new Profesor(ime, prezime, god_vrab, zvanje, oblast, br_pred);
                vraboteni.setLast(p);

                delete [] zvanje;
                delete [] oblast;

            }else if(tip==1){
                char *zvanje, *mentor;
                int br_pred;
                zvanje=new char[30];
                mentor=new char[30];
                assert(zvanje!=0);
                assert(mentor!=0);
                cout<<"Vnesi zvanje, mentor i br na predmeti"<<endl;
                cin>>zvanje>>mentor>>br_pred;
                Asistent *a=new Asistent(ime, prezime, god_vrab, zvanje, mentor, br_pred);
                vraboteni.setLast(a);

                delete [] zvanje;
                delete [] mentor;
            }else if(tip==2){
                char *rab_vreme;
                rab_vreme=new char[30];
                assert(rab_vreme!=0);
                cout<<"Vnesi rabotno vreme"<<endl;
                cin>>rab_vreme;
                Demonstrator *d=new Demonstrator(ime, prezime, god_vrab, rab_vreme);
                vraboteni.setLast(d);

                delete [] rab_vreme;
            }else{
                cout<<"Invalid choice"<<endl;
            }

            delete [] ime;
            delete [] prezime;
            break;
        }
        case 1:
        {
            SLLNode<Vraboten> *f=vraboteni.getFirst();
            while (f!=NULL) {
                Profesor *p=dynamic_cast<Profesor *>(f->getData());
                if(p!=0)
                {
                    p->prikazi_podatoci();
                }
                Asistent *a=dynamic_cast<Asistent *>(f->getData());
                if(a!=0){
                    a->prikazi_podatoci();
                }
                Demonstrator *d=dynamic_cast<Demonstrator *>(f->getData());
                if(d!=0){
                    d->prikazi_podatoci();
                }
                // moze i vaka koga bi se postavila funkcijata prikazi_podatoci kako virtuelna kaj Vraboten(base class)
//                f->getData()->prikazi_podatoci();
                f=f->getNext();
            }
            break;
        }
        default:
            break;
        }
        cin>>choice;
    }
    return 0;
}
