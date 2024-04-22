#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <vectorspace.h>
#include <R3space.h>

//I admit this is not the best logic to check whether the scalar is actually a real number
#define IS_DOUBLE_TYPE(type) (sizeof(type == sizeof(double))
#ifdef IS_DOUBLE_TYPE
scalar norm(vector v){
	return (scalar) sqrt((double) innerprod(v, v));
}

vector normalize(vector v){
	return scalarprod(scalarmultinvs(norm(v)), v);
}

vector * gram_schmidt(vector list[], int list_length){
	if (list_length == 0){
		return null; //inner product not defined for empty set
	}
	vector * orthonormal_set = malloc(sizeof(vector) * list_length);
	*orthonormal_set = normalize(list[0]);
	
	vector projection;
	vector orthonormal_complement;
	for (int i = 1; i < list_length; i++){
		for (int j = 0; j < i; j++){
			if (j == 0){
				projection = scalarprod(innerprod(list[i], list[0]), list[0]);
			} else {
				projection = vectoradd(projection, scalarprod(innerprod(list[i], list[j]), list[j])); 
			}

		}
		orthonormal_complement = vectoradd(list[i], vectorinvs(projection));
		*orthonormal_set + i = orthonormal_complement;
	}
	return orthonormal_set;
}

#endif
