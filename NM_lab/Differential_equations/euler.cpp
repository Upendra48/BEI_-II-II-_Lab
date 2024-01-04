// Implementation of Euler's method
#include <bits/stdc++.h>
using namespace std;

double f(double x, double y){
    return 3*pow(x,2)+1;
}

int main(){
    cout<<"Implementation of Euler's method"<<endl;
    double x0, y0, x, y, h, xn, slope;
    cout<<"Enter x0, y0, difference: ";
    cin >> x0 >> y0 >> h;
    cout << "Enter the calculation point: " << endl;
    cin >> xn;
    x = x0;
    y = y0;

    cout<<"x\t"<<"y\t"<<"slope"<<endl;
    cout<<"-------------------------"<<endl;
    while(x<xn){
        slope = f(x,y);
        cout<<x<<"\t"<<y<<"\t"<<slope<<endl;
        y = y + h*f(x,y);
        x = x + h;
    }
    cout<<x<<"\t"<<y<<"\t"<<slope<<endl;
    return 0;
}

