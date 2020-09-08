#ifndef VRABOTEN_H
#define VRABOTEN_H

#include <iomanip>
using namespace std;

class Vraboten{
    char *ime, *prezime;
    int godina_vrabotuvanje;
public:
    Vraboten(char *name="", char *lastN="", int year=0);
    virtual ~Vraboten();
    void postavi(char *name="", char *lastN="", int year=0);
    void prikazi_podatoci(); // moze da se stavi i kako virtual i da ne se koristi dynamic_cast
};

class Profesor: public Vraboten{
    char *zvanje, *oblast;
    int br_predmeti;
public:
    Profesor(char *name="", char *lastN="", int year=0, char *job="", char *field="", int numSubj=0);
    ~Profesor();
    void postavi(char *name="", char *lastN="", int year=0, char *job="", char *field="", int numSubj=0);
    void prikazi_podatoci();
};

class Asistent:public Vraboten{
    char *zvanje, *mentor;
    int br_predmeti;
public:
    Asistent(char *name="", char *lastN="", int year=0, char *job="", char *teach="", int numSubj=0);
    ~Asistent();
    void postavi(char *name="", char *lastN="", int year=0, char *job="", char *teach="", int numSubj=0);
    void prikazi_podatoci();
};

class Demonstrator:public Vraboten{
    char *rabotno_vreme;
public:
    Demonstrator(char *name="", char *lastN="", int year=0, char *workHours="");
    ~Demonstrator();
    void postavi(char *name="", char *lastN="", int year=0, char *workHours="");
    void prikazi_podatoci();
};

#endif // VRABOTEN_H
