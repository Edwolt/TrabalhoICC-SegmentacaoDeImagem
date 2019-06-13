#include <stdio.h>

#include "imagem.h"
#include "filtro.h"

int main()
{
    int i, j; // Iteradores

    int altura, largura;
    char *caminho;
    int x, y, criterio;
    int num_buscas;

    pixel **imagem, **imagem_filtro;

    scanf(" %ms", &caminho);
    imagem = imagem_abrir("teste1.pgm", &altura, &largura);

    imagem_filtro = imagem_caloca(altura, largura);

    scanf("%d", &num_buscas);

    for (i = 0; i < num_buscas; i++)
    {
        scanf("%d %d %d", &x, &y, &criterio);
        filtro_conquista(imagem_filtro, imagem, altura, largura, x, y, criterio, i + 1);
    }

    imagem_filtro = filtro_aplica(imagem_filtro, altura, largura);
    imagem_destroi(imagem, altura);
    imagem_destroi(imagem_filtro, altura);
}