#include <iostream>
#include <random>
#include "matrix.h"
#include "norm.h"
#include "misc.h"

using namespace std;

int main(int argc, char const *argv[])
{
	cout << "testing Matrix arithmetic:\n";

	cout << "I3 = 3x3 identity\n";
	Matrix I3 = identity(3);
	I3.print();

	cout << "\nI3 + I3 =\n";
	I3 += I3;
	I3. print();

	cout << "\n(I3 + I3) / 2 =\n";
	I3 /= 2;
	I3.print();

	cout << "\nI3 * 2 =\n";
	I3 *= 2;
	I3.print();

	cout << "\nI3 - I3 =\n";
	I3 -= I3;
	I3.print();

	cout << "\nI34 = 3x4x5 identity\n";
	Matrix I34 = identity(3, 4, 2, 5);
	I34.print();

	cout << "\nA = 2x3x4 zeroes\n";
	Matrix A = Matrix(2, 3, 4);
	A.print();

	cout << "\nA = 2x3x4 ones\n";
	A.fill(1);
	A.print();

	cout << "\nA + A =\n";
	A += A;
	A.print();

	cout << "\n(A + A) / 2 =\n";
	A /= 2;
	A.print();

	cout << "\nA = A * 2 =\n";
	A *= 2;
	A.print();

	float* R = new float[2 * 3 * 4];
	for (int i = 0; i < 24; ++i) R[i] = i;
	cout << "\nA = arrange(23)\n";
	A.fill_from(R);
	delete[] R;
	A.print();

	cout << "\nt = transpose(A) =\n";
	Matrix t = transpose(A);
	t.print();

	cout << "\nA = A * t =\n";
	A *= t;
	A.print();

	cout << "\nA = A - A =\n";
	A -= A;
	A.print();

	cout << "\nset A(1, 1, 1) = 10\n";
	A.set(1, 1, 1, 10);
	A.print();

	cout << "\nA(1, 1, 1) = " << A.get(1, 1, 1) << endl;

	cout << "\nset A(1, 1, 1) = 0\n";
	*A.ptr(1, 1, 1) = 0;
	A.print();
	return 0;
}