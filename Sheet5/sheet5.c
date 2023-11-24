#include <stdio.h>
#include <stdlib.h>



/*You have an array of 100 element contain all number from 0 t0 100 except
one number, write c function to find the missed number (try in O(n))*/

int missed_number_in_100(int *arr,int size){

    int sumFrom1to100=0;
    sumFrom1to100=((100)*(101))/2;

    int sumArr=0;
    for(int i=0;i<100;i++){
        sumArr+=arr[i];
    }

    return (sumFrom1to100-sumArr);

}

/*2) You have an array of 101 element contain all number from 1 t0 100, so one
number is repeated, write c function to find the repeated number (try in
O(n)).*/

int repeated_num_in_array(int *arr,int size){

    int sumFrom1to100=(100*101)/2;

    int sumArr=0;
    for(int i=0;i<101;i++){
        sumArr+=arr[i];
    }
    return (sumArr-sumFrom1to100);

}

/*3)You have an array of integers all numbers in the array repeated 2 times
except one number repeated one time only find this number (try o(n)).
array like {1,2,4,66,2,1,500,66,7,7,500}->4*/

int unique_number(int *arr,int size){

    int foundNumber=0;
    int *frq=calloc(sizeof(int),500);

    for(int i=0;i<size;i++){
        frq[arr[i]]++;
    }
    for(int i=0;i<size;i++){
        if(frq[i]==1){
            foundNumber=i;
        }
    }
    return foundNumber;


}

/*4)) repeat Q3 but array is sorted (try less than O(n)).
 array {1,1,2,2,4,4,70,70,73,80,80,81,81} ->73.*/

int unique_number_V2(int *arr,int size){

    int foundNumber=0;
    int *frq=calloc(sizeof(int),500);

    for(int i=0;i<size;i++){
        frq[arr[i]]++;
    }
    for(int i=0;i<size;i++){
        if(frq[i]==1){
            foundNumber=i;
        }
    }
    return foundNumber;

}

/*5)) You have an array of integers contain Mono numbers only (from 0 to 9)
 , write c function to find the most repeated number (try in O(n))*/


 int repeated_mono_number(int *arr,int size){
    int frq[10]={0};

    int max=0x80000000;
    int number=0;
    for(int i=0;i<size;i++){
        frq[arr[i]]++;
    }

    for(int i=0;i<10;i++){
        if(frq[i]>max){
            max=frq[i];
            number=i;
        }
    }
    return number;


 }



 /*6) Write c function to find the first repeated char in string (try in O(n)).
 "ahmed selem" ->e.*/

 char first_repeated_char(char *str){

    int frq[26]={0};
    char found_char='a';
    for(int i=0;str[i];i++){
        if(str[i]==' '){
            continue;
        }
        frq[str[i]-'a']++;
        if(frq[str[i]-'a']>1){
            found_char=str[i];
            break;
        }
    }
    return found_char;

 }

 /*7)write c function to copy string to string without copy repeated characters
 try (O(n)). "ahmed selem kamel"->"ahmed slk"*/
 void string_unique_copy(char *str1,char *str2){
    int frq[26]={0};

    for(int i=0;str1[i];i++){

        frq[str1[i]-'a']=1;

    }
    for(int i=0,j=0;str1[i];i++){
        if(frq[str1[i]-'a']==1){
            str2[j++]=str1[i];
            frq[str1[i]-'a']=0;
        }
    }
 }

 /*8) . Write C function to take an array and if it finds a number "given" makes the
 previous elements in a new array and returns it (try to optimize).*/

 int* new_arr(int *arr,int size,int target,int *NewArrSize){
     int i=0;
    for(i=0;i<size;i++){
        if(arr[i]==target){
            break;
        }
    }
    int *newarr=(int*)malloc(sizeof(int)*i);
    for(int j=0;j<i;j++){
        newarr[j]=arr[j];
    }
    *NewArrSize=i;
    return newarr;

 }

 /* 9) Write a c function to swap the two bytes of a short int (n=0xFE20 ->0X20FE)
 use 2 methods.*/

 short int swap_short(short int num){
    //method 1
    char *ptr=&num;
    char tmp=ptr[0];//20
    ptr[0]=ptr[1];//fe
    ptr[1]=tmp;//20
    return num;

    //method 2
    unsigned short tmp=num;
    tmp=(tmp>>8)|(tmp<<8);
    return tmp;


 }



int main()
{



    return 0;
}
