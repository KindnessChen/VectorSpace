#ifndef R3SPACE
#define R3SPACE

extern char* spacename = "R^3";

extern int dimension = 3;

typedef struct vector{
	double coords[3];
} vector;
typedef double scalar; //I thought about referring to this as "field" but this would sound weird as a return type


#endif
