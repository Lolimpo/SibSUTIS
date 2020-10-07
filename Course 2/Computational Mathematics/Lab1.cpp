#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

void FillMatrix(char* filename, float **A, int Length, int Height, bool *ErrFlag)
{
	char k;
	int sign = 1;
	std::ifstream in(filename);
	if (!in)
	{
		std::cout << "Error. File not found";
		*ErrFlag = true;
	}
	else
	{
		for (int i = 0; i < Height; i++)
			for (int j = 0; j < Length; j++)
			{
				in >> k;
				if (k == '-')
				{
					sign = -1;
					j--;
				}
				else
				{
					A[i][j] = (k - 48) * sign;
					sign = 1;
				}
			}
		in.close();
	}
}

void ExchangeMatrixStrings(float **A, int S1, int S2, int Length)
{
	float F;
	for (int n = 0; n < Length; n++)
	{
		F = A[S2][n];
		A[S2][n] = A[S1][n];
		A[S1][n] = F;
	}
}

int main()
{
	int Length = 4, Height = 3;
	bool ErrFlag = false;
	float Origin;
	float Multi;
	float Max;
	float **A = new float*[Length];
	for (int i = 0; i < Length; i++)
		A[i] = new float[Height];
	FillMatrix("Matrix.txt", A, Length, Height, &ErrFlag);
	if (ErrFlag)
		return 0;
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Length; j++)
		{
			std::cout << A[i][j];
			std::cout.width(13);
		}
		std::cout << "\n";
	}
	system("PAUSE");

	for (int z = 0; z < Height - 1; z++)
	{
		Max = abs(A[z][z]);
		for (int Heig = z + 1; Heig < Height; Heig++)
		{
			if (Max < abs(A[Heig][z]))
			{
				Max = abs(A[Heig][z]);
				ExchangeMatrixStrings(A, z, Heig, Length);
			}
		}
		Origin = A[z][z];
		for (int i = z + 1; i < Height; i++)
		{
			Multi = A[i][z] / A[z][z];
			for (int k = z; k < Length; k++)
			{
				A[i][k] = A[i][k] - A[z][k] * Multi;
			}
		}

	}

	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Length; j++)
		{
			printf("%.5f ", A[i][j]);
		}
		std::cout << "\n";
	}
	system("PAUSE");
    return 0;
}

