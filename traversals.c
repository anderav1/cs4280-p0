// Lexi Anderson
// Feb 13, 2022
// CS 4280, Project 0
// traversals.c

#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "node.h"
#include "traversals.h"

// breadth-first traversal
void traverseLevelOrder(node_t* root, const char fileName[]) {
  // TODO: implement level-order traversal
  
}

// visit node, then left and right children
void traversePreOrder(node_t* root, const char fileName[]) {
  if (root == NULL) return;
  
  // TODO: visit current node
  char* outputFile = NULL;
  sprintf(outputFile, "%s.preorder", fileName);

  printNodeToFile(root, outputFile);
  
  traversePreOrder(root->left, fileName);
  traversePreOrder(root->right, fileName);
}

// visit left and right children, then node
void traversePostOrder(node_t* root, const char fileName[]) {
  if (root == NULL) return;

  traversePostOrder(root->left, fileName);
  traversePostOrder(root->right, fileName);
  
  // TODO: visit current node
  char* outputFile = NULL;
  sprintf(outputFile, "%s.postorder", fileName);
  
  printNodeToFile(root, outputFile);
}

void printNodeToFile(node_t* node, const char fileName[]) {
  FILE* fp;
  listnode_t* listptr;
  
  if ((fp = fopen(fileName, "a+")) == NULL) {
    printf("Failed to open file %s", fileName);
    exit(1);
  }
  
  fprintf(fp, "%c :", node->letter);
  
  listptr = node->list->head;
  while (listptr != NULL) fprintf(fp, " %s", listptr->word);
  
  fprintf(fp, "\n");
  
  if (fclose(fp) == EOF) {
    printf("Failed to close file %s", fileName);
    exit(1);
  }
}
