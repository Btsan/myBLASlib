#include <vector>
#include <string>
#include <cmath>

using namespace std;

template <class T>
class Matrix {
	vector< vector<T> > block;
	unsigned int rows, cols;

public:

	Matrix() {
		rows = cols = 0;
	}

	Matrix(unsigned int rows, unsigned int cols) {
		this->rows = rows;
		this->cols = cols;
		block.resize(rows);
		for (int i = 0; i < rows; ++i) {
			block[i].resize(cols, 0);
		}
	}

	Matrix(vector< vector<T> >& copy) {
		block = copy;
		rows = block.size();
		cols = (rows > 0)? block[0].size() : 0;
	}

	int getRows() {return rows;}
	int getCols() {return cols;}

	vector<T> & operator[](unsigned int i) {
		return block[i];
	}

	string toString() {
		string dmp = "[";
		for (int i = 0; i < rows; ++i) {
			dmp += "[ ";
			for (int j = 0; j < cols; ++j) {
				dmp += to_string(block[i][j]);
				dmp += " ";
			}
			dmp += "]\n";
		}
		dmp[dmp.size() - 1] = ']';
		return dmp;
	}

	Matrix<T> transpose() {
		Matrix<T> t(cols, rows);
		for (int i = 0; i < cols; ++i) {
			for (int j = 0; j < rows; ++j) {
				t[i][j] = block[j][i];
			}
		}
		return t;
	}

	T reduce_sum() {
		T sum = 0;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				sum += block[i][j];
			}
		}
		return sum;
	}

	T reduce_mean() {
		return reduce_sum() / (rows * cols);
	}

	Matrix<T> square_root() {
		Matrix<T> m(rows, cols);
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				m[i][j] = sqrt(block[i][j]);
			}
		}
		return m;
	}

	Matrix<T> natural_log() {
		Matrix<T> m(rows, cols);
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				m[i][j] = log(block[i][j]);
			}
		}
		return m;
	}

	Matrix<T> multiply(T a) {
		Matrix<T> prod(block);
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				prod[i][j] *= a;
			}
		}
		return prod;
	}
};

template <class T>
Matrix<T> add(Matrix<T> a, Matrix<T> b) {
	if (a.getRows() != b.getRows() && a.getCols() != b.getCols()) {
		cerr << "Matrix addition: dimension mismatch\n";
		throw;
	}
	Matrix<T> sum(a.getRows(), a.getCols());
	for (int row = 0; row < a.getRows(); ++row) {
		for (int col = 0; col < a.getCols(); ++col) {
			sum[row][col] = a[row][col] + b[row][col];
		}
	}
	return sum;
}

template <class T>
Matrix<T> subtract(Matrix<T> a, Matrix<T> b) {
	if (a.getRows() != b.getRows() && a.getCols() != b.getCols()) {
		cerr << "Matrix subtraction: dimension mismatch\n";
		throw;
	}
	Matrix<T> diff(a.getRows(), a.getCols());
	for (int row = 0; row < a.getRows(); ++row) {
		for (int col = 0; col < a.getCols(); ++col) {
			diff[row][col] = a[row][col] - b[row][col];
		}
	}
	return diff;
}

template <class T>
Matrix<T> dot(Matrix<T> a, Matrix<T> b) {
	if (a.getCols() != b.getRows()) {
		cerr << "Matrix product: dimension mismatch\n";
		throw;
	}
	Matrix<T> prod(a.getRows(), b.getCols());
	for (int row = 0; row < a.getRows(); ++row) {
		for (int col = 0; col < b.getCols(); ++col) {
			for (int k = 0; k < a.getCols(); ++k) {
				prod[row][col] += a[row][k] * b[k][col];
			}
		}
	}
	return prod;
}

template <class T>
Matrix<T> dot(T a, Matrix<T> b) {
	Matrix<T> wrapper(1, 1);
	wrapper[0][0] = a;
	return dot<T>(wrapper, b);
}

template <class T>
Matrix<T> dot(Matrix<T> a, T b) {
	Matrix<T> wrapper(1, 1);
	wrapper[0][0] = b;
	return dot<T>(a, wrapper);
}

template <class T>
Matrix<T> identity(int n) {
	Matrix<T> I(n, n);
	for (int i = 0; i < n; ++i) {
		I[i][i] = 1;
	}
	return I;
}