#include <stdio.h>

#include "imagem.h"
#include "filtro.h"

int main()
{
    int altura, largura;
    char *caminho;
    scanf("%ms", caminho);
    pixel **imagem = imagem_abrir("teste1.pgm", &altura, &largura);

    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            printf("%d ", imagem[i][j]);
        }
        printf("\n");
    }

    imagem_destroi(imagem, altura);
}