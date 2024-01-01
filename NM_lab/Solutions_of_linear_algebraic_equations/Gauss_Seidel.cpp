// Implementation of Gauss Seidel method

/*
ALGORITHM:

1. Start

2. Arrange given system of linear equations in 
   diagonally dominant form

3. Read tolerable error (e)

4. Convert the first equation in terms of first variable, 
second equation in terms of second variable and so on. 

5. Set initial guesses for x0,  y0, z0 and so on

6. Substitute value of y0, z0 ... from step 5 in 
   first equation obtained from step 4 to calculate 
   new value of x1. Use x1, z0, u0 .... in second equation 
   obtained from step 4 to caluclate new value of y1. 
   Similarly, use x1, y1, u0... to find new z1 and so on.  

7. If| x0 - x1| > e and | y0 - y1| > e and | z0 - z1|  > e 
   and so on then goto step 9

8. Set x0=x1, y0=y1, z0=z1 and so on and goto step 6

9. Print value of x1, y1, z1 and so on

10. Stop
*/

#include <bits/stdc++.h>
using namespace std;

#define f1(x,y,z)  (17-y+2*z)/20
#define f2(x,y,z)  (-18-3*x+z)/20
#define f3(x,y,z)  (25-2*x+3*y)/20

int main(){
 
// arrange the system of linear equations in diagonally dominant form
double x0 = 0, y0 = 0, z0 = 0;
double x1, y1, z1;
double diff1, diff2, diff3;

do{
    // find new values of x1, y1, z1 for given x0, y0, z0
    x1 = f1(x0,y0,z0);
    y1 = f2(x1,y0,z0);
    z1 = f3(x1,y1,z0);
    
    diff1 = fabs(x1-x0);
    diff2 = fabs(y1-y0);
    diff3 = fabs(z1-z0);

    //cout<<"\t"<<x1<<"\t"<<y1<<"\t"<<z1<<endl;
    
    //? update values of x0, y0, z0
    x0 = x1;
    y0 = y1;
    z0 = z1;

}while(diff1>0.0001 && diff2>0.0001 && diff3>0.0001);

cout<< "x = "<< x1<< endl;
cout<< "y = "<< y1<< endl;
cout<< "z = "<< z1<< endl;

return 0;

}