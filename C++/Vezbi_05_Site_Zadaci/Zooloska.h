#ifndef ZOOLOSKA_H
#define ZOOLOSKA_H
class Datum{
    int den, mesec, godina;
public:
    Datum(int d=-1, int m=-1, int g=-1);
    int get_den();
    int get_mesec();
    int get_godina();
    void set_den(int d);
    void set_mesec(int m);
    void set_godina(int g);
};

class Zivotno{
    Datum datum_ragjanje;
    Datum datum_doneseno_vo_zooloska;
    Datum datum_vakcina;
    char tip;
    char pol;
    char ime[20];
public:
    Zivotno(int dr_den=-1, int dr_mesec=-1, int dr_godina=-1, int dz_den=-1, int dz_mesec=-1, int dz_godina=-1,
            int dv_den=-1, int dv_mesec=-1, int dv_godina=-1, char tip='c', char pol='m', char *ime="");
    void prikazi_podatoci();
    void presmetaj_vakcinacija(Datum currDate);
    void setObjekt(int dr_den=-1, int dr_mesec=-1, int dr_godina=-1, int dz_den=-1, int dz_mesec=-1, int dz_godina=-1,
                   int dv_den=-1, int dv_mesec=-1, int dv_godina=-1, char tip='c', char pol='m', char *ime="");
    char getTip();
};

#endif // ZOOLOSKA_H
