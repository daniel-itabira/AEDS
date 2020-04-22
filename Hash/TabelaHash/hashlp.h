#include <stdio.h>
#include <stdlib.h>


/*It initializes the keys-vals pairs tabele*/
void init_hash();

/*It computates the hash value
	- Return: index to insert the key.
*/
int hash(int key);

/*It implements a linear probing key-val insertion
	- Return: 1 of successful insertion
			0 otherwise
*/
int put(int key, float value);


/*It should count the number of probes before a hit
 starting at key
	- Return: # of probes
*/
int count_search_miss(int key);

/*It deletes a key-value pair from keys and vals
Keeping the linear probing property.
	- Return: value assigned to the delete Key
*/
int del(int key);

/* It prints the current state of the hash table*/
void display();

/* It prints all hash table*/
void display_all();

/* It prints the hash table as '*' for filled slots in the
hash table and '_' for the empty ones.*/
void display_clusters();

/*It returns the idx where the loop must stop to search*/
int stop_condition_idx(int k);

int alfa();
