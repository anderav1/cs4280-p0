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

int maxDepth = 0;

// Breadth-first traversal
// root -- root node of the binary search tree
// fileName -- name of the output file
void traverseLevelOrder(node_t* root, const char fileName[]) {
  int d, i;
  char outputFile[bufferSize];
  
  snprintf(outputFile, bufferSize, "%s.levelorder", fileName);
  
  d = getDepth(root);
  for (i = 1; i <= d; i++) printTreeLevel(root, i, outputFile);
}

// Pre-order traversal
// Visit node, then left and right children
// root -- current node in the BST
// fileName -- output file name
void traversePreOrder(node_t* root, const char fileName[]) {
  if (root == NULL) return;
  
  char outputFile[bufferSize];
  snprintf(outputFile, bufferSize, "%s.preorder", fileName);

  printNodeToFile(root, outputFile);
  
  traversePreOrder(root->left, fileName);
  traversePreOrder(root->right, fileName);
}

// Post-order traversal
// Visit left and right children, then node
// root -- current node in the BST
// fileName -- output file name
void traversePostOrder(node_t* root, const char fileName[]) {
  if (root == NULL) return;

  traversePostOrder(root->left, fileName);
  traversePostOrder(root->right, fileName);
  
  char outputFile[bufferSize];
  snprintf(outputFile, bufferSize, "%s.postorder", fileName);
  
  printNodeToFile(root, outputFile);
}

// Print current node to file
// node -- current node
// fileName -- output file name
void printNodeToFile(node_t* node, const char fileName[]) {
  FILE* fp;
  listnode_t* listptr;
  int depth;
  
  if ((fp = fopen(fileName, "a+")) == NULL) {
    printf("Failed to open file %s", fileName);
    exit(1);
  }
  
  depth = getDepth(node);
  if (depth > maxDepth) maxDepth = depth;
  
  fprintf(fp, "%d%*s %c :", maxDepth - depth, (maxDepth - depth) * 2, " ", node->letter);
  
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

// Print one level of the tree
// root -- current node
// level -- current node depth
// fileName -- output file name
void printTreeLevel(node_t* root, int level, const char fileName[]) {
  if (root == NULL) return;
  
  if (level == 1) printNodeToFile(root, fileName);
  else if (level > 1) {
    printTreeLevel(root->left, level - 1, fileName);
    printTreeLevel(root->right, level - 1, fileName);
  }
}

// Get depth of node
// node -- current tree node
int getDepth(node_t* node) {
  if (node == NULL) return 0;
  
  int depthL = getDepth(node->left);
  int depthR = getDepth(node->right);
  
  return (depthL > depthR ? depthL + 1 : depthR + 1);
}
