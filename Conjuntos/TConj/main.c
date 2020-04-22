#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TConj.h"

int main(){

    TConj A, B, C, D;
    int elemento , num , i;

    inicializar (&A);

    srand(171);
    for(i=0; i<20 ;i++)
    {
        inserir_elemento(&A, rand()%40);
    }
    printf("INSERIDOS:\n");
    imprimir(A);

    srand(171);
    for(i=0; i<10 ;i++)
    {
        excluir_elemento(&A, rand()%20-1);
    }
    printf("COM EXCLUIDOS:\n");
    imprimir(A);

    set_elemento(&A,999,2);
    printf("SET DO ELEMENTO: (999 na posicao 2)\n");
    imprimir(A);

    get_elemento(A,3,&elemento);
    printf("GET DO ELEMENTO: (posicao 3)\n");
    printf("ELEMENTO: %d\n", elemento);

    printf("TESTE DO ELEMENTO NO CONJUNTO (9) - ");
    int testeposicao = testar_elemento(A,9);
    if(testeposicao >=0){
        printf("Esta presente no conjunto! posicao: %d \n", testeposicao);
    }else{printf("Nao esta presente no conjunto! \n"); }

    B = gerar_conjunto(10);
    printf("CONJUNTO ALEATORIO: \n");
    imprimir(B);

    printf("TRANSFORMAR CONJ EM NUM INT: \n");
    num = conj2num(B);
    printf("NUM: %d  \n", num);

    C = num2conj(num);
    printf("TRANSFORMAR NUM PARA CONJUNTO \n");
    imprimir(C);

    printf("COMPARAR \n");
    if(comparar(B, C) == 1)
    {
        printf("os conjuntos sao iguais\n");
    }
    else
    {
        printf("os conjuntos sao diferentes\n");
    }

    printf("UNIAO:\n");
    D = uniao(A,B);
    imprimir(D);

    printf("INTERSECAO\n");

    D = inter(A,B);
    imprimir(D);

    printf("SUBTRAIR\n");

    D = subtrair(A,B);
    imprimir(D);


 return 0;
}
