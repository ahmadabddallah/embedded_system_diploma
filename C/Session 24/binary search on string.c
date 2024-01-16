
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