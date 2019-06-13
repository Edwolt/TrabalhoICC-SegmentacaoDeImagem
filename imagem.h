#ifndef IMAGEM_H
#define IMAGEM_H

#include <stdlib.h> // Alocacao dinamica
#include <stdio.h>  // Manipulacao de arquivos

typedef unsigned char pixel; // Vai de 0 a 255

/*
 * Aloca dinamicamente imagem na heap e salva os valores nela
 * Os valores altura e largura da imagem sao passados por referencia pela funcao
 */
pixel **imagem_abrir(const char *caminho, int *altura, int *largura);

//Aloca imagem dinamicamente
pixel **imagem_aloca(int altura, int largura);

void imagem_salva(const char *caminho);

// Desaloca imagem da heap
void imagem_destroi(pixel **imagem, int altura);

#endif