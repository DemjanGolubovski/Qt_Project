#include <iostream>
#include "Stedac.h"
using namespace std;


int main()
{
    // Demo-prikaz na funkcionalnosti
    cout<<"Default kamata: "<<Stedac::getKamata()<<endl;
    cout<<"Default broj na stedaci: "<<Stedac::getStedaci()<<endl;
    Stedac::setKamata(1.5);
    cout<<"Promeneta kamata: "<<Stedac::getKamata()<<endl;

    Stedac *stedac_1=new Stedac("Name", "Last Name", "Address", "012345678", 100, 20);
    cout<<"Ime: "<<stedac_1->getLice().getIme()<<", Prezime: "<<stedac_1->getLice().getPrezime()<<", Adresa: "<<
          stedac_1->getLice().getAdresa()<<", Telefon: "<<stedac_1->getLice().getTel()<<endl;
    cout<<"Bilans: "<<stedac_1->getBilans()<<", Kredit: "<<stedac_1->getKredit()<<endl;
    cout<<"Broj na stedaci: "<<stedac_1->getStedaci()<<endl;
    delete stedac_1;
    stedac_1=0;

    cout<<"Broj na stedaci: "<<Stedac::getStedaci()<<endl;
    Stedac *stedaci=new Stedac[2];
    cout<<"Broj na stedaci: "<<Stedac::getStedaci()<<endl;
    Covek *c=new Covek("Name_1", "Last Name_1", "Address_1", "123456789");
    stedaci[1].setLice(*c);
    stedaci[1].setBilans(2000);
    stedaci[1].setKredit(30);

    cout<<"Ime: "<<stedaci[1].getLice().getIme()<<", Prezime: "<<stedaci[1].getLice().getPrezime()<<", Adresa: "<<
          stedaci[1].getLice().getAdresa()<<", Telefon: "<<stedaci[1].getLice().getTel()<<endl;
    cout<<"Bilans: "<<stedaci[1].getBilans()<<", Kredit: "<<stedaci[1].getKredit()<<endl;

    delete [] stedaci;
    delete c;
    c=0;
    cout<<"Broj na stedaci: "<<Stedac::getStedaci()<<endl;
    return 0;
}
