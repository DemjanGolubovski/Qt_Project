#ifndef STEDAC_H
#define STEDAC_H
class Covek{
    char *ime;
    char *prezime;
    char *adresa;
    char *telefon;
public:
    // Konstruktor
    Covek(char *name="", char *lastN="", char *add="", char *tel="");
    // Set metodi
    void setIme(char *name);
    void setPrezime(char *lastN);
    void setAddresa(char *add);
    void setTel(char *tel);
    // Get metodi
    char *getIme() const;
    char *getPrezime() const;
    char *getAdresa() const;
    char *getTel() const;
    // Destruktor
    ~Covek();
};

class Stedac{
    static float kamata;
    static int brojStedaci;
    Covek lice;
    int bilans;
    int kredit;
public:
    // Konstruktor
    Stedac(char *name="", char *lastN="", char *add="", char *tel="", int bil=0, int kred=0);
    // Destruktor
    ~Stedac();
    // Set metodi
    void setLice(Covek c);
    void setKredit(int kred);
    void setBilans(int bil);
    // Get metodi
    int getBilans() const;
    int getKredit() const;
    Covek getLice() const;
    // Static funkcii
    static void setKamata(float cashKamata);
    static float getKamata();
    static int getStedaci();

};

#endif // STEDAC_H
