OBJS = BSTree.o AVLTree.o RBTree.o main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

prog : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS)

BSTree.o : BSTree.h BSTree.cpp
	$(CC) $(CFLAGS) BSTree.cpp

AVLTree.o : BSTree.h AVLTree.h AVLTree.cpp
	$(CC) $(CFLAGS) AVLTree.cpp

RBTree.o : BSTree.h RBTree.h RBTree.cpp
	$(CC) $(CFLAGS) RBTree.cpp

main.o : main.cpp BSTree.h AVLTree.h RBTree.h
	$(CC) $(CFLAGS) main.cpp

clean:
	\rm *.o *~ *.out *.gch
