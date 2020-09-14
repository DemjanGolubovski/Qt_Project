/*
-----Zadaca 1-----
#include <iostream>
#include <cstring>

using namespace std;

template <class T>
class Pole{
    int currBrElem;
    T *niza;
    int maxBrElem;
public:
    Pole(int maxBrElem=5){
        currBrElem=0;
        this->maxBrElem=maxBrElem;
        niza=new T[maxBrElem];
    }
    void setElem(T elem){
        if(currBrElem<maxBrElem)
            niza[currBrElem++]=elem;
        else
            cout<<"Nema vekje mesto"<<endl;
    }
    T getElem(int index){
        if(index>=0 && index<currBrElem)
            return niza[index];
        else{
            cout<<"index of of bounds"<<endl;
            return niza[0];
        }
    }
    int getBrElem(){return currBrElem;}
};

template <class T>
T max(Pole<T> pole){
    T maxi=pole.getElem(0);
    for(int i=1; i<pole.getBrElem(); i++){
        if(maxi<pole.getElem(i))
            maxi=pole.getElem(i);
    }
    return maxi;
}

template <>
char* max(Pole<char *> pole){
    char *maxi;
    maxi=new char[strlen(pole.getElem(0)) + 1];
    strcpy(maxi, pole.getElem(0));

    for(int i=1; i<pole.getBrElem(); i++){
        if(strcmpi(maxi, pole.getElem(i))<0)
        {
            delete [] maxi;
            maxi=new char[strlen(pole.getElem(i)) + 1];
            strcpy(maxi, pole.getElem(i));
        }
    }

    return maxi;
    delete [] maxi;
}

int main()
{
    Pole<int> int_p;
    Pole<double> double_p;
    Pole<char *> string_p;

    int_p.setElem(2);
    int_p.setElem(20);
    int_p.setElem(5);
    int_p.setElem(222);
    int_p.setElem(122);
    cout<<"Max int: "<<max(int_p)<<endl;

    double_p.setElem(5.5);
    double_p.setElem(55.5);
    double_p.setElem(125.5);
    double_p.setElem(53.5);
    double_p.setElem(5.45);
    cout<<"Max double: "<<max(double_p)<<endl;

    string_p.setElem("one");
    string_p.setElem("two");
    string_p.setElem("three");
    string_p.setElem("four");
    string_p.setElem("five");
    cout<<"Max string: "<<max(string_p)<<endl;

    return 0;
}
*/

/*
-----Zadaca 2-----
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <exception>
#include <fstream>

using namespace std;

class NoSuchFile: public exception{
public:
    void message(){cout<<"The file does not exist"<<endl;}
};

class Inventar{
    int id, kolicina;
    double cena;
public:
    Inventar(int id=0, int kolicina=0, double cena=0){
        this->id=id;
        this->kolicina=kolicina;
        this->cena=cena;
    }
    friend double operator+(const int suma, const Inventar &i){
        return suma+(i.kolicina*i.cena);
    }
    friend ostream &operator<<(ostream &output, const Inventar &i){
        output<<"ID: "<<i.id<<", Kolicina: "<<i.kolicina<<", Cena: "<<i.cena;
        return output;
    }
    int getKolicina() const {return kolicina;}
};

bool less_kolicina(const Inventar &i){
    return (i.getKolicina()<10)? true : false;
}

int main(){
    vector<Inventar> artikli;
    double suma=0, cena;
    int id, kolicina;
    ostream_iterator<Inventar> output(cout, "\n");

    try {
        ifstream reader("inventar.txt", ios::in);
        if(!reader)
            throw NoSuchFile();

        while(reader>>id>>kolicina>>cena){
            Inventar ins(id, kolicina, cena);
            artikli.push_back(ins);
        }

        suma=accumulate(artikli.begin(), artikli.end(), 0.0);
        cout<<"Vkupnata suma e: "<<suma<<endl;
        cout<<"Site artikli cija sto kolicina e pomala od 10:"<<endl;
        copy_if(artikli.begin(), artikli.end(), output, less_kolicina);

        reader.close();

    } catch (NoSuchFile &nsf) {
        nsf.message();
    }
    return 0;
}
*/

/*
-----Zadaca 3-----
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <exception>
#include <algorithm>
#include <set>

using namespace std;

class InvalidInputException:public exception{
public:
    void message(){cout<<"Invalid number was entered"<<endl;}
};

class Kvadrat{
    double strana;
public:
    Kvadrat(double strana=0){
        this->strana=strana;
    }
    friend ostream &operator<<(ostream &output, const Kvadrat &k){
        output<<"Kvadrat so strana: "<<k.strana;
        return output;
    }
    friend bool operator<(const Kvadrat &k1,const Kvadrat &k2){
        return (k1.strana<k2.strana)? true : false;
    }
    friend bool operator==(Kvadrat &k1, Kvadrat &k2){
        return (k1.strana==k2.strana)? true : false;
    }
};
class Pravoagolnik{
    double sirina, dolzina;
public:
    Pravoagolnik(double sirina=0, double dolzina=0){
        this->sirina=sirina;
        this->dolzina=dolzina;
    }
    friend ostream &operator<<(ostream &output, const Pravoagolnik &p){
        output<<"Pravoagolnik so sirina "<<p.sirina<<" i dolzina "<<p.dolzina;
        return output;
    }
    friend bool operator<(const Pravoagolnik &p1, const Pravoagolnik &p2){
        return (p1.sirina*p1.dolzina<p2.sirina*p2.dolzina)? true : false;
    }
};

int main(){
    set<Kvadrat> kvadrati_1;
    set<Pravoagolnik> pravoagolnici_1;
    set<Kvadrat> kvadrati_2;
    set<Pravoagolnik >pravoagolnici_2;

    ostream_iterator<Kvadrat> k_output(cout, "\n");
    ostream_iterator<Pravoagolnik> p_output(cout, "\n");

    ifstream reader_1("input_1.txt", ios::in);
    if(!reader_1){
        cout<<"Error"<<endl;
        exit(1);
    }
    ifstream reader_2("input_2.txt", ios::in);
    if(!reader_2){
        cout<<"Error"<<endl;
        exit(1);
    }

    int choice;
    double strana, sirina, dolzina;

    // Reading from first file
    while(reader_1>>choice){
        try {
            if(choice!=1 && choice!=2)
                throw InvalidInputException();
            else if(choice==1){
                reader_1>>sirina>>dolzina;
                Pravoagolnik *ins=new Pravoagolnik(sirina, dolzina);
                pravoagolnici_1.insert(*ins);
                delete ins;
            }
            else{
                reader_1>>strana;
                Kvadrat *ins=new Kvadrat(strana);
                kvadrati_1.insert(*ins);
                delete ins;
            }
        } catch (InvalidInputException &iie) {
            iie.message();
        }
    }
    // Reading from second file
    while(reader_2>>choice){
        try {
            if(choice!=1 && choice!=2)
                throw InvalidInputException();
            else if(choice==1){
                reader_2>>sirina>>dolzina;
                Pravoagolnik *ins=new Pravoagolnik(sirina, dolzina);
                pravoagolnici_2.insert(*ins);
                delete ins;
            }
            else{
                reader_2>>strana;
                Kvadrat *ins=new Kvadrat(strana);
                kvadrati_2.insert(*ins);
                delete ins;
            }
        } catch (InvalidInputException &iie) {
            iie.message();
        }
    }

    reader_1.close();
    reader_2.close();

    cout<<"\nUnija na Kvadrati: "<<endl;
    set<Kvadrat> k_unija;
    set_union(kvadrati_1.begin(), kvadrati_1.end(), kvadrati_2.begin(), kvadrati_2.end(), inserter(k_unija, k_unija.begin()));
    copy(k_unija.begin(), k_unija.end(), k_output);

    cout<<"\nUnija na Pravoagolnici: "<<endl;
    set<Pravoagolnik> p_unija;
    set_union(pravoagolnici_1.begin(), pravoagolnici_1.end(), pravoagolnici_2.begin(), pravoagolnici_2.end(), inserter(p_unija, p_unija.begin()));
    copy(p_unija.begin(), p_unija.end(), p_output);

    cout<<"\nPresek na Kvadrati: "<<endl;
    set<Kvadrat> k_presek;
    set_intersection(kvadrati_1.begin(), kvadrati_1.end(), kvadrati_2.begin(), kvadrati_2.end(), inserter(k_presek, k_presek.begin()));
    copy(k_presek.begin(), k_presek.end(), k_output);

    cout<<"\nPresek na Pravoagolnici: "<<endl;
    set<Pravoagolnik> p_presek;
    set_intersection(pravoagolnici_1.begin(), pravoagolnici_1.end(), pravoagolnici_2.begin(), pravoagolnici_2.end(), inserter(p_presek, p_presek.begin()));
    copy(p_presek.begin(), p_presek.end(), p_output);

    return 0;
}
*/

/*
-----Zadaca 4-----
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <cstring>
#include <iterator>

using namespace std;

class InvalidInputException:public exception{
public:
    void message(){cout<<"The word you entered was invalid"<<endl;}
};

class Besilka{
    char bukva;
    bool pogodok;
public:
    Besilka(char bukva){
        this->bukva=bukva;
        pogodok=false;
    }
    void pogodi(){pogodok=true;}
    char getBukva(){
        return bukva;
    }
    friend ostream &operator<<(ostream &output, const Besilka &b){
        if(b.pogodok)
            output<<b.bukva;
        else
            output<<'-';
        return output;
    }
    friend bool operator==(const Besilka &b1, const Besilka &b2){
        return (b1.bukva==b2.bukva)? true : false;
    }
};

int main(){
    vector<Besilka> zbor;
    cout<<"Vnesi zbor za pogoduvanje"<<endl;
    char guess[10];
    cin>>guess;

    for(int i=0; i<strlen(guess); i++){
        Besilka ins(guess[i]);
        zbor.push_back(ins);
    }

    int choice;
    int numGuesses=strlen(guess) + 3;
    ostream_iterator<Besilka> output(cout);
    int guessRight=0;
    while(numGuesses){
        if(guessRight==zbor.size())
        {
            cout<<"You won!!!!! The word is: ";
            copy(zbor.begin(), zbor.end(), output);
            cout<<endl;
            return 0;
        }

        cout<<"Number or remaining guesses: "<<numGuesses<<endl;
        cout<<"So far you've got: ";
        copy(zbor.begin(), zbor.end(), output);

        cout<<"\n0-Guess letter"<<endl;
        cout<<"1-Guess word"<<endl;
        cin>>choice;

        switch (choice) {
        case 0:
        {
            try {
                char letter;
                cin>>letter;
                if(isalpha(letter) && islower(letter))
                {
                    vector<Besilka>::iterator iter;
                    for(iter=zbor.begin(); iter!=zbor.end(); iter++){
                        if(iter->getBukva()==letter){
                            iter->pogodi();
                            guessRight++;
                        }
                    }
                }
                else
                    throw InvalidInputException();
            } catch (InvalidInputException &iie) {
                iie.message();
            }
            numGuesses--;
            break;
        }
        case 1:
        {
            try {
                char guessWord[zbor.size() + 1];
                cin>>guessWord;
                for(int k=0; k<strlen(guessWord); k++){
                    if(!isalpha(guessWord[k]) || !islower(guessWord[k]))
                        throw InvalidInputException();
                }
                vector<Besilka> guessW;
                for(int k=0; k<strlen(guessWord); k++){
                    guessW.push_back(guessWord[k]);
                }
                if(equal(zbor.begin(), zbor.end(), guessW.begin()))
                {
                    guessRight=zbor.size();
                    vector<Besilka>::iterator iter;
                    for(iter=zbor.begin(); iter!=zbor.end(); iter++){
                        iter->pogodi();
                    }
                }
                else{
                    cout<<"That is not the word"<<endl;
                }
            } catch (InvalidInputException &iie) {
                iie.message();
            }
            numGuesses--;
            break;
        }
        default:
            cout<<"Invalid input"<<endl;
            break;
        }
    }
    cout<<"You lost the game"<<endl;
    return 0;
}
