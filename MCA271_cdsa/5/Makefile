CC = gcc

# CFLAGS = -Wall -Wextra -pedantic -std=c99

SOURCES = main.c searching.c 	

HEADERS = searching.h 

TARGET = main


searching:
	$(CC) $(SOURCES) -o $(TARGET)

run:
	./main

clean:
	$(RM) $(TARGET)

.PHONY:all clean

