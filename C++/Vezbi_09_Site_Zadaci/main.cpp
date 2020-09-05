#include <iostream>
# include "Matrica.h"

using namespace std;

int main()
{
    Matrica m1(2, 2), m2(2, 2);
    int broj;
    cout<<"Vnesi matrici i broj"<<endl;
    cin>>m1>>m2>>broj;

    cout<<"Pecatenje na matrici"<<endl;
    cout<<m1<<endl;
    cout<<m2;

    cout<<"\nSporedba na matrici"<<endl;
    if(m1==m2)
        cout<<"Isti se"<<endl;
    if(m1!=m2)
        cout<<"Ne se isti"<<endl<<endl;

    cout<<"Copy constructor"<<endl;
    Matrica m3(m1); // copy constructor
    cout<<m3;

    cout<<"\nSobiranje:"<<endl;
    cout<<"mat1+mat2"<<endl;
    Matrica mTmp;
    mTmp=m1+m2;
    cout<<mTmp<<endl;

    cout<<"mat1+int"<<endl;
    mTmp=m1+broj;
    cout<<mTmp<<endl;

    cout<<"int+mat1"<<endl;
    mTmp=broj+m1;
    cout<<mTmp<<endl;

    cout<<"\nOdzemanje:"<<endl;
    cout<<"mat1-mat2"<<endl;
    mTmp=m1-m2;
    cout<<mTmp<<endl;

    cout<<"mat1-int"<<endl;
    mTmp=m1-broj;
    cout<<mTmp<<endl;

    cout<<"int-mat1"<<endl;
    mTmp=broj-m1;
    cout<<mTmp<<endl;

    cout<<"\nMnozenje:"<<endl;
    cout<<"mat1*mat2"<<endl;
    mTmp=m1*m2;
    cout<<mTmp<<endl;

    cout<<"mat1*int"<<endl;
    mTmp=m1*broj;
    cout<<mTmp<<endl;

    cout<<"int*mat1"<<endl;
    mTmp=broj*m1;
    cout<<mTmp<<endl;

    cout<<"Kastiranje:"<<endl;
    int *matrica;
    matrica=m1;
    for(int i=0; i<4; i++)
        cout<<matrica[i]<<" ";
    cout<<endl;

    cout<<"\nConversion constructor"<<endl;
    int matrica_2[4]={5,5,5,5};
    Matrica m4={2,2,matrica_2};
    cout<<m4<<endl;
    return 0;
}
