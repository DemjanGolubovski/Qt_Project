#include <iostream>
#include <cassert>
#include "Matrica.h"

using namespace std;

// Constructor
Matrica::Matrica(int red, int kol){
    redici=red;
    koloni=kol;
    matrica=new int[red*kol];
    assert(matrica!=0);
    for(int i=0; i<red*kol; i++){
        matrica[i]=0;
    }
}
// Constructor
Matrica::Matrica(int red, int kol, int *mat){
    redici=red;
    koloni=kol;
    matrica=new int[red*kol];
    assert(matrica!=0);
    for(int i=0; i<red*kol; i++){
        matrica[i]=mat[i];
    }
}
// Copy construcotr
Matrica::Matrica(const Matrica &m): redici(m.redici), koloni(m.koloni){
    matrica=new int[redici*koloni];
    assert(matrica!=0);
    for(int i=0; i<redici*koloni; i++){
        matrica[i]=m.matrica[i];
    }
}
// Destructor
Matrica::~Matrica(){
    delete [] matrica;
}
const Matrica &Matrica::operator=(const Matrica &m){
    if(&m!=this){
        if(redici!=m.redici && koloni!=m.koloni){
            delete [] matrica;
            redici=m.redici;
            koloni=m.koloni;
            matrica=new int[redici*koloni];
            assert(matrica!=0);
        }
        for(int i=0; i<redici*koloni; i++){
            matrica[i]=m.matrica[i];
        }
    }
    return *this;
}
ostream &operator<<(ostream &output, const Matrica &m){
    output<<"["<<m.redici<<", "<<m.koloni<<"]"<<endl;
    for(int i=0; i<m.redici*m.koloni; i++){
        output<<m.matrica[i];
        if((i+1)%m.koloni==0)
            output<<endl;
        else
            output<<" ";
    }
    return output;
}
istream &operator>>(istream &input, Matrica &m){
    for(int i=0; i<m.redici*m.koloni; i++)
        input>>m.matrica[i];
    return input;
}
int &Matrica::operator[](int index){ //left side
    assert(index>=0 && index<(redici*koloni));
    return matrica[index];
}
const int &Matrica::operator[](int index) const{ //right side
    assert(index>=0 && index<(redici*koloni));
    return matrica[index];
}
bool Matrica::operator==(const Matrica &m) const{
    if(redici==m.redici && koloni==m.koloni)
    {
        for(int i=0; i<redici*koloni; i++){
            if(matrica[i]!=m.matrica[i])
                return false;
        }
        return true;
    }
    return false;
}
bool Matrica::operator!=(const Matrica &m) const{
    return !(*this==m);
}
Matrica Matrica::operator+(const Matrica &m) const{
    assert(redici==m.redici && koloni==m.koloni);
    Matrica tmpObj(redici, koloni);
    for(int i=0; i<redici*koloni; i++)
        tmpObj.matrica[i]=matrica[i]+m.matrica[i];
    return tmpObj;
}
Matrica Matrica::operator+(const int broj) const{
    Matrica tmpObj(redici, koloni);
    for(int i=0; i<redici*koloni; i++)
        tmpObj.matrica[i]=matrica[i]+broj;
    return tmpObj;
}
Matrica operator+(const int broj,const Matrica &m){
    Matrica tmpObj(m.redici, m.koloni);
    for(int i=0; i<m.redici*m.koloni; i++)
        tmpObj.matrica[i]=m.matrica[i]+broj;
    return tmpObj;
}
Matrica Matrica::operator-(const Matrica &m) const{
    assert(redici==m.redici && koloni==m.koloni);
    Matrica tmpObj(redici, koloni);
    for(int i=0; i<redici*koloni; i++)
        tmpObj.matrica[i]=matrica[i]-m.matrica[i];
    return tmpObj;
}
Matrica Matrica::operator-(const int broj) const{
    Matrica tmpObj(redici, koloni);
    for(int i=0; i<redici*koloni; i++)
        tmpObj.matrica[i]=matrica[i]-broj;
    return tmpObj;
}
Matrica operator-(const int broj,const Matrica &m){
    Matrica tmpObj(m.redici, m.koloni);
    for(int i=0; i<m.redici*m.koloni; i++)
        tmpObj.matrica[i]=-m.matrica[i]+broj;
    return tmpObj;
}
Matrica Matrica::operator*(const Matrica &m) const{
    assert(koloni==m.redici);
    Matrica tmpObj(redici, m.koloni);
    int index=0;
    while(index<(redici*m.koloni)){
        int mat_1=0, mat_2=0;
        int tmpRed=index/m.koloni;
        int tmpKol=index%m.koloni;
        int suma=0;
        while(mat_1<(redici*koloni) && mat_2<(m.koloni*m.redici)){
            if(mat_1/koloni==tmpRed && mat_2%koloni==tmpKol){
                suma=suma+matrica[mat_1]*m.matrica[mat_2];
                mat_1++;
                mat_2++;
            }
            else if(mat_1/koloni!=tmpRed && mat_2%koloni!=tmpKol){
                mat_1++;
                mat_2++;
            }
            else if(mat_1/koloni!=tmpRed && mat_2%koloni==tmpKol){
                mat_1++;
            }
            else{
                mat_2++;
            }
        }
        tmpObj.matrica[index]=suma;
        index++;
    }
    return tmpObj;
}
Matrica Matrica::operator*(const int broj) const{
    Matrica tmpObj(redici, koloni);
    for(int i=0; i<redici*koloni; i++)
        tmpObj.matrica[i]=matrica[i]*broj;
    return tmpObj;
}
Matrica operator*(const int broj,const Matrica &m){
    Matrica tmpObj(m.redici, m.koloni);
    for(int i=0; i<m.redici*m.koloni; i++)
        tmpObj.matrica[i]=m.matrica[i]*broj;
    return tmpObj;
}
