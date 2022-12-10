#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char *reader();

bool isRoman(char *str);

int romanToInt(char c);

size_t romanConverter(char *string);

int main() {
  char *line = reader();
  size_t romanNumber = romanConverter(line);

  printf("%zu\n", romanNumber);
  free(line);
  return 0;
}

char *reader() {
  char *line = malloc(10000);

  printf("Digite um numero romano: ");
  fgets(line, 10000, stdin);
  if (isRoman(line)) {
    return line;
  } else {
    free(line);
    printf("Numero invalido, tente novamente.\n");
    return reader();
  }
}

bool isRoman(char *str) {
  char *roman = "IVXLCDM";

  for (int i = 0; i < strlen(str) - 1; i++) {
    if (!strchr(roman, str[i])) {
      return false;
    }
  }
  return true;
}

int romanToInt(char c) {
  switch (c) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
  }
}

size_t romanConverter(char *string) {
  size_t number = 0;

  for (size_t i = 0; i < strlen(string); i++) {
    if (romanToInt(string[i]) < romanToInt(string[i + 1])) {
      number += romanToInt(string[i + 1]) - romanToInt(string[i]);
      i++;
    } else {
      number += romanToInt(string[i]);
    }
  }
  return number;
}
