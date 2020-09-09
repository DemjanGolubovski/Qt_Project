#include <iostream>
#include "Oblici.h"
#include "SLL.h"
using namespace std;

int main()
{
    SLL<Oblik> oblici;
    cout<<"0-Kreiraj oblik"<<endl;
    cout<<"1-Ispecati gi site oblici"<<endl;
    cout<<"2-Ispecati odreden tip(2D/3D) na oblik"<<endl;
    cout<<"3-END"<<endl;
    int choice;
    cin>>choice;
    while(choice!=3){
        switch (choice) {
        case 0:
        {
            cout<<"0-Krug\n1-Kvadrat\n2-Triagolnik\n3-Topka\n4-Kocka\n5-Cilindar"<<endl;
            int tip;
            cin>>tip;
            if(tip==0){
                cout<<"Vnesi radius"<<endl;
                float r;
                cin>>r;
                Krug *k=new Krug(r);
                oblici.setLast(k);
            }
            else if(tip==1){
                cout<<"Vnesi strana"<<endl;
                float a;
                cin>>a;
                Kvadrat *k=new Kvadrat(a);
                oblici.setLast(k);
            }
            else if(tip==2){
                cout<<"Vnesi visina i strana"<<endl;
                float a,h;
                cin>>h>>a;
                Triagolni *t=new Triagolni(h, a);
                oblici.setLast(t);
            }
            else if(tip==3){
                cout<<"Vnesi radius"<<endl;
                float r;
                cin>>r;
                Topka *t=new Topka(r);
                oblici.setLast(t);
            }
            else if(tip==4){
                cout<<"Vnesi strana"<<endl;
                float a;
                cin>>a;
                Kocka *k=new Kocka(a);
                oblici.setLast(k);
            }
            else if(tip==5){
                cout<<"Vnesi visina i radius"<<endl;
                float r, h;
                cin>>h>>r;
                Cilindar *c=new Cilindar(h, r);
                oblici.setLast(c);
            }
            else
                cout<<"Invalid input"<<endl;
            break;
        }
        case 1:
        {
            SLLNode<Oblik> *f=oblici.getFirst();
            while(f!=NULL){
                f->getData()->print();
                f=f->getNext();
            }
            break;
        }
        case 2:
        {
            cout<<"0-2D\n1-3D"<<endl;
            int tip;
            cin>>tip;
            if(tip==0){
                SLLNode<Oblik> *f=oblici.getFirst();
                while(f!=NULL){
                    DvoDimenzionalni *tmp=dynamic_cast<DvoDimenzionalni *>(f->getData());
                    if(tmp!=0){
                        tmp->print();
                        cout<<"Plostina: "<<tmp->plostina()<<endl;
                    }
                    f=f->getNext();
                }
            }
            else if(tip==1){
                SLLNode<Oblik> *f=oblici.getFirst();
                while(f!=NULL){
                    TroDimenzionalni *tmp=dynamic_cast<TroDimenzionalni *>(f->getData());
                    if(tmp!=0){
                        tmp->print();
                        cout<<"Plostina: "<<tmp->plostina()<<endl;
                        cout<<"Volumen: "<<tmp->volumen()<<endl;
                    }
                    f=f->getNext();
                }
            }
            else{
                cout<<"Invalid input"<<endl;
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
