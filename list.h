// Lexi Anderson
// Feb 12, 2022
// CS 4280, Project 0
// list.h -- Define list structure that holds words for each tree node

#ifndef LIST_H
#define LIST_H

typedef struct listnode_t {
  char* word;
  struct listnode_t* next;
} listnode_t;

typedef struct {
  listnode_t *head, *tail;
} list_t;


list_t* createList();
listnode_t* createListNode(char*);
void addToList(list_t*, char*);
bool listEmpty(list_t*);


#endif
