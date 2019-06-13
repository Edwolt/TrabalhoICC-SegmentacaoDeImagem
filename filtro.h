#ifndef FILTRO_H
#define FILTRO_H

#include "imagem.h"

/* 
 * Conquista uma região (colore a imegem com a cor valor)
 * valor é o número que vai ser atribuido a região
 */
void filtro_conquista(pixel **imagem, int altura, int largura, int x, int y, int criterio, const int valor)

pixel **filtro_aplica(pixel **imagem);

#endif