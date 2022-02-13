// Lexi Anderson
// Feb 13, 2022
// CS 4280, Project 0
// buildTree.c

#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "buildTree.h"
#include "config.h"
#include "list.h"
#include "node.h"

// build a new tree based on contents of file
node_t* buildTree(FILE* file) {
  node_t* root = NULL;
  char word[bufferSize];
  
  while (fscanf(file, "%s", word) == 1) {  
    if (!isValidWord(word)) {
      printf("Fatal: invalid word \"%s\" encountered\n", word);
      exit(1);
    }
    root = insertInTree(root, word);
  }
  
  return root;
}

// check that word is comprised only of lowercase letters
bool isValidWord(const char word[]) {
  int i;
  for (i = 0; i < (int)strlen(word); i++) {
    if (word[i] < 'a' || word[i] > 'z') return false;
  }
  return true;
}

// add word to corresponding tree node
node_t* insertInTree(node_t* root, const char word[]) {
  char letter = getLastLetter(word);
  
  if (root == NULL) {
    node_t* newnode = createTreeNode(letter);
    addToList(newnode->list, word);
    return newnode;
  }
  
  if (letter < root->letter) {
    root->left = insertInTree(root->left, word);
  } else if (letter > root->letter) {
    root->right = insertInTree(root->right, word);
  } else {
    addToList(root->list, word);
  }
  
  return root;
}

// get the last letter in the word
char getLastLetter(const char word[]) {
    return word[strlen(word) - 1];
}

// create new tree node
node_t* createTreeNode(char letter) {
  node_t* newnode;
  list_t* newlist;
  
  newnode = (node_t*)malloc(sizeof(node_t));
  
  newnode->letter = letter;
  newnode->left = NULL;
  newnode->right = NULL;
  newnode->list = createList();
  
  return newnode;
}
