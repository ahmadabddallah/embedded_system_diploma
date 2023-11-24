#include <stdio.h>

int main() {
    /*3 methods for base of 2*/

    int n;
    scanf("%d",&n);

    /*and operation with num-1
    if((n&(n-1))==0){
        printf("number is base of 2\n");
    }
    */


    /*count number of ones if the counter ==1 it's base of 2
    int counter=0;
    int result=0;
    for(int i=31;i>=0;i--){
        result=((n>>i)&1);
        if(result==1){
            counter++;
        }
    }
    if(counter==0){
        printf("number is base of 2\n");
    }*/

    /*check the prime divisors of number is only number 2
    int flag=0;
    while(n>1){

        if(n%2!=0) {
            flag++;
        }
        n/=2;
    }
    if(flag==0){
        printf("number is base of 2\n");
    }
    */


}
