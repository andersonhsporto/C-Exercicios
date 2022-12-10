#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

bool isPalindrome(char *str);

int maxPalindrome(char *str);

char *getNextLine(int fd);

int maxPossiblePalindrome(char *str);

int main() {
  printf("%d\n", maxPalindrome("strings_01.txt"));
  return 0;
}

int maxPalindrome(char *str) {
  int fd = open(str, O_RDONLY);
  int temp;
  int max = 0;

  if (fd == -1) {
    printf("Error opening file");
    exit(1);
  }
  while (true) {
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

bool isPalindrome(char *str) {
	int len = strlen(str);
	if (len == 0) {
		return true;
	}

	int i = 0;
	int j = len - 1;

	while (i < j)
	{
		if (str[i] != str[j])
			return false;
		i++;
		j--;
	}
	return true;
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

