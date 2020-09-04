#include <iostream>
#include "Complex.h"
using namespace std;

int main()
{
    Complex c1, c2;
    int broj;
    cin>>c1>>c2>>broj;
    cout<<"Complex number 1: "<<c1<<endl;
    cout<<"Complex number 2: "<<c2<<endl;

    if(c1==c2)
        cout<<"\nThey are the same"<<endl;
    if(c1!=c2)
        cout<<"\nThey are not the same"<<endl;

    Complex tmpObj;
    tmpObj=c1*c2;
    cout<<"\nob1*ob2 = "<<tmpObj<<endl;
    tmpObj=c1*broj;
    cout<<"ob*int = "<<tmpObj<<endl;
    tmpObj=broj*c1;
    cout<<"int*ob = "<<tmpObj<<endl;

    c1+=c2;
    cout<<"\nob1+=ob2 = "<<c1<<endl;
    c1-=c2;
    cout<<"ob1-=ob2 = "<<c1<<endl;
    c1*=c2;
    cout<<"ob1*=ob2 = "<<c1<<endl;
    c1=c2;
    cout<<"ob1=ob2 = "<<c1<<endl;
    return 0;
}
