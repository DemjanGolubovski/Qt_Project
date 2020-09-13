#include <iostream>
#include <vector>
#include <exception>
#include <iterator>

using namespace std;

class NoSpaceException: public exception{
    int s_1, s_2;
public:
    NoSpaceException(int s_1, int s_2){
        this->s_1=s_1;
        this->s_2=s_2;
    }
    void printError(){
        cout<<"No space exception with sizes ("<<s_1<<", "<<s_2<<")"<<endl;
    }
};

int main()
{
    for(int i=0; i<5; i++){
        vector<int> v1;
        vector<int> v2;
        int s_1=rand()%1000;
        int s_2=rand()%1000;
        try {
            if(s_1<s_2)
                throw NoSpaceException(s_1, s_2);
            else{
                for(int j=0; j<s_2; j++)
                    v2.push_back(rand()%1000);

                copy(v2.begin(), v2.end(), back_inserter(v1));
            }
        }catch (NoSpaceException &nse) {
            nse.printError();
        }
    }
    return 0;
}
