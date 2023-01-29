#include <stdio.h>
#include <stdlib.h>

int main()
{   int Number1=0,Number2=0;
    printf("Please enter the 2 Numbers \n");
    scanf("%d%d",&Number1,&Number2);

    if(Number1>Number2){
        int tmp;
        tmp=Number2;
        Number2=Number1;
        Number1=tmp;
    }


    for(int i=Number2-1;i>Number1;i--){
        printf("%d ",i);
    }

}
