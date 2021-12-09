#include "../inc/libmx.h"

void mx_lib_checker() {
    /*char* arr[] = {"123", "123r532wqe", "ytu76"};
    mx_print_strarr(arr, " ");*/

    //printf("%lu\n", mx_hex_to_nbr("FADE"));
    
    //printf("%s\n", mx_nbr_to_hex(4294967295));

    //printf("%s\n", mx_itoa(-92184891));

    /*char *arr[] = {"abc", "xyz", "ghi", "def"};
    printf("%i\n", mx_bubble_sort(arr, 4));
    for (int i = 0; i < 4; i++) {
        printf("%s\n", arr[i]);
    }*/

// kviksortni mat' svoju iz kanavy, shabolda ebanaia
    /*char *arr[] = {"DMC", "Clint Eastwood", "Dr Brown", "Einstein", "Jessica", "Biff Tannen"};
    printf("\n\nFinal : %i\n", mx_quicksort(arr, 0, 5));
    for (int i = 0; i < 6; i++) {
        printf("%s\n", arr[i]);
    }*/
//
    
    //printf("%d\n", mx_get_char_index("sse", 'e'));

    /*char *strdup = mx_strdup("qwerty");
    printf("%s\n", strdup);*/
    
    /*char *p1;
    p1 = strstr("this is a test", "is");
    char *p2;
    p2 = mx_strstr("this is a test", "is");
    printf("%s - %s\n", p1, p2);
    return 0;*/
    
    /*printf("%d\n", mx_get_substr_index("McDonalds", "Don"));
    printf("%d\n", mx_get_substr_index("McDonalds Donuts", "on"));
    printf("%d\n", mx_get_substr_index("McDonalds", "Donatello"));
    printf("%d\n", mx_get_substr_index("McDonalds", NULL));
    printf("%d\n", mx_get_substr_index(NULL, "Don"));*/

    /*char *str = "yo, yo, yo Neo";
    char *sub = "yo";
    printf("%d\n", mx_count_substr(str, sub));
    printf("%d\n", mx_count_substr(str, NULL));
    printf("%d\n", mx_count_substr(NULL, sub));*/

    /*char *str= "  follow  *   the  white rabbit ";
    printf("%d\n", mx_count_words(str, '*')); 
    printf("%d\n", mx_count_words(str, ' '));
    printf("%d\n", mx_count_words(NULL, ' '));*/

    //printf("%s\n", mx_strtrim("\f My name... is Neo   \t\n"));

    /*char name[] = "\f          My name..  .is\r   Neo\t\n    r   \n  ";
    printf("%s", mx_del_extra_spaces(name));*/

    /*char **arr = mx_strsplit("123 456 789 101 112", ' ');
    for (int i = 0; i <= 5; i++) {
        printf("%s\n", arr[i]);
    }*/

    /*char *str1= "this";
    char *str2= "dodge ";
    char *str3= NULL;
    printf("%s\n", mx_strjoin(str2, str1)); 
    printf("%s\n", mx_strjoin(str1, str3));
    printf("%s\n", mx_strjoin(str3, str3));*/

    //printf("%s\n", mx_replace_substr("McDonalds", "alds", "uts"));

   /*unsigned char src[15]= "12345678909999";
   mx_memset(src, '1', 10);
   printf ("src: %s\n", src);
   memset (src, '2', 10);
   printf ("src: %s\n", src);*/

    /*char buf1[26], buf2[26];
    strcpy(buf1, "When, in the course of...");
    memcpy(buf2, buf1, 26);
    printf ("%s\n", buf2);
    strcpy(buf1, "...fo esruoc eht ni ,nehW");
    mx_memcpy(buf2, buf1, 26);
    printf ("%s\n", buf2);*/

    /*char str[20], out[20];
    strcpy(str, "hello there");
    mx_memccpy(out, str, ' ', 20);
    printf ("%s\n", out);*/

    /*int outcome = memcmp("abcdefgh", "abcdefgh", 9);
    if (!outcome) printf("equal\n");
    else if (outcome<0) printf("First less than second.\n");
    else printf("First greater than second\n");*/

    /*unsigned char src[15]="1234567890";
    char *sym;
    sym = memchr (src, '4', 10);
    printf ("%s\n", sym);*/

    /*char *sym = mx_memrchr("Trinity", 'i', 7); //returns "ity"
    printf ("%s\n", sym);
    sym =mx_memrchr("Trinity", 'M', 7); // NULL
    printf ("%s\n", sym);*/

    /*char *big = "abcdefghjk";
    char *lil = "cde";
    char *sym = mx_memmem(big, 11, lil, 4);
    printf ("%s\n", sym);*/

    /*char *p;
    p = (char *) malloc(17);
    if(!p) {
        printf("Allocation error.");
        exit (1);
    }
    strcpy(p, "This is 16 chars");
    p = (char *) realloc (p,18);
    if(!p) {
        printf("Allocation error.");
        exit (1);
    }
    strcat (p, ".");
    printf("%s\n", p);
    free(p);*/
}
