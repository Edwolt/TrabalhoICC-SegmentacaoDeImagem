CC      := gcc
EXEC    := trabalho
DEBUG   := debug
SRC     := $(wildcard *.c)
OBJ     := $(SRC:.c=.o)
CFLAGS  := -Wall -lm
RMFLAGS := -f -v
IN      := 1..11

all: $(EXEC)

run: $(EXEC)
	./$(EXEC)

compile: clean $(EXEC)

clean:
	rm $(OBJ) $(RMFLAGS)
	rm debug.out $(RMFLAGS)
	rm $(EXEC) $(RMFLAGS)

Teste:
	echo "for i in {$(IN)}; do ./$(EXEC) < TesteIn/\$$i.in > TesteOut/\$$i.out || break; done" | bash

$(DEBUG): $(OBJ)
	$(CC) -g -o $(DEBUG) $(SRC)

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)