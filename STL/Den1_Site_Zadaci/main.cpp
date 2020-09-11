/*
-----Zadaca 1-----
#include <iostream>

using namespace std;

template <class T>
void vlez(T *niza, int numElem){
    for(int i=0; i<numElem; i++)
        cin>>niza[i];
}

template <class T>
void pecati(const T *niza, int numElem){
    for(int i=0; i<numElem; i++)
        cout<<niza[i]<<" ";
    cout<<endl;
}

template <class T>
void sort(T *niza, int numElem){
    for(int i=0; i<numElem; i++){
        for(int j=i+1; j<numElem; j++){
            if(niza[i]>niza[j]){
                T tmp=niza[i];
                niza[i]=niza[j];
                niza[j]=tmp;
            }
        }
    }
}

int main()
{
    int *n_i=new int[10];
    double *n_d=new double[10];

    vlez(n_i, 10);
    pecati(n_i, 10);
    sort(n_i, 10);
    pecati(n_i, 10);

    vlez(n_d, 10);
    pecati(n_d, 10);
    sort(n_d, 10);
    pecati(n_d, 10);

    delete [] n_i;
    delete [] n_d;
    return 0;
}
*/

/*
-----Zadaca 2-----
#include <iostream>

using namespace std;

template< class T >  //*
int printArray( const T *array, const int count, const int lowSubscript, const int highSubscript)//**
{
    if(lowSubscript<0 || highSubscript>count)
        return 0;
    else{
        for(int i=lowSubscript; i<highSubscript; i++)
            cout<<array[i]<<" ";
        cout<<endl;
        return highSubscript-lowSubscript;
    }
}

template< class T >  //*
void printArray( const T *array, const int count )//**
{
   for ( int i = 0; i < count; i++ )
      cout << array[ i ] << " ";
      cout << endl;
}

int main()

{
   const int aCount = 5;
   const int bCount = 7;
   const int cCount = 6;

   int a[ aCount ] = { 1, 2, 3, 4, 5 };
   double b[ bCount ] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
   char c[ cCount ] = "HELLO";

   cout << "Poleto a sodrzi:" << endl;
   // povikaj int function-template specijalizacija
   int a_i=printArray( a, aCount, 2, 5 );  //***
   cout<<"Se ispecatija "<< a_i<<" elementi"<<endl;

   cout << "Poleto b sodrzi:" << endl;
   // povikaj double function-template specijalizacija
   int b_i=printArray( b, bCount, 1, 5 );  // ***
   cout<<"Se ispecatija "<< b_i<<" elementi"<<endl;

   cout << "Poleto c sodrzi:" << endl;
   // povikaj char function-template specijalizacija
   int c_i=printArray( c, cCount, 0, 7 );  //***
   cout<<"Se ispecatija "<< c_i<<" elementi"<<endl;
   return 0;
} // kraj na main
*/

/*
-----Zadaca 3-----
#include <iostream>

using namespace std;
// Dava greshka i ne moze da se iskompajlire bidejki return tipot na funkcijata mora da e prviot argument kaj template
// koga bi bilo def template<typename R, typename P> togash bi bilo vo red ili moze i ako imame template<typename P, typename R> togash funkcijata
// ako bi bila P implicit_cast(const R& p) togash bi bilo ok
template<typename P, typename R>
R implicit_cast(const P& p) {
  return p;
}
int main() {
  int i = 1;
  float x = implicit_cast<float>(i);
  int j = implicit_cast<int>(x);
}
*/

/*
-----Zadaca 4-----
#include <iostream>

using namespace std;

template< class T >  //*
void printArray( const T *array, const int count )//**
{
   for ( int i = 0; i < count; i++ )
      cout << array[ i ] << " ";
      cout << endl;
}

void printArray( const int *array, const int count )//**
{
   for ( int i = 0; i < count; i++ )
   {
       cout<<array[i]<<" ";
       if((i+1)%4==0)
           cout<<endl;
   }
   cout<<endl;
}

int main()

{
   const int aCount = 10;
   const int bCount = 7;
   const int cCount = 6;

   int a[ aCount ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
   double b[ bCount ] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
   char c[ cCount ] = "HELLO";

   cout << "Poleto a sodrzi:" << endl;
   // povikaj int function-template specijalizacija
   printArray( a, aCount);  //***

   cout << "Poleto b sodrzi:" << endl;
   // povikaj double function-template specijalizacija
   printArray( b, bCount);  // ***

   cout << "Poleto c sodrzi:" << endl;
   // povikaj char function-template specijalizacija
   printArray( c, cCount);  //***
   return 0;
}
*/

/*
-----Zadaca 5-----
#include <iostream>

using namespace std;

template <class T>
class Array{
    T *niza;
    int numElem;
public:
    Array(int numELem=5){
        this->numElem=numELem;
        niza=new T[numELem];
    }
    ~Array(){delete [] niza; }
    void setElem(int index, T elem){
        if(index<0 || index>=numElem)
            cout<<"Invalid input za index "<<index<<endl;
        else{
            niza[index]=elem;
        }
    }
    T getElem(int index){
        if(index<0 || index>=numElem)
        {
            cout<<"Invalid input za index "<<index<<endl;
            return niza[0];
        }
        else{
            return niza[index];
        }
    }
};
int main(){
    Array<int> int_niza(10);
    // vnesuvanje na elem i vnesuvanje na nevaliden index
    for(int i=0; i<11; i++){
        int_niza.setElem(i, i);
    }
    // pecatenje na elem i vnesuvanje na nevaliden elem
    for(int i=0; i<11; i++){
        cout<<int_niza.getElem(i)<<" ";
    }
    cout<<endl;

    Array<double> double_niza;
    // vnesuvanje na elem i vnesuvanje na nevaliden index
    for(int i=0; i<5; i++){
        double_niza.setElem(i, i*2.2);
    }
    // pecatenje na elem i vnesuvanje na nevaliden elem
    for(int i=0; i<5; i++){
        cout<<double_niza.getElem(i)<<" ";
    }
    cout<<endl;
    return 0;
}
*/
