#include "matrix.h"

#ifndef uint32
#define uint32 unsigned int
#endif

float max(const Matrix& a)
{
	const uint32 n = a.num_vals();
	float m = a.vals[0];

	for (uint32 i = 1; i < n; i++)
	{
		if (a.vals[i] > m) m = a.vals[i];
	}

	return m;
}

float min(const Matrix& a)
{
	const uint32 n = a.num_vals();
	float m = a.vals[0];

	for (uint32 i = 1; i < n; i++)
	{
		if (a.vals[i] < m) m = a.vals[i];
	}

	return m;
}

Matrix abs(Matrix a)
{
	const uint32 n = a.num_vals();

	for (uint32 i = 0; i < n; i++)
	{
		if (a.vals[i] < 0) a.vals[i] *= -1.;
	}

	return a;
}

Matrix reciprocal(Matrix a)
{
	const uint32 n = a.num_vals();

	for (uint32 i = 0; i < n; i++)
	{
		a.vals[i] = 1. / a.vals[i];
	}

	return a;
}

float trace(const Matrix& a, const uint32 ch = 0)
{
	const uint32 rows = a.num_rows();
	const uint32 cols = a.num_cols();
	const uint32 chan = ch * rows * cols;

	float t = 0;

	uint32 i = 0;
	while (i < rows && i < cols)
	{
		t += a.vals[chan + (i++ * (cols + 1))];
	}

	return t;
}