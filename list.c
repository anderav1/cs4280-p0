// Lexi Anderson
// Feb 13, 2022
// CS 4280, Project 0
// list.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

// Create empty list
// Returns the empty list
list_t* createList() {
  list_t* list = (list_t*)malloc(sizeof(list_t));
  
  list->head = NULL;
  list->tail = NULL;
  
  return list;
}

// Create a list node for a new word
// word -- word to use to create node
// Returns the newly created node
listnode_t* createListNode(const char word[]) {
  listnode_t* node = (listnode_t*)malloc(sizeof(listnode_t));
  
  strcpy(node->word, word);
  node->next = NULL;
  
  return node;
}

// Append new word to end of list
// list -- list to be appended
// word -- word to add to list
void addToList(list_t* list, const char word[]) {
  listnode_t* newnode = createListNode(word);
  
  if (listEmpty(list)) {
    list->head = newnode;
    list->tail = newnode;
    return;
  }
  
  list->tail->next = newnode;
  list->tail = newnode;
}

// Check if list is empty
// list -- list to check
// Returns true if empty
bool listEmpty(list_t* list) {
  return (list->head == NULL);
}
