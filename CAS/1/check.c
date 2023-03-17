/*
 * main.c
 */

#include <stdio.h>

// (A-1)*2 and (C*2+B)

int main(void) {
	unsigned char A = -10;
	unsigned char B = 253;
	unsigned char C = 31;
	unsigned char F = (A - 1) * 2 & (C * 2 + B);
	printf("%02X\n", F);
	return 0;
}
