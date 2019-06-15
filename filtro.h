#ifndef FILTRO_H
#define FILTRO_H

#include <stdbool.h>
#include <math.h>
#include "imagem.h"

/* 
 * Conquista uma região (colore a imegem com a cor valor)
 * Valor é o número que vai ser atribuido à região conquistada
 * Somente pixels de cor 0 podem ser conquistados
 */
void filtro_conquista(
    pixel **imagem_filtro,
    pixel **imagem,
    int altura, int largura,
    int x, int y, int criterio,
    int valor);

/*
 * Cria uma imagem apenas com as bordas usando a cor 1
 * Um pixel pertence a borda se algum vizinho tiver uma cor diferente da dele
 */
pixel **filtro_bordas(pixel **imagem, int altura, int largura);

#endif