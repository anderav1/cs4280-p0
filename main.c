// Lexi Anderson
// Feb 12, 2022
// CS 4280, Project 0
// main.c

#include "node.h"
#include "traversals.h"
#include "buildTree.h"

char* inputfile = NULL; 


int main(int argc, char* argv[]) {
	// TODO: process command line args
	if (argc == 0 || argc >= 3) {
		// TODO: print error message
	} else if (argc == 2) {
    inputfile = argv[1];
  }

	// TODO: make sure file is readable


	// TODO: set up keyboard processing


	node_t* root = buildTree(file);

	levelOrder(root);
	preOrder(root);
	postOrder(root);

	return 0;
}

