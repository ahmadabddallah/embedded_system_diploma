#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max(x,y) (x>y)?  x : y
int main()
{
    // 1- Write a program to take 2 numbers from user and calculate sum of all numbers between them.

   int Number1=0,Number2=0;
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

   

    // 2- Write a program to take numbers from user and find the max and min from them (let users choose the No of numbers.

    int no_of_numbers;
    scanf("%d",&no_of_numbers);
    int mx=-1;
    for(int i=0;i<no_of_numbers;i++){
        int x;
        scanf("%d",&x);
        mx=max(x,mx);
    }
    printf("%d",mx);

    // 3-Write a program to take numbers from user and calculate the sum of them (let users choose the No of numbers.
    int No_of_Numbers=0;
    printf("Please enter no numbers you want to sum \n");
    scanf("%d",&No_of_Numbers);
    int sum=0;
    for(int i=0;i<No_of_Numbers;i++){
        int x;
        scanf("%d",&x);
        sum+=x;
    }
    printf("The summation of Numbers is:%d",sum);


    //4-Write a program that take two numbers and multiply them without using * operation.

    int number1,number2,sum=0;
    scanf("%d%d",&number1,&number2);
    for(int i=0;i<number2;i++){
        sum+=number1;
    }
    printf("%d",sum);
    return 0;

    //5-Write a program that take two numbers and calculate the reminder without using % operation.

    int number1,number2,result=0;
    scanf("%d%d",&number1,&number2);
    while(number1>number2){
        number1-=number2;
    }
    result=number1;
    printf("%d",result);
    return 0;

    //6-Write a program to calculate the power of a number. The number and its power are input from user.

     int number,pow,result=1;
    scanf("%d%d",&number,&pow);
    for(int i=0;i<pow;i++){
        result*=number;
    }
    printf("%d",result);
    return 0;

    //7-Write a program that reads a positive integer and computes the factorial.
     int factorial=0;
    scanf("%d",&factorial);

    for(int i=factorial-1;i>0;i--){
        factorial*=i;
    }
    printf("%d",factorial);

    //8-Write a program that reads a positive integer and checks if it is a prime.
	 int number;
    scanf("%d",&number);
    int isprime=0;
    for(int i=2;i<= sqrt(number);i++){
        if(number%i==0){
            isprime++;
        }
    }
    if(isprime){
        printf("The number %d is not a prime number \n",number);
    }
    else
        printf("The number %d is a prime number \n",number);



    //9-Write a program that reads a positive integer and checks if it is a perfect square.
	int number;
    scanf("%d",&number);
    int tmp= sqrt(number);
    if( (tmp*tmp)==number){
        printf("The number %d his perfect square is %d \n",number,tmp);
    }
    else
        printf("The number %d is NOT perfect square \n",number);



    //10-Write a program that reads a positive integer and check if this number is a base of 2 like 1,2,4,8,16,32, 64...
    int number;
    scanf("%d",&number);
    if(log2(number)==ceil(log2(number))){
        printf("number :%d is abase of 2",number);
    }
    else
        printf("number :%d is NOT abase of 2",number);

    //11-Write a program to sum the digits in a decimal number 145 -> 1+4+5=10.
    int number;
    int sum=0;
    scanf("%d",&number);
    while(number>0){
        sum+=(number%10);
        number/=10;
    }
    printf("THe sum of digits is %d",sum);

	
	//12 -write a program to take even numbers from user and print the sum of them after each entry if the user enters 2 odd number the program print "bye" and stopped.
	int counter_of_odd=0;
    int sum=0;
    while (counter_of_odd<2){
        int x;
        scanf("%d",&x);
        if(x%2!=0){
            counter_of_odd++;
            if(counter_of_odd==2){
                printf("Bye\n");
                break;
            }
        }
        else{
            sum+=x;
		printf("The sum of number is %d \n",sum);
		}
		
		
    return 0;
}
