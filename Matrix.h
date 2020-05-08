#pragma once

class Matrix {

public:
	double** tab;
	int rows;
	int cols;

	Matrix(int, int); //constuctor
	//Matrix();
	~Matrix(); //destructor

//operator overloads
	Matrix operator=(const Matrix&);
	Matrix operator+(const Matrix&);
	Matrix operator-(const Matrix&);
	Matrix operator*(const Matrix&);
	Matrix operator*(double);


// matrix functions
	void initMatrixA(int, int, int);
	void initMatrixB();
	void showMatrix();
	static double normVect(Matrix);

};

