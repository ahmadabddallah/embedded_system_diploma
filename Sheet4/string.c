#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void scan_string(char* str)
{
    int i=0;
    fflush(stdin);
    scanf("%c",&str[i]);

    for(; str[i]!='\n';)
    {
        i++;
        scanf("%c",&str[i]);
    }
    str[i]=0;

}
int string_to_int(char*str)
{
    int n=0;
    for(int i=0; str[i]; i++)
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            if (i > 0)
            {
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
void int_to_string(int n,char *str)
{
    int i=0;

    while(n)
    {
        // 1 2
        str[i++]=(n%10)-0+'0';
        n/=10;
    }
    str[i]=0;
    reverse_string(str);

}

int string_length(char *str)
{
    int i=0;
    for(i=0; str[i]!='\0'; i++);
    return i;

}
int string_compare (char *str1,char *str2)
{
    int len1= string_length(str1);
    int len2= string_length(str2);
    if(len1!=len2)
    {
        return 1;
    }
    for(int i=0; str1[i]; i++)
    {
        if(str1[i]!=str2[i])
        {
            return 1;
        }
    }
    return 0;

};
void merge_modified_string(char*str1, char*str2,char *result)
{
    int i=0;
    for(int j=0; str1[j]; j++)
    {
        result[i++]=str1[j];
    }
    result[i++]='.';
    for(int j=0; str2[j]; j++)
    {
        result[i++]=str2[j];
    }
    result[i]=0;
}

void move_string_data(char *str1,char *str2)
{
    int i=0;
    for(; str2[i]; i++)
    {
        str1[i]=str2[i];
    }
    str1[i]=0;
}
void string_print(char *str)
{

    for(int i=0; str[i]!='\0'; i++)
    {
        printf("%c",str[i]);
    }
    printf("\n");

}

//-------------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------Sheet4--------------------------------------------------------------- //
//-------------------------------------------------------------------------------------------------------------------------//

//1-Write c function to reverse string "Ahmed salem"->melas demhA".
void reverse_string(char *str)
{

    int length=string_length(str);

    for(int p=0,q=length-1; p<=q; p++,q--)
    {
        char tmp;
        tmp=str[p];
        str[p]=str[q];
        str[q]=tmp;
    }


}

//2-Write c function to check if string is mirror or not "SalaS","SalelaS".
int check_mirror(char *str)
{
    int length=string_length(str);
    int ok=1;
    for(int p=0,q=length-1; p<=q; p++,q--)
    {
        if(str[p]!=str[q])
        {
            return 0;
        }
    }
    return 1;

}
//3-Write c function to reverse words in sentence (without using external arrays)
//" I work as an embedded software engineer for 3 years"
//-> " years 3 for engineer software embedded an as work I".

void print_reverse(char *str,int length)
{
    reverse_string(str);
    int brk=0;
    int i=0;
    while(i<length)
    {

        for(; (str[i]!=' ') &&(str[i]!='\0'); )
        {
            i++;
        }
        int j=i-1;
        for(; j>=brk; j--)
        {
            printf("%c",str[j]);
        }

        if(str[i]==' ')
        {
            brk=i+1;
            i++;
        }
        j=i+1;
        if(i>=length)
        {
            break;
        }
        printf(" ");

    }
}



//4-Write C function to take string contain three numbers separated by space,
//check what type of triangle this number could make, and return string
void extract_number_from_string(char *str)
{
    char equi[]="Equilateral triangle";
    char iso[]="Isosceles trinagle";
    char equio[]="scalene triangle";
    gets(str);
    int arr[3]= {0};
    int flag=0;
    for(int i=0; str[i]; i++)
    {
        if(str[i]==' ')
        {
            flag++;
            continue;
        }
        arr[flag]=arr[flag]*10+(str[i]-'0');
    }

    printf("%d %d %d",arr[0],arr[1],arr[2]);

}


//5-Write a C function to convert float number to string
void float_to_string(float f1,char *str)
{
    char dec[100]= {0};
    char fix[100]= {0};
    char number[200]= {0};

    int prec=100;

    int decimal_part=(int)f1;
    int_to_string(decimal_part,dec);
    //  printf("%s",dec);

    float fix_part_tmp=(f1-(int)f1);
    int fix_part=fix_part_tmp*prec;
    int_to_string(fix_part,fix);

    merge_modified_string(dec,fix,number);
    printf("%s",number);



}


//6-Write a C function to take 3 strings, “main string”, “find”, and “replace”, if you
//find the second string inside the first one replaces it with the t

void find_replace_func(char *main_str,char *Find,char *Replace)
{

    struct student arr[5]= {};

    int flag=0;
    int j=0;
    int i=0;
    for(; main_str[i]; i++)
    {
        if(main_str[i]==' ')
        {
            flag++;
            j=0;
            continue;
        }
        arr[flag].name[j++]=main_str[i];

    }
    for(int i=0; i<4; i++)
    {
        int flag = string_compare(arr[i].name,find);
        if(flag==0)
        {
            move_string_data(arr[i].name,replace);
        }
    }
    char new_string[100]= {0};
    flag=0;
    j=0;
    for(int i=0; i<5; i++)
    {
        for(int k=0; arr[i].name[k]; k++)
        {
            new_string[j++]=arr[i].name[k];
        }
        new_string[j++]=' ';
    }
    printf("%s",new_string);
}



//7-Write a C code to take string “hi,5,hello,12” and print the first word number of
//times as the first number ,and second word as the second number

void print_string_as_equ_int(char *str)
{
    int flag_str=0,flag_int=-1;
    char word1[100]= {0};
    char word2[100]= {0};
    char num1_str[100]= {0};
    char num2_str[100]= {0};
    int num1=0,num2=0;
    int i=0;
    int pos=0;

    for(; str[i]; i++)
    {
        if( (str[i]==',') && (str[i-1]>='0' && str[i-1]<='9'))
        {
            flag_str++;
            pos=0;
            continue;
        }
        if( (str[i]==',') && (str[i-1]>='a' && str[i-1]<='z') )
        {
            flag_int++;
            pos=0;
            continue;
        }
        if(str[i]==',')
        {
            pos=0;
        }

        if((str[i]>='a' && str[i]<='z') && (flag_str==0) )
        {
            word1[pos++]=str[i];
        }
        else if((str[i]>='a' && str[i]<='z') && (flag_str==1) )
        {
            word2[pos++]=str[i];
        }
        else if((str[i]>='0' && str[i]<='9') && (flag_int==0) )
        {
            num1_str[pos++]=str[i];
        }
        else if((str[i]>='0' && str[i]<='9') && (flag_int==1) )
        {
            num2_str[pos++]=str[i];
        }
    }


    num1= string_to_int(num1_str);
    num2= string_to_int(num2_str);

    for(int i =0 ; i<num1; i++)
    {
        printf("%s ",word1);
    }
    printf("\n");

    for(int i =0 ; i<num2; i++)
    {
        printf("%s ",word2);
    }

}
