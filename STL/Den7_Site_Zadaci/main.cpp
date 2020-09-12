/*
-----Zadaca 1-----
#include <iostream>
#include <list>
#include <iterator>
#include <numeric>
#include <algorithm>

using namespace std;

bool parni(int elem){
    return (elem%2==0)? true : false;
}
bool lessThan2000(int elem){
    return (elem < 2000)? true : false;
}
bool interval_1(int elem){
    return (elem>=2000 && elem<4000)? true : false;
}
bool interval_2(int elem){
    return (elem>=4000 && elem<6000)? true : false;
}
bool interval_3(int elem){
    return (elem>=6000 && elem<8000)? true : false;
}
bool interval_4(int elem){
    return (elem>=8000 && elem<10000)? true : false;
}

int main()
{
    list<int> lista;
    for(int i=0; i<10000; i++){
        lista.push_back(rand()%10000);
    }

    ostream_iterator<int> output(cout, " ");
    int result=0;

    result=count_if(lista.begin(), lista.end(), parni);
    cout<<"Broj na prani elementi:"<<result<<endl;

    result=count_if(lista.begin(), lista.end(), lessThan2000);
    cout<<"Broj na elementi pomali od 2000:"<<result<<endl;

    result=count_if(lista.begin(), lista.end(), interval_1);
    cout<<"Broj na elementi vo interval [2000, 4000):"<<result<<endl;

    result=count_if(lista.begin(), lista.end(), interval_2);
    cout<<"Broj na elementi vo interval [4000, 6000):"<<result<<endl;

    result=count_if(lista.begin(), lista.end(), interval_3);
    cout<<"Broj na elementi vo interval [6000, 8000):"<<result<<endl;

    result=count_if(lista.begin(), lista.end(), interval_4);
    cout<<"Broj na elementi vo interval [8000, 10000):"<<result<<endl;

    result=0;
    result=accumulate(lista.begin(), lista.end(), 0);
    cout<<"Sredna vrednost: "<<(float)result/10000<<endl;

    return 0;
}
*/

/*
-----Zadaca 2-----
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Karta{
    int broj, boja; // boja{0,1,2,3} => 0=srce, 1=baklava, 2=list, 3=detelinka
public:
    Karta(int broj, int boja){
        this->broj=broj;
        this->boja=boja;
    }
    int getBroj(){return broj;}
    int getBoja(){return boja;}
    friend ostream &operator<<(ostream &output, const Karta &k){
        output<<k.broj<<" "<<k.boja<<endl;
        return output;
    }
};

int main(){
    vector<Karta> spil;
    // Polnenje na spilot
    for(int i=1; i<=13; i++){
        for(int j=0; j<4; j++){
            Karta ins(i, j);
            spil.push_back(ins);
        }
    }
    // mesanje na spil
    random_shuffle(spil.begin(), spil.end());

    cout<<"Vnesi broj na igraci: "<<endl;
    int num;
    cin>>num;
    int numCardsPerson=52/num;
    cout<<"Sekoj igrac kje dobie po "<<numCardsPerson<<" karti"<<endl;

    // a.
    int pobednik=0, suma=0, brIgrac=0;
    for(int i=0; i<52; i++){
        suma+=spil[i].getBroj();
        if((i+1)%numCardsPerson==0){
            if(brIgrac==num)
                break;
            cout<<"Igrac "<<brIgrac<<" ima osvoeno "<< suma<<" poeni"<<endl;
            if(suma>pobednik)
                pobednik=suma;
            suma=0;
            brIgrac++;
        }
    }
    cout<<"Pobednik e igracot so suma "<<pobednik<<endl;

    //b.
    brIgrac=0;
    suma=0;
    pobednik=0;
    cout<<"\nBaranje b."<<endl;
    for(int i=0; i<52; i++){
        if(spil[i].getBoja()==0){
            suma+=(spil[i].getBroj()*2);
        }
        else{
            suma+=spil[i].getBroj();
        }
        if((i+1)%numCardsPerson==0){
            if(brIgrac==num)
                break;
            cout<<"Igrac "<<brIgrac<<" ima osvoeno "<< suma<<" poeni"<<endl;
            if(suma>pobednik)
                pobednik=suma;
            suma=0;
            brIgrac++;
        }
    }
    cout<<"Pobednik e igracot so suma "<<pobednik<<endl;
    return 0;
}
