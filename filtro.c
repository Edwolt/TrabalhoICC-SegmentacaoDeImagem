#include "filtro.h"

/*
 * Usei variáveeis gloabais para economizar memória durante a recursão _conquista()
 * Pois assim esses valores não tem que ser passado como parâmetro
 * Para ficar padronizado, adote sempre deixar esses valores zerado após o usá-los em uma função
 */
int _quantidade, _total; // Para fazer a média
int _criterio;
pixel **_imagem;
int _altura, _largura;
int _valor;

float _media(void) { return _total / ((float)_quantidade); }

// Função recursiva de conquista
void _conquista(int x, int y)
{
    // Pixel já foi visitado
    if(_imagem[x][y]!=0){
        return;
    }

    // Atingiu a borda da imagem
    if (x < 0 || x >= _altura || y < 0 || y >= _largura)
    {
        return;
    }

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

    return;
}

void filtro_conquista(
    pixel **imagem_filtro,
    pixel **imagem,
    int altura, int largura,
    int x, int y, int criterio,
    const int valor)
{
    _imagem = imagem;
    _altura = altura;
    _largura = largura;
    _criterio = criterio;

    // TODO Processa pixel (x, y)
    // Pois ele não será processado durante a recursão

    _conquista(x, y);
    _imagem = NULL;
    _quantidade = _total = _altura = _largura = _criterio = 0;

    return;
}

pixel **filtro_aplica(pixel **imagem, int altura, int largura)
{
    pixel **res;
    res = imagem_caloca(altura, largura);
    imagem_destroi(imagem, altura);
    return res;
}