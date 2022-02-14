// Lexi Anderson
// Feb 13, 2022
// CS 4280, Project 0
// main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "node.h"
#include "traversals.h"
#include "buildTree.h"

char fileName[bufferSize];

void printArgV(int, char*[]);
void resetOutputFiles(char*);
void clearFileContents(const char*);


int main(int argc, char* argv[]) {
  FILE* fp;
  node_t* root;

	if (argc == 0 || argc >= 3) {
    printf("Fatal: Improper usage\nUsage:");
    printArgV(argc, argv);
    exit(1);
	} else if (argc == 2) {
    strcpy(fileName, argv[1]);
  }

  if (strlen(fileName) != 0) {
    fp = fopen(fileName, "r");
    if (fp == NULL) {
      errExit("File \'%s\' is not readable", fileName);
    }
  } else {
    printf("main: Filename not provided, enter input (press CTRL+D when done): ");
    fp = stdin;
    printf("\n");
    strcpy(fileName, "out");
  }
  
  resetOutputFiles(fileName);

	root = buildTree(fp);
  puts("main: Tree built successfully");
 
  if (fp != stdin) fclose(fp);

  puts("main: Starting tree traversals");
	traverseLevelOrder(root, fileName);
	traversePreOrder(root, fileName);
	traversePostOrder(root, fileName);
  puts("main: All traversals completed");

	return 0;
}

// Print the entered command followed by line break
// argc -- argument count
// argv -- argument array
void printArgV(int argc, char* argv[]) {
  int i;
  for (i = 0; i < argc; i++) {
    printf(" %s", argv[i]);
  }
  printf("\n");
}

// Clean up any previously generated output files
// baseFileName -- first part of the name of the output files
void resetOutputFiles(char baseFileName[]) {
  char preFile[bufferSize], postFile[bufferSize], levelFile[bufferSize];
  
  snprintf(preFile, bufferSize, "%s.preorder", baseFileName);
  snprintf(postFile, bufferSize, "%s.postorder", baseFileName);
  snprintf(levelFile, bufferSize, "%s.levelorder", baseFileName);
  
  clearFileContents(preFile);
  clearFileContents(postFile);
  clearFileContents(levelFile);
}

// Erase file contents
// fileName -- name of file to clear
void clearFileContents(const char* fileName) {
  FILE* fp;
  
  if ((fp = fopen(fileName, "w")) == NULL) {
    errExit("main: Could not write to file %s\n", fileName);
  }
  
  if (fclose(fp) == EOF) {
    errExit("main: Could not close file %s\n", fileName);
  }
}

