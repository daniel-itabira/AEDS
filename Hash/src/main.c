#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hashlp.h"

extern int M; // size of linear probing table

int main(){

	int i, sum_cost;
	srand(time(0));

	M = 50; // pode mudar aqui
	init_hash();

	// Adding key-values
    for(int i=0;i<M;i++)
    {
        put(rand()%M,rand() % M ); //inserindo 1000 valores na hash
    }


	printf("Displaying only inseted key-values \n\n");
    display();

	printf("Displaying all hash table \n\n");
    display_all();

	printf("Displaying hash table as '*'' and '_' respectivelly occupied and empty slots.\n\n");
	display_clusters();

    printf("DELETADOS: \n\n");

    for(int i=0;i<M;i++) //deletando elementos aleatorios para teste
    {
        del(rand()%M);
    }
    display_clusters();


	//You also can check the insertion
	if( put(123456, 1.2) == 0 ){
		printf("Error: table is full.\n");
	}else{
		printf("key-value inserted.\n");
	}

	if( put(33242, 34.75) == 0 ){
		printf("Table is full.\n");
	}else{
		printf("key-value inserted.\n");
	}


	return 0;
}
