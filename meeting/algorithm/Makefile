.PHONY:	clean all
CC := g++
CFLAGS := -Wall -g -p
SOURCE := $(shell find . -type f -name "*.cpp")
BIN = $(SOURCE:.cpp=)
all : $(BIN)
%.o : %.cpp
	$(CC) $(CFLAGS) -o $< $@

clean:
	rm -f *.o $(BIN)
