/*
-----Zadaca 1-----
#include <iostream>
#include <exception>

using namespace std;

class MyException:public exception{
public:
    MyException(){
        cout<<"Kreiranje na obj"<<endl;
    }
    ~MyException(){
        cout<<"Unistuvanje na objekt"<<endl;
    }
};

int main()
{
    MyException obj;
    try {
        MyException *ptr=&obj;
        throw ptr;
    } catch (MyException *me) {
        cout<<"Ako ova se povika pred destruktorot toa e dokazot deka objektot ne se unistuva"<<endl;
    }
    return 0;
}
*/

/*
-----Zadaca 2-----
*/
#include <iostream>
#include <exception>

using namespace std;

class Motor: public exception{
public:
    void printError(){cout<<"Problem so motorot"<<endl;}
};

class Avtomobil{
public:
    Avtomobil(){
        throw Motor();
    }
};

class Garaza{
public:
    Garaza(){
        try {
            Avtomobil();
        } catch (Motor &m) {
            m.printError();
            throw;
        }
    }
};

int main(){
    try {
        Garaza g;
    } catch (...) {
        cout<<"Faten isklucok vo main"<<endl;
    }
    return 0;
}
