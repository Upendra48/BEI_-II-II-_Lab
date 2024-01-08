// Implementation of fibonacci series using recursion

#include <iostream>
using namespace std;

int Fact(int n){
    if(n==0 || n==1){
        
        return 1;
    }
    return Fact(n-1) + Fact(n-2);
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout << Fact(n) << endl;
    return 0;
}