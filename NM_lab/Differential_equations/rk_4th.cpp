// Implementation of RK 4 method

#include <iostream>
using namespace std;

double f(double x, double y)
{
    return (y-x)/(y+x);
}

int main(){
    double x0, y0, xn, h, k1, k2, k3, k4, k;
    cout << "Enter x0, y0, xn, h: ";
    cin >> x0 >> y0 >> xn >> h;
    cout << "x0 = " << x0 << "\ny0 = " << y0 << "\nxn = " << xn << "\nh = " << h << endl;
    cout << "x\ty" << endl;
    while(x0 < xn){
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + h/2, y0 + k1/2);
        k3 = h * f(x0 + h/2, y0 + k2/2);
        k4 = h * f(x0 + h, y0 + k3);
        k = (k1 + 2*k2 + 2*k3 + k4)/6;
        y0 = y0 + k;
        x0 = x0 + h;
        cout << x0 << "\t" << y0 << endl;
    }
    return 0;
}