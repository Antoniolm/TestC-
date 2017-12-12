#Compiler
CC = g++

#Compiler flags
CFLAGS  = -g -Wall

#Target
TARGET = valgrindTest
DEPENDENCIES = object.cpp

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp $(DEPENDENCIES)

clean:
	$(RM) $(TARGET)
