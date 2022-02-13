# Lexi Anderson
# Feb 13, 2022
# CS 4280, Project 0
# Makefile


CC = g++
CFLAGS = -g -Wall -std=c++11
OBJS = main.o buildTree.o traversals.o list.o config.o
DEPS = buildTree.h traversals.h list.h node.h config.h
TARGET = P0

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS): %.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $<


# clean up generated files
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS) *.preorder *.postorder *.levelorder
# TODO: remove any other files as necessary
