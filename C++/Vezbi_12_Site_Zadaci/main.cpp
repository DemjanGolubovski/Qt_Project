#include <iostream>
#include "Oblici.h"
#include "SLL.h"
using namespace std;

int main()
{
    SLL<Oblik> oblici;
    cout<<"0-Kreiraj oblik"<<endl;
    cout<<"1-Prikazi oblici"<<endl;
    cout<<"2-Prikazi odreden tip na oblik"<<endl;
    cout<<"3-END"<<endl;
    int choice;
    cin>>choice;
    while(choice!=3){
        switch (choice) {
        case 0:
        {
            cout<<"0-Kreiraj Krug"<<endl;
            cout<<"1-Kreiraj Kvadrat"<<endl;
            cout<<"2-Kreiraj Triagolnik"<<endl;
            cout<<"3-Kreiraj Topka"<<endl;
            cout<<"4-Kreiraj Kocka"<<endl;
            cout<<"5-Kreiraj Piramida"<<endl;
            int shape;
            cin>>shape;
            if(shape==0){
                Krug *k=new Krug();
                oblici.setLast(k);
            }
            else if(shape==1){
                Kvadrat *kv=new Kvadrat();
                oblici.setLast(kv);
            }
            else if(shape==2){
                Triagolnik *t=new Triagolnik();
                oblici.setLast(t);
            }
            else if(shape==3){
                Topka *to=new Topka();
                oblici.setLast(to);
            }
            else if(shape==4){
                Kocka *ko=new Kocka();
                oblici.setLast(ko);
            }
            else if(shape==5){
                Piramida *p=new Piramida();
                oblici.setLast(p);
            }
            else
                cout<<"Invalid input"<<endl;
            break;
        }
        case 1:
        {
            cout<<"Site oblici = "<<Oblik::getBrOblik()<<":"<<endl;
            SLLNode<Oblik> *f=oblici.getFirst();
            while(f!=NULL){
                f->getData()->display();
                f=f->getNext();
            }
            break;
        }
        case 2:
        {
            cout<<"0-2D oblici\n1-3D oblici"<<endl;
            int tip;
            cin>>tip;
            if(tip==0){
                cout<<"2D oblici = "<<DvoDimenzionalni::getBrDvoD()<<":"<<endl;
                SLLNode<Oblik> *f=oblici.getFirst();
                while(f!=NULL){
                    DvoDimenzionalni *dvaD=dynamic_cast<DvoDimenzionalni *>(f->getData());
                    if(dvaD!=0)
                        dvaD->display();
                    f=f->getNext();
                }
            }
            else if(tip==1){
                cout<<"3D oblici = "<<TroDimenzionalni::getBrTroD()<<":"<<endl;
                SLLNode<Oblik> *f=oblici.getFirst();
                while(f!=NULL){
                    TroDimenzionalni *troD=dynamic_cast<TroDimenzionalni *>(f->getData());
                    if(troD!=0)
                        troD->display();
                    f=f->getNext();
                }
            }
            else
                cout<<"Invalid input"<<endl;
            break;
        }
        default:
            break;
        }
        cin>>choice;
    }
    return 0;
}
