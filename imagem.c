#include "imagem.h"

pixel **imagem_abrir(const char *caminho, int *altura, int *largura)
{

    int i, j;

    FILE *arquivo = fopen(caminho, "r");
    if (arquivo == NULL)
    {
        fprintf(stderr, "Deu ruim, essa imgem nem existe");
    }

    // Ignora string ("P2")
    // Le altura e largura
    // Ignora inteiro com valor maximo da matriz de pixel (indica valor que representa o branco)
    fscanf(arquivo, "%*s %d %d %*d", altura, largura);

    pixel **imagem = imagem_aloca(*altura, *largura);

    for (i = 0; i < *altura; i++)
    {
        for (j = 0; j < *largura; j++)
        {
            fscanf(arquivo, "%hhu", &imagem[i][j]);
        }
    }

    return imagem;
}

pixel **imagem_aloca(int altura, int largura)
{
    pixel **imagem = malloc(1);
}

void imagem_salva(const char *caminho) {}

void imagem_destroi(pixel **imagem, int altura)
{
    int i;
    for (i = 0; i < altura; i++)
    {
        free(imagem[i]);
    }
    free(imagem);
}