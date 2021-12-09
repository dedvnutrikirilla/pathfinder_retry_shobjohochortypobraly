#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
	if (hex == NULL) {
		return 0;
	}

	unsigned long base = 1;
	unsigned long decimal = 0;

	int len = 0;
	
	while (hex[len] != '\0') {
		if (!(hex[len] >= '0' && hex[len] <= '9')
		&& !((hex[len] >= 'A' && hex[len] <= 'F')
        || (hex[len] >= 'a' && hex[len] <= 'f'))) {
			return 0;
        }

		len++;
	}
	
	for (int i = len - 1; i >= 0; i--) {
		if (hex[i] >= '0' && hex[i] <= '9') {
	        decimal += (hex[i] - 48) * base;
	        base *= 16;
	    }
	    else if (hex[i] >= 'A' && hex[i] <= 'F') {
	        decimal += (hex[i] - 55) * base;
	        base *= 16;
	    }
	    else if (hex[i] >= 'a' && hex[i] <= 'f') {
	        decimal += (hex[i] - 87) * base;
	        base *= 16;
	    }
	}
	
	return decimal;
}
