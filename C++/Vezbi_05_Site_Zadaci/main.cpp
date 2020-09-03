#include <iostream>
#include "Zooloska.h"
using namespace std;

int main()
{
    int n;
    cin>>n;
    Zivotno zivotni[n];
    int index=0;
    cout<<"0-Dodadi zivotno"<<endl;
    cout<<"1-Prikazi broj na zivotni"<<endl;
    cout<<"2-Prikazi zivotni od dadena grupa"<<endl;
    cout<<"3-Prikazi site zivotni"<<endl;
    cout<<"4-Site zivotni koi treba da se vakciniraaat za 1 nedela"<<endl;
    cout<<"5-END"<<endl;
    int choice;
    cin>>choice;
    while(choice!=5){
        switch (choice) {
        case 0:
        {
            if(index<n){
            cout<<"Vnesi: datum na raganje_den, datum na raganje_mesec, datum na raganje_godina, datum doneseno vo zooloska_den, "
                  "datum doneseno vo zooloska_mesec, datum doneseno vo zooloska_godina,datum na vakcinacija_den, datum na vakcinacija_mesec,"
                  "datum na vakcinacija_godina, tip, pol, ime"<<endl;
            int dr_den, dr_mesec, dr_godina, dz_den, dz_mesec, dz_godina, dv_den, dv_mesec, dv_godina;
            char tip, pol;
            char ime[20];
            cin>>dr_den>>dr_mesec>>dr_godina>>dz_den>>dz_mesec>>dz_godina>>dv_den>>dv_mesec>>dv_godina>>tip>>pol>>ime;
            zivotni[index++].setObjekt(dr_den, dr_mesec, dr_godina, dz_den, dz_mesec, dz_godina, dv_den, dv_mesec, dv_godina, tip, pol, ime);}
            else
                cout<<"The zoo is full"<<endl;
            break;
        }
        case 1:
        {
            cout<<"Momentalno ima "<<index<<" zivotni"<<endl;
            break;
        }
        case 2:
        {
            char grupa;
            cin>>grupa;
            for(int i=0;i<index; i++){
                if(zivotni[i].getTip()==grupa)
                    zivotni[i].prikazi_podatoci();
            }
            break;
        }
        case 3:
        {
            for(int i=0;i<index; i++){
                zivotni[i].prikazi_podatoci();
            }
            break;
        }
        case 4:
        {
            int den, mesec, godina;
            cin>>den>>mesec>>godina;
            Datum tmp_date(den, mesec, godina);
            for(int i=0;i<index; i++){
                zivotni[i].presmetaj_vakcinacija(tmp_date);
            }
            break;
        }
        default:
            break;

        }
        cin>>choice;
    }
    return 0;
}
