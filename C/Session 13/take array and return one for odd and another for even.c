#include <stdio.h>
#include <stdlib.h>


void split_array(int *arr,int size,int **oddArr,int *oddArrSize,int **evenArr,int *evenArrSize){
    int countEven=0,countOdd=0;
    for(int i=0;i<size;i++){
        if(arr[i]&1){
            countOdd++;
        }
        else{
            countEven++;
        }
    }
    *oddArrSize=countOdd;
    *evenArrSize=countEven;

    *evenArr=malloc(sizeof(int)*countEven);
    *oddArr=malloc(sizeof(int)*countOdd);

    for(int i=0,oddidx=0,evenidx=0;i<size;i++){
        if(arr[i]&1){
            (*oddArr)[oddidx++]=arr[i];
        }
        else{
            (*evenArr)[evenidx++]=arr[i];
        }
    }
    return ;


}
int main() {



    int arr[]={1,2,3,4,5,6,7,8,9};

    int*evenArr=0,*oddArr=0;
    int oddArrSize=0,evenArrsize=0;
    split_array(arr,9,&oddArr,&oddArrSize,&evenArr,&evenArrsize);

   for(int i=0;i<oddArrSize;i++){
        printf("%d ",oddArr[i]);
    }

    for(int i=0;i<evenArrsize;i++){
        printf("%d ",evenArr[i]);
    }

}
