#ifndef MATRICA_H
#define MATRICA_H

#include <iomanip>
using namespace std;

class Matrica{
    int redici, koloni;
    int *matrica;
public:
    friend ostream &operator<<(ostream &, const Matrica &);
    friend istream &operator>>(istream &, Matrica &);

    Matrica(int red=1, int kol=1);
    Matrica(int red, int kol, int *mat);
    Matrica(const Matrica &);
    ~Matrica();

    const Matrica &operator=(const Matrica &);

    bool operator==(const Matrica &) const;
    bool operator!=(const Matrica &) const;

    Matrica operator+(const Matrica &) const;
    Matrica operator+(const int broj) const;
    friend Matrica operator+(const int broj, const Matrica &);

    Matrica operator-(const Matrica &) const;
    Matrica operator-(const int broj) const;
    friend Matrica operator-(const int broj, const Matrica &);

    Matrica operator*(const Matrica &) const;
    Matrica operator*(const int broj) const;
    friend Matrica operator*(const int broj, const Matrica &);

    int &operator[](int);
    const int &operator[](int) const;

    operator int*(){ return matrica; } // ????????????????????????????????????????????????????????????????/
};
#endif // MATRICA_H
