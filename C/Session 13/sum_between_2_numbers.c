#include <stdio.h>



int sum_between_2_numbers(int n1,int n2){
    int sum_n1=((n1)*(n1+1)/2);
    int sum_n2=((n2-1)*((n2-1)+1)/2);

    return (sum_n2-sum_n1);
}
int main() {



    printf("%d", sum_between_2_numbers(7,10));


}
