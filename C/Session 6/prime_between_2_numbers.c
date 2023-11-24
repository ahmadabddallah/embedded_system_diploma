#include<stdlib.h>



//This is a professional way using Sieve Algorithm
//Optimized Time Complexity

#define MAX(A,B)	(A)>(B)?(A):(B)
#define MIN(A,B)    (A)>(B)?(B):(A)

int* sieve(int n)
{

    int *arr=(int*)calloc(sizeof(int),n);

    for(int i=2; i*i<=n; i++)
    {

        if(arr[i]==0)
        {

            for(int j=i*i; j<=n; j+=i)
            {
                arr[j]=1;
            }
        }
    }

    
    return arr;

}

int main()
{

    int n1=55,n2=100;

    int mx=MAX(n1,n2);
    int mn=MIN(n1,n2);


    int *arr=sieve(mx);

    for(int i=mn; i<=mx; i++)
    {
        if(arr[i]==0)
        {
            printf("%d ",i);

        }

    }

}
