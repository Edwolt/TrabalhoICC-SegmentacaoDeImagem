all: main

run: main
	./main

debug.out: imagem.o filtro.o  main.o 
	gcc -g -o debug.out main.c filtro.c imagem.c

main: imagem.o filtro.o  main.o
	gcc -o main *.o -Wall

main.o:
	gcc -c main.c -Wall

filtro.o:
	gcc -c filtro.c -Wall

imagem.o:
	gcc -c imagem.c -Wall

clean:
	rm *.o -f -v