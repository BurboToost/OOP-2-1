#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class First{
    private:
        double amount=200000;

    public:
    void update(double wiBal){
        if(wiBal>amount){cout<<"Not Enough Balance"<<endl;}
        else if(wiBal<=amount){
            int rem=amount-wiBal;
            cout<<"Remaining Balance"<<rem<<endl;
        }
    }


};


int main(){
    double wiBal;
    cin>>wiBal;
    First obj;
    obj.update(wiBal);

}