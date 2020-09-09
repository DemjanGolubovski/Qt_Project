#ifndef OBLICI_H
#define OBLICI_H
class Oblik{
    static int brOblik;
public:
    Oblik();
    virtual void display()=0;
    static int getBrOblik();
    virtual ~Oblik();
};
class DvoDimenzionalni: public Oblik{
    static int brDvoD;
public:
    DvoDimenzionalni();
    void display();
    static int getBrDvoD();
    virtual ~DvoDimenzionalni();
};
class TroDimenzionalni:public Oblik{
    static int brTroD;
public:
    TroDimenzionalni();
    void display();
    static int getBrTroD();
    virtual ~TroDimenzionalni();
};
class Krug:public DvoDimenzionalni{
    static int brKrug;
public:
    Krug();
    void display();
    static int getBrKrug();
    ~Krug();
};
class Kvadrat:public DvoDimenzionalni{
    static int brKvadrat;
public:
    Kvadrat();
    void display();
    static int getBrKvadrat();
    ~Kvadrat();
};
class Triagolnik:public DvoDimenzionalni{
    static int brTriagolnik;
public:
    Triagolnik();
    void display();
    static int getBrTriagolnik();
    ~Triagolnik();
};
class Kocka:public TroDimenzionalni{
    static int brKocki;
public:
    Kocka();
    void display();
    static int getBrKocka();
    ~Kocka();
};
class Piramida:public TroDimenzionalni{
    static int brPiramidi;
public:
    Piramida();
    void display();
    static int getBrPiramida();
    ~Piramida();
};
class Topka:public TroDimenzionalni{
    static int brTopki;
public:
    Topka();
    void display();
    static int getBrTopka();
    ~Topka();
};

#endif // OBLICI_H
