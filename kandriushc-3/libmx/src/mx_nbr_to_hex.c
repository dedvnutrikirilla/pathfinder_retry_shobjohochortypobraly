#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    if(nbr < 0) {
        return 0;
    }

    if (nbr == 0) {
        return "0";
    }

    unsigned long nbrnum = nbr;
    int length = 0;

    while (nbrnum > 1) {
        nbrnum /=16;
        length ++;
    }

    char *hexstring = mx_strnew(length);
    
    while(nbr > 1) {
        int temp = nbr % 16;
        if(temp >= 0 && temp <= 9) {
            hexstring[length - 1] = 48 + temp;
        }
        else if (temp >= 10) {
            hexstring[length - 1] = 87 + temp;
        }
        nbr /= 16;
        length--;
    }

    return hexstring;
}
