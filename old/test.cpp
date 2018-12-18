#include <iostream>
#include "Matrix.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
	Matrix<float> I = identity<float>(4);
	cout << "Identity matrix:\n" << I.toString() << endl;

	cout << "I * 4 =\n" << I.multiply(4).toString() << endl;

	cout << "I + I =\n" << add<float>(I, I).toString() << endl;

	cout << "I - I =\n" << subtract<float>(I, I).toString() << endl;

	cout << "transpose(I) =\n" << I.transpose().toString() << endl;

	cout << "sqrt(I) =\n" << I.square_root().toString() << endl;

	cout << "log(I) =\n" << I.natural_log().toString() << endl;

	return 0;
}