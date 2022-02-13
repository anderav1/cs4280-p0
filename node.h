// Lexi Anderson
// Feb 12, 2022
// CS 4280, Project 0
// node.h -- define tree node structure and functionality


#ifndef NODE_H
#define NODE_H

#include "list.h"

typedef struct node_t {
  char letter;
  node_t *left, *right;
  list_t *list;
};

typedef struct tree_t {
  node_t *root;
};


#endif
