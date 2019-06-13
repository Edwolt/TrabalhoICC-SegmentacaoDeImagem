all: main

run: main
	./main

main: filtro.o imagem.o
	gcc -o main main.c *.o

filtro.o:
	gcc -c filtro.c

imagem.o:
	gcc -c imagem.c

clean:
	rm *.o -f -v

