CXX = g++
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
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) -c $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS)
