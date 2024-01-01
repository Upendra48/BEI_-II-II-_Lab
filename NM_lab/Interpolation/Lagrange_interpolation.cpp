/*
1. Start

2. Read number of data (n)

3. Read data Xi and Yi for i=1 ton n

4. Read value of independent variables say xp
   whose corresponding value of dependent say yp is to be determined.
   
5. Initialize: yp = 0

6. For i = 1 to n
     Set p = 1
     For j =1 to n
       If i ≠ j then 
         Calculate p = p * (xp - Xj)/(Xi - Xj)
       End If
     Next j
     Calculate yp = yp + p * Yi
   Next i

6. Display value of yp as interpolated value.

7. Stop
*/ 

#include<bits/stdc++.h>
using namespace std;
int main()
{
	 double x[100], y[100], xp, yp=0, p;
	 int i,j,n;

	 /* Input Section */
	 cout<<"Enter number of data: ";
	 cin>>n;
	 cout<<"Enter data:"<< endl;
	 for(i=1;i<=n;i++)
	 {
		  cout<<"x["<< i<<"] = ";
		  cin>>x[i];
		  cout<<"y["<< i<<"] = ";
		  cin>>y[i];
	 }
	 cout<<"Enter interpolation point: ";
	 cin>>xp;

	 /* Implementing Lagrange Interpolation */
	 for(i=1;i<=n;i++)
	 {
		  p=1;
		  for(j=1;j<=n;j++)
		  {
			   if(i!=j)
			   {
			    	p = p* (xp - x[j])/(x[i] - x[j]);
			   }
		  }
		  yp = yp + p * y[i];
	 }
	 cout<< endl<<"Interpolated value at "<< xp<< " is "<< yp;

	 return 0;
}
