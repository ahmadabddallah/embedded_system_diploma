#include "student.h"
extern student arr[100];
extern int length;
void swap_student(student *st1 ,student *st2){
    student tmp;
    tmp=*st1;
    *st1=*st2;
    *st2=tmp;

}
void student_read(student *st)
{
    printf("please enter the name of student \n");
    scanf("%s",&st->str);
    fflush(stdin);
    printf("please enter the age of student \n");
    scanf("%d",&st->age);
    printf("please enter the gpa of student \n");
    fflush(stdin);
    scanf(" %c",&st->GPA);
    printf("please enter the Phone no \n");
    scanf("%s",&st->phone);
    fflush(stdin);
}

void add_student()
{
    student_read(&arr[length++]);
}
void edit_student()
{
    printf("\n please enter the name of student do want to edit \n");
    int idx;
    scanf("%d",&idx);
    student_read(&arr[idx]);
}
void student_print(int idx)
{

    printf("\n The name is %s  \n the age is %d \n and the GPA is %c \n",arr[idx].str,arr[idx].age,arr[idx].GPA);

}
void call_student()
{
    char str[100];
    scanf("%s",&str);

    for(int i=0; i<length; i++)
    {
        if(arr[i].str==str)    // maybe error here due to compare between two strings
        {
            printf("\n %s \n",arr[i].phone);
            return 0;
        }

    }

}
void NumberOfStudent()
{
    printf("the school has %d student \n",length);

}

void print_school()
{
    for(int i=0; i<length; i++)
    {
        student_print(i);
    }
}
void delete_student(){
    printf("please enter the index of student you want to delete \n");
    int idx;
    scanf("%d",&idx);
    for(int i=idx;i<length-1;i++){
        swap_student(&arr[idx],&arr[idx+1]);
    }
    length--;
}
