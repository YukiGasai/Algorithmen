#include <iostream>



void printMatrix(float** matrix, int size) {
	std::cout << std::endl;
	for (int i = 0; i < size; i++)
	{
		for (int y = 0; y < size; y++)
		{
			std::cout << matrix[y][i] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void prinVector(float* vector, int size) {
	std::cout << std::endl;
	for (int y = 0; y < size; y++)
	{
		std::cout << vector[y] << std::endl;
	}
	std::cout << std::endl;
}

float getBetrag(float* vector, int size) {
	float sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += vector[i] * vector[i];
	}
	return sqrt(sum);
}


float* JacobiVerfahren(float** matrix, float* B, int size) {

	float* oldResult = new float[size];
	float* newResult = new float[size];
	for (int i = 0; i < size; i++) {
		oldResult[i] = 0;
		newResult[i] = 0;
	}

	int runs = 0;

	while (true) {

		//Von oben nach unten
		for (int i = 0; i < size; i++)
		{

			float sum = 0;
			//Von links nach rechts
			for (int j = 0; j < size; j++)
			{
				if (i == j)continue;
				sum += matrix[j][i] * oldResult[j];
			}

			newResult[i] = 1/matrix[i][i] *( B[i] - sum);
		}


		if (abs(getBetrag(oldResult, size) - getBetrag(newResult, size)) < 0.00001) {
			std::cout << "RUNNS JacobiVerfahren " << runs << std::endl;
			return newResult;
		}
		else {
			for (int i = 0; i < size; i++)
			{
				oldResult[i] = newResult[i];
			}
		}
		runs++;
	}


}

float* GaußSeidelVerfahren(float** matrix, float* B, int size, int runs = 100) {
	float* result = new float[size];
	for (int i = 0; i < size; i++) {
		result[i] = 0;
	}


	for (int runIndex = 0; runIndex < runs; runIndex++)
	{

		//Von oben nach unten
		for (int i = 0; i < size; i++)
		{

			float sum = 0;
			//Von links nach rechts
			for (int j = 0; j < size; j++)
			{
				if (i == j)continue;
				sum += matrix[j][i] * result[j];
			}

			result[i] = 1 / matrix[i][i] * (B[i] - sum);
		}
	}
	std::cout << "RUNNS GaußSeidelVerfahren " << runs << std::endl;
	return result;
}


bool Diagonaldominanz(float** matrix, int size) {
	for (int y = 0; y < size; y++)
	{
		float rowSum = 0;
		for (int x = 0; x < size; x++)
		{
			if (x != y) {
				rowSum += abs(matrix[x][y]);
			}
		}
		if (rowSum > matrix[y][y]) {
			return false;
		}
	}
	return true;
}

int main() {

	int size = 3;

	float** matrix = new float* [size];
	for (int i = 0; i < size; i++)
		matrix[i] = new float[size];

	matrix[0][0] = 3;
	matrix[1][0] = 1;
	matrix[2][0] = 0;

	matrix[0][1] = 1;
	matrix[1][1] = 3;
	matrix[2][1] = 1;

	matrix[0][2] = 0;
	matrix[1][2] = 1;
	matrix[2][2] = 3;


	float* B = new float [size];
	B[0] = 1;
	B[1] = 5;
	B[2] = 7;
	

	if (Diagonaldominanz(matrix, size)) {

		prinVector(JacobiVerfahren(matrix, B, size),size);
		prinVector(GaußSeidelVerfahren(matrix, B, size,17),size);

	}
}