#ifndef COMPLEX_H
#define COMPLEX_H
#include <iomanip>
using namespace std;
class Complex {
public:
   Complex( double = 0.0, double = 0.0 );       // konstruktor
   const Complex operator+=( const Complex & );  // sobiranje
   const Complex operator-=( const Complex & );  // odzemanje
   const Complex operator*=( const Complex & ); // mnozenje

   const Complex &operator=( const Complex & ); // dodeluvanje

   friend ostream &operator<<(ostream &,const Complex &);
   friend istream &operator>>(istream &, Complex &);

   Complex operator*(const Complex &) const; // mnozenje ob1*ob2
   Complex operator*(const int broj) const; // mnozenje ob*int
   friend Complex operator*(const int broj, const Complex &); // mnozenje int*ob

   bool operator==(const Complex &) const; // ob1==ob2
   bool operator!=(const Complex &) const; // ob1!=ob2

private:
   double real;       // realen del
   double imaginary;  // imaginaren del
};

#endif // COMPLEX_H
