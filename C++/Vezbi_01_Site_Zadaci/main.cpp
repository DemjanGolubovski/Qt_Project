/*
-----Zadaca 1-----
#include <iostream>

using namespace std;

inline void circleArea(int radius){ cout<<"Radius: "<<radius*radius*3.14<<endl; }

int main()
{
    int radius;
    cin>>radius;
    circleArea(radius);
    return 0;
}
*/

/*
-----Zadaca 2-----
#include <iostream>

using namespace std;

inline int tripleCallByValue(int count){ return count*3; }
inline void tripleCallByReference(int &count){ count*=3; }

int main()
{
    int count;
    cin>>count;
    cout<<"By value: "<<tripleCallByValue(count)<<endl;
    tripleCallByReference(count);
    cout<<"By reference: "<<count<<endl;
    return 0;
}
*/
