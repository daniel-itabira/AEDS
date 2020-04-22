#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome[10];
    double salario,vendas,montante;

    gets(nome);

    scanf("%lf",&salario);
    scanf("%lf",&vendas);

    montante = salario + vendas/100*15;

    printf("TOTAL = R$ %.2lf",montante);


    return 0;
}
