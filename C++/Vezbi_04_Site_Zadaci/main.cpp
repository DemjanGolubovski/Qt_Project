#include <iostream>
#include "Dropki.h"

using namespace std;

int main()
{
    cout<<"0-Sobiranje"<<endl;
    cout<<"1-Odzemanje"<<endl;
    cout<<"2-Mnozenje"<<endl;
    cout<<"3-Delenje"<<endl;
    cout<<"4-END"<<endl;
    int choice;
    int broitel_1, imenitel_1, broitel_2, imenitel_2;
    cin>>choice;
    while(choice!=4){
        switch (choice) {
        case 0:
        {
            cout<<"Vnesi: broitel_1, imenitel_1, broitel_2, imenitel_2"<<endl;
            cin>>broitel_1>>imenitel_1>>broitel_2>>imenitel_2;
            Dropki d1(broitel_1, imenitel_1), d2(broitel_2, imenitel_2);
            d1.sobiranje(d2);
            d1.print();
            d1.print_realNumber();
            break;
        }
        case 1:
        {
            cout<<"Vnesi: broitel_1, imenitel_1, broitel_2, imenitel_2"<<endl;
            cin>>broitel_1>>imenitel_1>>broitel_2>>imenitel_2;
            Dropki d1(broitel_1, imenitel_1), d2(broitel_2, imenitel_2);
            d1.odzemanje(d2);
            d1.print();
            d1.print_realNumber();
            break;
        }
        case 2:
        {
            cout<<"Vnesi: broitel_1, imenitel_1, broitel_2, imenitel_2"<<endl;
            cin>>broitel_1>>imenitel_1>>broitel_2>>imenitel_2;
            Dropki d1(broitel_1, imenitel_1), d2(broitel_2, imenitel_2);
            d1.mnozenje(d2);
            d1.print();
            d1.print_realNumber();
            break;
        }
        case 3:
        {
            cout<<"Vnesi: broitel_1, imenitel_1, broitel_2, imenitel_2"<<endl;
            cin>>broitel_1>>imenitel_1>>broitel_2>>imenitel_2;
            Dropki d1(broitel_1, imenitel_1), d2(broitel_2, imenitel_2);
            d1.delenje(d2);
            d1.print();
            d1.print_realNumber();
            break;
        }
        default:
            break;
        }
        cin>>choice;
    }
    return 0;
}
