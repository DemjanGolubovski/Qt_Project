/*
-----Zadaca 1-----
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Imenik{
    char *ime, *tel_broj;
public:
    Imenik(char *ime="", char *tel_broj=""){
        this->ime=new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->tel_broj=new char[strlen(tel_broj) + 1];
        strcpy(this->tel_broj, tel_broj);
    }
    ~Imenik(){
        delete [] ime;
        delete [] tel_broj;
    }
    char *getIme(){return ime;}
    char *getTel(){return tel_broj;}
    friend ostream &operator<<(ostream &, const Imenik &);
};
ostream &operator<<(ostream &output, const Imenik &i){
    output<<i.ime<<" "<<i.tel_broj<<endl;
    return output;
}

bool isMin(Imenik i1, Imenik i2){
    if(strcmpi(i1.getIme(),i2.getIme())<0)
        return true;
    return false;
}

int main()
{
    vector<Imenik> imenik;
    char ime[20], tel[10];
    for(int i=0; i<5; i++){
        cin>>ime>>tel;
        Imenik tmp(ime, tel);
        imenik.push_back(tmp);
    }
    sort(imenik.begin(), imenik.end(), isMin);
    vector<Imenik>::iterator iter;
    for(iter=imenik.begin(); iter!=imenik.end(); iter++){
        cout<<(*iter);
    }
    return 0;
}*/

/*
-----Zadaca 2-----
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool mySort(char c1, char c2){
    if(c1<c2)
        return true;
    return false;
}

int main(){
    char z1[20], z2[20];
    cin>>z1>>z2;
    vector<char> zbor1;
    vector<char> zbor2;
    for(int i=0; i<strlen(z1); i++)
    {
        zbor1.push_back(z1[i]);
    }
    for(int i=0; i<strlen(z2); i++)
    {
        zbor2.push_back(z2[i]);
    }
    sort(zbor1.begin(), zbor1.end(), mySort);
    sort(zbor2.begin(), zbor2.end(), mySort);
    if(equal(zbor1.begin(), zbor1.end(), zbor2.begin()))
        cout<<"Anagrami se"<<endl;
    else
        cout<<"Ne se anagrami"<<endl;
    return 0;
}
*/

/*
-----Zadaca 3-----
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool mySort(char *c1, char *c2){
    if(strcmpi(c1,c2)<0)
        return true;
    return false;
}

int main(){
    char tekst[100];
    gets(tekst);
    vector<char *> zborovi;
    int index=0;
    char *zbor=new char[20];
    for(int i=0; i<strlen(tekst); i++){
        if(tekst[i]!=' '){
            zbor[index++]=tekst[i];
        }
        else{
            zborovi.push_back(zbor);
            index=0;
            zbor=new char[20];
        }
    }
    zborovi.push_back(zbor);

    sort(zborovi.begin(), zborovi.end(), mySort);
    vector<char *>::iterator iter;
    for(iter=zborovi.begin(); iter!=zborovi.end(); iter++){
        cout<<(*iter)<<endl;
    }
    delete [] zbor;
    return 0;
}

