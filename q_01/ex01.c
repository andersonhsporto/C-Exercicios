#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

bool	isPalindrome(char *str);
int		maxPalindrome(char *str);
char	*getNextLine(int fd);
int		maxPossiblePalindrome(char *str);

int main() {
	printf("%d\n", maxPalindrome("strings_01.txt"));
	return 0;
}

int maxPalindrome(char *str) {
	int fd = open(str, O_RDONLY);
	int temp;
	int max = 0;

	if (fd == -1) {
		return -1;
	}
	while (true)
	{
		char *line = getNextLine(fd);
		if (line == NULL)
			break;
		temp = maxPossiblePalindrome(line);
		if (temp > max) {
			max = temp;
		}
		free(line);
	}
	close(fd);
	return max;
}

char *getNextLine(int fd) {
    char *s = malloc(10000), *c = s;

    while (read(fd, c, 1) > 0 && *c++ != '\n');
    return c > s ? (*c = 0, s) : (free(s), NULL);
}

char *reverseString(char *string) {
	char *result = malloc(strlen(string) + 1);

	for (int i = 0; i < strlen(string); i++) {
		result[i] = string[strlen(string) - i - 1];
	}
	result[strlen(string)] = '\0';
	return result;
}

bool isPalindrome(char *str) {
	char *reversed = reverseString(str);

	if (strcmp(str, reversed) == 0) {
		free(reversed);
		return true;
	}
	free(reversed);
	return false;
}

int maxPossiblePalindrome(char *str) {
	int len = strlen(str);
	int max = 0;

	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			char *substr = malloc(j - i + 1);
			strncpy(substr, str + i, j - i);
			substr[j - i] = '\0';
			if (isPalindrome(substr)) {
				int substrLen = strlen(substr);
				if (substrLen > max) {
					max = substrLen;
				}
			}
			free(substr);
		}
	}
	return max;
}

