CC = g++
CFLAGS = -g -Wall

BIN = ./bin
SRC = ./src

TARGET = crdir

all: crdir

crdir: directory
	$(CC) $(CFLAGS) $(SRC)/crdir.cpp $(BIN)/*.o -o $(BIN)/$(TARGET)

directory:
	$(CC) -c $(SRC)/directory.cpp -o $(BIN)/directory.o

clean:
	$(RM) $(BIN)/*.o $(BIN)/$(TARGET)
