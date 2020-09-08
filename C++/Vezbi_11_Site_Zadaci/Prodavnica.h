#ifndef PRODAVNICA_H
#define PRODAVNICA_H

#include <iomanip>
using namespace std;

class Datum{
    int den, mesec, godina;
public:
    Datum(int den=-1, int mesec=-1, int godina=-1);
    int getDen() const;
    int getMesec() const;
    int getGodina() const;
    void setDen(const int den);
    void setMesec(const int mesec);
    void setGodina(const int godina);
    friend ostream &operator<<(ostream &output, const Datum &d);
};
// Apstraktna klasca
class Artikl{
protected:
    char *ime;
    char *golemina; // XS, S, M, L, ...
    int cena;
    Datum datum_donesen;
public:
    Artikl(char *ime="", char *golemina="", int cena=0, Datum datum_donesen=0);
    virtual ~Artikl();
    virtual void prikazi_podatoci() const;
    virtual int presmetaj_nabavka(Datum currDate)=0; // cista virtuelna funkcija
};

class Pantaloni:public Artikl{
    Datum datum_sledna_nabavka;
public:
    Pantaloni(char *ime="", char *golemina="", int cena=0, Datum datum_donesen=0, Datum datum_sledna_nabavka=0);
    void prikazi_podatoci() const;
    int presmetaj_nabavka(Datum currDate);
};

class Kosuli:public Artikl{
public:
    Kosuli(char *ime="", char *golemina="", int cena=0, Datum datum_donesen=0);
    void prikazi_podatoci() const;
    int presmetaj_nabavka(Datum currDate);
};

#endif // PRODAVNICA_H
