#pragma once
#include "Matrix.h"

#define eps 1e-9


class Equation {

public:
	Matrix A, b, x;
	int N;

	Equation(Matrix, Matrix, Matrix, int);
	int metodaJacobiegoIloscIteracji();
	int metodaGaussaSeidlaIloscIteracji();
	double metodaFaktoryzacjiLU();
	void show();
	
};