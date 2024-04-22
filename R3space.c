#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <vectorspace.h>
#include <R3space.h>

scalar scalaradd(scalar a, scalar b){
	return (scalar) (double) a + (double) b;
}

scalar scalarmultiply(scalar a, scalar b){
	return (scalar) (double) a * (double) b;
}

scalar scalaraddinvs(scalar a){
	return (scalar) -1 * (double) a;
}

scalar scalarmultinvs(scalar a){
	return (scalar) 1 / (double) a;
}

vector scalarprod(scalar a, vector v){
	for (int i = 0; i < 3; i++){
		v.coords[i] = (double) a * v.coords[i];
	}
}

vector vectoradd(vector v, vector w){
	vector sum;
	for (int i = 0; i < 3; i++){
		sum.coords[i] = v.coords[i] + w.coords[i];
	}
}

vector vectorinvs(vector v){
	vector invs;
	for (int i = 0; i < 3; i++){
		invs.coords[i] = -1 * v.coords[i];
	}
}

scalar innerprod(vector v, vector w){
	return (scalar) (v.coords[0] * w.coords[0] + v.coords[1] * w.coords[1] + v.coords[2] * w.coords[2]);
}
//comment
