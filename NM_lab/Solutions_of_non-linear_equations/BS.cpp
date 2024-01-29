// C++ program for implementation of Bisection Method for
// solving equations
#include<bits/stdc++.h>
using namespace std;
#define EPSILON 0.01

double func(double x)
{
	return x*x - 612;
}

int main()
{	
	double a , b ;
	up:
	cin >> a >> b;
	

	if (func(a) * func(b) >= 0)
	{
		cout << "You have not assumed right a and b\n";
		goto up;
	}
	double c;
	cout << "a\t\t" << "b\t\t" << "Function a\t\t function b \t\t"<<"mid part"<< endl;
	while((b-a) >= EPSILON){
		c = (a+b)/2;        // Find middle point
		cout << a<<"\t\t" << b <<"\t\t"<< func(a)<<"\t\t\t\t" << func(b)<<"\t\t\t\t" << c << endl;
		if(func(c) == 0.0){      // Check if middle point is root
			break;
		}
		else if(func(c)*func(a) < 0){    // Decide the side to repeat the steps
			b = c;
		}
		else{
			a = c;
		}
		
	}
	cout << "The value of root is : " << c;
	return 0;
}
