#ifndef string_h_

#define string_h_

struct student {
    char name [100];
};

void scan_string(char* str);

void string_print(char *str);

void reverse_string(char *str);
int string_length(char *str);
int string_compare (char *str1 ,char *str2);
int check_mirror(char *str);

int string_to_int(char*str);
void extract_number_from_string(char *str);

void int_to_string(int n,char *str);

void merge_modified_string(char*str1 , char*str2,char *result);

void float_to_string(float f,char *str);
void move_string_data(char *str1,char *str2);

void find_replace_func(char *main_str,char *Find,char *Replace);

void print_string_as_equ_int(char *str);

#endif // string_h_
