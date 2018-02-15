#Compiler
CC = g++

#Compiler flags
CFLAGS  = -g -Wall

#Target
TARGET = main

all: $(TARGET)

$(TARGET): $(TARGET).cpp threadPackage/*
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp threadPackage/* -lpthread  -std=c++0x

clean:
	$(RM) $(TARGET)
