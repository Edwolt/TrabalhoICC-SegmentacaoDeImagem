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
    return _imagem_filtro[x][y] == 0 && abs(_imagem[x][y] - _total / _quantidade) < _criterio;
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
    if (x - 1 >= 0 && _na_media(x - 1, y))
    {
        _imagem_filtro[x - 1][y] = _valor;
        _quantidade++;
        _total += _imagem[x - 1][y];
    }

    // Processa pixel a direita
    if (y + 1 < _largura && _na_media(x, y + 1))
    {
        _imagem_filtro[x][y + 1] = _valor;
        _quantidade++;
        _total += _imagem[x][y + 1];
    }

    // Processa pixel abaixo
    if (x + 1 < _altura && _na_media(x + 1, y))
    {
        _imagem_filtro[x + 1][y] = _valor;
        _quantidade++;
        _total += _imagem[x + 1][y];
    }

    // Processa pixel a esquerda
    if (y - 1 >= 0 && _na_media(x, y - 1))
    {
        _imagem_filtro[x][y - 1] = _valor;
        _quantidade++;
        _total += _imagem[x][y - 1];
    }

    // Recursão pixel a cima
    printf("call (%d %d)\n", x - 1, y);
    _conquista(x - 1, y);

    // Recursão pixel a direita
    printf("call (%d %d)\n", x, y + 1);
    _conquista(x, y + 1);

    // Recursão pixel abaixo
    printf("call (%d %d)\n", x + 1, y);
    _conquista(x + 1, y);

    // Recursão pixel a esquerda
    printf("call (%d %d)\n", x, y - 1);
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

    printf(" -- valores antes --\n");
    printf("imagem_filtro:  %p\n", _imagem_filtro);
    printf("imagem:         %p\n", _imagem);
    printf("altura:         %d\n", _altura);
    printf("largura:        %d\n", _largura);
    printf("criterio:       %d\n", _criterio);
    printf("valor:          %d\n", _valor);
    printf("quantidade:     %d\n", _quantidade);
    printf("total:          %d\n", _total);

    // Processa pixel (x, y), pois ele não será processado durante a recursão
    if (_imagem_filtro[x][y] == 0)
    {
        _total = _imagem[x][y];
        _quantidade = 1;
        _imagem_filtro[x][y] = _valor;
    }

    _conquista(x, y);

    printf(" -- valores depois --\n");
    printf("imagem_filtro:  %p\n", _imagem_filtro);
    printf("imagem:         %p\n", _imagem);
    printf("altura:         %d\n", _altura);
    printf("largura:        %d\n", _largura);
    printf("criterio:       %d\n", _criterio);
    printf("valor:          %d\n", _valor);
    printf("quantidade:     %d\n", _quantidade);
    printf("total:          %d\n", _total);

    // Atribuindo zero às variáveis globais para evitar problemas
    _imagem_filtro = NULL;
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