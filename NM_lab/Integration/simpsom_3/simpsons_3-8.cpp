// Simpsons 3/8 rule


/*
Start

2. Define function f(x)

3. Read lower limit of integration, upper limit of 
   integration and number of sub interval

4. Calcultae: step size = (upper limit - lower limit)/number of sub interval

5. Set: integration value = f(lower limit) + f(upper limit)

6. Set: i = 1

7. If i > number of sub interval then goto 

8. Calculate: k = lower limit + i * h

9. If i mod 3 =0 then 
     Integration value = Integration Value + 2* f(k)
   Otherwise
     Integration Value = Integration Value + 3 * f(k)
   End If

10. Increment i by 1 i.e. i = i+1 and go to step 7

11. Calculate: Integration value = Integration value * step size*3/8 

12. Display Integration value as required answer

13. Stop 
*/

#include <bits/stdc++.h>
using namespace std;


/* Define function here */
#define f(x) 1/(1+pow(x,2))


int main()
{
 float lower, upper, integration=0.0, stepSize, k;
 int i, subInterval;

 /* Input */
 cout<<"Enter lower limit of integration: ";
 cin>>lower;
 cout<<"Enter upper limit of integration: ";
 cin>>upper;
 cout<<"Enter number of sub intervals: ";
 cin>>subInterval;

 /* Calculation */

 /* Finding step size */
 stepSize = (upper - lower)/subInterval;

 /* Finding Integration Value */
 integration = f(lower) + f(upper);

 for(i=1; i<= subInterval-1; i++)
 {
  k = lower + i*stepSize;

  if(i%3==0)
  {
    integration = integration + 2 * (f(k));
  }
  else
  {
    integration = integration + 3 * (f(k));
  }

 }

 integration = integration * stepSize*3.0/8.0;

 cout<< endl <<"Required value of integration is: "<< integration;

 return 0;
}
