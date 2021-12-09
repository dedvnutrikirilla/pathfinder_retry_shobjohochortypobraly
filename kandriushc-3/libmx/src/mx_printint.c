#include "../inc/libmx.h"

void mx_printint(int n) {
    if(n == -2147483648) {
		write(1, "-2147483648", 11);
		return;
	}	
	
	if(n == 0) {
		mx_printchar(48);
		return;
	}

    if(n < 0) {
		mx_printchar('-');
        n *= -1;
	}

    int temp = n;
    int len = 0;
    
    while (temp != 0) {
		temp /= 10;
		len++;
	}

	char num_str[len];
	int d = 0;
    temp = n;

	for (int i = 0; i < len; i++) {
		d = temp % 10;
		num_str[i] = d + 48;
		temp /= 10;
	}

	for(int i = len - 1; i >= 0; i--) {
		mx_printchar(num_str[i]);
	}

	return;
}
