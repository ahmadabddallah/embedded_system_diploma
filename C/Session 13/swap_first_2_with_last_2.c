#include <stdio.h>
#include <stdlib.h>


//write function to find the max and the second max element in array
void maxAndSecmax(int *arr,int size,int*max,int*sec_max){


    for(int i=0;i<10;i++){
        if(arr[i]>*max){
            *sec_max=*max;
            *max=arr[i];
        }
        else if(arr[i]>*sec_max &&arr[i]!=*max){
            *sec_max=arr[i];
        }

    }

}


int main()
{
    int arr[]= {10,10,10,4,5,6,7,8,10,10};
    int max=0x80000000,sec_max=0x80000001;
    maxAndSecmax(arr,10,&max,&sec_max);

    printf("the max number is %d the second max is %d=",max,sec_max);




}
