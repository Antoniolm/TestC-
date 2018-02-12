#Compiler
CC = g++

#Compiler flags
CFLAGS  = -g -Wall

#Target
TARGET = main
DEPENDENCIES = semaphore.cpp

all: $(TARGET)

$(TARGET): $(TARGET).cpp semaphore.cpp semaphore.h
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp $(DEPENDENCIES) -std=c++0x

clean:
	$(RM) $(TARGET)
