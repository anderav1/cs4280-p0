// Lexi Anderson
// Feb 12, 2022
// CS 4280, Project 0
// main.c

#include "node.h"
#include "traversals.h"
#include "buildTree.h"

char* filename = NULL; 


int main(int argc, char* argv[]) {
	if (argc == 0 || argc >= 3) {
		// TODO: print error message
    puts("Invalid argument count");
	} else if (argc == 2) {
    filename = argv[1];
  }

  FILE* fp;
  if ((fp = fopen(filename, "r")) == NULL) {
    // TODO: print error message
    puts("File not readable");
  }

	// TODO: set up keyboard processing


	node_t* root = buildTree(fp);

//	levelOrder(root);
//	preOrder(root);
//	postOrder(root);

	return 0;
}

