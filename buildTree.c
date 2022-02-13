// Lexi Anderson
// Feb 12, 2022
// CS 4280, Project 0
// buildTree.c

#include <string.h>
#include "list.h"
#include "node.h"

// build a new tree based on contents of file
node_t* buildTree(FILE* file) {
  node_t* root = NULL;

  char* word = NULL;
  while (fscanf(file, "%s", &word) == 1) {
    if (!isValidWord(word)) {
      // return error message and abort
    }
    
    root = insertInTree(root, word);
  }
  
  return root;
}

// check that word is comprised only of lowercase letters
private bool isValidWord(char* word) {
  int i;
  for (i = 0; i < strlen(word); i++) {
    if (word[i] < 'a' || word[i] > 'z') return false;
  }
  return true;
}

// add word to corresponding tree node
private node_t* insertInTree(node_t* root, char* word) {
  char letter = getLastLetter(word);
  
  if (root == NULL) {
    node_t* newnode = createTreeNode(letter);
    addToList(newnode->list, word);
    return newnode;
  }
  
  if (letter < root->letter) {
    root->left = insertInTree(root->left, letter);
  } else if (letter > root->letter) {
    root->right = insertInTree(root->right, letter);
  } else {
    addToList(root->list, word);
  }
  
  return root;
}

// get the last letter in the word
private char getLastLetter(char[] word) {
    return word[strlen(word) - 1];
}

// create new tree node
private node_t* createTreeNode(char letter) {
  node_t* newnode = (node_t*)malloc(sizeof(node_t));
  
  newnode->letter = letter;
  newnode->left = NULL;
  newnode->right = NULL;
  newnode->list = NULL;
  
  return newnode;
}
