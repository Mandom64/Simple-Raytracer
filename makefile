CC := gcc
FLAGS := -g -Wall -Wextra -O3 -std=gnu99 -lm
TARGET := raytracer

$(TARGET): main.c
	$(CC) $(FLAGS) -o $(TARGET) $<

clean: 
	rm $(TARGET)
