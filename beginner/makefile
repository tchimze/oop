CC = gcc
TARGET = oop libraryBook bankAccount
SRC = oop.c libraryBook.c bankAccount.c
CFLAG = -Wall -pedantic

.PHONY : all clean

all: $(TARGET)

$(TARGET): %: %.c
	$(CC) $< -o $@

clean: 
	rm -f $(TARGET)

