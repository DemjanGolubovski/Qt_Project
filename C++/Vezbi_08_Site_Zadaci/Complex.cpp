#include <iostream>
#include "Complex.h"
using namespace std;

Complex::Complex( double r, double i ): real( r ), imaginary( i ) { }

const Complex Complex::operator+=( const Complex &operand2 )
{
    real=real+operand2.real;
    imaginary=imaginary+operand2.imaginary;
    return *this;
}
const Complex Complex::operator-=( const Complex &operand2 )
{
    real=real-operand2.real;
    imaginary=imaginary-operand2.imaginary;
    return *this;
}
const Complex Complex::operator*=( const Complex &operand2 )
{
    Complex tmp;
    tmp.real=real;
    tmp.imaginary=imaginary;
    real=tmp.real*operand2.real-tmp.imaginary*operand2.imaginary;
    imaginary=tmp.real*operand2.imaginary+tmp.imaginary*operand2.real;
    return *this;
}
const Complex& Complex::operator=( const Complex &right )
{
   real = right.real;
   imaginary = right.imaginary;
   return *this;
}
ostream &operator<<(ostream &output, const Complex &c){
    output<<'('<<c.real<<", "<<c.imaginary<<')';
    return output;
}
istream &operator>>(istream &input,Complex &c){
    input>>c.real;
    input>>c.imaginary;
    return input;
}
Complex Complex::operator*(const Complex &c) const{
    Complex tmp;
    tmp.real=real*c.real-imaginary*c.imaginary;
    tmp.imaginary=real*c.imaginary+imaginary*c.real;
    return tmp;
}
Complex Complex::operator*(const int broj) const{
    Complex tmp;
    tmp.real=real*broj;
    tmp.imaginary=imaginary*broj;
    return tmp;
}
Complex operator*(const int broj, const Complex &c){
    Complex tmp;
    tmp.real=c.real*broj;
    tmp.imaginary=c.imaginary*broj;
    return tmp;
}
bool Complex::operator==(const Complex &c) const{
    return (real==c.real && imaginary==c.imaginary);
}
bool Complex::operator!=(const Complex &c) const{
    return (real!=c.real || imaginary!=c.imaginary);
}
