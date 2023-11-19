CC = gcc
CFLAGS = -Wall -g
SOURCE = $(shell find . -type f -name "*.cpp")
BIN = $(patsubst %.cpp, %, $(SOURCE))
all:$(BIN)

%.o : %.cpp
	$(CC) $(CFLAGS) $@ -o $<
clean:
	rm -f *.o $(BIN)
