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
pixel _valor;
int _quantidade, _total; // Para fazer a média

// Função recursiva de conquista
void _conquista(int x, int y)
{
    // printf("%d %d -> analise\n", x, y);
    // (x, y) aponta para um pixel que não existe (ultrapassou dimenssao da imagem)
    if (x < 0 || x >= _altura || y < 0 || y >= _largura)
    {
        return;
    }

    // printf("%d %d -> existe\n", x, y);
    // Pixel já foi conquistado
    if (_imagem_filtro[x][y] != 0)
    {
        return;
    }

    printf("%d %d -> conquistavel\n", x, y);
    // Não satifaz condição
    if (abs(_imagem[x][y] - _total / _quantidade) > _criterio)
    {
        return;
    }
    _imagem_filtro[x][y] = _valor;
    _total += _imagem[x][y];
    _quantidade++;
    // printf("%d %d -> OK\n", x, y);

    // Cima
    _conquista(x - 1, y);

    // Direita
    _conquista(x, y + 1);

    // Baixo
    _conquista(x + 1, y);

    // Esquerda
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
    _valor = (pixel)valor;

    printf(" -- valores antes --\n");
    // printf("imagem_filtro:  %p\n", _imagem_filtro);
    // printf("imagem:         %p\n", _imagem);
    printf("altura:         %d\n", _altura);
    printf("largura:        %d\n", _largura);
    printf("criterio:       %d\n", _criterio);
    printf("valor:          %d\n", _valor);
    printf("quantidade:     %d\n", _quantidade);
    printf("total:          %d\n", _total);

    /*
     * Impede divisão por zero durante o calculo da média
     * Pois se simplesmente jogar esse pixel em _conquista()
     * _quantidade seria igual a 0
     */
    printf("%p [%d][%d]\n", _imagem_filtro, x, y);
    if (_imagem_filtro[x][y] == 0)
    {
        _imagem_filtro[x][y] = _valor;
        _total += _imagem[x][y];
        _quantidade = 1;

        printf("quantidade:     %d\n", _quantidade);
        printf("total:          %d\n", _total);

        // Cima
        _conquista(x - 1, y);

        // Direita
        _conquista(x, y + 1);

        // Baixo
        _conquista(x + 1, y);

        // Esquerda
        _conquista(x, y - 1);
    }

    printf(" -- valores depois --\n");
    // printf("imagem_filtro:  %p\n", _imagem_filtro);
    // printf("imagem:         %p\n", _imagem);
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

pixel **filtro_bordas(pixel **imagem, int altura, int largura)
{
    int i, j;

    pixel **res;
    res = imagem_caloca(altura, largura);
    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            if (i - 1 >= 0 && imagem[i - 1][j])
            {
                res[i][j] = 1;
            }
            else if (j + 1 < largura && imagem[i][j + 1])
            {
                res[i][j] = 1;
            }
            else if (i + 1 < altura && imagem[i + 1][j])
            {
                res[i][j] = 1;
            }
            else if (j - 1 >= 0 && imagem[i][j - 1])
            {
                res[i][j] = 1;
            }
        }
    }
    imagem_destroi(imagem, altura);
    return res;
}