#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstring>

#ifndef uint32
#define uint32 unsigned int
#endif

using namespace std;

class Matrix
{
	uint32 rows, cols, chans, n;

public:
	float* vals;

	Matrix(const uint32 cols = 0)
	{
		this->cols = cols;
		rows = chans = (cols > 0)? 1 : 0;
		n = rows * cols * chans;

		if (cols > 0)
		{
			vals = new float[cols];
			fill(0);
		}
	}

	Matrix(const uint32 rows, const uint32 cols, const uint32 chans = 1, const float* init = NULL)
	{
		this->rows = (cols > 0 && rows > 0)? rows : 0;
		this->cols = (rows > 0 && rows > 0)? cols : 0;
		this->chans = (rows > 0 && rows > 0)? ((chans > 0)? chans : 1) : 0;
		n = rows * cols * chans;

		if (n > 0)
		{
			vals = new float[n];
			if (init != NULL) fill_from(init);
			else fill(0);
		}
	}

	inline void fill_from(const float* init)
	{
		memcpy(vals, init, n * sizeof(float));
	}

	inline void fill(const float val)
	{
		for (uint32 i = 0; i < n; i++)
		{
			vals[i] = val;
		}
	}

	void print() const
	{
		cout << rows << " rows \t" << cols << " cols\t" << chans << " channels\n";
		for (uint32 k = 0; k < chans; k++)
		{
			for (uint32 i = 0; i < rows; i++)
			{
				cout << ' ';
				for (uint32 j = 0; j < cols; j++)
				{
					cout << vals[(k * (rows * cols)) + (i * cols) + j];
					if (j < cols - 1) cout << ", ";
				}
				cout << endl;
			}
			cout << endl;
		}
	}

	uint32 num_rows() const {return rows;}
	uint32 num_cols() const {return cols;}
	uint32 num_chans() const {return chans;}
	uint32 num_vals() const {return n;}

	Matrix& operator+=(const float& rhs)
	{
		for (uint32 i = 0; i < n; i++)
		{
			vals[i] += rhs;
		}
		return *this;
	}

	Matrix& operator-=(const float& rhs)
	{
		for (uint32 i = 0; i < n; i++)
		{
			vals[i] -= rhs;
		}
		return *this;
	}

	Matrix& operator*=(const float& rhs)
	{
		for (uint32 i = 0; i < n; i++)
		{
			vals[i] *= rhs;
		}
		return *this;
	}

	Matrix& operator/=(const float& rhs)
	{
		for (uint32 i = 0; i < n; i++)
		{
			vals[i] /= rhs;
		}
		return *this;
	}

	Matrix& operator+=(const Matrix& rhs)
	{
		for (uint32 i = 0; i < n; i++)
		{
			vals[i] += rhs.vals[i];
		}
		return *this;
	}

	Matrix& operator-=(const Matrix& rhs)
	{
		for (uint32 i = 0; i < n; i++)
		{
			vals[i] -= rhs.vals[i];
		}
		return *this;
	}

	Matrix& operator*=(const Matrix& rhs)
	{
		const uint32 c_cols = rhs.num_cols();
		const uint32 c_rows = rhs.num_rows();
		const uint32 c_chans = rhs.num_chans();

		n = rows * c_cols * chans;
		float* prod = new float[n]{0};
		for (uint32 channel = 0; channel < chans; channel++)
		{
			for (uint32 i = 0; i < rows; i++)
			{
				const uint32 dest = (channel * rows * c_cols) + (i * c_cols);
				const uint32 src_a = (channel * rows * cols) + (i * cols);
				for (uint32 j = 0; j < c_cols; j++)
				{
					uint32 src_b = cols * c_cols;
					if (c_chans > 1) src_b *= channel;
					src_b += j;
					for (uint32 k = 0; k < cols; k++)
					{
						prod[dest + j] += vals[src_a + k] * rhs.vals[src_b + (k * c_cols)];
					}
				}
			}
		}

		cols = c_cols;
		fill_from(prod);

		return *this;
	}

	float get(const uint32 row, const uint32 col, const uint32 chan) const
	{
		return vals[(chan * rows * cols) + (row * cols) + col];
	}

	void set(const uint32 row, const uint32 col, const uint32 chan, const float& val)
	{
		vals[(chan * rows * cols) + (row * cols) + col] = val;
	}

	float* ptr(const uint32 row, const uint32 col, const uint32 chan) const
	{
		return vals + (chan * rows * cols) + (row * cols) + col;
	}
};

inline Matrix operator+(Matrix lhs, const Matrix& rhs)
{
	lhs += rhs;
	return lhs;
}

inline Matrix operator-(Matrix lhs, const Matrix& rhs)
{
	lhs -= rhs;
	return lhs;
}

inline Matrix operator+(Matrix lhs, const float& rhs)
{
	lhs += rhs;
	return lhs;
}

inline Matrix operator-(Matrix lhs, const float& rhs)
{
	lhs -= rhs;
	return lhs;
}

inline Matrix operator*(Matrix lhs, const float& rhs)
{
	lhs *= rhs;
	return lhs;
}

inline Matrix operator/(Matrix lhs, const float& rhs)
{
	lhs /= rhs;
	return lhs;
}

inline Matrix operator*(Matrix lhs, const Matrix& rhs)
{
	lhs *= rhs;
	return lhs;
}

Matrix identity(const uint32 rows, const uint32 cols, const uint32 chans, const float val = 1) {
	Matrix I = Matrix(rows, cols, chans);

	const uint32 ch = rows * cols;
	uint32 i = 0;
	while (i < rows && i < cols)
	{
		const uint32 id = i * (cols + 1);
		for (uint32 channel = 0; channel < chans; channel++)
		{
			I.vals[(channel * ch) + id] = val;
		}
		i++;
	}

	return I;
}

Matrix identity(const uint32 n, const float val = 1)
{
	return identity(n, n, 1, val);
}

Matrix transpose(const Matrix& a)
{
	const uint32 rows = a.num_rows();
	const uint32 cols = a.num_cols();
	const uint32 chans = a.num_chans();
	Matrix t = Matrix(cols, rows, chans);

	for (uint32 channel = 0; channel < chans; channel++)
	{
		const uint32 ch = channel * rows * cols;
		for (uint32 i = 0; i < rows; i++)
		{
			for (uint32 j = 0; j < cols; j++)
			{
				t.vals[ch + (j * rows) + i] = a.vals[ch + (i * cols) + j];
			}
		}
	}

	return t;
}

#endif