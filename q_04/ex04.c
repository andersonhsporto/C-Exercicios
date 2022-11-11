#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int value;
  struct ListNode *next;
};

struct ListNode *createNode(int value);

struct ListNode *lastNode(struct ListNode *head);

void addNodeBack(struct ListNode **head, struct ListNode *node);

struct ListNode *arrayToList(int *numberArray, int size);

void sortList(struct ListNode **list);

struct ListNode *mergeKLists(struct ListNode **list, int listSize);

void printList(struct ListNode *head);

void freeList(struct ListNode *head);

int main() {
  struct ListNode *listA = arrayToList((int[]){1, 3, 8}, 3);
  struct ListNode *listB = arrayToList((int[]){1, 3, 6}, 3);
  struct ListNode *listC = arrayToList((int[]){8, 9}, 2);

  struct ListNode *listArray[] = {listA, listB, listC};
  struct ListNode *mergedList = mergeKLists(listArray, 3);
  printList(mergedList);

  freeList(listA);
  freeList(listB);
  freeList(listC);
  freeList(mergedList);
  return 0;
}

struct ListNode *createNode(int value) {
  struct ListNode *node = malloc(sizeof(struct ListNode));

  if (node) {
    node->value = value;
    node->next = NULL;
    return node;
  }
  return NULL;
}

struct ListNode *lastNode(struct ListNode *head) {
  if (head) {
    while (head->next) {
      head = head->next;
    }
    return head;
  }
  return NULL;
}

void addNodeBack(struct ListNode **head, struct ListNode *node) {
  struct ListNode *current;

  if (*head) {
    current = lastNode(*head);
    current->next = node;
  } else {
    *head = node;
  }
}

struct ListNode *arrayToList(int *numberArray, int size) {
  struct ListNode *head = createNode(numberArray[0]);

  for (int i = 1; i < size; i++) {
    addNodeBack(&head, createNode(numberArray[i]));
  }
  return head;
}

void sortList(struct ListNode **list) {
  struct ListNode *current = *list;
  struct ListNode *next = NULL;
  int temp;

  if (*list == NULL) {
    return;
  }
  while (current->next != NULL) {
    next = current->next;
    while (next != NULL) {
      if (current->value > next->value) {
        temp = current->value;
        current->value = next->value;
        next->value = temp;
      }
      next = next->next;
    }
    current = current->next;
  }
}

struct ListNode *mergeKLists(struct ListNode **list, int listSize) {
  struct ListNode *mergedList = NULL;

  for (int i = 0; i < listSize; i++) {
    struct ListNode *current = list[i];

    while (current != NULL) {
      addNodeBack(&mergedList, createNode(current->value));
      current = current->next;
    }
  }
  sortList(&mergedList);

  return mergedList;
}

void printList(struct ListNode *head) {
  struct ListNode *current = head;

  while (current != NULL) {
    printf("%d ", current->value);
    current = current->next;
  }
  printf("\n");
}

void freeList(struct ListNode *head) {
  struct ListNode *current = head;
  struct ListNode *next;

  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
}
