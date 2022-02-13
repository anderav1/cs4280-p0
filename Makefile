# Lexi Anderson
# Feb 12, 2022
# CS 4280, Project 0
# Makefile


CC = g++
CFLAGS = -g -Wall -std=c++11
OBJS = main.o buildTree.o traversals.o list.o
DEPS = buildTree.h traversals.h list.h node.h
TARGET = P0

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS): %.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $<


# clean up generated files
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)
# TODO: remove any other files as necessary
