all: main

run: main
	./main

main: imagem.o filtro.o  main.o
	gcc -o main *.o -Wall

main.o:
	gcc -o main.c -Wall

filtro.o:
	gcc -c filtro.c -Wall

imagem.o:
	gcc -c imagem.c -Wall

clean:
	rm *.o -f -v

