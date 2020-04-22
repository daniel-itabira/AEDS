#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TConj.h"
#define VAZIO 0
void inicializar(TConj* pA){

    pA->elemento = (TElem*) calloc(10,sizeof(TElem));
    pA->n = 10;
    pA->last = pA->elemento[pA->n-1].item;
    if(!pA->elemento){
		printf("ERRO: NAO FOI POSSIVEL ALOCAR MEMORIA PARA VETOR\n");
		exit(1);
	}
}
int inserir_elemento(TConj* pA, int elem){

        for(int i=0;i<pA->n;i++)
        {
            if(pA->elemento[i].item == elem)      //verifica se o elemento ja existe no conjunto
            {
                return 0;
                exit(1);
            }
        }

        int realocar =0;

        for(int i=0;i<pA->n;i++)
        {
            if(pA->elemento[i].item == VAZIO)    //verificando se possui espaço para o elemento
            {
                realocar = 0;
                pA->elemento[i].item = elem;
                pA->last = pA->elemento[pA->n-1].item;
                return 1;
            }
           realocar = 1;
        }

        if(realocar == 1)
        {
            int antigo = pA->n;
            pA->n = pA->n+1;
            pA->elemento = (TElem*) realloc(pA->elemento,sizeof(TElem)*pA->n);   //realocando memoria em +1 para o novo elemento
            pA->elemento[pA->n-1].item = VAZIO;

            if(pA->elemento[pA->n-1].item == VAZIO)
            {
                pA->elemento[pA->n-1].item = elem;
            }

            pA->last = pA->elemento[pA->n-1].item; //salvando o ultimo elemento e last
        }

}
int excluir_elemento(TConj* pA, int elem){

    int i=0, j;
    int aux=0;

    for(i=0;i<pA->n;i++)
    {
        if(pA->elemento[i].item == elem)
        {
            for(j=i; j<pA->n;j++)
            {
                pA->elemento[j].item = pA->elemento[j+1].item; //arrastando elementos para nova posicao
            }
            pA->elemento = (TElem*) realloc(pA->elemento,sizeof(TElem)*pA->n-1); //deslacando memoria do elemento excluido
            pA->n = pA->n-1;                      //novo tamanho do conjunto
            return 1;
        }
        else
        {
            return 0; //elemento nao presente no conjunto
        }
    }
}
int set_elemento(TConj* pA, int elem, int pos){

    if(pos < 0)
    {
        return 0;
    }
    for(int i=0;i<pA->n;i++)
        {
            if(pA->elemento[i].item == elem)      //verifica se o elemento ja existe no conjunto
            {
                return 0;
                exit(1);
            }
        }
    if(pos <= pA->n)
    {
        pA->elemento[pos].item = elem; //set no elemento
        return 1;
    }
    else
    {
        return 0; //a posicao nao existe no conjunto
    }
}
int get_elemento(TConj A, int pos, int* pelem){

    if(pos < 0)
    {
        return 0;
    }
    if(pos <= A.n)
    {
        *pelem = A.elemento[pos].item; //get do elemento
        return 1;
    }
    else
    {
        return 0;
    }
}
int testar_elemento(TConj A, int elem){

    for(int i=0;i<A.n;i++)
    {
        if(A.elemento[i].item == elem) //condicao para testar se o elmeento esta presente no conjunto
        {
            return i;
        }
    }
    return -1;
}
TConj gerar_conjunto(int n){

    if(n <= 0)
    {
        exit(1);
    }
    TConj aleatorio;
    aleatorio.n = n;

    aleatorio.elemento = malloc(n*sizeof(TElem));

    for(int i=0;i<n;i++)
    {
        aleatorio.elemento[i].item = rand()%100;
    }
    aleatorio.last = aleatorio.elemento[n-1].item;

    return aleatorio;
}
TConj num2conj(int num){

    if(num<=0)
    {
        exit(1);
    }

    int aloc = 2;
    int* p;
    p = (int*) malloc(aloc*sizeof(int));      //aloca ponteiro auxiliar para salvar os resutados do resto ta divsao

    int aux;
    int i=0;
    do{
        aux = num%10;  //faz resto da divisao para separar os elementos
        num = num/10;
        p[i] = aux;     //guarda no ponteiro
        i++;
            if(num>0)
            {
                p = (int*) realloc(p,sizeof(int)*aloc+1); //realoca espaço caso num nao for 0
                aloc++;

            }
    }while(num>0);

    for(int x=0;x<i;x++)
    {
        for(int y=0;y<i;y++)
        {
            if(p[x]==p[y])      //se o numero tiver numeros iguais ele nao pode ser um conjunto
            {
                break;
                exit(1);
            }
        }
    }

    TConj num2;                 //conjunto para retorno
    num2.n = i;
    num2.elemento = (TElem*) malloc(i*sizeof(TElem));

    int retorno = 0;
    for(int j=i;j>0;j--)
    {
        num2.elemento[j-1].item = p[retorno];
        retorno++;
    }
    num2.last = num2.elemento[num2.n-1].item;

    free(p); //libera o ponteiro auxiliar

    return num2;
}
int conj2num(TConj A){

    if(A.n <= 0)
    {
        exit(1);
    }
    int* vetor; //vetor para guardar a potencia de cada elemento
    vetor = malloc(A.n*sizeof(int));
        int aux = A.n-1;

    for(int i=0;i<A.n;i++)
    {
        vetor[i] = A.elemento[i].item*pow(10,aux); //potencia do elemento
        aux--;
    }

    int soma=0;
    for(int j=0;j<A.n;j++)
    {
        soma = soma + vetor[j];
    }
    soma = soma+1;
    free(vetor);
    return soma;
}
int comparar(TConj A, TConj B){

    if(A.n == B.n)
    {
       insertionSort(&A);   //ordena os conjuntos para facilitar a comparacao de elementos
       insertionSort(&B);

       for(int i=0;i<A.n;i++)
       {
           if(A.elemento[i].item != B.elemento[i].item) //compara os elementos
           {
               return 0;
           }
       }
       return 1;
    }
    else
    {
        return 0;
    }
}
TConj uniao(TConj A, TConj B){

    int* ponteiro;
    int tamanho = A.n+B.n;
    ponteiro = (int*) malloc(tamanho*sizeof(int));

    int i=0;
    for(i;i<A.n;i++)              //armazenando itens do conjnto no ponteiro
    {
        ponteiro[i] = A.elemento[i].item;
    }
    int retorno=0;
    for(i;i<tamanho;i++)
    {
        ponteiro[i] = B.elemento[retorno].item;
        retorno++;
    }

    insertionSortP(ponteiro,tamanho);

    int tamanho_novo = VAZIO;

    rearanja(ponteiro,tamanho,&tamanho_novo);  //ajusta o conjunto eliminando elementos repetidos

    tamanho = tamanho - tamanho_novo;
    ponteiro = (int*) realloc(ponteiro,sizeof(int)*tamanho);



    TConj C;   //conjunto de retorno
    C.n = tamanho;
    C.elemento = (TElem*) malloc(tamanho*sizeof(TElem));

    for(int k=0;k<tamanho;k++)
    {
        C.elemento[k].item = ponteiro[k];  //atribuindo itens ao conjunto
    }

    C.last = C.elemento[tamanho-1].item;
    free(ponteiro);

    return C;
}


TConj inter(TConj A, TConj B){

    int* ponteiro;
    int tamanho=A.n+B.n;
    int separador = 0;
    int cont =0;

    ponteiro = (int*) calloc(tamanho,sizeof(int)); //calloc para definir memoria setada com 0 para evitar lixo na comparacao

    int aux=0;

    insertionSort(&A);
    insertionSort(&B);

    for(int i=0;i<A.n;i++)
    {
        for(int j=0;j<B.n;j++)
        {
            if(A.elemento[i].item == B.elemento[j].item)  //compara elementos para ver se sao iguais
            {
                aux++;
                ponteiro[i] = A.elemento[i].item;
            }

        }
    }

    tamanho=aux;
    insertionSortP(ponteiro,tamanho);

    ponteiro = (int*) realloc(ponteiro,sizeof(int)*tamanho); //reallocando memoria do ponteiro pos insercao

    int tamanho_novo = VAZIO;
    rearanja(ponteiro,tamanho,&tamanho_novo);       //reallocando depois do rearanjo

    tamanho = tamanho - tamanho_novo;
    ponteiro = (int*) realloc(ponteiro,sizeof(int)*tamanho);

    TConj C;                                                //conjunto C para retorno
    C.elemento = (TElem*) malloc(tamanho*sizeof(TElem));
    C.n = tamanho;

    for(int i=0; i<tamanho;i++)
    {
        C.elemento[i].item = ponteiro[i];   //atribuindo items
    }
    C.last = C.elemento[C.n-1].item;

    free(ponteiro);
    return C;

}

TConj subtrair(TConj A, TConj B){

    int* ponteiro;
    int* ponteiro2;
    int tamanho=A.n+B.n;
    ponteiro = (int*) calloc(A.n,sizeof(int));              //ponteiro auxiliar para o conjunto A
    ponteiro2 = (int*) calloc(B.n,sizeof(int));                 //ponteiro auxiliar para conjunto B
    int aux=0,aux2=0;
    int x=0,y=0;
    int igual=0;
    int igual2=0;
    for(int i=0;i<A.n;i++)
    {
        for(int j=0;j<B.n;j++)
        {
                if(A.elemento[i].item != B.elemento[j].item)
                {
                    igual = 1;  //testa elementos diferentes caso todos forem diferentes a variavel igual recebe 1;
                }
                else{
                    igual = 0;
                    break;
                }
        }

        if(igual==1)  //se a variavel for 1 atribui o elemento no vetor auxiliar correspondente
        {
            aux++;
            igual = 0;
            ponteiro[x] = A.elemento[i].item;
            x++;
        }
    }
    for(int i=0;i<B.n;i++)
    {
        for(int j=0;j<A.n;j++)
        {
                if(B.elemento[i].item != A.elemento[j].item)   //teste para o segndo conjunto
                {
                    igual2 = 1;
                }
                else{
                    igual2 = 0;
                    break;
                }
        }

        if(igual2==1)
        {
            aux2++;
            igual2 = 0;
            ponteiro2[y] = B.elemento[i].item;
            y++;
        }
    }

    ponteiro = (int*) realloc(ponteiro,sizeof(int)*aux);
    ponteiro2 = (int*) realloc(ponteiro2,sizeof(int)*aux2);

    int tam = aux+aux2;
    int* conjunt;
    conjunt = malloc(tam*sizeof(int));
    int junta=0;
    for(junta;junta<aux;junta++)
    {
        conjunt[junta] = ponteiro[junta];      //junta os conjuntos em um conjunto novo
    }
    int retorno=0;
    for(int i=0;i<aux2;i++)
    {
        conjunt[junta]= ponteiro2[retorno];  //agrupa tudo
        retorno++;
        junta++;
    }
    TConj C;
    C.n = aux+aux2;
    C.elemento = (TElem*) calloc(C.n,sizeof(TElem));

    for(int i=0;i<C.n;i++)
    {
        C.elemento[i].item = conjunt[i];  //atribui os elementos do ponteiro para o cnjunto retorno
    }
    C.last = C.elemento[C.n-1].item;



    free(ponteiro2);
    free(ponteiro);
    free(conjunt);

    return C;
}
void imprimir(TConj A){
	int i;
	if(A.n<=0)
    {
        exit(1);
    }
	printf("Array:\n");
    for(i=0;i<A.n;i++)
    {
        printf("%d ",A.elemento[i].item);
        if(A.elemento[i].item == A.last)   //verifica se chegou no ultimo elemento do conjunto
        {
            break;
            exit(1);
        }
    }
    printf("\n");
}
