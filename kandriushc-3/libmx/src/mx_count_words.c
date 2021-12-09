#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    bool cond = true;
    unsigned count = 0;
    int i = 0;
    
    if (str == NULL)
        return -1;
    else {
        while (str[i]) {
            if (str[i] == c)
                cond = true;
            else if (cond == true) {
                cond = false;
                count++;
            }
            i++;
        }
        
        return count;
    }
}
