#include <stdio.h>
#include <stdlib.h>

int main()
{
    int linhas, colunas;

    float **matriz1, **matriz2;

    scanf("%d \n %d", &linhas,&colunas);

    if(linhas==colunas)
    {
        matriz1 = (float **) malloc(linhas*sizeof(float *));

        for(int i=0; i<linhas; i++)
            {
                matriz1[i]= (float *) malloc(colunas*sizeof(float));
                for(int j=0; j<colunas;j++)
                {
                    scanf("%f", &matriz1[i][j]);
                }
                printf("\n");
            }

        scanf("%d \n %d", &linhas,&colunas);

        if(linhas==colunas || colunas==linhas)
        {
            matriz2= (float **) malloc(linhas*sizeof(float *));

                for(int i=0; i<linhas; i++)
            {
                matriz2[i]= (float *) malloc(colunas*sizeof(float));
                for(int j=0; j<colunas;j++)
                {
                    scanf("%f", &matriz2[i][j]);
                }
                printf("\n");
            }
        }
    }

    float **matrizsoma;

    matrizsoma = (float **) malloc(linhas*sizeof(float *));

    for(int i=0; i<linhas; i++)
            {
                matrizsoma[i] = (float *) malloc(linhas*sizeof(float));
                for(int j=0; j<linhas ;j++)
                {
                    matrizsoma[i][j] = matriz1[i][j]+ matriz2[i][j];
                }
            }

    for(int i=0; i<linhas;i++)
    {
        for(int j=0; j<linhas;j++)
        {
            printf("%f ",matrizsoma[i][j]);
        }
        printf("\n");
    }

    free(matriz1);
    free(matriz2);
    free(matrizsoma);

    return 0;
}
