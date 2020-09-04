#ifndef DROPKI_H
#define DROPKI_H
class Dropki{
    int broitel;
    int imenitel;
public:
    Dropki(int br=-1, int ime=-1);
    Dropki operator+(Dropki &d);
    Dropki operator-(Dropki &d);
    Dropki operator*(Dropki &d);
    Dropki operator/(Dropki &d);

    Dropki operator+(int broj);
    Dropki operator-(int broj);
    Dropki operator*(int broj);
    Dropki operator/(int broj);

    void print();
    void print_realNumber();
};
#endif // DROPKI_H
