// Lexi Anderson
// Feb 13, 2022
// CS 4280, Project 0
// config.c

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "config.h"

// Abort execution and print error message
// format -- formatted string to be used in error message
// ... -- optional argument list
void errExit(char* format, ...) {
  char errMsg[bufferSize];
  char printMsg[bufferSize];
  
  va_list args;
  va_start(args, format);
  vsnprintf(errMsg, bufferSize, format, args);
  va_end(args);
  
  sprintf(printMsg, "Fatal: %s", errMsg);
  perror(printMsg);
  
  exit(1);
}