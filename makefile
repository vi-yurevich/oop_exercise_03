CC=g++
CFLAGS=-std=c++14 -pedantic
OUTPUT=oop_exercise_03

all:
	$(CC) $(CFLAGS) Figure.h Figure.cpp main.cpp -o $(OUTPUT)
run:
	./$(OUTPUT)