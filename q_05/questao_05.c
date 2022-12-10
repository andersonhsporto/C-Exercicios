#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define GREEN  "\x1B[32m"
#define CYAN  "\x1B[36m"
#define RESET  "\x1B[0m"
#define LINES  3
#define COLLUMS  5

void  slotGame(int prize[LINES][COLLUMS]);
int   **createSlot();
void  fillRandomSlot(int **slot);
void  printMatrix(int **matrix);
bool  checkSlot(int **answer, int slot[LINES][COLLUMS]);
void  freeSlot(int **slot);

int main(void) {
  int prize[LINES][COLLUMS] = {{1, 0, 0, 0, 1},
                               {0, 1, 0, 1, 0},
                               {0, 0, 1, 0, 0}};

  slotGame(prize);
  return (0);
}

void slotGame(int prize[LINES][COLLUMS]) {
  int **slot = createSlot();

  while (true) {
    printf(GREEN"--------- Nova Tentativa ---------\n"RESET);
    fillRandomSlot(slot);
    printMatrix(slot);
    if (checkSlot(slot, prize)) {
      printf(GREEN"---------    Ganhou!     ---------\n"RESET);
      break;
    }
    printf(CYAN"Tenha mais sorte na proxima vez!\n"RESET);
  }
  freeSlot(slot);
}

void fillRandomSlot(int **slot) {
  int j;

  for (int i = 0; i < LINES; i++) {
    j = 0;
    while (j < COLLUMS) {
      slot[i][j] = rand() % 2;
      j++;
    }
  }
}

void printMatrix(int **matrix) {
  for (int i = 0; i < LINES; i++) {
    printf("\t    ");
    for (int j = 0; j < COLLUMS; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int **createSlot() {
  int **slot;
  int line = 0;

  slot = malloc(sizeof(int *) * 3);
  while (line < LINES) {
    slot[line++] = malloc(sizeof(int));
  }
  return (slot);
}

bool checkSlot(int **answer, int slot[LINES][COLLUMS]) {
  for (int i = 0; i < LINES; i++) {
    for (int j = 0; j < COLLUMS; j++) {
      if (answer[i][j] != slot[i][j]) {
        return false;
      }
    }
  }
  return true;
}

void freeSlot(int **slot) {
  for (int i = 0; i < LINES; i++) {
    free(slot[i]);
  }
  free(slot);
}

