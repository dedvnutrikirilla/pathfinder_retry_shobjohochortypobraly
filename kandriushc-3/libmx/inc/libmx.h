#ifndef MINILIBMX_H
#define MINILIBMX_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#ifdef __MACH__
  #include <malloc/malloc.h>
  #include <sys/acl.h>
#else
  #include <malloc.h>
  #define malloc_size malloc_usable_size
  #define S_IXUSR __S_IEXEC // v_(0-0)_v //
  #include <stdio.h>
  #include <string.h>
#endif

// v MY STRUCT v
typedef struct s_list {
    void *data;
    struct s_list *next;
}               t_list;
// ^ MY STRUCT ^

// v MY USEFUL v
bool mx_isspace(int);
char *mx_strchr(const char *, int);
int mx_strncmp(const char *, const char *, int);
void mx_arrstr_swap(char **arr1, char **arr2);
void mx_clear_list(t_list **list);
void mx_pop_index(t_list **list, int index);
void mx_push_index(t_list **list, void *data, int index);
// vvv FOR CHECKING ONLY (include stdio and string) vvv
void mx_lib_checker();
// ^^^
// ^ MY USEFUL ^

// v UTILS PACK v
void mx_printchar(char);
//  vvv     ╮( ˘ ､ ˘ )╭     vvv
void mx_print_unicode(wchar_t c);
//  ^^^     ╮( ˘ ､ ˘ )╭     ^^^
void mx_printstr(const char *);
void mx_print_strarr(char**, const char*);
void mx_printint(int);
double mx_pow(double, unsigned);
int mx_sqrt(int);
char *mx_nbr_to_hex(unsigned long n);
unsigned long mx_hex_to_nbr(const char *);
char *mx_itoa(int);
void mx_foreach(int *, int, void(*)(int));
int mx_binary_search(char **, int, const char *, int *);
int mx_bubble_sort(char **, int);
// vvv     ╮( ˘ ､ ˘ )╭     vvv
int mx_quicksort(char **, int, int);
////////////////////////////////////////////////////
// ^ UTILS PACK ^

// v STRING PACK v
int mx_strlen(const char *);
void mx_swap_char(char *, char *);
void mx_str_reverse(char *);
void mx_strdel(char **);
void mx_del_strarr(char ***);
int mx_get_char_index(const char *, char);
char *mx_strdup(const char *);
char *mx_strndup(const char *, size_t);
char *mx_strcpy(char *, const char *);
char *mx_strncpy(char *, const char *, int);
int mx_strcmp(const char *, const char *);
char *mx_strcat(char *, const char *);
char *mx_strstr(const char *, const char *);
int mx_get_substr_index(const char *, const char *);
int mx_count_substr(const char *, const char *);
int mx_count_words(const char *, char);
char *mx_strnew(const int);
char *mx_strtrim(const char *);
char *mx_del_extra_spaces(const char *);
char **mx_strsplit(const char *, char);
char *mx_strjoin(char const *, char const *);
char *mx_file_to_str(const char *);
// v_(^0_0^)_v  vvv unchecked vvv  v_(^0_0^)_v
char *mx_replace_substr(const char *, const char *, const char *);
// ^ STRING PACK ^

// v MEMORY PACK v
void *mx_memset(void *b, int c, size_t len);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
int mx_memcmp(const void *s1, const void *s2, size_t n);
void *mx_memchr(const void*s, int c, size_t n);
void *mx_memrchr(const void *s, int c, size_t n);
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len);
void *mx_memmove(void *dst, const void *src, size_t len);
void *mx_realloc(void *ptr, size_t size);
// ^ MEMORY PACK ^

// v LIST PACK v
t_list *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_push_back(t_list **list, void *data);
void mx_pop_front(t_list **head);
void mx_pop_back(t_list **head);
int mx_list_size(t_list *list);
// v_(^0_0^)_v  vvv unchecked vvv  v_(^0_0^)_v
t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *));
// ^ LIST PACK ^

#endif
