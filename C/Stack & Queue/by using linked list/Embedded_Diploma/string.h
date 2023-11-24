#ifndef STRING_H_
#define STRING_H_

void string_scan(char *str,int max_size);

void string_print(char *str);
int string_length(char*str);
void string_upperToLower(char *str);


void string_reverse(char *str);
int string_compare(char *str1,char *str2);

int binary_search_toFound_String(char **arr,int size,char *str);

int string_compare_not_sensitive(char *str1,char*str2);

void intToString(int n,char *str);
int stringToInt(char* str);




#endif
