#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
int main(int argc, int *argv[])
{
    FILE *file1 = fopen(argv[1],"r");
    FILE *file2 = fopen(argv[2],"r");

    if(file1 == NULL)
    {
        fclose(file1);
        fclose(file2);
        return 0;
    }

    int x;
    printf("Deseja sobrescrever o arquivo?\n1 - SIM\n0 - NAO\n");
    scanf("%d",&x);

    if(x<0 || x>1)
    {
        fclose(file1);
        fclose(file2);
        return 0;
    }

    if(x==1)
    {
        fclose(file2);
        file2 = fopen(argv[2], "w");
    }
    else
    {
        fclose(file1);
        fclose(file2);
        return 0;
    }

    copiarConteudo(file1,file2);
    fclose(file1);
    fclose(file2);
    return 0;
}
void copiarConteudo(FILE *file1,FILE *file2)
{
    char copia[100];
    while(fgets(copia, 100,file1) != NULL);
    fputs(copia,file2);
}
