CC = gcc

# CFLAGS = -Wall -Wextra -pedantic -std=c99

SOURCES = main.c cinema.c dlinkedlist.c 	

HEADERS = cinema.h dlinkedlist.h 

TARGET = main


cinema:
	$(CC) $(SOURCES) -o $(TARGET)

run:
	./main

clean:
	$(RM) $(TARGET)

.PHONY:all clean

