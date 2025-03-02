#include "filtro.h"

/*
 * Variáveis gloabais para economizar memória durante a recursão _conquista()
 * Pois assim os valores não tem que ser passado como parâmetro
 * Para evitar problemas, sempre deixe esses valores em zero após o usá-los em uma função
 */
static pixel **_imagem_filtro;
static pixel **_imagem;
static int _altura, _largura;
static int _criterio;
static pixel _valor;
static int _quantidade, _total; // Para a média

bool _na_media(int x, int y)
{
    float criterio = (float)_criterio;

    float diferenca = _total;                             // Calculo da média
    diferenca /= _quantidade;                             //
    diferenca = _imagem[x][y] - diferenca;                // Subtração
    diferenca = (diferenca > 0) ? diferenca : -diferenca; // Módulo da media

    return (diferenca <= criterio);
}

// Função recursiva de conquista
void _conquista(int x, int y)
{
    // Se (x, y) aponta para um pixel que não existe (ultrapassou dimenssao da imagem)
    if (x < 0 || x >= _altura || y < 0 || y >= _largura)
    {
        return;
    }

    // Se pixel já foi conquistado
    if (_imagem_filtro[x][y] != 0)
    {
        return;
    }

    // Se não satifaz condição
    if (!_na_media(x, y))
    {
        return;
    }

    _imagem_filtro[x][y] = _valor;
    _total += _imagem[x][y];
    _quantidade++;

    _conquista(x - 1, y); // Cima
    _conquista(x, y + 1); // Direita
    _conquista(x + 1, y); // Baixo
    _conquista(x, y - 1); // Esquerda

    return;
}

void filtro_conquista(pixel **imagem_filtro, pixel **imagem,
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

    /*
     * Primeira iteração do algoritmo de conquista
     * Impede divisão por zero durante o calculo da média
     * Pois se simplesmente jogar esse pixel em _conquista()
     * _quantidade seria igual a 0
     */
    if (_imagem_filtro[x][y] == 0)
    {
        _imagem_filtro[x][y] = _valor;
        _total += _imagem[x][y];
        _quantidade = 1;

        _conquista(x - 1, y); // Cima
        _conquista(x, y + 1); // Direita
        _conquista(x + 1, y); // Baixo
        _conquista(x, y - 1); // Esquerda
    }

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
    int i, j; // iteradores
    pixel **res;

    res = imagem_caloca(altura, largura);
    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            if ((i - 1 >= 0 && imagem[i][j] != imagem[i - 1][j]) ||
                (j + 1 < largura && imagem[i][j] != imagem[i][j + 1]) ||
                (i + 1 < altura && imagem[i][j] != imagem[i + 1][j]) ||
                (j - 1 >= 0 && imagem[i][j] != imagem[i][j - 1]))
            {
                res[i][j] = 1;
            }
        }
    }
    imagem_destroi(imagem, altura);
    return res;
}