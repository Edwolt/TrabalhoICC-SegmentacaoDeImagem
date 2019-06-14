CC      := gcc
EXEC    := trabalho
DEBUG   := debug
SRC     := imagem.c filtro.c main.c
OBJ     := $(SRC:.c=.o)
CFLAGS  := -Wall
RMFLAGS := -f -v

all: $(EXEC)

run: $(EXEC)
	./$(EXEC)

compile: clean $(EXEC)

clean:
	rm $(OBJ) $(RMFLAGS)
	rm debug.out $(RMFLAGS)
	rm $(EXEC) $(RMFLAGS)

$(DEBUG): $(OBJ)
	$(CC) -g -o $(DEBUG) $(SRC)

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(FLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(FLAGS)