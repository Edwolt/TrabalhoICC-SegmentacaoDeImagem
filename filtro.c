#include "filtro.h"

// Usei variáveeis locais para economizar espaço durante a recursão
// Adote sempre deixar zerado após o uso em uma função
int media = 0;
int criterio = 0;

// Função recursiva de conquista
void _conquista()
{
}

void filtro_conquista(pixel **imagem, int x, int y, int crit, const int valor)
{
    criterio = crit;
    _conquista();
    criterio = media = 0;
}