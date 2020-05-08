#include <iostream>
#include <chrono>
#include "Matrix.h"
#include "Equation.h"

#define N 962
#define a1A 13
#define a1C 3
#define a2 -1
#define a3 -1


using namespace std; 
int main() {
	
// ZADANIE A
	Matrix A(N, N);
	A.initMatrixA(a1A, a2, a3);
	Matrix b(N, 1);
	b.initMatrixB();
	Matrix x(N, 1);
	Matrix x1(N, 1);
	Matrix x2(N, 1);

	Equation eq(A, b, x, N);
	Equation eq1(A, b, x1, N);
	Equation eq2(A, b, x2, N);

// ZADANIE B
	auto start = chrono::high_resolution_clock::now();
	cout << "ILOSC ITERACJI METOD¥ JACOBIEGO: " <<eq.metodaJacobiegoIloscIteracji() << endl;
	auto finish = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = finish - start;
	cout << "Elapsed time: " << elapsed.count() << endl << endl;


	start = chrono::high_resolution_clock::now();
	cout << "ILOSC ITERACJI METOD¥ GAUSSA-SEIDLA: " << eq1.metodaGaussaSeidlaIloscIteracji() << endl;
	finish = chrono::high_resolution_clock::now();
	elapsed = finish - start;
	cout << "Elapsed time: " << elapsed.count() << endl << endl;
	
	
	/*start = chrono::high_resolution_clock::now();
	cout << "WARTOSC NORMY Z RESIDUUM WEKTORA x: " << eq1.metodaFaktoryzacjiLU() << endl;
	finish = chrono::high_resolution_clock::now();
	elapsed = finish - start;
	cout << "Elapsed time: " << elapsed.count() << endl<<endl;
	*/

// ZADANIE C 
	Matrix A2(N, N);
	A2.initMatrixA(a1C, a2, a3);
	Matrix x3(N, 1);
	Equation eq3(A2, b, x3, N);

	// Metody iteracyjne nie zbiegaj¹ siê, poniewa¿ norma z residuum wektora x roœnie zamiast maleæ,
	// st¹d metoda "metodaJacobiegoIloscIteracji()" bêdzie wykonywaæ siê w nieskoñczonoœæ,
	// dlatego poni¿sze wyœwietlenie pozostawiam zakomentowane 
	//cout << "ILOSC ITERACJI METOD¥ JACOBIEGO: " << eq3.metodaJacobiegoIloscIteracji() << endl;
	

// ZADANIE D
	start = chrono::high_resolution_clock::now();
	cout << "NORMA Z RESIDUUM WEKTORA x PODCZAS OBLICZEÑ METOD¥ FAKTORYZACJI LU: " << eq3.metodaFaktoryzacjiLU() << endl;
	finish = chrono::high_resolution_clock::now();
	elapsed = finish - start;
	cout << "Elapsed time: " << elapsed.count() << endl<<endl;


// ZADANIE E
	/*start = chrono::high_resolution_clock::now();
	cout << "NORMA Z RESIDUUM WEKTORA x PODCZAS OBLICZEÑ METOD¥ FAKTORYZACJI LU: " << eq2.metodaFaktoryzacjiLU() << endl;
	finish = chrono::high_resolution_clock::now();
	elapsed = finish - start;
	cout << "Elapsed time: " << elapsed.count() << endl << endl;
	*/
	system("pause");

	return 0;
}

