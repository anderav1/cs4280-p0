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

// Build a new tree based on contents of file
// file -- pointer to input file or stdin
// Returns the root node of the generated tree
node_t* buildTree(FILE* file) {
  node_t* root = NULL;
  char word[bufferSize];
  
  if (fscanf(file, "%s", word) < 1) {
    errExit("Input empty");
  }
  
  do {
    if (!isValidWord(word)) {
      errExit("Fatal: invalid word \"%s\" encountered\n", word);
    }
    
    root = insertInTree(root, word);
  } while (fscanf(file, "%s", word) == 1);
  
  return root;
}

// Check that word is comprised only of lowercase letters
// word -- string to be validated
// Returns true if the string contains all legal characters
bool isValidWord(const char word[]) {
  int i;
  for (i = 0; i < (int)strlen(word); i++) {
    if (word[i] < 'a' || word[i] > 'z') return false;
  }
  return true;
}

// Add word to corresponding tree node
// root -- root node of tree
// word -- word to be added
// Returns the root node of the tree
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

// Get the last letter in the word
// word -- word from which to extract last letter
// Returns the last letter in the word
char getLastLetter(const char word[]) {
    return word[strlen(word) - 1];
}

// Create new tree node
// letter -- letter to create new tree node with
// Returns the newly created node
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
