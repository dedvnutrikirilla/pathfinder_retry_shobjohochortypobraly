#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (buf_size <= 0 || fd <= 0) {
        return -2;
    }

    char* temp = *lineptr;
    *lineptr = NULL;
    char *buf = mx_strnew(buf_size);
    int reading = 0;
    int nobytes = 0;
    int delim_ind = mx_get_char_index(buf, delim);

    while ((reading = read(fd, buf, buf_size)) > 0) {
        if(delim_ind >= 0) {
            buf[delim_ind] = '\0';
            *lineptr = mx_strjoin(*lineptr, buf);
            nobytes = mx_strlen(buf);

            free(buf);
            free(temp);
            return nobytes;
        }
        *lineptr = mx_strjoin(*lineptr, buf);
        nobytes += reading;
    }

    free(buf);

    if (nobytes == 0) {
        *lineptr = temp;
        free(temp);
        if (reading == -1) {
            return -2;
        }
        else {
            return -1;
        }
    }

    free(temp);
    return nobytes;
}
