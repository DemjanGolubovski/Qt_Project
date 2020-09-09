#include <iostream>
#include "Oblici.h"

using namespace std;
// inicijalizacija na static variables
int Oblik::brOblik=0;
int DvoDimenzionalni::brDvoD=0;
int TroDimenzionalni::brTroD=0;
int Krug::brKrug=0;
int Kvadrat::brKvadrat=0;
int Triagolnik::brTriagolnik=0;
int Topka::brTopki=0;
int Kocka::brKocki=0;
int Piramida::brPiramidi=0;

Oblik::Oblik(){
    brOblik++;
}
Oblik::~Oblik(){
    brOblik--;
}
int Oblik::getBrOblik(){
    return brOblik;
}

DvoDimenzionalni::DvoDimenzionalni(){
    brDvoD++;
}
DvoDimenzionalni::~DvoDimenzionalni(){
    brDvoD--;
}
void DvoDimenzionalni::display(){
    cout<<"2D figura"<<endl;
}
int DvoDimenzionalni::getBrDvoD(){
    return brDvoD;
}

TroDimenzionalni::TroDimenzionalni(){
    brTroD++;
}
TroDimenzionalni::~TroDimenzionalni(){
    brTroD--;
}
void TroDimenzionalni::display(){
    cout<<"3D figura"<<endl;
}
int TroDimenzionalni::getBrTroD(){
    return brTroD;
}

Krug::Krug(){
    brKrug++;
}
Krug::~Krug(){
    brKrug--;
}
void Krug::display(){
    cout<<"Krug"<<endl;
}
int Krug::getBrKrug(){
    return brKrug;
}

Kvadrat::Kvadrat(){
    brKvadrat++;
}
Kvadrat::~Kvadrat(){
    brKvadrat--;
}
void Kvadrat::display(){
    cout<<"Kvadrat"<<endl;
}
int Kvadrat::getBrKvadrat(){
    return brKvadrat;
}

Triagolnik::Triagolnik(){
    brTriagolnik++;
}
Triagolnik::~Triagolnik(){
    brTriagolnik--;
}
void Triagolnik::display(){
    cout<<"Triagolnik"<<endl;
}
int Triagolnik::getBrTriagolnik(){
    return brTriagolnik;
}

Topka::Topka(){
    brTopki++;
}
Topka::~Topka(){
    brTopki--;
}
void Topka::display(){
    cout<<"Topka"<<endl;
}
int Topka::getBrTopka(){
    return brTopki;
}

Kocka::Kocka(){
    brKocki++;
}
Kocka::~Kocka(){
    brKocki--;
}
void Kocka::display(){
    cout<<"Kocka"<<endl;
}
int Kocka::getBrKocka(){
    return brKocki;
}

Piramida::Piramida(){
    brPiramidi++;
}
Piramida::~Piramida(){
    brPiramidi--;
}
void Piramida::display(){
    cout<<"Piramida"<<endl;
}
int Piramida::getBrPiramida(){
    return brPiramidi;
}
