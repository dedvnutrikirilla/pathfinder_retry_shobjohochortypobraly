#include "../inc/libmx.h"

int mx_sqrt(int x) {
    if (x <= 0) {
        return 0;
    }

    int half_x = x / 2 + 1;

	for (int i = 0; i < half_x; i++) {
		if(i * i == x) {
			return i;
		}
	}
	
	return 0;
}
