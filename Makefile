CXX = g++
CXX_FLAGS = -g -Wall -ggdb

BIN = bin
SRC = src
INCLUDE = include
LIB = lib
EXECUTABLE = main

all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

test1: clean all
	clear
	./$(BIN)/$(EXECUTABLE) test/abc.txt test/abc.txt.lzw

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*