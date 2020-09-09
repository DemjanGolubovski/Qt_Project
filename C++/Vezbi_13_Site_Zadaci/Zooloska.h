#ifndef ZOOLOSKA_H
#define ZOOLOSKA_H

#include <iomanip>
using namespace std;

class Datum{
    int den, mesec, godina;
public:
    Datum(int den=0, int mesec=0, int godina=0);
    void setDen(const int den);
    void setMesec(const int mesec);
    void setGodina(const int godina);
    int getDen() const;
    int getMesec() const;
    int getGodina() const;
    friend ostream& operator<<(ostream &output, const Datum &date);
};

class Zivotno{
private:
    static int brZivotni;
protected:
    Datum datumRagjanje;
    Datum datumDoneseno;
    char pol; // (m/z)
    char *ime;
    Datum datumVakcinirano;
public:
    Zivotno(Datum datumRagjanje=0, Datum datumDoneseno=0, char pol=' ', char *ime="", Datum datumVakcinirano=0);
    virtual void prikazi_podatoci();
    virtual int presmetaj_vakcinacija(Datum currDate)=0;
    virtual ~Zivotno();
    static int getBrZivotni();
};

class Vlekaci:public Zivotno{
    Datum datumSlednaVakcinacija;
    static int brVlekaci;
public:
    Vlekaci(Datum datumRagjanje=0, Datum datumDoneseno=0, char pol=' ', char *ime="", Datum datumVakcinirano=0,
            Datum datumSlednaVakcinacija=0);
    void prikazi_podatoci();
    int presmetaj_vakcinacija(Datum currDate);
    static int getBrVlekaci();
};

class Ptici:public Zivotno{
    char letac; // (d/n)
    static int brPtici;
public:
    Ptici(Datum datumRagjanje=0, Datum datumDoneseno=0, char pol=' ', char *ime="", Datum datumVakcinirano=0,
          char letac=' ');
    void prikazi_podatoci();
    int presmetaj_vakcinacija(Datum currDate);
    static int getBrPtici();
};

class Cicaci:public Zivotno{
    char prezivar; // (d/n)
    static int brCicaci;
public:
    Cicaci(Datum datumRagjanje=0, Datum datumDoneseno=0, char pol=' ', char *ime="", Datum datumVakcinirano=0,
          char prezivar=' ');
    void prikazi_podatoci();
    int presmetaj_vakcinacija(Datum currDate);
    static int getBrCicaci();
};

#endif // ZOOLOSKA_H
