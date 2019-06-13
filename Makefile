OBJ   := imagem.o filtro.o main.o
SRC   := imagem.c filtro.c main.c
FLAGS := -Wall

all: main

run: main
	./main

compile: clean main

debug.out: ${OBJ}
	gcc -g -o debug.out ${SRC}

main: ${OBJ}
	gcc -o main ${OBJ} -Wall

main.o:
	gcc -c main.c -Wall

filtro.o:
	gcc -c filtro.c -Wall

imagem.o:
	gcc -c imagem.c -Wall

clean:
 	rm ${OBJ} -f -v
	rm debug.out -f -v
	rm main -f -v