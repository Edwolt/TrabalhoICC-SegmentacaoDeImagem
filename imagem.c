#include "imagem.h"

pixel **imagem_abrir(const char *caminho, int *altura, int *largura)
{

    int i, j; // Iteradores

    FILE *arquivo = fopen(caminho, "r");
    if (arquivo == NULL)
    {
        printf("\nErro: imagem_abrir()");
        printf("Não foi possível abrir a imagem\n");
        exit(EXIT_FAILURE);
    }

    // Ignora string ("P2")
    // Lê altura e largura
    // Ignora inteiro com valor maximo da matriz de pixel (indica valor que representa o branco)
    fscanf(arquivo, "%*s %d %d %*d", largura, altura);

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
    int i; // Iteradores

    pixel **imagem = (pixel **)malloc(altura * sizeof(pixel *));
    if (imagem == NULL)
    {
        printf("\nErro: imagem_aloca()");
        printf("Não foi possivel alocar imagem\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < altura; i++)
    {
        imagem[i] = (pixel *)malloc(largura * sizeof(pixel));
        if (imagem[i] == NULL)
        {
            printf("\nErro: imagem_aloca()");
            printf("Não foi possivel alocar imagem\n");
            exit(1);
        }
    }

    return imagem;
}

pixel **imagem_caloca(int altura, int largura)
{
    int i; // Iteradores

    pixel **imagem = (pixel **)calloc(altura, sizeof(pixel *));
    if (imagem == NULL)
    {
        printf("\nErro: imagem_caloca()");
        printf("Não foi possivel alocar imagem\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < altura; i++)
    {
        imagem[i] = (pixel *)calloc(largura, sizeof(pixel));
        if (imagem[i] == NULL)
        {
            printf("\nErro: imagem_caloca()");
            printf("Não foi possivel alocar imagem\n");
            exit(EXIT_FAILURE);
        }
    }

    return imagem;
}

void imagem_salva(const char *caminho, pixel **imagem,
                  int altura, int largura, int max)
{
    int i, j;

    FILE *arquivo = fopen(caminho, "w");
    if (arquivo == NULL)
    {
        printf("\nErro: imagem_salva()");
        printf("Não foi possivel abrir imagem\n");
        exit(EXIT_FAILURE);
    }

    fprintf(arquivo, "P2\n");
    fprintf(arquivo, "%d %d\n", largura, altura);
    fprintf(arquivo, "%d\n", max);

    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            fprintf(arquivo, "%hhu ", imagem[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
}

void imagem_destroi(pixel **imagem, int altura)
{
    int i; // Iteradores

    for (i = 0; i < altura; i++)
    {
        free(imagem[i]);
    }
    free(imagem);

    return;
}