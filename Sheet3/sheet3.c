#include <stdio.h>
#include <stdlib.h>
#define max(x,y) (x>y)?x:y

int Fibonacci(int n){
    int a[5000];
     a[0]=0;
     a[1]=1;
     a[2]=1;
    for(int i=3;i<=n;i++){
        a[i]=a[i-1]+a[i-2];
    }
    return a[n];

}
void print_array(int *arr,int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }

}

void swap(int *a,int *b){

    int tmp=*a;
     *a=*b;
     *b=tmp;


}

// 1-Write a C function to return the index of LAST occurrence of a number in a
//given array. Array index start from 0. If the item is not in the list return -1.
int last_index(int *arr,int size,int idx){
    for(int i=size-1;i>=0;i--){
        if(arr[i]==idx){
            return idx;
        }

    }
    return -1;

}

//2-Write a C function to return the maximum and minimum number in an array and their indexes.
void array_data(int *arr,int size,int *pidxMx,int *pidxMn,int *pmx,int *pmn){
    for(int i=0;i<size;i++){
        if(arr[i]>*pmx){
            *pmx=arr[i];
            *pidxMx=i;
        }
        if(arr[i]<*pmn){
            *pmn=arr[i];
            *pidxMn=i;
        }

    }


}

//3-Write a C function that return 0 if a given number is a power of 3,
//otherwise return 1
int is_pow3(int n){
    while(n>3){
        if(n%3!=0){
            return 0;
        }
        n/=3;
    }
    if(n==3){
        return 1;
    }


}


//question 4

//(5) Write c function to find the most repeated number in an array of integers.
int most_repeated (int *arr,int size,int *pidx){
    int frq[1000];
    for(int i=0;i<size;i++){
        frq[arr[i]]++;
    }
    int mx=0x80000000;
    for(int i=0;i<size;i++){
        if(frq[i]>mx){
            mx=frq[i];
            *pidx=i+1;
        }
    }
    return mx;



}


//6) Write a C function to take an array and reverse its elements.
void reverse(int *arr,int size){
    for(int i=0;i<=size/2;i++){

        swap(&arr[i],&arr[size-i-1]);
    }

}

//7)Write a C function to take 2 arrays and swap them (try with 2 different
//sizes).
void swap_array_with_different_size(int *arr1,int size1,int *arr2,int size2){
    int mn=0xffffffff;
    if(size1>size2){
        mn=size2;
    }
    else
        mn=size1;

        for(int i=0;i<mn;i++) {
            swap(&arr1[i], &arr2[i]);
        }
}
//8) Write a C function that return the count of the longest consecutive
//occurrence of a given number in an array.
//Array= {1,2,2,3,3,3,3,4,4,4,4,3,3,3} and searching for 3 -> result = 4.
int count_longest_consecutive_search(int *arr,int size,int num){
    int count=0;
    int mx=0x80000000;
    for(int i=0;i<size;i++){
        if(arr[i]==num){
            count++;
        }
        else{
            if(mx<count)
            mx=count;
            count=0;
        }

    }
    return mx;

}
//9)Write a C function that return the count of the longest consecutive
//occurrence of any number ,and return the number
//Array={1,2,2,3,3,3,3,4,4,4,4,4,3,3,3} result -> 5 ,number ->4
int count_longest_consecutive(int *arr,int size,int *pNum){
    int frq[1000]={0};
    int count=0;
    int mx=0x80000000;
    for(int i=1;i<size-1;i++){
        if(arr[i]==arr[i-1]){
            count++;
        }
        else{
            if(count>mx){
                mx=count;
                *pNum=arr[i];
                count=0;
            }

        }

    }
    return mx;

}



//10-Write c function to take 2 arrays and return an array by merging
//them like this ( arr1={1,2,3,4,5},arr2={11,12,13,14,15} return
//arr3={1,11,2,12,3,13,4,14,5,15} )

void merge_array(int *arr1,int size1,int *arr2,int size2,int *arr3){
    int size3=size1+size2;
    int j=0;
    for(int i=0;j<size3;i++){
        arr3[j++]=arr1[i];
        arr3[j++]=arr2[i];
    }
}

//11-Write a c function that removes the repeated number of an input
//sorted array and return a new array without the repeated number
void remove_repeated(int *arr,int *new_arr,int size){
    if(size==0 || size==1){
        return ;
    }
    //112233445
    int j=0;
    for(int i=0;i<size-1;i++){
        if(arr[i]!=arr[i+1]){
            new_arr[j++]=arr[i];
        }

    }
    new_arr[j++]=arr[size-1];
}
//12-Write c function to take an array (with unknown size) contain 2 zeros
//swap the 3 element after the first zero with the 3 element after the second
//zero ( x,x,x,0,1,2,3,xxxx,0,5,6,7,xxxx ->swap 1,2,3with 5,6,7).

void swap_after_2zeros(int *arr){

    int count=0;
    int first=0;
    int second=0;
    for(int i=0;count<2;i++){
        if(arr[i]==0 &&count==0){
            count++;
            first=i+1;
            continue;
        }
        if(arr[i]==0 && count==1){
            count++;
            second=i+1;
            break;
        }

    }
    for(int i=0;i<3;i++){
        swap(&arr[first++],&arr[second++]);
    }


}



//13-Write c function to take an array and return the biggest difference
//between 2 numbers in the array (the smaller number must come first in the
//array) {10,1,5,3,6,8,7,2}->return 7 difference between 1,8.
int biggest_difference(int *arr,int size){
    int diff=0x80000000;
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]<arr[j]){
                if((arr[j]-arr[i])>diff){
                    diff=(arr[j]-arr[i]);
                }
            }
        }
    }
    return diff;
}


//14-Write c function to find the most repeated number in an array of
//char (size of the array is very large) try to optimize your code.
int most_repeated_char(int *arr,int size){
    int frq[127]={0};
    int sum=0x80000000;
    for(int i=0;i<arr[i];i++){
        frq[arr[i]]++;
        if(frq[arr[i]]>sum){
            sum=frq[arr[i]];
        }
    }
    return sum;


}

//15 Write a C Function that swaps two pointers.
void swap_pointer(int **px,int **py){
    int*tmp;
    tmp=*px;
    *px=*py;
    *py=tmp;
}

//16-Write a C function to get the nth term of Fibonacci series, and use it
//to print the first 20 element.
void print_Fibonacci(int n){
    for(int i=0;i<n;i++){
        printf("%d %d\n",i, Fibonacci(i));

    }


}
//17-Write a C function to take 10 mono numbers (from 0to 9) from user
//and return the most repeated one, if user enter number bigger than 9
//return -1(don’t use arrays)
int most_repeated_mono(){
    int ctr0=0,ctr1=0,ctr2=0,ctr3=0,ctr4=0,ctr5=0,ctr6=0,ctr7=0,ctr8=0,ctr9=0;
    int mx=0x80000000;
    for(int i=0;i<10;i++){
        int x;
        scanf("%d",&x);

        switch (x) {
            case 0:
                ctr0++;
                break;
            case 1:
                ctr1++;
                break;
            case 2:
                ctr2++;
                break;
            case 3:
                ctr3++;
                break;
            case 4:
                ctr4++;
                break;
            case 5:
                ctr5++;
                break;
            case 6:
                ctr6++;
                break;
            case 7:
                ctr7++;
                break;
            case 8:
                ctr8++;
                break;
            case 9:
                ctr9++;
                break;
            default:
                return -1;
                break;
        }

        mx=max(mx,ctr0);
        mx=max(mx,ctr1);
        mx=max(mx,ctr2);
        mx=max(mx,ctr3);
        mx=max(mx,ctr4);
        mx=max(mx,ctr5);
        mx=max(mx,ctr6);
        mx=max(mx,ctr7);
        mx=max(mx,ctr8);
        mx=max(mx,ctr9);
    }

    if(mx==ctr0){
        return 0;
    }
    else if(mx==ctr1)
        return 1;
    else if(mx==ctr2)
        return 2;
    else if(mx==ctr3)
        return 3;
    else if(mx==ctr4)
        return 4;
    else if(mx==ctr5)
        return 5;
    else if(mx==ctr6)
        return 6;
    else if(mx==ctr7)
        return 7;
    else if(mx==ctr8)
        return 8;
    else if(mx==ctr9)
        return 9;
    else
        return -1;


}


int main()
{
    /* Question 2
    int mxid=-1,minid=0x7fffffff; //to index
    int mx=-1,mn=0x7fffffff;//to value
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    array_data(arr,10,&mxid,&minid,&mx,&mn);
    printf("The maximum number is %d=  his idx is %d=\n",mx,mxid);
    printf("The minimum number is %d=  his idx is %d\n=",mn,minid);
    */
    /*
    int arr[11]={0,1,2,3,4,5,6,7,8,9,10};

    reverse(arr,11);
    printf("\n \n");
    print_array(arr,11);
     */
    //print_Fibonacci(20);

   /* int x=10,y=20;
    int *px=&x;
    int *py=&y;

    printf("%d %d\n",px,py);
    swap_pointer(&px,&py);
    printf("%d %d",px,py);
    */
   /*
   int arr1[]={1,2,3,4,5};
   int arr2[]={11,12,13,14,15};
   int arr3[10];

    merge_array(arr1,5,arr2,5,arr3);
    print_array(arr3,10);


    printf("%d",most_repeated_mono());
    */
   int arr[]={1,1,1,0,1,2,3,5,6,7,0,10,20,30};
    swap_after_2zeros(arr);
    print_array(arr,14);
    return 0;
}
