#include <stdio.h>



int mult_by_7(int num){
    int tmp_num=num;
    num=num<<3;
    num-=tmp_num;
    return num;

}

int main() {


    int n;
    scanf("%d",&n);

    n=mult_by_7(n);
    printf("%d",n);


}
