#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

class Vraboten{
    int bodovi;
    char *ime;
    static int vredBod;
public:
    Vraboten(char *ime="", int bodovi=0){
        this->bodovi=bodovi;
        this->ime=new char[strlen(ime) + 1];
        assert(this->ime!=0);
        strcpy(this->ime, ime);
    }
    ~Vraboten(){
        delete [] ime;
    }
    Vraboten(const Vraboten &v){
        bodovi=v.bodovi;
        ime=new char[strlen(v.ime) + 1];
        assert(ime!=0);
        strcpy(ime, v.ime);
    }
    Vraboten &operator=(const Vraboten &v){
        if(this!=&v){
            delete [] ime;
            bodovi=v.bodovi;
            ime=new char[strlen(v.ime) + 1];
            assert(ime!=0);
            strcpy(ime, v.ime);
        }
        return *this;
    }
    friend ostream &operator<<(ostream &output, const Vraboten &v){
        output<<"Ime: "<<v.ime<<", Bodovi: "<<v.bodovi<<", Plata: "<<v.bodovi*vredBod;
        return output;
    }
    friend bool operator<(const Vraboten &v1, const Vraboten &v2){
        return (v1.bodovi<v2.bodovi)? true : false;
    }
    friend int operator+(int val, Vraboten &v){
        return v.bodovi+val;
    }
    static int getBodovi(){return vredBod;}
};
int Vraboten::vredBod=2;

int main()
{
    vector<Vraboten> vraboteni;
    Vraboten v1("vrab_1", 10);
    Vraboten v2("vrab_2", 5);
    Vraboten v3("vrab_3", 15);
    Vraboten v4("vrab_4", 20);
    Vraboten v5("vrab_5", 150);

    vraboteni.push_back(v1);
    vraboteni.push_back(v2);
    vraboteni.push_back(v3);
    vraboteni.push_back(v4);
    vraboteni.push_back(v5);

    int suma=accumulate(vraboteni.begin(), vraboteni.end(), 0);
    cout<<"Vkupno treba da se isplatat: "<<suma*Vraboten::getBodovi()<<endl;
    sort(vraboteni.begin(), vraboteni.end());
    ostream_iterator<Vraboten> output(cout, "\n");
    copy(vraboteni.begin(), vraboteni.end(), output);
    return 0;
}
