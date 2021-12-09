#include "../inc/libmx.h"

double mx_pow(double n, unsigned int pow) {
    double temp = n;
	
    while (pow > 1) {
        n *= temp;
        pow--;
    }

    return n;
}
