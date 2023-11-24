#include <stdio.h>
#include <stdlib.h>

void SWAP(int *X,int *Y){
         *X=*X ^ *Y;
         *Y=*X ^ *Y;
         *X=*X ^ *Y;

         };


void swap(int *no1, int  *no2)
{
    int tp=*no1;
    *no1=*no2;
    *no2=tp;

}

int main()
{
    int Number1=0,Number2=0;
    printf("Please enter the 2 Numbers \n");
    scanf("%d%d",&Number1,&Number2);

    //Method 1 with Third Variable
    int tmp;
    tmp=Number2;
    Number2=Number1;
    Number1=tmp;




    //method 2 With Pointer
    swap(&Number1,&Number2);


    //method 3 With Arithmetic operation
    int val1,val2;
    val1=Number1+Number2;
    Number1=val1-Number1;
    Number2=val1-Number2;




    //Method 4 Using Macro
    SWAP(&Number1,&Number2);



    printf("Number 1 is :%d Number 2 is :%d",Number1,Number2);


}
