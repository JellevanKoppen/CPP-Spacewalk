CC=g++
IDIR=include
SRCDIR=src

EXECUTABLE_NAME=spacewalk
#LIBS=-lncurses

all:
	$(CC) -I $(IDIR) $(SRCDIR)/* -o $(EXECUTABLE_NAME) $(LIBS) -g
	./$(EXECUTABLE_NAME)
clean:
	rm *.o $(EXECUTABLE_NAME)

src:
	$(CC) -I $(IDIR) $(SRCDIR)/* -o $(EXECUTABLE_NAME) $(LIBS)
