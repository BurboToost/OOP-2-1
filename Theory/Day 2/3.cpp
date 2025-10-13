#include<bits/stdc++.h>
using namespace std;

class Base{
    public:
    int a = 5;


};
class Derived: private Base{
    public:
    int b=10;
};

int main(){
    Derived ob;
    //cout<<ob.a<<endl;

    Derived ob2;
    cout<<ob2.a<<endl;
}
