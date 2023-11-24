#include <stdio.h>

#define CLR_BIT(num,bit)    num=((num)&(~(1<<bit)))

int main() {


    int n=2;

    CLR_BIT(n,0);
    printf("%d",n);


}
