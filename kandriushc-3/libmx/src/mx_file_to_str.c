#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
	if(!file) {
		return NULL;
    }

	int len_file = open(file, O_RDONLY);
	if(len_file < 0){
		close(len_file);
		return NULL;
	}

	int length= 0;
	char file_char;
    while(read(len_file, &file_char, 1)) {
        length++;
    }
	close(len_file);

	if(length == 0) {
        return NULL;
    }
	
	int temp_file = open(file, O_RDONLY);
	char *buffer = mx_strnew(length);

	read(temp_file, buffer, length);
	close(temp_file);
	
	return buffer;
}
