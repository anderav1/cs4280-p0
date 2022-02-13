// Lexi Anderson
// Feb 13, 2022
// CS 4280, Project 0
// main.c

#include "node.h"
#include "traversals.h"
#include "buildTree.h"

char* filename = NULL;

void printArgV(int, char*[]);


int main(int argc, char* argv[]) {
	if (argc == 0 || argc >= 3) {
    printf("Fatal: Improper usage\nUsage:");
    printArgV(argc, argv);
    return(1);
	} else if (argc == 2) {
    filename = argv[1];
  }

  FILE* fp;
  if (filename != NULL) {
    if ((fp = fopen(filename, "r")) == NULL) {
      printf("Fatal: File \"%s\" is not readable\n", argv[1]);
      return(1);
    }
  } else fp = stdin;

	node_t* root = buildTree(fp);
 
  if (fp != stdin) fclose(fp);

//	levelOrder(root);
//	preOrder(root);
//	postOrder(root);

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

