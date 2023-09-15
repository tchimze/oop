CC = gcc
TARGET = mul
SRC = mul.c
CFLAG = -Wall -pedantic

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAG) $(SRC) -o $(TARGET)

clean :
	rm -f $(TARGET)
