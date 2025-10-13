#include<bits/stdc++.h>
using namespace std;

class First{

    private:
    

    public:
    First(){
        cout<<"Object Created\n"<<endl;
    }
    ~First(){
        cout<<"Destructor"<<endl;
    }

};


int main(){
    First obj;
    return 0;
}