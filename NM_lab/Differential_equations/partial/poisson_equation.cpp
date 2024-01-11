#include <bits/stdc++.h>
#define GRID_SIZE 5

using namespace std;

int arr[GRID_SIZE][GRID_SIZE]={0,0};
int res[GRID_SIZE][GRID_SIZE];
void display()
{
for(int i=GRID_SIZE-1;i>=0;i--)
    {
        for(int j=0;j<GRID_SIZE;j++)
        {
            printf("a[%d][%d] : %d\t",i,j,arr[i][j]);
            
        }
        printf("\n");
    }
}
void displayResult()
{
    for(int m=GRID_SIZE-2;m>=1;m--)
    {
        for(int n=1;n<=GRID_SIZE-2;n++)
        {
            printf("u[%d][%d]:%d\t",m,n,arr[m][n]);
        }
        printf("\n");
    }
}
void displayResidue()
{
    for(int m=GRID_SIZE-2;m>=1;m--)
    {
        for(int n=1;n<=GRID_SIZE-2;n++)
        {
            printf("res[%d][%d]:%d\t",m,n,res[m][n]);
        }
        printf("\n");
    }
}

int main()
{
    int i,j;
    //Applying boundary conditions 
    printf("Applying boundary conditions the grid looks like!\n");
    for(int i=GRID_SIZE-1;i>=0;i--)
    {
        for(int j=0;j<GRID_SIZE;j++)
        {
            if(i== (GRID_SIZE - 1) || j == (GRID_SIZE - 1))
            {
            arr[i][j]=i*i*j*j;
            }
            else
            {
                arr[i][j]=0;
            }
            printf("a[%d][%d] : %d\t",i,j,arr[i][j]);
            
        }
        printf("\n");
    }
    //Finding the midpoint of the matrix from standard five point formula extending 1 step further
    for(int i=GRID_SIZE-1;i>=1;i--)
    {
        for(int j=1;j<GRID_SIZE;j++)
        {
            if(i == (GRID_SIZE-1)/2 && j == (GRID_SIZE-1)/2)
            {
                arr[i][j]=(arr[i-2][j]+arr[i+2][j]+arr[i][j+2]+arr[i][j-2])/4;
            }
        }
    }
    //Applying diagonal five point formula
    for(int m=GRID_SIZE-2;m>=1;m--)
    {
        for(int n=1;n<=GRID_SIZE-2;n++)
        {
            if(m!=((GRID_SIZE-1)/2) && n!=((GRID_SIZE-1)/2))
            arr[m][n]= (arr[m+1][n-1] + arr[m+1][n+1] + arr[m-1][n-1] + arr[m-1][n+1])/4;
        }
    }
    printf("\nDisplaying result after applying diagonal five point formula\n");
    display();
    //Applying standard five point formula
    for(int m=GRID_SIZE-2;m>=1;m--)
    {
        for(int n=1;n<=GRID_SIZE-2;n++)
        {
            if(arr[m][n]==0)
            arr[m][n]= (arr[m+1][n] + arr[m][n-1] + arr[m-1][n] + arr[m][n+1])/4;
        }
    }
   
    printf("\nDisplaying Result before residue!!\n");
    displayResult();

    for(int m=GRID_SIZE-2;m>=1;m--)
    {
        for(int n=1;n<=GRID_SIZE-2;n++)
        {
            res[m][n]= (arr[m+1][n] + arr[m][n-1] + arr[m-1][n] + arr[m][n+1])-4*arr[m][n];
        }
    }

    printf("\nDisplaying Residue!!\n");
    displayResidue();
    
    for(int m=GRID_SIZE-2;m>=1;m--)
    {
        for(int n=1;n<=GRID_SIZE-2;n++)
        {
            arr[m][n]=arr[m][n]+res[m][n]/4;
        }
    }
    printf("\nDisplaying Result after residue!!\n");
    displayResult();
    return 0;
}