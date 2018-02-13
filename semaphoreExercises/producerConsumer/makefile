#Compiler
CC = g++

#Compiler flags
CFLAGS  = -g -Wall

#Target
TARGET = main

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp -pthread -std=c++0x

clean:
	$(RM) $(TARGET)
