#include "filtro.h"

/*
 * Usei variáveeis gloabais para economizar memória durante a recursão _conquista()
 * Pois assim esses valores não tem que ser passado como parâmetro
 * Para evitar problemas, sempre deixe esses valores em zero após o usá-los em uma função
 */
pixel **_imagem_filtro;
pixel **_imagem;
int _altura, _largura;
int _criterio;
int _valor;
int _quantidade, _total; // Para fazer a média

bool _na_media(int x, int y)
{
    return _imagem_filtro[x][y] == 0 && abs(_imagem[x][y] - _media()) < _criterio;
}

pixel _media(void)
{
    return _total / _quantidade;
}

// Função recursiva de conquista
void _conquista(int x, int y)
{
    // Atingiu a borda da imagem
    if (x < 0 || x >= _altura || y < 0 || y >= _largura)
    {
        return;
    }

    // Pixel não foi conquistado, logo seus vizinhos não seram conquistado por ele
    if (_imagem_filtro[x][y] != _valor)
    {
        return;
    }

    // Processa pixel a cima
    if (x - 1 >= 0 && _imagem_filtro[x - 1][y] == 0 &&
        abs(_imagem[x - 1][y] - _media()) < _criterio)
    {
        _imagem_filtro[x - 1][y] = _valor;
        _quantidade++;
        _total += _imagem[x - 1][y];
    }

    // Processa pixel a direita
    if (y + 1 < _largura && _imagem_filtro[x][y + 1] == 0 && abs(_imagem[x][y + 1] - _media()) < _criterio)
    {
        _imagem[x][y + 1] = _valor;
        _quantidade++;
        _total += _imagem[x][y + 1];
    }

    // Processa pixel abaixo
    if (x + 1 < _altura && _imagem_filtro[x + 1][y] == 0 && abs(_imagem[x + 1][y] - _media()) < _criterio)
    {
        _imagem[x + 1][y] = _valor;
        _quantidade++;
        _total += _imagem[x + 1][y];
    }

    // Processa pixel a esquerda
    if (y - 1 >= 0 && _imagem_filtro[x][y - 1] == 0 && abs(_imagem[x][y - 1] - _media()) < _criterio)
    {
        _imagem[x][y - 1] = _valor;
        _quantidade++;
        _total += _imagem[x][y - 1];
    }

    // Recursão pixel a cima
    _conquista(x - 1, y);

    // Recursão pixel a direita
    _conquista(x, y + 1);

    // Recursão pixel abaixo
    _conquista(x + 1, y);

    // Recursão pixel a esquerda
    _conquista(x, y - 1);

    return;
}

void filtro_conquista(
    pixel **imagem_filtro,
    pixel **imagem,
    int altura, int largura,
    int x, int y, int criterio,
    int valor)
{

    // Atribuindo valores as variáveis globais
    _imagem_filtro = imagem_filtro;
    _imagem = imagem;
    _altura = altura;
    _largura = largura;
    _criterio = criterio;
    _valor = valor;

    // Processa pixel (x, y), pois ele não será processado durante a recursão
    if (_imagem[x][y] == 0)
    {
        _total = _imagem[x][y];
        _quantidade = 1;
        _imagem[x][y] = _valor;
    }

    _conquista(x, y);

    // Atribuindo zero às variáveis globais para evitar problemas
    _imagem = NULL;
    _altura = 0;
    _largura = 0;
    _criterio = 0;
    _valor = 0;
    _total = 0;
    _quantidade = 0;

    return;
}

pixel **filtro_aplica(pixel **imagem, int altura, int largura)
{
    pixel **res;
    res = imagem_caloca(altura, largura);
    imagem_destroi(imagem, altura);
    return res;
}