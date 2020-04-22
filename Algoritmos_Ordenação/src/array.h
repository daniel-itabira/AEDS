#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	int key;
}TItem;

typedef struct{
	TItem* item;
	int n;
}TArray;

void allocateArray(TArray*, int);
void freeArray(TArray*);
void printArray(TArray*);
int isSorted(TArray*);
void generateSorted(TArray*, int);
void generateInvert(TArray*,int);
void generateRandom(TArray*, int);
void generateRandomNoRep(TArray*, int);
void generateAlmostSorted(TArray*,int);
void generateAlmostSortedNoRep(TArray*,int);
