#include "list.h"

#include <cstdlib>

void initializeList(List* list) {
  list->head = nullptr;
  list->size = 0;
}

bool listEmpty(List* list) { return !list->head; }

bool listFull(List* list) { return false; }

int listSize(List* list) { return list->size; }

void destroyList(List* list) {
  ListNode* temp;

  while (list->head) {
    temp = list->head->next;
    std::free(list->head);
    list->head = temp;
  }

  list->size = 0;
}

void traverseList(List* list, void (*visit)(ListEntry)) {
  ListNode* temp = list->head;

  while (temp) {
    (*visit)(temp->entry);

    temp = temp->next;
  }
}
