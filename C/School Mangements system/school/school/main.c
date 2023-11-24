#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void display();
student arr[100];
int length=0;
int main()
{
    printf("=============WELCOME==========\n");
    while(1)
    {
        char choice;
        display();
        fflush(stdin);
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            add_student();
            break;
        case 2:
            edit_student();
            break;
        case 3:
            printf("please enter the index of student you want to print \n");
            int index;
            scanf("%d",&index);
            student_print(index);
            break;
        case 4:
            delete_student();
            break;
        case 5:
            print_school();
            break;
        case 6:
            call_student();
            break;
        case 7:
            printf("THE total number of student in school right now is \n %d \n ",length);
            break;
        default:
            printf("wrong choice please pree correct choice \n");
        }
    }
    return 0;
}
void display()
{
    printf("press the button you want \n");
    printf("1- Add Student\n");
    printf("2- Edit student\n");
    printf("3- Print student\n");
    printf("4- delete student\n");
    printf("5- print school\n");
    printf("6- call student\n");
    printf("7- How many students in school?\n");

}
