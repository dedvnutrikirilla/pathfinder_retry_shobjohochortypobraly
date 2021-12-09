#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (!s || !*s) {
        return NULL;
    }
    
    int count = mx_count_words(s, c);

    int letters = 0;
    int start = -1;
    int word_counter = 0;
    int position = 0;

    char **split_arr = (char**) malloc((count + 1) * sizeof(char *));

    while (s[position] != '\0') {
        if (s[position] != c) {
            letters++;
            if (start == -1) {
                start = position;
            }
        }
        else {
            if(letters > 0) {
                split_arr[word_counter] = mx_strndup(&s[start], letters);
                letters = 0;
                start = -1;
                word_counter++;
            }
        }
        position++;
    }

    if(s[position] == '\0' && start > -1){
        split_arr[word_counter] = mx_strndup(&s[start], letters);
    }

    split_arr[count] = NULL;

    return split_arr;
}
