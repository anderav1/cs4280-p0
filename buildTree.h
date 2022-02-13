// Lexi Anderson
// Feb 12, 2022
// CS 4280, Project 0
// buildTree.h

#ifndef BUILD_TREE_H
#define BUILD_TREE_H

#include <stdio.h>
#include "node.h"

node_t* buildTree(FILE*);
bool isValidWord(char*);
node_t* insertInTree(node_t*, char*);
char getLastLetter(char*);
node_t* createTreeNode(char);


#endif
