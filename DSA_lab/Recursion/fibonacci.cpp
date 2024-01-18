// Implementation of fibonacci series using recursion

#include <iostream>
using namespace std;

// int fib(int n);

int fib(int n){
    if(n==0 || n==1){
        return n;
    }
    return fib(n-1) + fib(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}


// Dynamic Programming

// int fib(int n){
//     int f[n+1];
//     f[0] = 0;
//     f[1] = 1;
//     for(int i=2; i<=n; i++){
//         f[i] = f[i-1] + f[i-2];
//     }
//     return f[n];
// }