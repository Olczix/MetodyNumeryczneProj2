#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix(int r, int c) //b(N,1)
{
	this->rows = r;
	this->cols = c;
	
	tab = new double* [rows];
	for (int i = 0; i < rows; i++) {
		tab[i] = new double[cols];
		for (int j = 0; j < cols; j++) 
			tab[i][j] = 0;
	}
}

Matrix::~Matrix() {
	/*for (int i = 0; i < rows; i++) {
		delete[] this->tab[i];
	}
	delete[] tab;*/
}


Matrix Matrix::operator=(const Matrix& M)
{
	Matrix newMatrix(rows, cols);
	for (int i = 0; i < rows; i++) 
		for (int j = 0; j < cols; j++) 
			newMatrix.tab[i][j] = M.tab[i][j];

	this->tab = newMatrix.tab;
	return newMatrix;
}


Matrix Matrix::operator+(const Matrix& M)
{
	if (rows != M.rows || cols != M.cols) {
		cout << "Matrix sizes do not match." << endl;
		return (*this);
	}

	Matrix newMatrix(rows, cols);
	for (int i = 0; i < rows; i++) 
		for (int j = 0; j < cols; j++) 
			newMatrix.tab[i][j] = tab[i][j] - M.tab[i][j];
		
	return newMatrix;
}


Matrix Matrix::operator-(const Matrix& M)
{
	if (rows != M.rows || cols != M.cols) {
		cout << "Matrix sizes do not match." << endl;
		return (*this);
	}

	Matrix newMatrix(rows, cols);
	for (int i = 0; i < rows; i++) 
		for (int j = 0; j < cols; j++) 
			newMatrix.tab[i][j] = tab[i][j] - M.tab[i][j];
	
	return newMatrix;
}


Matrix Matrix::operator*(const Matrix& M){
	if (this->cols != M.rows) {
		cerr << " Wrong matrices sizes ( operator* )" << endl;
		return (*this);
	}
	else {
		Matrix newMatrix(this->rows, M.cols);
		for (int i = 0; i < newMatrix.rows; ++i)
			for (int j = 0; j < newMatrix.cols; ++j)
				for (int k = 0; k < cols; ++k)
					newMatrix.tab[i][j] += (this->tab[i][k] * M.tab[k][j]);
		return newMatrix;
	}
}


Matrix Matrix::operator*(double d){
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			tab[i][j] *= d;
	return (*this);
}


void Matrix::initMatrixA(int a1, int a2, int a3) {
	for (int i = 0; i < rows; i++) 
		for (int j = 0; j < cols; j++) 
			if (i == j) {
				tab[i][j] = a1;
				if (j - 1 >= 0)
					tab[i][j - 1] = a2;

				if (j + 1 < cols)
					tab[i][j + 1] = a2;

				if (j - 2 >= 0)
					tab[i][j - 2] = a3;

				if (j + 2 < cols)
					tab[i][j + 2] = a3;

			}
}


void Matrix::initMatrixB(){
	for (int i = 0; i < rows; i++)
		tab[i][0] = sin(6 * (i+1));
}



void Matrix::showMatrix() {
	cout << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (tab[i][j] == 0)
				cout << " ";
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}
}

double Matrix::normVect(Matrix m){
	double v = 0.0;

	if (m.cols != 1) {
		cerr << "Matrix does not represent vector" << endl;
	}
	else { //vector 
		for (int i = 0; i < m.rows; i++) {
			double a = m.tab[i][0];
			v += pow(a, 2);
		}
	}
	return sqrt(v);
}
