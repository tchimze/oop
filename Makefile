 CC = gcc
 SRC = cmemory.c encrypt.c
TARGET = cmemory encrypt
 CFLAG = -g -Wall -Wextra

all: $(TARGET)

$(TARGET): %: %.c
	$(CC) $(CFLAG) $< -o $@
clean: 
	rm -f $(TARGET)
