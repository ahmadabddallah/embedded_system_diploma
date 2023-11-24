#include <stdio.h>

int factorial(int num){
    int result=num;
    for(int i=num-1;i>0;i--){
        result*=i;

    }

    return result;
}

int is_strong(int num){
    int flag=0;
    int sum=0;
    int tmp_num=num;
    while(tmp_num>0){
        sum+= factorial(tmp_num%10);
        tmp_num/=10;
    }
    if(sum==num){
        flag=0;
    }
    else{
        flag=1;
    }
    return flag;
}


int main() {


    int n;
    scanf("%d",&n);

    if(is_strong(n)==0){
        printf("%d is a strong number",n);
    }
    else{
        printf("%d is not a strong number \n");
    }


}
