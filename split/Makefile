CC = clang
CFLAGS = -std=gnu11 -g -Wall -Wextra -pedantic
DEPS = split.h
OBJ = split.o test.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

split: $(OBJ)
	clang -o $@ $^ $(CFLAGS)
