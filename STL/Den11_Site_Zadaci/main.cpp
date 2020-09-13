/*
-----Zadaca 1-----
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    cout<<setw(m)<<"col 1"<<setw(m)<<"col 2"<<setw(m)<<"col 3"<<setw(m)<<"col 4"<<endl;
    cout<<setprecision(3)<<fixed;
    for(int i=0; i<n; i++){
        cout<<setw(m)<<i<<setw(m)<<pow(i,2)<<setw(m)<<sqrt(i)<<setw(m)<<pow(i,1.0/3)<<endl;
    }
    return 0;
}
*/

/*
-----Zadaca 2-----
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(){
    ifstream reading("osnovna.txt", ios::in);
    ofstream writing("nova.txt", ios::out);
    if(!reading){
        cout<<"Error occured for reading"<<endl;
        exit(1);
    }
    if(!writing){
        cout<<"Error occured for writing"<<endl;
        exit(1);
    }

    char *zbor=new char[30];
    while(reading>>zbor){
        if(strlen(zbor)<10){
            writing<<zbor<<endl;
        }
    }

    delete [] zbor;
    writing.close();
    reading.close();
    return 0;
}
