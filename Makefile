
IDIR =./include
SRCDIR=./src
CC=c++ -g -Wall -Werror 
INCLIBS=-lpthread
CFLAGS=-I$(IDIR)

ODIR=./src


_DEPS = graph.h trie.h qstack.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = server.o graph.o trie.o main.o qstack.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

%.o: %.cpp $(DEPS)
	rm -f $@
	$(CC) -c -o $@ $< $(CFLAGS) $(INCLIBS)

facebook: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(INCLIBS)
