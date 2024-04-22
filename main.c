#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vectorspace.h"
#include "R3space.h"

void parse_input(char *, int *, vector *);

void main(void){
	printf("Let's find an orthonormal set of vectors using the Gram-Schmidt process!\n");
	printf("We are currently working in the vector space %s.\n", spacename);

	printf("Please enter at least 1 and at most %d vectors in %s in this format: a11,a12,a13;b11,b12,b13; etc.\n", dimension, spacename);
	char * line = NULL;
	size_t size;
	size_t nread = getline(&line, &size, stdin);
	if (nread == -1){
		free(line);
		exit(1);
	}

	vector * inputs;
	int input_size;
	parse_input(line, &input_size, inputs);

	vector * orthonormal_set = gram_schmidt(inputs);

	printf("The orthonormal set corresponding to your input is ");
	for (int i = 0; i < input_size; i++){
		printf("(%d, %d, %d), ", orthonormal_set[i].coords[0], orthonormal_set[i].coords[1], orthonormal_set[i].coords[2]);
	}
	printf("\n");
	free(orthonormal_set);
}

parse_input(char * line, int * n, vector * set){
	char * intermediate[dimension + 1];
	intermediate[0] = strtok(line, ";");
	int i = 0;
	while (intermediate[i] != NULL){
		i++;
		if (i <= dimension){
			intermediate[i] = strtok(NULL, ";");
		} else{
			break;
		}
	}
	if (i == 0){
		printf("Error: You must enter at least one vector.\n");
		exit(2);
	}
	if (i == dimension + 1){
		printf("Error: No set of more than %d vectors can be orthonormal in %s. If you don't believe me, prove this yourself.\n", dimension, spacename);
		exit(3);
	}
	free(line);

	//I hate to hardcode this part but I did :(
	for (int j = 0; j < i; j++){
		vector v;
		char * ptr1;
		char * ptr2;
		char * ptr3;
		v.coords[0] = strtod(strtok(intermediate[j], ","), &ptr1);
		v.coords[1] = strtod(strtok(NULL, ","), &ptr2);
		v.coords[2] = strtod(strtok(NULL, ","), &ptr3);
		if (strtok(NULL


