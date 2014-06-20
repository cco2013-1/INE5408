OBJS = BSTree.o AVLTree.o RBTreeV2.o main.o
CC = g++
DEBUG = -g -O0
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

prog : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS)

BSTree.o : BSTree.h BSTree.cpp
	$(CC) $(CFLAGS) BSTree.cpp

AVLTree.o : BSTree.h AVLTree.h AVLTree.cpp
	$(CC) $(CFLAGS) AVLTree.cpp

RBTreeV2.o : BSTree.h RBTreeV2.h RBTreeV2.cpp
	$(CC) $(CFLAGS) RBTreeV2.cpp

main.o : main.cpp BSTree.h AVLTree.h RBTree.h
	$(CC) $(CFLAGS) main.cpp

clean:
	\rm *.o *~ *.out *.gch
