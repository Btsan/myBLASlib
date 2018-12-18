#include "matrix.h"
#include <cmath>

float l_norm(const Matrix& a, const float p = 2, const float q = 1, const uint32 ch = 0)
{
	const uint32 rows = a.num_rows();
	const uint32 cols = a.num_rows();
	const uint32 channel = ch * rows * cols;
	float norm = 0;

	for (uint32 j = 0; j < cols; j++)
	{
		const uint32 column_id = channel +j;
		float column_norm = 0;
		for (uint32 i = 0; i < rows; i++)
		{
			column_norm += (p != 1)? pow(abs(a.vals[column_id + (i * cols)]), p) : abs(a.vals[column_id + (i * cols)]);
		}
		norm += pow(column_norm, q / p);
	}

	return (q != 1)? pow(norm, 1 / q) : norm;
}