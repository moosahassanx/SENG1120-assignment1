CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES= Student.cpp Linkedlist.cpp LinkedListDemo.cpp Node.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=assignment1

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core
