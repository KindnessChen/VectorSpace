#ifndef VECTORSPACE
#define VECTORSPACE

#include "R3space.h"

scalar scalaradd(scalar, scalar);

scalar scalarmultiply(scalar, scalar);

scalar scalaraddinvs(scalar);

scalar scalarmultinvs(scalar);

vector scalarprod(scalar, vector);

vector vectoradd(vector, vector);

vector vectorinvs(vector);

scalar innerprod(vector, vector);

scalar norm(vector);

vector normalize(vector);

vector* gram_schmidt(vector list[]);

#endif
