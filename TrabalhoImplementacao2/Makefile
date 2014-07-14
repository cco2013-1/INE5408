OBJS = BSTree.o AVLTree.o WordOccurrences.o ListOfOccurrences.o InvertedList.o main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
STLFLAGS = -std=c++0x

prog : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS)

BSTree.o : BSTree.h BSTree.cpp
	$(CC) $(CFLAGS) BSTree.cpp

AVLTree.o : BSTree.h AVLTree.h AVLTree.cpp
	$(CC) $(CFLAGS) AVLTree.cpp

WordOccurrences.o : WordOccurrences.h WordOccurrences.cpp
	$(CC) $(CFLAGS) WordOccurrences.cpp

ListOfOccurrences.o : WordOccurrences.h ListOfOccurrences.h ListOfOccurrences.cpp
	$(CC) $(CFLAGS) ListOfOccurrences.cpp

InvertedList.o : WordOccurrences.h InvertedList.h InvertedList.cpp
	$(CC) $(CFLAGS) $(STLFLAGS) InvertedList.cpp

main.o : main.cpp BSTree.h AVLTree.h WordOccurrences.h ListOfOccurrences.h InvertedList.h
	$(CC) $(CFLAGS) main.cpp

clean:
	\rm *.o *~ *.out *.gch
