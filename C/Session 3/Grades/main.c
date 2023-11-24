#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Grade=0;
    printf("Please enter The Grade of the Student\n");
    scanf("%d",&Grade);
    if(Grade>=50 && Grade <60){
        printf("The Student Grade is : D \n");
    }
    else if(Grade>=60 && Grade <70){
        printf("The Student Grade is : C \n");
    }
    else if(Grade>=70 && Grade <80){
        printf("The Student Grade is : B \n");
    }
    else if(Grade>=80 && Grade <90){
        printf("The Student Grade is : B+ \n");
    }
    else if(Grade>=90 && Grade <=100){
        printf("The Student Grade is : A \n");
    }
    else if(Grade>=0 && Grade <50)
        printf("The Student Grade is : F \n");
    else
        printf("Error,Please Enter a valid number \n");

    return 0;
}
