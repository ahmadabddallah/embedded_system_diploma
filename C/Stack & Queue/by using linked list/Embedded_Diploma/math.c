
#include "math.h"

int stringToInt2(char *str,int*pnum)
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
        else
            return 0;
    }
    *pnum=n;
    return 1;

}

void swap(int *px,int *py)
{

    int tmp=*px;
    *px=*py;
    *py=tmp;



}
char *funstr(int n)
{

    char *s;
    if(n==1)
        s="paula magdy";
    else
        s="asmaa";
    return s;

}

int* funcnew(void)
{

    static int x=5;
    x++;
    printf("%d\n",x);
    return &x;

}

int *arr_new(int n,int *yy)
{

    static int arr[]= {10,20,30,40,50};
    int *p=arr;
    p[2]=n;

    static int y =1;
    y++;
    *yy=y;
    return p;
}

int factorial(int n)
{

    int sum=1;
    for(int j=n; j>0; j--)
    {
        sum*=j;
    }
    return sum;


}
int max_number(int n)
{
    static int mx=0x80000000;
    static int flag=0;
    if(flag==0)
    {
        mx=n;
        flag=n;
    }

    if(n>mx)
    {
        mx=n;
    }
    return mx;
}

int *array_scan3(void)
{

    int *ptr;
    int sz;
    printf("please enter the size of array you want \n");
    scanf("%d",&sz);
    ptr=(char*)calloc(sz,sizeof(int));//store data in heap;
    for(int j=0; j<sz; j++)
    {
        printf("please enter the value of A[%d]\n",j);
        scanf("%d",&ptr[j]);
    }
    return ptr;
}

int array_mostRepeated(int *arr,int size,int *pnum)
{

    int i,j,max=0,c=0,count=0;
    for(i=0; i<size; i++)
    {
        count=0;

        for(j=i; j<size; j++)
        {
            c++;
            if(arr[i]==arr[j])
            {
                count++;
            }
        }
        if(count>max)
        {
            max=count;
            *pnum=arr[i];
        }
    }
    printf("c: %d\n",c);
    return max;

}


int sum_numbers(int n)
{


    return (n*(n+1))/2;

}
int array_mostRepeatedSorted(int *arr,int size,int *pnum)
{
    int i=0,j,max=0,c=0,count=1;
    for(; i<size-1; i++)
    {
        c++;
        if(arr[i]==arr[i+1])
        {
            count++;
            if(count>max)
            {
                max=count;
                *pnum=arr[i];
            }

        }
        else
            count=1;

    }
    printf("c : %d\n",c);
    return max;

}

int array_mostRepeatedMono(int *arr,int size,int *pnum)
{
    int count[10]= {0};
    int c=0;
    int mx=0x80000000;
    for(int i=0; i<size; i++)
    {
        c++;
        count[arr[i]]++;
        if(count[arr[i]]>mx)
        {
            mx=count[arr[i]];
            *pnum=arr[i];
        }

    }
    printf("s:%d c: %d \n",size,c);
    //array_print(count,10);
    return mx;
}
int array_mostRepeated2(int *arr,int size,int *pnum)
{

    int c=0;
    int i,max=arr[0],count_size,min=0,max_c=0;

    for(i=0; i<size; i++)
    {
        c+=2;
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }

    count_size=max-min+1;

    int *count=calloc(count_size,sizeof(int));

    for(int i=0; i<size; i++)
    {
        count[arr[i]]++;
    }

    for(int i=0; i<count_size; i++)
    {
        if(count[i]>max_c)
        {
            max_c=count[i];
            *pnum=i;
        }
    }
    printf("s:%d  c:%d\n",size,c);
    free(count);
    return max_c;

}

void string_copyNoRepeated(char *str,char *str2)
{
    int *frq=calloc(256,sizeof(int));
    int c=0;
    for(int i=0; str[i]; i++)
    {
        frq[str[i]-'a']=1;
        c++;
    }

    int j=0;

    for(int i=0; str[i]; i++)
    {
        if(frq[str[i]-'a']>=1)
        {
            c++;
            str2[j++]=str[i];
            frq[str[i]-'a']=0;
        }
    }
    str[j]=0;
    printf("%d",c);
    free(frq);

}

int array_binarySearch(int *arr,int size, int num)
{
    int first,last,middle;
    first=0;
    last=size-1;

    while(first<=last)
    {
        middle=(first+last)/2;

        if(arr[middle]==num)
        {

            return middle;
        }
        else if(arr[middle]>num)
        {
            last=middle-1;
        }
        else
        {
            first=middle+1;
        }

    }
    return -1;
}


int fact_r(int n)
{

    //base case
    if(n==1)
    {
        return 1;
    }
    else if(n==0)
    {
        return 1 ;
    }
    return fact_r(n-1)*n;



}

int fib(int n)
{
    int n0=0;
    int n1=1;
    int n2;
    if(n==0 || n==1)
    {
        return n;
    }
    for(int i=1; i<n; i++)
    {
        n2=n1+n0;
        n0=n1;
        n1=n2;
    }
    return n2;
}

int fib_r(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }

    return fib_r(n-1)+fib_r(n-2);
}

int fibb(int n)
{

    if(n==0 || n==1)
    {
        return n;
    }
    return fibb(n-1)+fibb(n-1);

}

int func55(int x)
{
    static int c=0;
    c++;

    if(x==0)
    {
        printf("%d\n",c);
        return 0;

    }
    else
    {
        printf("%d",x);
        func55(--x);
    }


}

void swap_char(char *p1,char *p2)
{
    char temp=*p1;
    *p1=*p2;
    *p2=temp;

}
void swap_pointers(char **p1,char **p2)
{
    printf("func   %d    %d\n",p1,p2);
    char *temp=*p1;
    *p1=*p2;
    *p2=temp;

}

void arrayOfPointers_print(char **arr,int size)
{

    int i;
    for(i=0; i<size; i++)
    {
        /* for(int j=0;arr[i][j];j++){
             printf("%c",arr[i][j]);
         }
         printf("\n");
         */
        string_print(arr[i]);
    }
    printf("\n-----------------------------------\n");

}
void swapp_pointers(char **pp1,char **pp2)
{
    char *temp=*pp1;
    *pp1=*pp2;
    *pp2=temp;
}




int arrayOfPointers_search(char **arr,int size,char *s)
{
    int i;
    for(int i=0; i<size; i++)
    {
        if(string_compare(arr[i],s)==1)
        {
            return i;
        }
    }
    return -1;

}

void array_bubblesSort(int *arr,int size)
{

    int i,j,temp,c=0,flag=0;
    for(j=0; j<size&&flag==0 ; j++)
    {
        flag=1;
        for(i=0; i<size-1-j; i++)
        {

            c++;
            if(arr[i]<arr[i+1])
            {
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                flag=0;
            }
        }

    }
    printf("\n size=%d c is %d\n",size,c);

}

/*void array_2dsort(char arr[][3],int size){

    int i,j,c=0,flag=0;
    char *temp;
    for(j=0; j<size&&flag==0 ; j++)
    {
        flag=1;
        for(i=0; i<size-1-j; i++)
        {
            c++;
            if(string_compare(arr[],arr[i+1])==1)
            {
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                flag=0;
            }
        }
    }

}
*/



void arrayOfPointers_bubbleSort(char **arr,int size)
{
    int i,j,c=0,flag=0;
    char *temp;
    for(j=0; j<size&&flag==0 ; j++)
    {
        flag=1;
        for(i=0; i<size-1-j; i++)
        {
            c++;
            if(string_compare(arr[i],arr[i+1])==1)
            {
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                flag=0;
            }
        }
    }

}

void array2D_print(int arr[][5],int row,int col)
{

    int i,j;
    for(i=0; i<row; i++)
    {

        for(j=0; j<col; j++)
        {
            printf("%4d ",arr[i][j]);
        }
        printf("\n");

    }


}
void arrayp_print(int **arr,int row,int col)
{

    int i,j;
    for(i=0; i<row; i++)
    {

        for(j=0; j<col; j++)
        {
            printf("%3d ",arr[i][j]);
        }
        printf("\n");
    }

}

void array_2d_search(char page [][50],int line,char ch,int *i_index,int *j_index)
{
    int i,j;
    for(i=0; i<line; i++)
    {

        for(j=0; page[i][j]; j++)
        {
            if(page[i][j]==ch)
            {

                *i_index=i;
                *j_index=j;
                return ;
            }
        }

    }
    *i_index=-1;
    *j_index=-1;


}

void star_set(char(*arr)[100],int row,int col,int star_x,int star_y)
{
    int i,j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if((j==star_y)&&(i<star_x))
            {
                arr[i][j]='v';
            }
            else if((j==star_y)&&(i>star_x))
            {
                arr[i][j]='^';
            }
            else if((j<star_y)&&(i==star_x))
                arr[i][j]='>';
            else if((j>star_y)&&(i==star_x))
                arr[i][j]='<';
            else
                arr[i][j]='0';
        }

    }
    arr[star_x][star_y]='*';

}


void array_selectionSort(int *arr,int size)
{
    int pos=size-1;
    int mx=0x80000000;
    int idx=0;
    for(int j=0; j<size; j++)
    {
        mx=0x80000000;

        for(int i=0; i<size-j; i++)
        {
            if(mx<arr[i])
            {
                mx=arr[i];
                idx=i;
            }

        }
        swap(&arr[pos--],&arr[idx]);

    }

}

