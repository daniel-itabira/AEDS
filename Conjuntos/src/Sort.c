#include <stdio.h>
#include <stdlib.h>
#include "TConj.h"
void insertionSort(TConj* pA){

    int j;
    int i;
    int key;

    for (int i = 1;i < pA->n; i++){
		key = pA->elemento[i].item;
		j = i - 1;
       while ((j >= 0) && (pA->elemento[j].item > key))
        {
			pA->elemento[j + 1].item = pA->elemento[j].item;
			j--;
		}
		pA->elemento[j + 1].item = key;
	}
}
void insertionSortP(int* pA,int tam){

    int j;
    int i;
    int key;

    for (int i = 1;i < tam; i++){
		key = pA[i];
		j = i - 1;
       while ((j >= 0) && (pA[j]> key))
        {
			pA[j + 1] = pA[j];
			j--;
		}
		pA[j + 1] = key;
	}
}
void rearanja(int* A,int tam,int* tamanho_novo){

    int reajuste = 0;

    for(int i=0;i<tam;i++)
    {
        if(A[i] == A[i+1])
        {
            for(int j=i; j<tam;j++)
            {
                A[j] = A[j+1];//arrastando elementos para nova posicao
            }
            reajuste++;
        }
    }
    *tamanho_novo = reajuste;
}

