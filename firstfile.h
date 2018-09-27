
#ifndef __FIRSTFILE_H__
#define __FIRSTFILE_H__
int circ(unsigned int num, int counter);
bool is_prime(int* arr, int len);
unsigned long int power(int num, int expo);
int convert(const char *hexval, int index);
int strlength(const char *str);
void int2char(int num, char* rgb);
void sub_str(const char *str, char *sub, int start, int length);
bool patt_check(char *sub, const char *pattern);
bool same_str(char *str1, char *str2);
void toLower(char *arr);
void sort_three(int a, int b, int c, int *list);
long int unique_sums(const int *A, unsigned int n, unsigned int k);
bool circular_prime(unsigned int n);
unsigned long int any2dec(const char *num, unsigned int b);
void hex2rgb(const char *hex, char *rgb);
unsigned int str_search(const char *pattern, const char *text);
bool same_gmail(const char *g1, const char *g2);
void to_hostname(char *address);
#endif
