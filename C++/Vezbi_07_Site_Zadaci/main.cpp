#include <iostream>
#include "Dropki.h"
using namespace std;

int main()
{
    int broitel_1, imenitel_1,broitel_2, imenitel_2, broj;
    cin>>broitel_1>>imenitel_1>>broitel_2>>imenitel_2>>broj;
    Dropki *d1=new Dropki(broitel_1, imenitel_1);
    Dropki *d2=new Dropki(broitel_2, imenitel_2);

    cout<<"Sobiranje ob1+ob2:"<<endl;
    Dropki tmpObje;
    tmpObje=*d1+*d2;
    tmpObje.print();
    tmpObje.print_realNumber();

    cout<<"Sobiranje ob1+int:"<<endl;
    tmpObje=*d1+broj;
    tmpObje.print();
    tmpObje.print_realNumber();

    cout<<"Odzemanje ob1-ob2:"<<endl;
    tmpObje=*d1-*d2;
    tmpObje.print();
    tmpObje.print_realNumber();

    cout<<"Odzemanje ob1-int:"<<endl;
    tmpObje=*d1-broj;
    tmpObje.print();
    tmpObje.print_realNumber();

    cout<<"Mnozenje ob1*ob2:"<<endl;
    tmpObje=(*d1)*(*d2);
    tmpObje.print();
    tmpObje.print_realNumber();

    cout<<"Mnozenje ob1*int:"<<endl;
    tmpObje=*d1*broj;
    tmpObje.print();
    tmpObje.print_realNumber();

    cout<<"Delenje ob1/ob2:"<<endl;
    tmpObje=(*d1)/(*d2);
    tmpObje.print();
    tmpObje.print_realNumber();

    cout<<"Delenje ob1/int:"<<endl;
    tmpObje=*d1/broj;
    tmpObje.print();
    tmpObje.print_realNumber();

    delete d1;
    d1=0;
    delete d2;
    d2=0;
    return 0;
}
