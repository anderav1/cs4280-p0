// Lexi Anderson
// Feb 12, 2022
// CS 4280, Project 0
// list.c

#include "list.h"

// create empty list
list_t* createList() {
  list_t* list = (list_t*)malloc(sizeof(list_t));
  
  list->head = NULL;
  list->tail = NULL;
  
  return list;
}

// create a list node for a new word
private listnode_t* createListNode(char* word) {
  listnode_t* node = (listnode_t*)malloc(sizeof(listnode_t));
  
  strcpy(node->word, word);
  node->next = NULL;
  
  return node;
}

// append new word to end of list
void addToList(list_t* list, char* word) {
  listnode_t* newnode = createListNode(word);
  
  if (listEmpty(list)) {
    list->head = node;
    list->tail = node;
    return;
  }
  
  list->tail->next = node;
  list->tail = node;
}

// check if list is empty
bool listEmpty(list_t* list) {
  return (list->head == NULL);
}
