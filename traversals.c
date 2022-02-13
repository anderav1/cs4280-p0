// Lexi Anderson
// Feb 13, 2022
// CS 4280, Project 0
// traversals.c

#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "list.h"
#include "node.h"
#include "traversals.h"

// breadth-first traversal
void traverseLevelOrder(node_t* root, const char fileName[]) {
  int d, i;
  char outputFile[bufferSize];
  
  snprintf(outputFile, bufferSize, "%s.levelorder", fileName);
  
  d = getDepth(root);
  for (i = 1; i <= d; i++) printTreeLevel(root, i, outputFile);
}

// visit node, then left and right children
void traversePreOrder(node_t* root, const char fileName[]) {
  if (root == NULL) return;
  
  char outputFile[bufferSize];
  snprintf(outputFile, bufferSize, "%s.preorder", fileName);

  printNodeToFile(root, outputFile);
  
  traversePreOrder(root->left, fileName);
  traversePreOrder(root->right, fileName);
}

// visit left and right children, then node
void traversePostOrder(node_t* root, const char fileName[]) {
  if (root == NULL) return;

  traversePostOrder(root->left, fileName);
  traversePostOrder(root->right, fileName);
  
  char outputFile[bufferSize];
  snprintf(outputFile, bufferSize, "%s.postorder", fileName);
  
  printNodeToFile(root, outputFile);
}

// print current node to file
void printNodeToFile(node_t* node, const char fileName[]) {
  FILE* fp;
  listnode_t* listptr;
  
  if ((fp = fopen(fileName, "a+")) == NULL) {
    printf("Failed to open file %s", fileName);
    exit(1);
  }
  
  fprintf(fp, "%c :", node->letter);
  
  listptr = node->list->head;
  while (listptr != NULL) {
    fprintf(fp, " %s", listptr->word);
    listptr = listptr->next;
  }
  
  fprintf(fp, "\n");
  
  if (fclose(fp) == EOF) {
    printf("Failed to close file %s", fileName);
    exit(1);
  }
}

// print one level of the tree
void printTreeLevel(node_t* root, int level, const char fileName[]) {
  if (root == NULL) return;
  
  if (level == 1) printNodeToFile(root, fileName);
  else if (level > 1) {
    printTreeLevel(root->left, level - 1, fileName);
    printTreeLevel(root->right, level - 1, fileName);
  }
}

// get depth of node
int getDepth(node_t* node) {
  if (node == NULL) return 0;
  
  int depthLeft = getDepth(node->left);
  int depthRight = getDepth(node->right);
  
  return (depthLeft > depthRight ? depthLeft + 1 : depthRight + 1);
}
