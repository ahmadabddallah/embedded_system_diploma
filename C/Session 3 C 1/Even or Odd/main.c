#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Number=0;
    printf("Please Enter the Number \n");
    scanf("%d",&Number);
    if(Number % 2==0){
        printf("The Numer %d is Even ",Number);
    }
    else
        printf("The Numer %d is Odd ",Number);

    return 0;
}
