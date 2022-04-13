CC=gcc
CFLAGS=-g -Wall -Iinclude -DDEBON
LIBS=-lm
SRC=src/*.c
OUTFILE=bin/qfs.out

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUTFILE) $(LIBS)