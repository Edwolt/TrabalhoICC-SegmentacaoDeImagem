#ifndef FILTRO_H
#define FILTRO_H

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
    const int valor);

pixel **filtro_aplica(pixel **imagem, int altura, int largura);

#endif