#include <limits.h>
#include "sort.h"
#define TRUE 1
#define FALSE 0

void bubbleSort(TArray* pA, long* att, long* comp){
	TItem aux;

	for(int i = 0; i < pA->n-1; i++){
		for(int j = 0; j < pA->n-i-1; j++){
			(*comp)++;
			if(pA->item[j].key > pA->item[j+1].key){
				(*att)+=3;
				aux           = pA->item[j];
				pA->item[j]   = pA->item[j+1];
				pA->item[j+1] = aux;
			}
		}
	}
}

void bubbleSortO(TArray* pA, long* att, long* comp){

    TItem aux;
	char troca = TRUE;

	for(int i = 0; i < pA->n-1 && troca == TRUE ; i++){
		troca = FALSE;
		for(int j = 0; j < pA->n-i; j++){
			(*comp)++;
			if(pA->item[j].key < pA->item[j-1].key){
				(*att)+=3;
				aux           = pA->item[j];
				pA->item[j]   = pA->item[j-1];
				pA->item[j-1] = aux;
				troca 		  = TRUE;
			}
		}
	}
}

void selectSort(TArray* pA,long* att,long*comp){

    int min; TItem aux;

    for(int i = 0; i < pA->n - 1; i++){
        min = i;
        for(int j = i + 1; j < pA->n; j++){
                (*comp)++;
            if( pA->item[j].key < pA->item[min].key){
                    min = j;
            }
        }
                (*att) += 3;
                aux = pA->item[min];
                pA->item[min] = pA->item[i];
                pA->item[i] = aux;

    }
}

void selectSortO(TArray* pA,long* att,long* comp){

    int min;
    TItem aux;
    for(int i = 0; i < pA->n-1; i++){
        min = i;
        for(int j = i+1; j < pA->n; j++){
            if( pA->item[j].key < pA->item[min].key){
                min = j;
                (*att)++;
            } (*comp)++;
        }

        if(i != min){
            aux = pA->item[min];
            pA->item[min] = pA->item[i];
            pA->item[i] = aux;
            (*att) += 3;
        }
        (*comp)++;
    }

}

void insertionSort(TArray* pA,long* att,long* comp){

    int j;
    int i;
    int key;

    for (int i = 1;i < pA->n; i++){
		key = pA->item[i].key;
		j = i - 1;
		(*comp)+2;
       while ((j >= 0) && (pA->item[j].key > key))
        {
            (*att)+=1;
			pA->item[j + 1] = pA->item[j];
			j--;
		}
		pA->item[j + 1].key = key;
	}

}

void insertionSortO(TArray* pA,long* att,long* comp){

	int i, j;

    TItem temp, *arraySentinel = malloc((pA->n + 1) * sizeof(TItem));

    for(i = 0; i < pA->n; i++){
        arraySentinel[i+1] = pA->item[i];
        (*att)++;
    }
    arraySentinel[0].key = INT_MIN;

    for (i = 1; i < (pA->n + 1); i++) {
            temp = arraySentinel[i];
            j = i;
            (*att) += 2;
            while (arraySentinel[j - 1].key > temp.key) {
                arraySentinel[j] = arraySentinel[j - 1];
                j--;
                (*att)++;
                (*comp)++;
            }
            arraySentinel[j] = temp;
    }

    for (int i = 1; i < (pA->n + 1); i++){
        pA->item[i-1] = arraySentinel[i];
        (*att)++;
    }
}
void shell_sort(TArray* pA, int tamanho,long* att, long*comp)
{
    int i , j , value;
    int gap = 1;

    do {
         gap = 3*gap+1;
       } while(gap < tamanho);

    do {
        gap /= 3;

    for(i = gap; i < tamanho; i++) {

        value = pA->item[i].key;
        j = i - gap;
        (*att)+=1;
        (*comp)+=2;

    while (j >= 0 && value < pA->item[j].key) {

            (*att)+=1;
        pA->item[j + gap] = pA->item[j];
        j -= gap;
    }

    pA->item[j + gap].key = value;
    }
    }while(gap > 1);
}
void shellSort(TArray* pA,long* att,long* comp){

	shell_sort(pA,pA->n,att,comp);
}

void quick_Sort(TArray* vetor,int esquerda,int direita,long* att,long* comp){

    int i, j, pivo;
    TItem aux;
	i = esquerda;
	j = direita-1;
	pivo = vetor->item[(esquerda + direita) / 2].key;
	while(i <= j)
	{
		while(vetor->item[i].key < pivo && i < direita)
        {
			i++;
		}
		while(vetor->item[j].key > pivo && j > esquerda)
		{
			j--;
		}
		(*comp)++;
		if(i <= j)
		{
		    (*att)+=3;
			aux = vetor->item[i];
			vetor->item[i] = vetor->item[j];
			vetor->item[j] = aux;
			i++;
			j--;
		}
	}
	(*comp)++;
	if(j > esquerda){

        quick_Sort(vetor, esquerda, j+1,att,comp);
	}

    (*comp)++;
	if(i < direita){

        quick_Sort(vetor, i, direita,att,comp);
	}

}
void quickSort(TArray* pA,long* att,long* comp){

    int esquerda =0;
    int direita = pA->n;

    quick_Sort(pA,esquerda,direita,att,comp);
}

void criarHeap(TArray* pA, int inicio, int fim,long* att,long* comp){

    TItem aux = pA->item[inicio];
    int filho = (inicio * 2)+1;

    while(filho<=fim){
            (*comp)+=2;
    if(filho<fim && (filho+1)<fim){
        if(pA->item[filho].key <pA->item[filho+1].key){

            filho++;
        }
    }
    if(aux.key<pA->item[filho].key){
            (*att)+=1;
        pA->item[inicio]=pA->item[filho];
        inicio=filho;
        filho=(2*inicio)+1;
    }
    else{

        filho=fim+1;
    }
}

    pA->item[inicio] = aux;
}


void heap_sort(TArray* pA, int tamanho,long* att,long* comp){

    int i;
    TItem aux;
    for(i=(tamanho-1)/2;i>=0;i--){

        criarHeap(pA,i,tamanho-1,att,comp);
    }
    for(i=tamanho-1;i>=1;i--){

            (*att)+=3;
        aux = pA->item[0];
        pA->item[0]=pA->item[i];
        pA->item[i]=aux;
        criarHeap(pA,0,i-1,att,comp);
    }
}

void heapSort(TArray* pA,long* att,long* comp){

   int tamanho = pA->n;

   heap_sort(pA,tamanho,att,comp);
}



void merge(TArray* vetor, int comeco, int meio, int fim,long* att,long* comp){

    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        (*comp)++;
        if(vetor->item[com1].key < vetor->item[com2].key) {
                (*att)+=1;
            vetAux[comAux] = vetor->item[com1].key;
            com1++;
        } else {
                (*att)+=1;
            vetAux[comAux] = vetor->item[com2].key;
            com2++;
        }
        comAux++;
    }
    (*comp)++;
    while(com1 <= meio){

            (*att)+=1;
        vetAux[comAux] = vetor->item[com1].key;
        comAux++;
        com1++;
    }
    (*comp)++;
    while(com2 <= fim) {

             (*att)+=1;
        vetAux[comAux] = vetor->item[com2].key;
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){

             (*att)+=1;
        vetor->item[comAux].key = vetAux[comAux-comeco];
    }

    free(vetAux);
}

void merge_sort(TArray* vetor, int comeco, int fim,long* att,long* comp){

    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        merge_sort(vetor, comeco, meio,att,comp);
        merge_sort(vetor, meio+1, fim,att,comp);
        merge(vetor, comeco, meio, fim,att,comp);
    }
}
void mergeSort(TArray* pA,long* att,long* comp){

    merge_sort(pA,0,pA->n-1,att,comp);

}







