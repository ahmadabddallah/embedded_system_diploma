#ifndef STUDENT_H_
#define STUDENT_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char str[100];
    int age;
    char GPA;
    char phone[14];

} student;



void swap_student(student *st1,student *st2);




void student_read(student *st);
void student_print();

void add_student();
void edit_student();
void print_student();

void call_student();
void NumberOfStudent();
void print_school();
void delete_student();

#endif // STUDENT_H_
