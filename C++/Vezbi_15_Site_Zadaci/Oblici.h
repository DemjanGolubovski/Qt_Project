#ifndef OBLICI_H
#define OBLICI_H
class Oblik{
public:
    virtual void print()=0;
    virtual float plostina();
    virtual float volumen();
    virtual ~Oblik();
};
class DvoDimenzionalni:public Oblik{
public:
    void print();
    virtual float plostina()=0;
};
class TroDimenzionalni:public Oblik{
public:
    void print();
    virtual float plostina()=0;
    virtual float volumen()=0;
};
class Krug:public DvoDimenzionalni{
    float radius;
public:
    Krug(float radius=0.0);
    void print();
    float plostina();
};
class Kvadrat:public DvoDimenzionalni{
    float strana;
public:
    Kvadrat(float strana=0.0);
    void print();
    float plostina();
};
class Triagolni:public DvoDimenzionalni{
    float visina, strana;
public:
    Triagolni(float visina=0.0, float strana=0.0);
    void print();
    float plostina();
};
class Topka:public TroDimenzionalni{
    float radius;
public:
    Topka(float radius=0.0);
    void print();
    float plostina();
    float volumen();
};
class Kocka:public TroDimenzionalni{
    float strana;
public:
    Kocka(float strana=0.0);
    void print();
    float plostina();
    float volumen();
};
class Cilindar:public TroDimenzionalni{
    float visina, radius;
public:
    Cilindar(float visina=0.0, float radius=0.0);
    void print();
    float plostina();
    float volumen();
};

#endif // OBLICI_H
