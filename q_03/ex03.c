#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void printColor(int32_t color) {
	printf("0x%X\n", color);
}

void gradualIncrease(int32_t r_init, int32_t r_final, int steps) {
	int32_t diff = r_final - r_init;
	int32_t step = diff / steps;

	for (int i = 1; i < steps; ++i) {
		printColor(r_init + step * i);
	}
	printColor(r_final);
}

void defaultCase() {
	uint32_t initialColor = 0x00001A;
	uint32_t finalColor = 0xFF001A;
	int steps = 3;

	gradualIncrease(initialColor, finalColor, steps);
	exit(0);
}

char charToHex(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	if (c >= 'a' && c <= 'f') {
		return c - 'a' + 10;
	}
	if (c >= 'A' && c <= 'F') {
		return c - 'A' + 10;
	}
	return 0;
}

uint32_t stringToHex(char *str) {
	uint32_t result = 0;
	int len = strlen(str);

	for (int i = 0; i < len; i++) {
		result = result * 16 + charToHex(str[i]);
	}
	return result;
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		defaultCase();
	} else if (argc == 4) {
		uint32_t	initialColor = stringToHex(argv[2]);
		uint32_t	finalColor = stringToHex(argv[3]);
		int			steps = atoi(argv[4]);

		gradualIncrease(initialColor, finalColor, steps);
	}
	return 0;
}