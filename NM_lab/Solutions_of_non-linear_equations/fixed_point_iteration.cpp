// Fixed Point Iteration Method

#include <bits/stdc++.h>
using namespace std;

#define EPSILON 0.01

double func(double x)
{
    return x*x-4;
}

int main(){
    double a, b,x1 = 0;
    cout << "Enter the initial guess: ";
    cin >> a >> b;
    if(  a > b && func(a) * func(b) > 0){
        cout << "Incorrect guess\n";
        return 0;
    }
    else{
        double x0 = (a + b) / 2;
        do{
            double x1 = func(x0);
            x0 = x1;
        } while(fabs(func(x1)) > EPSILON);
        cout << x1 << endl;
    }
    return 0;
}
