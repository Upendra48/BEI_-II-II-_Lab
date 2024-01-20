// Secant method to find the root of a non-linear equation
#include<bits/stdc++.h>
#define EPSILON 0.001
#define e 1.5
using namespace std;

double func(double x)
{
    //return x*x - 612;
    return 3 * x + sin(x) - pow(e, x);
    //return x * log10(x) - 1.2;
    //return sin(x) - 2 * x + 1;
    //return tan(x) + tanh(x);
}

int main(){
    double x0;
    double x1;
    double x=0;
    double count = 0;
    cin >> x0 >> x1;
    if(func(x0)*func(x1)<=0){
    do{
        x = x1 - (x1 - x0)/(func(x1)-func(x0))*func(x1);
        x0 = x1;
        x1 = x;
        count++;
    }while(fabs(func(x))>=EPSILON);
    cout << "The value of the root is : " << x; 
    cout << "\nNumber of iterations : " << count;
    }
    else{
        cout << "Root does not lie between " << x1 <<" "<< x0 << endl;
    }
    return 0;
    
}