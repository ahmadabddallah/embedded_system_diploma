#include <stdio.h>
#include <stdlib.h>

int main()
{   int No_of_Numbers=0;
    printf("Please enter no numbers you want to sum \n");
    scanf("%d",&No_of_Numbers);
    int sum=0;
    for(int i=0;i<No_of_Numbers;i++){
        int x;
        scanf("%d",&x);
        sum+=x;
    }
    printf("The summation of Numbers is:%d",sum);

}
