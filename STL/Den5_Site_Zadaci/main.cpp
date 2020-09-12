/*
-----Zadaca 1-----
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
bool palindrom(vector<T> p){
    vector<T> rev_p=p;
    for(int i=0; i<p.size()/2; i++){
        if(p[i]!=rev_p[p.size()-1-i])
            return false;
    }
    return true;
}

int main()
{
    vector<int> int_v;
    int_v.push_back(1);
    int_v.push_back(2);
    int_v.push_back(2);
    int_v.push_back(1);

    if(palindrom(int_v))
        cout<<"Palindrom"<<endl;
    else
        cout<<"Ne e palindrom"<<endl;
    return 0;
}
*/

/*
-----Zadaca 2-----
#include <iostream>
#include <list>
#include <cstring>

using namespace std;

bool containsElem(list<char *> elems, char *elem){
    list<char *>::iterator iter;
    for(iter=elems.begin(); iter!=elems.end(); iter++){
        if(strcmp((*iter), elem)==0)
            return true;
    }
    return false;
}

void newList(list<char *> mail, list<char *> &combo_list){
    list<char *>::iterator iter;
    for(iter=mail.begin(); iter!=mail.end(); iter++){
        if(!containsElem(combo_list, (*iter)))
            combo_list.push_back((*iter));
    }
}

int main(){
    list<char *> mail_1;
    list<char *> mail_2;
    list<char *> mail_3;
    list<char *> combo_list;
    mail_1.push_back("g.demjan");
    mail_1.push_back("mail.mail@");
    mail_2.push_back("g.demjan");
    mail_3.push_back("mail.com");
    newList(mail_1, combo_list);
    newList(mail_2, combo_list);
    newList(mail_3, combo_list);
    cout<<"All the mails in one list:"<<endl;
    list<char *>::iterator iter;
    for(iter=combo_list.begin(); iter!=combo_list.end(); iter++){
        cout<<*iter<<endl;
    }
    return 0;
}
*/

/*
-----Zadaca 3-----
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    deque<int> d;
    vector<int> v;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_back(5);
    for(int i=d.size()-1; i>=0; i--){
        v.push_back(d[i]);
    }

    deque<int>::iterator iter;
    cout<<"Deque: "<<endl;
    for(iter=d.begin(); iter!=d.end(); iter++){
        cout<<*iter<<" ";
    }
    cout<<endl;

    cout<<"Vector:"<<endl;
    vector<int>::iterator v_iter;
    for(v_iter=v.begin(); v_iter!=v.end(); v_iter++){
        cout<<*v_iter<<" ";
    }
    cout<<endl;

    return 0;
}
*/

/*
-----Proekt 1-----
*/
#include <iostream>
#include <list>

using namespace std;

class Kvadrat{
    float strana;
public:
    Kvadrat(float strana=0){
        this->strana=strana;
    }
    float plostina(){return strana*strana;}
    friend ostream &operator<<(ostream &output, const Kvadrat &k);
    bool operator==(const Kvadrat &k){
        if(k.strana==strana)
            return true;
        return false;
    }
};
ostream &operator<<(ostream &output, const Kvadrat &k){
    output<<"Strana: "<<k.strana<<endl;
    return output;
}

class Pravoagolnik{
    float sirina, visina;
public:
    Pravoagolnik(float sirina=0, float visina=0){
        this->sirina=sirina;
        this->visina=visina;
    }
    float plostina(){return sirina*visina;}
    friend ostream &operator<<(ostream &outpu, const Pravoagolnik &p);
    bool operator==(const Pravoagolnik &p){
        if(p.sirina==sirina && p.visina==visina)
            return true;
        return false;
    }
};
ostream &operator<<(ostream &output, const Pravoagolnik &p){
    output<<"Sirina: "<<p.sirina<<", Visina: "<<p.visina<<endl;
    return output;
}

class Krug{
    float radius;
public:
    Krug(float radius=0){
        this->radius=radius;
    }
    float plostina(){return radius*radius*3.14;}
    friend ostream &operator<<(ostream &output, const Krug &k);
    bool operator==(const Krug &k){
        if(k.radius==radius)
            return true;
        return false;
    }
};
ostream &operator<<(ostream &output, const Krug &k){
    output<<"Radius: "<<k.radius<<endl;
    return output;
}

template <class T>
class Mnozestvo{
    static int brElem;
    list<T> elementi;
public:
    void setElem(T elem){
        int flag=1;
        typename list<T>::iterator iter;
        if(elementi.empty()){
            elementi.push_back(elem);
            brElem++;
        }
        else{
        for(iter=elementi.begin(); iter!=elementi.end(); iter++){
            if((*iter)==elem){
                flag=0;
                break;
            }
        }
        if(flag){
            elementi.push_back(elem);
            brElem++;
        }
        }
    }
    static int getBrElem(){return  brElem;}
    void print(){
        typename list<T>::iterator iter;
        for(iter=elementi.begin(); iter!=elementi.end(); iter++){
            cout<<(*iter);
        }
    }
    T maxElem(){
        typename list<T>::iterator iter;
        iter=elementi.begin();
        T maxi=(*iter);
        iter++;
        while(iter!=elementi.end()){
            if(maxi.plostina()<(*iter).plostina())
                maxi=(*iter);
            iter++;
        }
        return maxi;
    }
};
template <class T> int Mnozestvo<T>::brElem=0;

int main(){
    Mnozestvo<Kvadrat> kvadrati;
    Mnozestvo<Krug> krugovi;
    Mnozestvo<Pravoagolnik> pravoagolnici;

    cout<<"0-Dodadi kvadrat"<<endl;
    cout<<"1-Dodadi krug"<<endl;
    cout<<"2-Dodadi pravoagolnik"<<endl;
    cout<<"3-Prikazi gi kvadratite"<<endl;
    cout<<"4-Prikazi gi krugovite"<<endl;
    cout<<"5-Prikazi gi pravoagolnicite"<<endl;
    cout<<"6-Prikazi najgolem element"<<endl;
    cout<<"7-Prikazi br na elementi"<<endl;
    cout<<"8-END"<<endl;

    int choice;
    cin>>choice;
    while(choice!=8){
        switch (choice) {
        case 0:
        {
            int str;
            cin>>str;
            Kvadrat k(str);
            kvadrati.setElem(k);
            break;
        }
        case 1:
        {
            int rad;
            cin>>rad;
            Krug k(rad);
            krugovi.setElem(k);
            break;
        }
        case 2:
        {
            int sir, vis;
            cin>>sir>>vis;
            Pravoagolnik p(sir, vis);
            pravoagolnici.setElem(p);
            break;
        }
        case 3:
        {
            kvadrati.print();
            break;
        }
        case 4:
        {
            krugovi.print();
            break;
        }
        case 5:
        {
            pravoagolnici.print();
            break;
        }
        case 6:
        {
            cout<<"Max elem kaj kvadrati e: "<<kvadrati.maxElem();
            cout<<"Max elem kaj krugovi e: "<<krugovi.maxElem();
            cout<<"Max elem kaj pravoagolnici e: "<<pravoagolnici.maxElem();
            break;
        }
        case 7:
        {
            cout<<"Broj na kvadrati: "<<Mnozestvo<Kvadrat>::getBrElem()<<endl;
            cout<<"Broj na krugovi: "<<Mnozestvo<Krug>::getBrElem()<<endl;
            cout<<"Broj na pravoagolnici: "<<Mnozestvo<Pravoagolnik>::getBrElem()<<endl;
            break;
        }
        default:
            break;
        }
        cin>>choice;
    }
    return 0;
}
