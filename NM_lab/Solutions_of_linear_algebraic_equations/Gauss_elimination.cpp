/*
1. Start

2. Read Number of Unknowns: n

3. Read Augmented Matrix (A) of n by n+1 Size

4. Transform Augmented Matrix (A) 
   to Upper Trainagular Matrix by Row Operations.

5. Obtain Solution by Back Substitution.

6. Display Result.

7. Stop
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
	 double a[10][10], x[10], ratio;
	 int i,j,k,n;

     /* Setting precision and writing floating point values in fixed-point notation. */
     //cout<< setprecision(3)<< fixed;

	 /* Inputs */
	 /* 1. Reading number of unknowns */
	 cout<<"Enter number of unknowns: ";
	 cin>>n;

	 /* 2. Reading Augmented Matrix */
	 cout<<"Enter Coefficients of Augmented Matrix: "<< endl;
	 for(i=1;i<=n;i++)
	 {
		  for(j=1;j<=n+1;j++)
		  {
			   cout<<"a["<< i<<","<< j<<"]=";
			   cin>>a[i][j];
		  }
	 }
	/* Applying Gauss Elimination */
	 for(i=1;i<=n-1;i++)
	 {
		  if(a[i][i] == 0.0)
		  {
			   cout<<"Mathematical Error!";
			   exit(0);
		  }
		  for(j=i+1;j<=n;j++)
		  {
			   ratio = a[j][i]/a[i][i];

			   for(k=1;k<=n+1;k++)
			   {
			  		a[j][k] = a[j][k] - ratio*a[i][k];
			   }
		  }
	 }
    /* Obtaining Solution by Back Substitution Method */
    x[n] = a[n][n + 1] / a[n][n];

	 for(i=n-1;i>=1;i--)
	 {
		  x[i] = a[i][n+1];
		  for(j=i+1;j<=n;j++)
		  {
		  		x[i] = x[i] - a[i][j]*x[j];
		  }
		  x[i] = x[i]/a[i][i];
	 }

	 /* Displaying Solution */
	 cout<< endl<<"Solution: "<< endl;
	 for(i=1;i<=n;i++)
	 {
	  	cout<<"x["<< i<<"] = "<< x[i]<< endl;
	 }

	 return(0);
}


/*
1. Start

2. Input the Augmented Coefficients Matrix (A):
	
	For i = 1 to n
		
		For j = 1 to n+1
			
			Read Ai,j
		
		Next j
	
	Next i

3. Apply Gauss Elimination on Matrix A:
	
	For i = 1 to n-1
		
		If Ai,i = 0
			
			Print "Mathematical Error!"
			Stop
		
		End If
		
		For j = i+1 to n
			
			Ratio = Aj,i/Ai,i
			
			For k = 1 to n+1
				
				Aj,k = Aj,k - Ratio * Ai,k
			
			Next k
		Next j
	Next i

4. Obtaining Solution by Back Substitution:
	
	Xn = An,n+1/An,n
	
	For i = n-1 to 1 (Step: -1)
		
		Xi = Ai,n+1
		
		For j = i+1 to n
			
			Xi = Xi - Ai,j * Xj
		
		Next j
		
		Xi = Xi/Ai,i
	Next i

5. Display Solution:
	
	For i = 1 to n
		
		Print Xi
	
	Next i

6. Stop

*/