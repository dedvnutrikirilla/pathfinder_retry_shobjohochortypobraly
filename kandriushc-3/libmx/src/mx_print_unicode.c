#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c){
    if (c < 0x80) {
        char print[1];
		print[0] = (c >> 0 & 0x7F) | 0x00;
		write(1, &print, 1);
	}
	else if (c < 0x0800) {
        char print[2];
		print[0] = (c >> 6 & 0x1F) | 0xC0;
		print[1] = (c >> 0 & 0x3F) | 0x80;
		write(1, &print, 2);
	}
	else if (c < 0x010000) {
        char print[3];
		print[0] = (c >> 12 & 0x0F) | 0xE0;
		print[1] = (c >> 6 & 0x3F) | 0x80;
		print[2] = (c >> 0 & 0x3F) | 0x80;
		write(1, &print, 3);
	}
	else {
        char print[4];
		print[0] = (c >> 18 & 0x07) | 0xF0;
		print[1] = (c >> 12 & 0x3F) | 0x80;
		print[2] = (c >> 6 & 0x3F) | 0x80;
		print[3] = (c >> 0 & 0x3F) | 0x80;
		write(1, &print, 4);
	}
}
