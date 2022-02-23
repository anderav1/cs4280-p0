# Project 0

CS 4280: Program Translation Project  
Lexi Anderson


## Overview
This program will read character strings from a file pointer and place them in a binary search tree organized with respect to the last character of the string. Each node in the tree will contain the last character of the string and a list of read strings that end in that character. The tree is never balanced or restructured other than growing new nodes.  
Once the end of the input is reached and each string has been added to the binary search tree, the program will perform level-order, pre-order, and post-order traversals on the tree. The results of each traversal will be printed out to corresponding output files such that the nodes are listed in order of traversal and the indentation of each line indicates the level of the tree in which the node resides.  

## Input Data Criteria
* The size of the input file is unknown to the program.
* Each input string should be composed only of lowercase letters. The input data may include any characters, so the program must check that each string is valid. If an invalid string is encountered, the program will terminate with an error.
* Assume that each string is separated with any number of standard whitespace separators (space, tab, newline).

## Invocation
Invoke the program via the command:
```
P0 [outputfile] [< inputfile]
```

Arguments:  
`outputfile` (optional) -- The base file name for the output files. Default will be 'out'.  
`inputfile` (optional) -- The name of the file to read input from. Default will be `stdin`.  

