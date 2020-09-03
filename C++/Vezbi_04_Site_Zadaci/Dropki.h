#ifndef DROPKI_H
#define DROPKI_H
class Dropki{
    int broitel;
    int imenitel;
public:
    Dropki(int br=-1, int ime=-1);
    void sobiranje(Dropki d);
    void odzemanje(Dropki d);
    void mnozenje(Dropki d);
    void delenje(Dropki d);
    void print();
    void print_realNumber();
    int get_broitel();
    int get_imenitel();
};
#endif // DROPKI_H
