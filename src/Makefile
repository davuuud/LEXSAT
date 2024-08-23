CC = g++
DEFS = 
INCLUDES = -I../lib
CFLAGS = -pedantic -Wall -Wextra $(DEFS) $(INCLUDES)
LDFLAGS = -L../lib -lcadical

OBJECTS = lexsat.o utils.o simple.o

.PHONY: all clean
.SUFFIXES:
.SUFFIXES: .c .o

all: lexsat

lexsat: $(OBJECTS)

%: %.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm lexsat $(OBJECTS)
