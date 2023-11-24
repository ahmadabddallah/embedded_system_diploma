#include <stdio.h>
#include <stdlib.h>
#include "string.h"


void string_scan(char *str,int max_size){
    int i=0;
    fflush(stdin);
    scanf("%c",&str[i]);
    for(;str[i]!='\n'&&i<max_size-1;){
        i++;
        scanf("%c",&str[i]);

    }
    str[i]=0;
}


void string_print(char *str){
    int i;
    for( i=0;str[i]!='\0';i++){
        printf("%c",str[i]);
    }
    printf("\n");
}

int string_length(char*str){
    int i;
    for(i=0;str[i]!='\0';i++){

    }
    return i;
}
void string_upperToLower(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {

        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] -= 'A';
            str[i] += 'a';
        }
    }
}

void string_reverse(char *str) {
    int size= string_length(str);
    size--;
    int i=0;
    for(;i<=size;i++,size--){
        char tmp;
        tmp=str[size];
        str[size]=str[i];
        str[i]=tmp;
    }

}

int string_compare(char *str1,char *str2){

    for(int i=0;str1[i] || str2[i];i++){
        if(str1[i]>str2[i]){
            return 1;
        }
        else if(str1[i]<str2[i]){
            return -1;
        }

    }
    return 0;


}
int binary_search_toFound_String(char **arr,int size,char *str){

    int first=0,last=size-1;

    int mid=(first+last)/2;

    while(first<=last){
        mid=(first+last)/2;
        int result=string_compare_not_sensitive(arr[mid],str);//to run the function string_compare only once
        if(result==0){

            return mid;
        }
        else if(result==1){
            first=mid+1;
        }
        else if(result==-1){
            last=mid-1;
        }

    }
    return -1;


}

int string_compare_not_sensitive(char *str1,char*str2){
    int ok =0;
    for(int i=0;str1[i]||str2[i];i++){  //make a temporary variable with lower letter for both strings then check.
        char tmp1=str1[i],tmp2=str2[i];
        if(str1[i]>='A' &&str1[i]<='Z'){
            tmp1-='A';
            tmp1+='a';
        }
        if(str2[i]>='A' &&str2[i]<='Z'){
            tmp2-='A';
            tmp2+='a';
        }
        if(tmp1>tmp2){
            ok=1;
        }
        else if(tmp1<tmp2){
            ok=-1;
        }

    }
    return ok;

}
void intToString(int n,char *str){
    int i=0, rem,tmp;
    tmp=n;
    if(n==0){
        str[0]='0';
        str[1]=0;
    }
    else if(n<0) {
        str[i++] = '-';
        tmp = tmp * -1;


        while (tmp > 0) {
            int x = tmp % 10;
            str[i++] = x + '0';
            tmp /= 10;
        }
        for (int j = 1; j < i; j++) {
            char c;
            c = str[j];
            str[j] = str[i - 1];
            str[i - 1] = c;
            i--;
        }
    }
    else {
        while (n > 0) {
            rem = n % 10;
            rem += '0';
            str[i++] = rem;
            n /= 10;
        }
        str[i] = 0;
        string_reverse(str);
    }

}
int stringToInt(char* str){
    int n=0;
    for(int i=0;str[i];i++){
        if(str[i]>='0'&&str[i]<='9') {
            if (i > 0) {
                n *= 10;
            }
            n += str[i] - '0' + 0;
        }
    }
    if(str[0]=='-')
    return n*-1;
    else
        return n;

}

