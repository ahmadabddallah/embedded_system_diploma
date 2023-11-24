#include <stdio.h>

int main() {
    /*by using if statement*/

    int n1,n2,result=0;
    printf("please enter the first number then the second number \n");
    scanf("%d %d",&n1,&n2);

    char operation;
    printf("please enter the operation you want to do{+,-,*,/} \n");
    scanf(" %c",&operation);



    /*by using switch statement*/
    switch(operation){
        case '+':
            result=n1+n2;
            break;
        case'-':
            result=n1-n2;
            break;
        case'*':
            result=n1*n2;
            break;
        case '/':
            if(n2==0){
                //can't divied on zero
                result=-1;
            }
            else{
                result=n1/n2;
            }
            break;
        default:
            printf("please enter a valid operation\n");

    }
	printf("%d",result);
    return 0;
}
