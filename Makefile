CC      := gcc
EXEC    := main
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
	rm main $(RMFLAGS)

debug.out: $(OBJ)
	$(CC) -g -o debug.out $(SRC)

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(FLAGS)

main.o:
	$(CC) -c main.c $(FLAGS)

filtro.o:
	$(CC) -c filtro.c $(FLAGS)

imagem.o:
	$(CC) -c imagem.c $(FLAGS)
