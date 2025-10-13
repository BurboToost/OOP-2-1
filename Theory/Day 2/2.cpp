#include<bits/stdc++.h>
using namespace std;

class First{

    private:
    int a,b;

    public:
    First(int x, int y){
        a=x;
        b=y;

    }
    First(const First &ob){
    a=ob.a;
    b=ob.b;
}

    ~First(){
        cout<<"Destructor"<<endl;
    }

};


int main(){
    First obj(7,12);
    First ob2(obj);
}