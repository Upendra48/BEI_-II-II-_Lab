// C++ program for implementation of Newton Raphson Method for
// solving equations
#include<bits/stdc++.h>
#define EPSILON 0.001
using namespace std;


double func(double x)
{
	return x*x + x - 2;
}


double derivFunc(double x)
{
	return 2*x + 1;
}


int main()
{
	double x0;
	double x1;
	cin >> x0;
    
	double f = func(x0)/derivFunc(x0);
	while(f >= EPSILON)
	{
		x1 = x0 - f;
		x0 = x1;
		f = func(x0)/derivFunc(x0);
	}
	cout << "The value of the root is : " << x1;
	return 0;
}
