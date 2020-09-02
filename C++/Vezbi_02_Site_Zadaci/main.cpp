#include <iostream>

using namespace std;

template<class min>
min minimum(min br1, min br2){
    if(br1 <= br2)
        return br1;
    return br2;
}
int main()
{
    int int1, int2;
    float fl1, fl2;
    char c1, c2;
    cout<<"Celi broevi:"<<endl;
    cin>>int1>>int2;
    cout<<"Min: "<<minimum(int1, int2)<<endl;

    cout<<"Realni broevi:"<<endl;
    cin>>fl1>>fl2;
    cout<<"Min: "<<minimum(fl1, fl2)<<endl;

    cout<<"Karakteri:"<<endl;
    cin>>c1>>c2;
    cout<<"Min: "<<minimum(c1, c2)<<endl;

    return 0;
}
