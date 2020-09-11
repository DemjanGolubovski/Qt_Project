/*
-----Zadaca 1-----
#include <iostream>

using namespace std;

template <class T>
class Zapis{
  T x, y, z;
public:
  Zapis(T x=0, T y=0, T z=0){
      this->x=x;
      this->y=y;
      this->z=z;
  }
  T getX(){return x;}
  T getY(){return y;}
  T getZ(){return z;}
};

template <class U>
bool kontrolor(U obj){
    if((obj.getX() + obj.getY() + obj.getZ())>10000)
        return true;
    return false;
}

int main()
{
    Zapis<int> i_obj(100, 22, 13);
    Zapis<double> d_obj(1000.55, 10000.12, 12.2345);
    if(kontrolor(i_obj))
        cout<<"Int nadminuva 10000"<<endl;
    if(kontrolor(d_obj))
        cout<<"Double nadminuva 10000"<<endl;
    return 0;
}
*/

/*
-----Zadaca 2-----
*/
#include <iostream>
#include <cstring>

using namespace std;

template <class T>
class Mnozestvo{
    static int brElem;
    int maxBrElem;
    T *siteElem;
public:
    Mnozestvo(int maxBrElem=5){
        this->maxBrElem=maxBrElem;
        siteElem=new T[maxBrElem];
    }
    ~Mnozestvo(){
        delete [] siteElem;
    }
    void vnesiElem(T elem){
        if(brElem<maxBrElem)
        {
            int flag=1;
            for(int i=0; i<brElem; i++)
            {
                if(siteElem[i]==elem){
                    flag=0;
                    break;
                }
            }
            if(flag)
                siteElem[brElem++]=elem;
        }else{
            cout<<"No more space"<<endl;
        }
    }
    void prikaziElem(){
        for(int i=0; i<brElem; i++)
            cout<<siteElem[i]<<" ";
        cout<<endl;
    }
    T maxElem(){
        T maxi=siteElem[0];
        for(int i=1; i<brElem; i++){
            if(maxi<siteElem[i])
                maxi=siteElem[i];
        }
        return maxi;
    }
    static int getElem(){return brElem;}
};
template <class T> int Mnozestvo<T>::brElem=0;

template <>
class Mnozestvo<char *>{
    static int brElem;
    int maxBrElem;
    char **siteElem;
public:
    Mnozestvo(int maxBrElem=5){
        this->maxBrElem=maxBrElem;
        siteElem=new char*[maxBrElem];
    }
    ~Mnozestvo(){
        for(int i=0; i<brElem; i++)
            delete siteElem[i];
        delete [] siteElem;
        brElem=0;
    }
    void vnesiElem(char *elem){
        if(brElem<maxBrElem)
        {
            int flag=1;
            for(int i=0; i<brElem; i++)
            {
                if(strcmp(elem, siteElem[i])==0){
                    flag=0;
                    break;
                }
            }
            if(flag){
                siteElem[brElem]=new char[strlen(elem) + 1];
                strcpy(siteElem[brElem], elem);
                brElem++;
            }
        }else{
            cout<<"No more space"<<endl;
        }
    }
    void prikaziElem(){
        for(int i=0; i<brElem; i++)
            cout<<siteElem[i]<<" ";
        cout<<endl;
    }
    char* maxElem(){
        char  *maxi=new char[strlen(siteElem[0]) + 1];
        strcpy(maxi, siteElem[0]);

        for(int i=1; i<brElem; i++){
            if(strcmp(maxi, siteElem[i])<0)
            {
                delete [] maxi;
                maxi=new char[strlen(siteElem[i]) + 1];
                strcpy(maxi, siteElem[i]);
            }
        }
        return maxi;
    }
    static int getElem(){return brElem;}
};
int Mnozestvo<char *>::brElem=0;

int main(){
    Mnozestvo<int> int_m;
    Mnozestvo<double> double_m;
    Mnozestvo<char *> char_m;

    cout<<"0-Vnesi vo mnozestvo od int-s"<<endl;
    cout<<"1-Vnesi vo mnozestvo od double-s"<<endl;
    cout<<"2-Vnesi vo mnozestvo od char*-s"<<endl;
    cout<<"3-Prikazi go int mnozestvoto"<<endl;
    cout<<"4-Prikazi go double mnozestvoto"<<endl;
    cout<<"5-Prikazi go char* mnozestvoto"<<endl;
    cout<<"6-Prikazi najgolem elem vo mnozestvata"<<endl;
    cout<<"7-Prikazi br na elem vo mnozestvata"<<endl;
    cout<<"8-END"<<endl;

    int choice;
    cin>>choice;
    while(choice!=8){
        switch (choice) {
        case 0:
        {
            int ins;
            cin>>ins;
            int_m.vnesiElem(ins);
            break;
        }
        case 1:
        {
            double ins;
            cin>>ins;
            double_m.vnesiElem(ins);
            break;
        }
        case 2:
        {
            char ins[20];
            cin>>ins;
            char_m.vnesiElem(ins);
            break;
        }
        case 3:
        {
            int_m.prikaziElem();
            break;
        }
        case 4:
        {
            double_m.prikaziElem();
            break;
        }
        case 5:
        {
            char_m.prikaziElem();
            break;
        }
        case 6:
        {
            cout<<"Max int elem: "<<int_m.maxElem()<<endl;
            cout<<"Max double elem: "<<double_m.maxElem()<<endl;
            cout<<"Max char* elem: "<<char_m.maxElem()<<endl;
            break;
        }
        case 7:
        {
            cout<<"Br na int elem: "<<Mnozestvo<int>::getElem()<<endl;
            cout<<"Br na double elem: "<<Mnozestvo<double>::getElem()<<endl;
            cout<<"Br na char* elem: "<<Mnozestvo<char *>::getElem()<<endl;
            break;
        }
        default:
            break;
        }
        cin>>choice;
    }

    return 0;
}
