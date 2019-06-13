#include "filtro.h"

/*
 * Usei variáveeis gloabais para economizar memória durante a recursão de _conquista
 * Pois esses valores teria que ser passado como parâmetro para na função recursica _conquista
 * Para ficar padronizado, adote sempre deixar esses valores zerado após o usá-los em uma função
 */
int _quantidade = 0; // Para fazer a média
int _total = 0;      // Para fazer a média
int _criterio = 0;
pixel **_imagem = NULL;
int _altura = 0;
int _largura = 0;
int _valor = 0;

float media()
{
    return _total / ((float)_quantidade);
}

// Função recursiva de conquista
void _conquista(int x, int y)
{
    // TODO Volta na recursão pois atingiu a borda da imagem

    // TODO Processa pixel a cima

    // TODO Processa pixel a direita

    // TODO Processa pixel abaixo

    // TODO Processa pixel a esquerda

    // Recursão pixel a cima
    _conquista(x, y - 1);

    // Recursão pixel a direita
    _conquista(x + 1, y);

    // Recursão pixel abaixo
    _conquista(x, y + 1);

    // Recursão pixel a esquerda
    _conquista(x - 1, y);
}

void filtro_conquista(pixel **imagem, int altura, int largura, int x, int y, int criterio, const int valor)
{
    _imagem = imagem;
    _altura = altura;
    _largura = largura;
    _criterio = criterio;

    // TODO Processa pixel (x, y) pois ele não será testado durante a recursão

    _conquista(x, y);
    _imagem = NULL;
    _quantidade = _total = _altura = _largura = _criterio = 0;
}