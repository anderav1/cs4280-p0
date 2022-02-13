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

  if (fileName != NULL) {
    fp = fopen(fileName, "r");
    if (fp == NULL) {
      errExit("File \'%s\' is not readable", fileName);
    }
  } else {
    puts("Filename not provided, using default");
    fp = stdin;
    strcpy(fileName, "out");
  }
  
  resetOutputFiles(fileName);

	root = buildTree(fp);
 
  if (fp != stdin) fclose(fp);

//	traverseLevelOrder(root, fileName);
	traversePreOrder(root, fileName);
	traversePostOrder(root, fileName);

	return 0;
}

// print the entered command followed by line break
void printArgV(int argc, char* argv[]) {
  int i;
  for (i = 0; i < argc; i++) {
    printf(" %s", argv[i]);
  }
  printf("\n");
}

// clean up any previously generated output files
void resetOutputFiles(char* baseFileName) {
  char *preFile, *postFile, *levelFile;
  
  sprintf(preFile, "%s.preorder", baseFileName);
  sprintf(postFile, "%s.postorder", baseFileName);
  sprintf(levelFile, "%s.levelorder", baseFileName);
  
  clearFileContents(preFile);
  clearFileContents(postFile);
  clearFileContents(levelFile);
}

// erase file contents
void clearFileContents(const char* fileName) {
  FILE* fp;
  
  if ((fp = fopen(fileName, "w")) == NULL) {
    errExit("Could not write to file %s\n", fileName);
  }
  
  if (fclose(fp) == EOF) {
    errExit("Could not close file %s\n", fileName);
  }
}

