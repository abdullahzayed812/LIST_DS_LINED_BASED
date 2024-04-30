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

void insertList(int pos, ListEntry element, List* list) {
  ListNode* newNode = (ListNode*)std::malloc(sizeof(ListNode));
  ListNode* visitor = list->head;

  newNode->entry = element;
  newNode->next = nullptr;

  // Special case if pos == 0
  if (pos == 0) {
    newNode->next = list->head;
    list->head = newNode;
  } else {
    for (int i = 0; i < pos - 1; i++) {
      visitor = visitor->next;
    }

    newNode->next = visitor->next;
    visitor->next = newNode;
  }

  list->size++;
}

void deleteList(int pos, ListEntry* element, List* list) {
  ListNode* visitor = list->head;
  ListNode* temp;

  if (pos == 0) {
    *element = list->head->entry;
    temp = list->head->next;
    std::free(list->head);
    list->head = temp;
  } else {
    for (int i = 0; i < pos - 1; i++) {
      visitor = visitor->next;
    }

    *element = visitor->next->entry;
    temp = visitor->next->next;
    std::free(visitor->next);
    visitor->next = temp;
  }

  list->size--;
}

void retrieveList(int pos, ListEntry* element, List* list) {
  ListNode* visitor = list->head;

  for (int i = 0; i < pos; i++) {
    visitor = visitor->next;
  }

  *element = visitor->entry;
}

void replaceList(int pos, ListEntry element, List* list) {
  ListNode* visitor = list->head;

  for (int i = 0; i < pos; i++) {
    visitor = visitor->next;
  }

  visitor->entry = element;
}

void traverseList(List* list, void (*visit)(ListEntry)) {
  ListNode* temp = list->head;

  while (temp) {
    (*visit)(temp->entry);

    temp = temp->next;
  }
}
