CC = g++
CFLAGS = -Wall -g
SOURCE = $(shell find . -type f -name "*.cpp")
BIN = $(SOURCE:%.cpp=%)
all : $(BIN)
print:
	@echo $(SOURCE)

% : %.o
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o $(all)
