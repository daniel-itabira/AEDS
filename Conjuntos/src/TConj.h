#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct{
    int item;
}TElem;

typedef struct{
    TElem* elemento;
    int n;
    int last;
}TConj;

void inicializar(TConj* pA);
int inserir_elemento(TConj* pA, int elem);
int excluir_elemento(TConj* pA, int elem);
int set_elemento(TConj* pA, int elem, int pos);
int get_elemento(TConj A, int pos, int* pelem);
int testar_elemento(TConj A, int elem);
TConj gerar_conjunto(int n);
TConj num2conj(int num);
int conj2num(TConj A);
int comparar(TConj A, TConj B);
void imprimir(TConj A);
TConj uniao(TConj A, TConj B);
TConj inter(TConj A, TConj B);
TConj subtrair(TConj A, TConj B);
void insertionSort(TConj* A);
void insertionSortP(int* pA,int tam);
void rearanja(int* A,int tam,int* tamanho_novo);
