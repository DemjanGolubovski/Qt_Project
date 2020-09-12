/*
-----Zadaca 1-----
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <map>

using namespace std;

class Stedac{
    char *ime, *prezime;
public:
    Stedac(char *ime="", char *prezime=""){
        this->ime=new char[strlen(ime) + 1];
        assert(this->ime!=0);
        strcpy(this->ime, ime);

        this->prezime=new char[strlen(prezime) + 1];
        assert(this->prezime!=0);
        strcpy(this->prezime, prezime);
    }
    Stedac(const Stedac &s){
        ime=new char[strlen(s.ime) + 1];
        assert(ime!=0);
        strcpy(ime, s.ime);

        prezime=new char[strlen(s.prezime) + 1];
        assert(prezime!=0);
        strcpy(prezime, s.prezime);
    }
    ~Stedac(){
        delete [] ime;
        delete [] prezime;
    }
    Stedac &operator=(const Stedac &s){
        if(this!=&s){
            delete [] ime;
            delete [] prezime;

            ime=new char[strlen(s.ime) + 1];
            assert(ime!=0);
            strcpy(ime, s.ime);

            prezime=new char[strlen(s.prezime) + 1];
            assert(prezime!=0);
            strcpy(prezime, s.prezime);
        }
        return *this;
    }
    bool operator==(const Stedac &s){
        if(strcmp(ime, s.ime)==0 && strcmp(prezime, s.prezime)==0)
            return true;
        return false;
    }
    friend ostream &operator<<(ostream &output, const Stedac &s){
        output<<"Ime: "<<s.ime<<", Prezime: "<<s.prezime;
        return output;
    }
    friend bool operator<(const Stedac &s1, const Stedac &s2){
        if(strcmp(s1.ime, s2.ime)<0)
            return true;
        return false;
    }
};

class Uplata{
    Stedac s;
    int suma;
public:
    Uplata(Stedac s=0, int suma=0){
        this->s=s;
        this->suma=suma;
    }
    friend ostream &operator<<(ostream &output, const Uplata &u);
};
ostream &operator<<(ostream &output, const Uplata &u){
    output<<"Stedac: "<<endl;
    output<<u.s<<", Suma: "<<u.suma;
    return output;
}

typedef std::multimap< Stedac, Uplata, std::less< Stedac > > mmid;

int main()
{
    mmid uplati;
    cout<<"0-Dodadi stedac"<<endl;
    cout<<"1-Prikazi iplata za daden stedac"<<endl;
    cout<<"2-END"<<endl;

    int choice;
    cin>>choice;
    while(choice!=2){
        switch (choice) {
        case 0:
        {
            char ime[20], prezime[30];
            int suma;
            cin>>ime>>prezime>>suma;
            Stedac s(ime, prezime);
            Uplata u(s, suma);
            uplati.insert(mmid::value_type(s, u));
            break;
        }
        case 1:
        {
            cout<<"Vnesi ime i prezime na stedac"<<endl;
            char i[20], p[30];
            cin>>i>>p;
            Stedac s_find(i, p);
            mmid::iterator iter;
            for (iter=uplati.begin(); iter!=uplati.end(); ++iter ){
                if(s_find==iter->first)
                    cout<<iter->second<<endl;
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
*/

/*
-----Zadaca 2-----
*/
#include <iostream>
#include <queue>

using namespace std;

class Proces{
    int id, prioritet;
public:
    Proces(int id=0, int prioritet=0){
        this->id=id;
        this->prioritet=prioritet;
    }
    friend bool operator<(const Proces &p1, const Proces &p2){
        if(p1.prioritet<p2.prioritet)
            return true;
        return false;
    }
    friend ostream &operator<<(ostream &output, const Proces &p){
        output<<"ID: "<<p.id<<", Prioritet: "<<p.prioritet;
        return output;
    }
};

int main(){
    priority_queue<Proces> procesi;
    cout<<"Vnesi 5 procesi"<<endl;
    int id, prioritet;;
    for(int i=0; i<5; i++){
        cout<<"Vnesi id i prioritet: ";
        cin>>id>>prioritet;
        Proces ins(id, prioritet);
        procesi.push(ins);
    }

    while(!procesi.empty()){
        cout<<procesi.top()<<endl;
        procesi.pop();
    }
    return 0;
}
