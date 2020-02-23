CC = gcc
CFLAGS = -Wall -std=c99

all: sed253

sed253: sed253.c copy.h copy.c delete.h delete.c substitute.h substitute.c
	$(CC) $(CFLAGS) $^ -o sed253

clean:
	rm sed253
