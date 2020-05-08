#include "Equation.h"

#include <iostream>
using namespace std;

Equation::Equation(Matrix A, Matrix b, Matrix x, int N) :A(A), b(b), x(x), N(N) {}

 int Equation::metodaJacobiegoIloscIteracji() // O(n^2)
{
	int counter = 0;
	Matrix xtmp(N, 1);
	xtmp.tab = x.tab;

	do {
		for (int i = 0; i < N; i++) {
			double val = b.tab[i][0];
			for (int k = 0; k < N; k++) 
				if (k != i)
					val -= A.tab[i][k] * x.tab[k][0];
			val /= A.tab[i][i];
			xtmp.tab[i][0] = val;
		}
		x = xtmp;
		counter++;
		//cout << Matrix::normVect(A * x - b) << endl;
	} while (Matrix::normVect(A * x - b) >=eps);
	
	return counter;
}

int Equation::metodaGaussaSeidlaIloscIteracji() // O(n^2)
{
	int counter = 0;
	do {
		for (int i = 0; i < N; i++) {
			double val = b.tab[i][0];
			for (int k = 0; k < N; k++) 
				if (k != i) 
					val -= A.tab[i][k] * x.tab[k][0];
			
			val /= A.tab[i][i];
			x.tab[i][0] = val;
		}
		counter++;
	} while (Matrix::normVect(A * x - b) >= eps);

	return counter;
}

double Equation::metodaFaktoryzacjiLU(){ // O(n^3)
	// A = L * U
	Matrix L(N, N);
	Matrix U(N, N);


	//Inicjalizacja macierzy L i U

	// L = I (macierz jednostkowa)
	for (int i = 0; i < N; i++)
		L.tab[i][i] = 1.0;

	// U = A
	for (int i = 0; i < N; i++)
		for (int j = 0; j < i+1; j++)
			U.tab[j][i] = A.tab[j][i];


	for (int i = 0; i < N; i++) {

		// uzupe³nianie "wyniowej" macierzy U - macierz trójk¹tna górna
		for (int j = 0; j < i + 1; j++) 	
			for (int k = 0; k < j ; k++)
				U.tab[j][i] = U.tab[j][i] - L.tab[j][k] * U.tab[k][i];
	

		// uzupe³niane macierzy L - macierz trójk¹tna dolna
		for (int j = i + 1; j < N; j++) {
			for (int k = 0; k < i ; k++)
				L.tab[j][i] = L.tab[j][i] - L.tab[j][k] * U.tab[k][i];
			

			L.tab[j][i] = L.tab[j][i] + A.tab[j][i];
			L.tab[j][i] = L.tab[j][i] / U.tab[i][i];
		}
	}
	
	//L.showMatrix();
	//U.showMatrix();
	//(L * U).showMatrix();

	Matrix y(N, 1);

	//Podstawienie w przód dla Ly = b		
	for (int i = 0; i < N; i++) 
	{
		double tmp = b.tab[i][0];
		for (int j = 0; j < i; j++) 
			tmp = tmp - y.tab[j][0] * L.tab[i][j];
		
		y.tab[i][0] = tmp / L.tab[i][i];
	}


	//Podstawienie wstecz dla Ux = y
	for (int i = N - 1; i >= 0; i--) 
	{
		double tmp = y.tab[i][0];
		for (int j = i + 1; j < N; j++) 
				tmp -= U.tab[i][j] * x.tab[j][0];
	
		x.tab[i][0] = tmp / U.tab[i][i];
	}

	return Matrix::normVect(A * x - b);
}


void Equation::show(){

	A.showMatrix();
	b.showMatrix();
	x.showMatrix();

}

