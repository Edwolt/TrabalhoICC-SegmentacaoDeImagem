#include <stdio.h>
#include <string.h>

#include "imagem.h"
#include "filtro.h"

void imprime_coordenadas_bordas(pixel **imagem, int altura, int largura)
{
    int i, j; // Iteradores

    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            if (imagem[i][j] == 1)
            {
                printf("(%d, %d)\n", i, j);
            }
        }
    }

    return;
}

int main(void)
{
    int i, j; // Iteradores

    int altura, largura;
    char caminho[200];
    int x, y, criterio;
    int num_buscas;

    pixel **imagem, **imagem_filtro;

    scanf(" %s", caminho);
    imagem = imagem_abrir(caminho, &altura, &largura);

    imagem_filtro = imagem_caloca(altura, largura);

    scanf("%d", &num_buscas);

    for (i = 1; i <= num_buscas; i++)
    {
        scanf("%d %d %d", &x, &y, &criterio);
        filtro_conquista(imagem_filtro, imagem,
                         altura, largura,
                         x, y, criterio,
                         i);
    }

    imagem_filtro = filtro_bordas(imagem_filtro, altura, largura);

    imprime_coordenadas_bordas(imagem_filtro, altura, largura);

    char resultados[200] = "Resultados/";
    strcat(resultados, caminho);

    imagem_salva(resultados, imagem_filtro, altura, largura, 1);

    imagem_destroi(imagem, altura);
    imagem_destroi(imagem_filtro, altura);

    return EXIT_SUCCESS;
}