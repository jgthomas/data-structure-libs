#include <stdio.h>
#include "convertors.h"


int main()
{
        char *num_string = "123";
        char c = 'a';
        float f = 10.91;
        int n = 99;
        float f_char = 98.11;
        int index = 5;
        char c2 = 'C';
        
        int num = convert_to_int(&num_string, string_to_int);
        int char_num = convert_to_int(&c, char_to_int);
        int float_int = convert_to_int(&f, float_to_int);
        char char_from_n = convert_to_char(&n, int_to_char);
        char char_from_f = convert_to_char(&f_char, float_to_char);
        char char_idx = convert_to_char(&index, index_to_lower_char);
        char char_idx2 = convert_to_char(&index, index_to_upper_char);
        int idx_char = convert_to_int(&c, lower_char_to_index);
        int idx_char2 = convert_to_int(&c2, upper_char_to_index);
        
        printf("%d\n", num);
        printf("%d\n", char_num);
        printf("%d\n", float_int);
        printf("%c\n", char_from_n);
        printf("%c\n", char_from_f);
        printf("%c\n", char_idx);
        printf("%c\n", char_idx2);
        printf("%d\n", idx_char);
        printf("%d\n", idx_char2);
}
